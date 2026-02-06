// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InteractionSystemGameMode.h"

#ifdef INTERACTIONSYSTEM_InteractionSystemGameMode_generated_h
#error "InteractionSystemGameMode.generated.h already included, missing '#pragma once' in InteractionSystemGameMode.h"
#endif
#define INTERACTIONSYSTEM_InteractionSystemGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AInteractionSystemGameMode ***********************************************
INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemGameMode_NoRegister();

#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInteractionSystemGameMode(); \
	friend struct Z_Construct_UClass_AInteractionSystemGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AInteractionSystemGameMode, AGameModeBase, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/InteractionSystem"), Z_Construct_UClass_AInteractionSystemGameMode_NoRegister) \
	DECLARE_SERIALIZER(AInteractionSystemGameMode)


#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AInteractionSystemGameMode(AInteractionSystemGameMode&&) = delete; \
	AInteractionSystemGameMode(const AInteractionSystemGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractionSystemGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractionSystemGameMode); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AInteractionSystemGameMode) \
	NO_API virtual ~AInteractionSystemGameMode();


#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h_12_PROLOG
#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AInteractionSystemGameMode;

// ********** End Class AInteractionSystemGameMode *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
