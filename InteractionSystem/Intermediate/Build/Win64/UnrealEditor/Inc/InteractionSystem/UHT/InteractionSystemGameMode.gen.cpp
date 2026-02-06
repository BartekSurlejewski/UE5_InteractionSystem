// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InteractionSystemGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeInteractionSystemGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemGameMode();
INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_InteractionSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AInteractionSystemGameMode ***********************************************
void AInteractionSystemGameMode::StaticRegisterNativesAInteractionSystemGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AInteractionSystemGameMode;
UClass* AInteractionSystemGameMode::GetPrivateStaticClass()
{
	using TClass = AInteractionSystemGameMode;
	if (!Z_Registration_Info_UClass_AInteractionSystemGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("InteractionSystemGameMode"),
			Z_Registration_Info_UClass_AInteractionSystemGameMode.InnerSingleton,
			StaticRegisterNativesAInteractionSystemGameMode,
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
	return Z_Registration_Info_UClass_AInteractionSystemGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AInteractionSystemGameMode_NoRegister()
{
	return AInteractionSystemGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AInteractionSystemGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a first person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "InteractionSystemGameMode.h" },
		{ "ModuleRelativePath", "InteractionSystemGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a first person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInteractionSystemGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AInteractionSystemGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_InteractionSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractionSystemGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AInteractionSystemGameMode_Statics::ClassParams = {
	&AInteractionSystemGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractionSystemGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AInteractionSystemGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AInteractionSystemGameMode()
{
	if (!Z_Registration_Info_UClass_AInteractionSystemGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AInteractionSystemGameMode.OuterSingleton, Z_Construct_UClass_AInteractionSystemGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AInteractionSystemGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AInteractionSystemGameMode);
AInteractionSystemGameMode::~AInteractionSystemGameMode() {}
// ********** End Class AInteractionSystemGameMode *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h__Script_InteractionSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AInteractionSystemGameMode, AInteractionSystemGameMode::StaticClass, TEXT("AInteractionSystemGameMode"), &Z_Registration_Info_UClass_AInteractionSystemGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInteractionSystemGameMode), 2755530508U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h__Script_InteractionSystem_3452001666(TEXT("/Script/InteractionSystem"),
	Z_CompiledInDeferFile_FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h__Script_InteractionSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h__Script_InteractionSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
