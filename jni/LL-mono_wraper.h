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
#ifndef mono_wraper_h__
#define mono_wraper_h__

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/class.h> 
#include <mono/metadata/debug-helpers.h> 
#include <mono/metadata/mono-config.h> 
#include <mono/metadata/object.h> 

typedef MonoDomain* (*Proc_mono_get_root_domain)();
typedef MonoAssembly* (*Proc_mono_domain_assembly_open)(MonoDomain *domain, const char *name);
typedef MonoImage* (*Proc_mono_assembly_get_image)(MonoAssembly *assembly);
typedef MonoClass* (*Proc_mono_class_from_name)(MonoImage *image, const char* name_space, const char *name);
typedef MonoClassField* (*Proc_mono_class_get_fields)(MonoClass* klass, void **iter);
typedef const char* (*Proc_mono_field_get_name)(MonoClassField *field);
typedef MonoType* (*Proc_mono_field_get_type)(MonoClassField *field);
typedef int(*Proc_mono_type_get_type)(MonoType *type);
typedef void(*Proc_mono_field_get_value)(MonoObject *obj, MonoClassField *field, void *value);
typedef MonoMethod* (*Proc_mono_class_get_method_from_name)(MonoClass *klass, const char *name, int param_count);
typedef MonoObject* (*Proc_mono_runtime_invoke)(MonoMethod *method, void *obj, void **params, MonoObject **exc);
typedef MonoMethodDesc* (*Proc_mono_method_desc_new)(const char *name, bool include_namespace);
typedef MonoMethod* (*Proc_mono_method_desc_search_in_class)(MonoMethodDesc *desc, MonoClass *klass);
typedef void* (*Proc_mono_method_get_unmanaged_thunk)(MonoMethod *method);
typedef MonoObject* (*Proc_mono_field_get_value_object)(MonoDomain *domain, MonoClassField *field, MonoObject *obj);
typedef MonoClass* (*Proc_mono_object_get_class)(MonoObject *obj);
typedef const char* (*Proc_mono_class_get_name)(MonoClass *kclass);
typedef MonoClass* (*Proc_mono_class_get_element_class)(MonoClass *klass);
typedef MonoClassField* (*Proc_mono_class_get_field_from_name)(MonoClass *klass, const char *name);
typedef MonoProperty* (*Proc_mono_class_get_property_from_name)(MonoClass *klass, const char *name);
typedef MonoMethod* (*Proc_mono_property_get_get_method)(MonoProperty *prop);
typedef MonoType* (*Proc_mono_class_get_type)(MonoClass *klass);
typedef char* (*Proc_mono_array_addr_with_size)(MonoArray *array, int size, uintptr_t idx);
typedef int(*Proc_mono_array_element_size)(MonoClass *ac);
typedef MonoClass* (*Proc_mono_class_get_parent)(MonoClass *klass);
typedef char *(*Proc_mono_string_to_utf8)(MonoString *s);
typedef MonoThread * (*Proc_mono_thread_attach)(MonoDomain *domain);
typedef void (*Proc_mono_thread_detach)(MonoThread *thread);
typedef void* (*Proc_mono_object_unbox)(MonoObject *obj);
typedef MonoString* (*Proc_mono_string_new)(MonoDomain *domain, const char *text);


#define proc_array_addr(array,type,index) ((type*)(void*) proc_array_addr_with_size (array, sizeof (type), index))

class mono_wraper{
public:
	static bool mono_init(const char *monopath);

	static MonoImage* mono_get_image(MonoDomain* pDomain, const char* path);

	static MonoDomain* mono_get_root_domain();

	static MonoAssembly* mono_domain_assembly_open(MonoDomain *domain, const char *name);

	static MonoImage* mono_assembly_get_image(MonoAssembly *assembly);

	static MonoClass* mono_class_from_name(MonoImage *image, const char* name_space, const char *name);

	static MonoClassField* mono_class_get_fields(MonoClass* klass, void **iter);

	static const char* mono_field_get_name(MonoClassField *field);

	static MonoType* mono_field_get_type(MonoClassField *field);

	static int mono_type_get_type(MonoType *type);

	static void mono_field_get_value(MonoObject *obj, MonoClassField *field, void *value);

	static MonoMethod* mono_class_get_method_from_name(MonoClass *klass, const char *name, int param_count);

	static MonoObject* mono_runtime_invoke(MonoMethod *method, void *obj, void **params, MonoObject **exc);

	static MonoMethodDesc* mono_method_desc_new(const char *name, bool include_namespace);

	static MonoMethod* mono_method_desc_search_in_class(MonoMethodDesc *desc, MonoClass *klass);

	static void* mono_method_get_unmanaged_thunk(MonoMethod *method);

	static MonoObject* mono_field_get_value_object(MonoDomain *domain, MonoClassField *field, MonoObject *obj);

	static MonoClass* mono_object_get_class(MonoObject *obj);

	static const char* mono_class_get_name(MonoClass *kclass);

	static MonoClass* mono_class_get_element_class(MonoClass *klass);

	static MonoClassField* mono_class_get_field_from_name(MonoClass *klass, const char *name);

	static MonoProperty* mono_class_get_property_from_name(MonoClass *klass, const char *name);

	static MonoMethod* mono_property_get_get_method(MonoProperty *prop);

	static MonoType* mono_class_get_type(MonoClass *klass);

	static char* mono_array_addr_with_size(MonoArray *array, int size, uintptr_t idx);

	static int mono_array_element_size(MonoClass *ac);

	static MonoClass* mono_class_get_parent(MonoClass *klass);

	static char* mono_string_to_utf8(MonoString *s);

	static MonoThread * mono_thread_attach(MonoDomain *domain);

	static void mono_thread_detach(MonoThread *thread);

	static void* mono_object_unbox(MonoObject *obj);

	static MonoString* mono_string_new(MonoDomain *domain, const char *text);

	//

	static MonoObject* get_class_member_object(MonoDomain* pDomain, MonoClass* pclass, MonoObject* obj, const char* member);

	static MonoObject* get_class_static_member_object(MonoDomain* pDomain, MonoClass* pclass, const char* member);

	static MonoObject* get_class_member_object(MonoDomain* pDomain, MonoObject* obj, const char* member);

	static MonoObject* get_class_static_member_object(MonoDomain* pDomain, MonoImage* image, char* szclass, const char* member);

	static void get_class_member_value(MonoObject* obj, const char *name, void* value);

	static MonoObject* get_array_object(MonoArray* pArray, unsigned int index);

	static char* get_array_value(MonoArray* pArray, unsigned int index);

	static MonoObject* get_list_item_object(MonoDomain* pDomain, MonoObject* plist, unsigned int index);

	//获取list里单个元素的大小
	static int get_list_item_size(MonoDomain* pDomain, MonoObject* plist);

	//获取list里元素的个数
	static int get_list_item_count(MonoObject* plist);

	static int get_map_item_count(MonoObject* pMap);

	//引用类型
	static MonoObject* get_map_object(MonoDomain* pDomain, MonoObject* pMap, int key);

	//值类型
	static char* get_map_value(MonoDomain* pDomain, MonoObject* pMap, int key);
private:
	static Proc_mono_get_root_domain proc_get_root_domain;
	static Proc_mono_domain_assembly_open proc_assembly_open;
	static Proc_mono_assembly_get_image proc_assembly_get_image;
	static Proc_mono_class_from_name proc_class_from_name;
	static Proc_mono_class_get_fields proc_class_get_fields;
	static Proc_mono_field_get_name proc_field_get_name;
	static Proc_mono_field_get_type proc_field_get_type;
	static Proc_mono_type_get_type proc_type_get_type;
	static Proc_mono_field_get_value proc_field_get_value;
	static Proc_mono_class_get_method_from_name proc_class_get_method_from_name;
	static Proc_mono_runtime_invoke proc_runtime_invoke;
	static Proc_mono_method_desc_new proc_method_desc_new;
	static Proc_mono_method_desc_search_in_class proc_method_desc_search_in_class;
	static Proc_mono_method_get_unmanaged_thunk proc_method_get_unmanaged_thunk;
	static Proc_mono_field_get_value_object proc_field_get_value_object;
	static Proc_mono_object_get_class proc_object_get_class;
	static Proc_mono_class_get_name proc_class_get_name;
	static Proc_mono_class_get_element_class proc_class_get_element_class;
	static Proc_mono_class_get_field_from_name proc_class_get_field_from_name;
	static Proc_mono_class_get_property_from_name proc_class_get_property_from_name;
	static Proc_mono_property_get_get_method proc_property_get_get_method;
	static Proc_mono_class_get_type proc_class_get_type;
	static Proc_mono_array_addr_with_size proc_array_addr_with_size;
	static Proc_mono_array_element_size proc_array_element_size;
	static Proc_mono_class_get_parent proc_class_get_parent;
	static Proc_mono_string_to_utf8 proc_string_to_utf8;
	static Proc_mono_thread_attach proc_thread_attach;
	static Proc_mono_thread_detach proc_thread_detach;
	static Proc_mono_object_unbox proc_object_unbox;
	static Proc_mono_string_new proc_string_new;
};

#endif // mono_wraper_h__