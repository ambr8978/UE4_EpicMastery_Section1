// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPSGAME_FPSCharacter_generated_h
#error "FPSCharacter.generated.h already included, missing '#pragma once' in FPSCharacter.h"
#endif
#define FPSGAME_FPSCharacter_generated_h

#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_RPC_WRAPPERS \
	virtual bool ServerFire_Validate(); \
	virtual void ServerFire_Implementation(); \
 \
	DECLARE_FUNCTION(execServerFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerFire_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerFire_Validate")); \
			return; \
		} \
		this->ServerFire_Implementation(); \
		P_NATIVE_END; \
	}


#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerFire_Validate(); \
	virtual void ServerFire_Implementation(); \
 \
	DECLARE_FUNCTION(execServerFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerFire_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerFire_Validate")); \
			return; \
		} \
		this->ServerFire_Implementation(); \
		P_NATIVE_END; \
	}


#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_EVENT_PARMS
#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_CALLBACK_WRAPPERS
#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSCharacter(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSCharacter(); \
public: \
	DECLARE_CLASS(AFPSCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAFPSCharacter(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSCharacter(); \
public: \
	DECLARE_CLASS(AFPSCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCharacter(AFPSCharacter&&); \
	NO_API AFPSCharacter(const AFPSCharacter&); \
public:


#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCharacter(AFPSCharacter&&); \
	NO_API AFPSCharacter(const AFPSCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSCharacter)


#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1PComponent() { return STRUCT_OFFSET(AFPSCharacter, Mesh1PComponent); } \
	FORCEINLINE static uint32 __PPO__GunMeshComponent() { return STRUCT_OFFSET(AFPSCharacter, GunMeshComponent); } \
	FORCEINLINE static uint32 __PPO__CameraComponent() { return STRUCT_OFFSET(AFPSCharacter, CameraComponent); } \
	FORCEINLINE static uint32 __PPO__NoiseEmitterComponent() { return STRUCT_OFFSET(AFPSCharacter, NoiseEmitterComponent); }


#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_18_PROLOG \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_EVENT_PARMS


#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_RPC_WRAPPERS \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_CALLBACK_WRAPPERS \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_INCLASS \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_CALLBACK_WRAPPERS \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_INCLASS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StealthGame_Source_FPSGame_Public_FPSCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
