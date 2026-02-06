// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InteractionSystemCameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeInteractionSystemCameraManager() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemCameraManager();
INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemCameraManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_InteractionSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AInteractionSystemCameraManager ******************************************
void AInteractionSystemCameraManager::StaticRegisterNativesAInteractionSystemCameraManager()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AInteractionSystemCameraManager;
UClass* AInteractionSystemCameraManager::GetPrivateStaticClass()
{
	using TClass = AInteractionSystemCameraManager;
	if (!Z_Registration_Info_UClass_AInteractionSystemCameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("InteractionSystemCameraManager"),
			Z_Registration_Info_UClass_AInteractionSystemCameraManager.InnerSingleton,
			StaticRegisterNativesAInteractionSystemCameraManager,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AInteractionSystemCameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_AInteractionSystemCameraManager_NoRegister()
{
	return AInteractionSystemCameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AInteractionSystemCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Basic First Person camera manager.\n *  Limits min/max look pitch.\n */" },
#endif
		{ "IncludePath", "InteractionSystemCameraManager.h" },
		{ "ModuleRelativePath", "InteractionSystemCameraManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic First Person camera manager.\nLimits min/max look pitch." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInteractionSystemCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AInteractionSystemCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_InteractionSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractionSystemCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AInteractionSystemCameraManager_Statics::ClassParams = {
	&AInteractionSystemCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractionSystemCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AInteractionSystemCameraManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AInteractionSystemCameraManager()
{
	if (!Z_Registration_Info_UClass_AInteractionSystemCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AInteractionSystemCameraManager.OuterSingleton, Z_Construct_UClass_AInteractionSystemCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AInteractionSystemCameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AInteractionSystemCameraManager);
AInteractionSystemCameraManager::~AInteractionSystemCameraManager() {}
// ********** End Class AInteractionSystemCameraManager ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h__Script_InteractionSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AInteractionSystemCameraManager, AInteractionSystemCameraManager::StaticClass, TEXT("AInteractionSystemCameraManager"), &Z_Registration_Info_UClass_AInteractionSystemCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInteractionSystemCameraManager), 2706601051U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h__Script_InteractionSystem_765205395(TEXT("/Script/InteractionSystem"),
	Z_CompiledInDeferFile_FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h__Script_InteractionSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h__Script_InteractionSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
