// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/FPSCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSCharacter() {}
// Cross Module References
	FPSGAME_API UClass* Z_Construct_UClass_AFPSCharacter_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_FPSGame();
	FPSGAME_API UFunction* Z_Construct_UFunction_AFPSCharacter_ServerFire();
	ENGINE_API UClass* Z_Construct_UClass_UPawnNoiseEmitterComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimSequence_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSProjectile_NoRegister();
// End Cross Module References
	static FName NAME_AFPSCharacter_ServerFire = FName(TEXT("ServerFire"));
	void AFPSCharacter::ServerFire()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFPSCharacter_ServerFire),NULL);
	}
	void AFPSCharacter::StaticRegisterNativesAFPSCharacter()
	{
		UClass* Class = AFPSCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ServerFire", (Native)&AFPSCharacter::execServerFire },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AFPSCharacter_ServerFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
				{ "ToolTip", "Server:\nReliable: This code is guaranteed to executre on the server eventually (could be delayed by networking issues, packet loss, etc.)\nWithValidation:" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, "ServerFire", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x80280CC0, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFPSCharacter_NoRegister()
	{
		return AFPSCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_AFPSCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_FPSGame,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AFPSCharacter_ServerFire, "ServerFire" }, // 1046175098
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "FPSCharacter.h" },
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NoiseEmitterComponent_MetaData[] = {
				{ "Category", "AI" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NoiseEmitterComponent = { UE4CodeGen_Private::EPropertyClass::Object, "NoiseEmitterComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a001d, 1, nullptr, STRUCT_OFFSET(AFPSCharacter, NoiseEmitterComponent), Z_Construct_UClass_UPawnNoiseEmitterComponent_NoRegister, METADATA_PARAMS(NewProp_NoiseEmitterComponent_MetaData, ARRAY_COUNT(NewProp_NoiseEmitterComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraComponent_MetaData[] = {
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
				{ "ToolTip", "First person camera" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraComponent = { UE4CodeGen_Private::EPropertyClass::Object, "CameraComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a001d, 1, nullptr, STRUCT_OFFSET(AFPSCharacter, CameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_CameraComponent_MetaData, ARRAY_COUNT(NewProp_CameraComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GunMeshComponent_MetaData[] = {
				{ "Category", "Mesh" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
				{ "ToolTip", "Gun mesh: 1st person view (seen only by self)" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GunMeshComponent = { UE4CodeGen_Private::EPropertyClass::Object, "GunMeshComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a001d, 1, nullptr, STRUCT_OFFSET(AFPSCharacter, GunMeshComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(NewProp_GunMeshComponent_MetaData, ARRAY_COUNT(NewProp_GunMeshComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh1PComponent_MetaData[] = {
				{ "Category", "Mesh" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
				{ "ToolTip", "Pawn mesh: 1st person view" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh1PComponent = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh1PComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a001d, 1, nullptr, STRUCT_OFFSET(AFPSCharacter, Mesh1PComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(NewProp_Mesh1PComponent_MetaData, ARRAY_COUNT(NewProp_Mesh1PComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsCarryingObjective_MetaData[] = {
				{ "Category", "Gameplay" },
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
			};
#endif
			auto NewProp_bIsCarryingObjective_SetBit = [](void* Obj){ ((AFPSCharacter*)Obj)->bIsCarryingObjective = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsCarryingObjective = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsCarryingObjective", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000034, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFPSCharacter), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bIsCarryingObjective_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bIsCarryingObjective_MetaData, ARRAY_COUNT(NewProp_bIsCarryingObjective_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireAnimation_MetaData[] = {
				{ "Category", "Gameplay" },
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
				{ "ToolTip", "AnimMontage to play each time we fire" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FireAnimation = { UE4CodeGen_Private::EPropertyClass::Object, "FireAnimation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010001, 1, nullptr, STRUCT_OFFSET(AFPSCharacter, FireAnimation), Z_Construct_UClass_UAnimSequence_NoRegister, METADATA_PARAMS(NewProp_FireAnimation_MetaData, ARRAY_COUNT(NewProp_FireAnimation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[] = {
				{ "Category", "Gameplay" },
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
				{ "ToolTip", "Sound to play each time we fire" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FireSound = { UE4CodeGen_Private::EPropertyClass::Object, "FireSound", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010001, 1, nullptr, STRUCT_OFFSET(AFPSCharacter, FireSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(NewProp_FireSound_MetaData, ARRAY_COUNT(NewProp_FireSound_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[] = {
				{ "Category", "Projectile" },
				{ "ModuleRelativePath", "Public/FPSCharacter.h" },
				{ "ToolTip", "Projectile class to spawn" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProjectileClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000010001, 1, nullptr, STRUCT_OFFSET(AFPSCharacter, ProjectileClass), Z_Construct_UClass_AFPSProjectile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_ProjectileClass_MetaData, ARRAY_COUNT(NewProp_ProjectileClass_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NoiseEmitterComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CameraComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GunMeshComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Mesh1PComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bIsCarryingObjective,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FireAnimation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FireSound,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileClass,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AFPSCharacter>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AFPSCharacter::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00800080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFPSCharacter, 998045436);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFPSCharacter(Z_Construct_UClass_AFPSCharacter, &AFPSCharacter::StaticClass, TEXT("/Script/FPSGame"), TEXT("AFPSCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
