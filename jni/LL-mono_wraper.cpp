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

#include "LL-mono_wraper.h"
#include<dlfcn.h> 

Proc_mono_get_root_domain mono_wraper::proc_get_root_domain = NULL;
Proc_mono_domain_assembly_open mono_wraper::proc_assembly_open = NULL;
Proc_mono_assembly_get_image mono_wraper::proc_assembly_get_image = NULL;
Proc_mono_class_from_name mono_wraper::proc_class_from_name = NULL;
Proc_mono_class_get_fields mono_wraper::proc_class_get_fields = NULL;
Proc_mono_field_get_name mono_wraper::proc_field_get_name = NULL;
Proc_mono_field_get_type mono_wraper::proc_field_get_type = NULL;
Proc_mono_type_get_type mono_wraper::proc_type_get_type = NULL;
Proc_mono_field_get_value mono_wraper::proc_field_get_value = NULL;
Proc_mono_class_get_method_from_name mono_wraper::proc_class_get_method_from_name = NULL;
Proc_mono_runtime_invoke mono_wraper::proc_runtime_invoke = NULL;
Proc_mono_method_desc_new mono_wraper::proc_method_desc_new = NULL;
Proc_mono_method_desc_search_in_class mono_wraper::proc_method_desc_search_in_class = NULL;
Proc_mono_method_get_unmanaged_thunk mono_wraper::proc_method_get_unmanaged_thunk = NULL;
Proc_mono_field_get_value_object mono_wraper::proc_field_get_value_object = NULL;
Proc_mono_object_get_class mono_wraper::proc_object_get_class = NULL;
Proc_mono_class_get_name mono_wraper::proc_class_get_name = NULL;
Proc_mono_class_get_element_class mono_wraper::proc_class_get_element_class = NULL;
Proc_mono_class_get_field_from_name mono_wraper::proc_class_get_field_from_name = NULL;
Proc_mono_class_get_property_from_name mono_wraper::proc_class_get_property_from_name = NULL;
Proc_mono_property_get_get_method mono_wraper::proc_property_get_get_method = NULL;
Proc_mono_class_get_type mono_wraper::proc_class_get_type = NULL;
Proc_mono_array_addr_with_size mono_wraper::proc_array_addr_with_size = NULL;
Proc_mono_array_element_size mono_wraper::proc_array_element_size = NULL;
Proc_mono_class_get_parent mono_wraper::proc_class_get_parent = NULL;
Proc_mono_string_to_utf8 mono_wraper::proc_string_to_utf8 = NULL;
Proc_mono_thread_attach mono_wraper::proc_thread_attach = NULL;
Proc_mono_thread_detach mono_wraper::proc_thread_detach = NULL;
Proc_mono_object_unbox mono_wraper::proc_object_unbox = NULL;
Proc_mono_string_new mono_wraper::proc_string_new = NULL;

bool mono_wraper::mono_init(const char *monopath){
	void* dlhandle = dlopen(monopath, RTLD_LAZY);
	if (dlhandle == NULL){
		return false;
	}
	proc_get_root_domain = (Proc_mono_get_root_domain)dlsym(dlhandle, "mono_get_root_domain");
	proc_assembly_open = (Proc_mono_domain_assembly_open)dlsym(dlhandle, "mono_domain_assembly_open");
	proc_assembly_get_image = (Proc_mono_assembly_get_image)dlsym(dlhandle, "mono_assembly_get_image");
	proc_class_from_name = (Proc_mono_class_from_name)dlsym(dlhandle, "mono_class_from_name");
	proc_class_get_fields = (Proc_mono_class_get_fields)dlsym(dlhandle, "mono_class_get_fields");
	proc_field_get_name = (Proc_mono_field_get_name)dlsym(dlhandle, "mono_field_get_name");
	proc_field_get_type = (Proc_mono_field_get_type)dlsym(dlhandle, "mono_field_get_type");
	proc_type_get_type = (Proc_mono_type_get_type)dlsym(dlhandle, "mono_type_get_type");
	proc_field_get_value = (Proc_mono_field_get_value)dlsym(dlhandle, "mono_field_get_value");
	proc_class_get_method_from_name = (Proc_mono_class_get_method_from_name)dlsym(dlhandle, "mono_class_get_method_from_name");
	proc_runtime_invoke = (Proc_mono_runtime_invoke)dlsym(dlhandle, "mono_runtime_invoke");
	proc_method_desc_new = (Proc_mono_method_desc_new)dlsym(dlhandle, "mono_method_desc_new");
	proc_method_desc_search_in_class = (Proc_mono_method_desc_search_in_class)dlsym(dlhandle, "mono_method_desc_search_in_class");
	proc_method_get_unmanaged_thunk = (Proc_mono_method_get_unmanaged_thunk)dlsym(dlhandle, "mono_method_get_unmanaged_thunk");
	proc_field_get_value_object = (Proc_mono_field_get_value_object)dlsym(dlhandle, "mono_field_get_value_object");
	proc_object_get_class = (Proc_mono_object_get_class)dlsym(dlhandle, "mono_object_get_class");
	proc_class_get_name = (Proc_mono_class_get_name)dlsym(dlhandle, "mono_class_get_name");
	proc_class_get_element_class = (Proc_mono_class_get_element_class)dlsym(dlhandle, "mono_class_get_element_class");
	proc_class_get_field_from_name = (Proc_mono_class_get_field_from_name)dlsym(dlhandle, "mono_class_get_field_from_name");
	proc_class_get_property_from_name = (Proc_mono_class_get_property_from_name)dlsym(dlhandle, "mono_class_get_property_from_name");
	proc_property_get_get_method = (Proc_mono_property_get_get_method)dlsym(dlhandle, "mono_property_get_get_method");
	proc_class_get_type = (Proc_mono_class_get_type)dlsym(dlhandle, "mono_class_get_type");
	proc_array_addr_with_size = (Proc_mono_array_addr_with_size)dlsym(dlhandle, "mono_array_addr_with_size");
	proc_array_element_size = (Proc_mono_array_element_size)dlsym(dlhandle, "mono_array_element_size");
	proc_class_get_parent = (Proc_mono_class_get_parent)dlsym(dlhandle, "mono_class_get_parent");
	proc_string_to_utf8 = (Proc_mono_string_to_utf8)dlsym(dlhandle, "mono_string_to_utf8");
	proc_thread_attach = (Proc_mono_thread_attach)dlsym(dlhandle, "mono_thread_attach");
	proc_thread_detach = (Proc_mono_thread_detach)dlsym(dlhandle, "mono_thread_detach");
	proc_object_unbox = (Proc_mono_object_unbox)dlsym(dlhandle, "mono_object_unbox");
	proc_string_new = (Proc_mono_string_new)dlsym(dlhandle, "mono_string_new");

	return proc_get_root_domain && proc_assembly_open && proc_assembly_get_image && proc_class_from_name &&
		proc_class_get_fields && proc_field_get_name && proc_field_get_type && proc_type_get_type &&
		proc_field_get_value && proc_class_get_method_from_name && proc_runtime_invoke && proc_method_desc_new &&
		proc_method_desc_search_in_class && proc_method_get_unmanaged_thunk && proc_field_get_value_object &&
		proc_object_get_class && proc_class_get_name && proc_class_get_element_class && proc_class_get_field_from_name &&
		proc_class_get_property_from_name && mono_property_get_get_method && proc_class_get_type && proc_array_addr_with_size &&
		proc_array_element_size && proc_class_get_parent && proc_string_to_utf8 && proc_thread_attach && proc_thread_detach &&
		proc_object_unbox && proc_string_new;
}

MonoImage* mono_wraper::mono_get_image(MonoDomain* pDomain, const char* path)
{
	if (pDomain != NULL){

		MonoAssembly* assembly = proc_assembly_open(pDomain, path);
		if (assembly != NULL){
			return proc_assembly_get_image(assembly);     //获取MonoClass;
		}
	}
	return NULL;
}

MonoDomain* mono_wraper::mono_get_root_domain()
{
	return proc_get_root_domain();
}

MonoAssembly* mono_wraper::mono_domain_assembly_open(MonoDomain *domain, const char *name)
{
	return proc_assembly_open(domain, name);
}

MonoImage* mono_wraper::mono_assembly_get_image(MonoAssembly *assembly)
{
	return proc_assembly_get_image(assembly);
}

MonoClass* mono_wraper::mono_class_from_name(MonoImage *image, const char* name_space, const char *name)
{
	return proc_class_from_name(image, name_space, name);
}

MonoClassField* mono_wraper::mono_class_get_fields(MonoClass* klass, void **iter)
{
	return proc_class_get_fields(klass, iter);
}

const char* mono_wraper::mono_field_get_name(MonoClassField *field)
{
	return proc_field_get_name(field);
}

MonoType* mono_wraper::mono_field_get_type(MonoClassField *field)
{
	return proc_field_get_type(field);
}

int mono_wraper::mono_type_get_type(MonoType *type)
{
	return proc_type_get_type(type);
}

void mono_wraper::mono_field_get_value(MonoObject *obj, MonoClassField *field, void *value)
{
	proc_field_get_value(obj, field, value);
}

MonoMethod* mono_wraper::mono_class_get_method_from_name(MonoClass *klass, const char *name, int param_count)
{
	return proc_class_get_method_from_name(klass, name, param_count);
}

MonoObject* mono_wraper::mono_runtime_invoke(MonoMethod *method, void *obj, void **params, MonoObject **exc)
{
	return proc_runtime_invoke(method, obj, params, exc);
}

MonoMethodDesc* mono_wraper::mono_method_desc_new(const char *name, bool include_namespace)
{
	return proc_method_desc_new(name, include_namespace);
}

MonoMethod* mono_wraper::mono_method_desc_search_in_class(MonoMethodDesc *desc, MonoClass *klass)
{
	return proc_method_desc_search_in_class(desc, klass);
}

void* mono_wraper::mono_method_get_unmanaged_thunk(MonoMethod *method)
{
	return proc_method_get_unmanaged_thunk(method);
}

MonoObject* mono_wraper::mono_field_get_value_object(MonoDomain *domain, MonoClassField *field, MonoObject *obj)
{
	return proc_field_get_value_object(domain, field, obj);
}

MonoClass* mono_wraper::mono_object_get_class(MonoObject *obj)
{
	return proc_object_get_class(obj);
}

const char* mono_wraper::mono_class_get_name(MonoClass *kclass)
{
	return proc_class_get_name(kclass);
}

MonoClass* mono_wraper::mono_class_get_element_class(MonoClass *klass)
{
	return proc_class_get_element_class(klass);
}

MonoClassField* mono_wraper::mono_class_get_field_from_name(MonoClass *klass, const char *name)
{
	return proc_class_get_field_from_name(klass, name);
}

MonoProperty* mono_wraper::mono_class_get_property_from_name(MonoClass *klass, const char *name)
{
	return proc_class_get_property_from_name(klass, name);
}

MonoMethod* mono_wraper::mono_property_get_get_method(MonoProperty *prop)
{
	return proc_property_get_get_method(prop);
}

MonoType* mono_wraper::mono_class_get_type(MonoClass *klass)
{
	return proc_class_get_type(klass);
}

char* mono_wraper::mono_array_addr_with_size(MonoArray *array, int size, uintptr_t idx)
{
	return proc_array_addr_with_size(array, size, idx);
}

int mono_wraper::mono_array_element_size(MonoClass *ac)
{
	return proc_array_element_size(ac);
}

MonoClass* mono_wraper::mono_class_get_parent(MonoClass *klass)
{
	return proc_class_get_parent(klass);
}

char* mono_wraper::mono_string_to_utf8(MonoString *s)
{
	return proc_string_to_utf8(s);
}

MonoThread * mono_wraper::mono_thread_attach(MonoDomain *domain)
{
	return proc_thread_attach(domain);
}

void mono_wraper::mono_thread_detach(MonoThread *thread)
{
	proc_thread_detach(thread);
}

void* mono_wraper::mono_object_unbox(MonoObject *obj)
{
	return proc_object_unbox(obj);
}



MonoString* mono_wraper::mono_string_new(MonoDomain *domain, const char *text)
{
	return proc_string_new(domain, text);
}



//////////////////////////////////////////////////////////////////////////
MonoObject* mono_wraper::get_class_member_object(MonoDomain* pDomain, MonoClass* pclass, MonoObject* obj, const char* member)
{
	MonoClassField* field = proc_class_get_field_from_name(pclass, member);
	if (field)
		return proc_field_get_value_object(pDomain, field, obj);
	return NULL;	
}

MonoObject* mono_wraper::get_class_member_object(MonoDomain* pDomain, MonoObject* obj, const char* member)
{
	MonoClass* pClass = mono_object_get_class(obj);

	if (pClass){
		return get_class_member_object(pDomain, pClass, obj, member);
	}

	return NULL;	
}

MonoObject* mono_wraper::get_class_static_member_object(MonoDomain* pDomain, MonoClass* pclass, const char* member)
{
	MonoClassField* field = proc_class_get_field_from_name(pclass, member);
	if (field){
		return proc_field_get_value_object(pDomain, field, NULL);
	}

	return NULL;
}

MonoObject* mono_wraper::get_class_static_member_object(MonoDomain* pDomain, MonoImage* image, char* szclass, const char* member)
{
	MonoClass* pClass = mono_wraper::mono_class_from_name(image, "", szclass);     //获取MonoClass
	if (pClass){
		return get_class_static_member_object(pDomain, pClass, member);
	}
	return NULL;
}

void mono_wraper::get_class_member_value(MonoObject* obj, const char *name, void* value)
{
	MonoClass* pClass = proc_object_get_class(obj);
	if (pClass){
		MonoClassField* field = proc_class_get_field_from_name(pClass, name);
		if (field)
			proc_field_get_value(obj, field, value);
	}
}


MonoObject* mono_wraper::get_array_object(MonoArray* pArray, unsigned int index)
{

	MonoObject* presult = NULL;
	uintptr_t size = (uintptr_t)mono_array_length(pArray);
	if (index < size){
		MonoClass* pItemsClass = proc_object_get_class((MonoObject*)pArray);
		MonoClass* elementClass = proc_class_get_element_class(pItemsClass);
		int ele_size = proc_array_element_size(pItemsClass);
		char* data = proc_array_addr_with_size(pArray, ele_size, index);
		presult = *(MonoObject**)(data);
	}
	return  presult;
}

char* mono_wraper::get_array_value(MonoArray* pArray, unsigned int index)
{

	char* presult = NULL;
	uintptr_t size = (uintptr_t)mono_array_length(pArray);
	if (index < size){
		MonoClass* pItemsClass = proc_object_get_class((MonoObject*)pArray);
		MonoClass* elementClass = proc_class_get_element_class(pItemsClass);
		int ele_size = proc_array_element_size(pItemsClass);
		presult = proc_array_addr_with_size(pArray, ele_size, index);
	}
	return  presult;
}

MonoObject* mono_wraper::get_list_item_object(MonoDomain* pDomain, MonoObject* plist, unsigned int index)
{

	MonoObject* presult = NULL;
	MonoClass* pClass = proc_object_get_class(plist);
	if (pClass){
		MonoObject* pItems = get_class_member_object(pDomain, pClass, plist, "_items");
		if (pItems){
			MonoArray* item_array = (MonoArray*)pItems;
			presult = get_array_object(item_array, index);
		}
	}
	return presult;
}

int mono_wraper::get_list_item_size(MonoDomain* pDomain, MonoObject* plist)
{

	MonoClass* pClass = proc_object_get_class(plist);
	if (pClass){
		MonoObject* pItems = get_class_member_object(pDomain, pClass, plist, "_items");
		if (pItems){
			MonoArray* item_array = (MonoArray*)pItems;
			MonoClass* pItemsClass = proc_object_get_class(pItems);
			return proc_array_element_size(pItemsClass);
		}
	}
	return 0;
}

int mono_wraper::get_list_item_count(MonoObject* plist)
{
	int count = 0;

	MonoClass* pClass = proc_object_get_class(plist);

	if (pClass){
		MonoClassField* field = proc_class_get_field_from_name(pClass, "_size");
		if (field){
			proc_field_get_value(plist, field, &count);
		}
	}
	return count;
}

int mono_wraper::get_map_item_count(MonoObject* pMap)
{
	int count = 0;

	MonoClass* pClass = proc_object_get_class(pMap);

	if (pClass){
		MonoClassField* field = proc_class_get_field_from_name(pClass, "count");
		if (field){
			proc_field_get_value(pMap, field, &count);
		}
	}
	return count;
}

//
MonoObject* mono_wraper::get_map_object(MonoDomain* pDomain, MonoObject* pMap, int key)
{

	MonoObject* pResult = NULL;
	MonoClass* pClass = proc_object_get_class(pMap);

	if (pClass){
		MonoObject* pkeySlots = get_class_member_object(pDomain, pClass, pMap, "keySlots");
		MonoObject* pvalueSlots = get_class_member_object(pDomain, pClass, pMap, "valueSlots");
		MonoClass* pkeySlotsClass = proc_object_get_class(pkeySlots);

		uintptr_t map_size = get_map_item_count(pMap);

		for (uintptr_t i = 0; i < map_size; i++){
			int* pItem = (int*)get_array_value((MonoArray*)pkeySlots, i);
			if (pItem &&  *pItem == key){
				pResult = get_array_object((MonoArray*)pvalueSlots, i);
				break;
			}
		}
	}
	return pResult;
}

//值类型
char* mono_wraper::get_map_value(MonoDomain* pDomain, MonoObject* pMap, int key)
{

	char* pResult = NULL;
	MonoClass* pClass = proc_object_get_class(pMap);

	if (pClass){
		MonoObject* pkeySlots = get_class_member_object(pDomain, pClass, pMap, "keySlots");
		MonoObject* pvalueSlots = get_class_member_object(pDomain, pClass, pMap, "valueSlots");
		MonoClass* pkeySlotsClass = proc_object_get_class(pkeySlots);

		uintptr_t map_size = get_map_item_count(pMap);

		for (uintptr_t i = 0; i < map_size; i++){
			int* pItem = (int*)get_array_value((MonoArray*)pkeySlots, i);
			if (pItem &&  *pItem == key){
				pResult = get_array_value((MonoArray*)pvalueSlots, i);
				break;
			}
		}
	}
	return pResult;
}