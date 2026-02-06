// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InteractionSystemPlayerController.h"

#ifdef INTERACTIONSYSTEM_InteractionSystemPlayerController_generated_h
#error "InteractionSystemPlayerController.generated.h already included, missing '#pragma once' in InteractionSystemPlayerController.h"
#endif
#define INTERACTIONSYSTEM_InteractionSystemPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AInteractionSystemPlayerController ***************************************
INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemPlayerController_NoRegister();

#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemPlayerController_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInteractionSystemPlayerController(); \
	friend struct Z_Construct_UClass_AInteractionSystemPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INTERACTIONSYSTEM_API UClass* Z_Construct_UClass_AInteractionSystemPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AInteractionSystemPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/InteractionSystem"), Z_Construct_UClass_AInteractionSystemPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AInteractionSystemPlayerController)


#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemPlayerController_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AInteractionSystemPlayerController(AInteractionSystemPlayerController&&) = delete; \
	AInteractionSystemPlayerController(const AInteractionSystemPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractionSystemPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractionSystemPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AInteractionSystemPlayerController) \
	NO_API virtual ~AInteractionSystemPlayerController();


#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemPlayerController_h_17_PROLOG
#define FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemPlayerController_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemPlayerController_h_20_INCLASS_NO_PURE_DECLS \
	FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemPlayerController_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AInteractionSystemPlayerController;

// ********** End Class AInteractionSystemPlayerController *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projekty_UE5_InteractionSystem_InteractionSystem_Source_InteractionSystem_InteractionSystemPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
