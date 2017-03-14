/*
*****************************************************************************
* File        : 
* Description : u3d mono reflection
* Creation    : 2017.2.28
* Author      : LLhack 
* History     : 
*
******************************************************************************
**/
#include <stdarg.h>
#include <unistd.h>    
#include <stdio.h>    
#include <stdlib.h>    
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <jni.h>
#include <android/log.h>
#include "LL-gamejni.h"
#include "LL-mono_wraper.h"

#define REGCALSSNAME "com/LLgameFucker/u3dGameJni"
#define PRINT_LOG(format, ...)   __android_log_print(ANDROID_LOG_ERROR, "LL-gamejni", format, ##__VA_ARGS__);

#define DEBUG 1

#ifndef JNIEXPORT
#define JNIEXPORT __attribute__ ((visibility("default")))
#endif

MonoDomain* domain = NULL;
MonoImage* image = NULL;
bool isInitMonoEnv = false;

// init mono
int initMonoEnv(const char* szMonoPath)
{
	if (!mono_wraper::mono_init(szMonoPath)){
	#ifdef DEBUG
	PRINT_LOG("mono_init failed!!!!");
	#endif
		return -1;
	}
	domain = mono_wraper::mono_get_root_domain();
	if (domain == NULL){
	#ifdef DEBUG
	PRINT_LOG("mono_get_root_domain failed");
	#endif
		return -1;
	}
	image = mono_wraper::mono_get_image(domain, "Assembly-CSharp");
	if (image == NULL){
	#ifdef DEBUG
	PRINT_LOG("mono_get_image failed");
	#endif
		return -1;
	}
	return 0;
}

jint native_monoInit(JNIEnv* env, jobject thiz, jstring jstrMonoPath)
{
	int result = 0;
	const char* szMonoPath = env->GetStringUTFChars(jstrMonoPath, 0);
	if (!szMonoPath){
		result = -1;
		goto END;
	}
	if (!isInitMonoEnv){
		initMonoEnv(szMonoPath);
		isInitMonoEnv = true;
	}	
END:
	env->ReleaseStringUTFChars(jstrMonoPath, szMonoPath);
	return result;
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	PRINT_LOG("call JNI_OnLoad ~~!!");
	JNIEnv* env;
	if (vm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK)
		return -1;
	JNINativeMethod methods[] =
	{
		{ "doMonoInit", "(Ljava/lang/String;)I", (void *)native_monoInit },
	};

	#define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))

	jclass clz;
	clz = env->FindClass(REGCALSSNAME);

	env->RegisterNatives(clz, methods, NELEM(methods));

	return JNI_VERSION_1_4;
}
