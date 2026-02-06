// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InteractionSystemCharacter.h"

#ifdef INTERACTIONSYSTEM_InteractionSystemCharacter_generated_h
#error "InteractionSystemCharacter.generated.h already included, missing '#pragma once' in InteractionSystemCharacter.h"
#endif
#define INTERACTIONSYSTEM_InteractionSystemCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AInteractionSystemCharacter **********************************************
#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoMove); \
	DECLARE_FUNCTION(execDoAim);


INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemCharacter_NoRegister();

#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInteractionSystemCharacter(); \
	friend struct Z_Construct_UClass_AInteractionSystemCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AInteractionSystemCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/InteractionSystem"), Z_Construct_UClass_AInteractionSystemCharacter_NoRegister) \
	DECLARE_SERIALIZER(AInteractionSystemCharacter)


#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AInteractionSystemCharacter(AInteractionSystemCharacter&&) = delete; \
	AInteractionSystemCharacter(const AInteractionSystemCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractionSystemCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractionSystemCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AInteractionSystemCharacter) \
	NO_API virtual ~AInteractionSystemCharacter();


#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCharacter_h_21_PROLOG
#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AInteractionSystemCharacter;

// ********** End Class AInteractionSystemCharacter ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
