// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InteractionSystemCameraManager.h"

#ifdef INTERACTIONSYSTEM_InteractionSystemCameraManager_generated_h
#error "InteractionSystemCameraManager.generated.h already included, missing '#pragma once' in InteractionSystemCameraManager.h"
#endif
#define INTERACTIONSYSTEM_InteractionSystemCameraManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AInteractionSystemCameraManager ******************************************
INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemCameraManager_NoRegister();

#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInteractionSystemCameraManager(); \
	friend struct Z_Construct_UClass_AInteractionSystemCameraManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemCameraManager_NoRegister(); \
public: \
	DECLARE_CLASS2(AInteractionSystemCameraManager, APlayerCameraManager, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/InteractionSystem"), Z_Construct_UClass_AInteractionSystemCameraManager_NoRegister) \
	DECLARE_SERIALIZER(AInteractionSystemCameraManager)


#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AInteractionSystemCameraManager(AInteractionSystemCameraManager&&) = delete; \
	AInteractionSystemCameraManager(const AInteractionSystemCameraManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractionSystemCameraManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractionSystemCameraManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AInteractionSystemCameraManager) \
	NO_API virtual ~AInteractionSystemCameraManager();


#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h_13_PROLOG
#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h_16_INCLASS_NO_PURE_DECLS \
	FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AInteractionSystemCameraManager;

// ********** End Class AInteractionSystemCameraManager ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCameraManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
