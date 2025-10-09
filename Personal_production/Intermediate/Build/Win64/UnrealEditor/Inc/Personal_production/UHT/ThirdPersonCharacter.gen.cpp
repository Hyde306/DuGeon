// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Personal_production/ThirdPersonCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeThirdPersonCharacter() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
PERSONAL_PRODUCTION_API UClass* Z_Construct_UClass_AThirdPersonCharacter();
PERSONAL_PRODUCTION_API UClass* Z_Construct_UClass_AThirdPersonCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_Personal_production();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AThirdPersonCharacter ****************************************************
void AThirdPersonCharacter::StaticRegisterNativesAThirdPersonCharacter()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AThirdPersonCharacter;
UClass* AThirdPersonCharacter::GetPrivateStaticClass()
{
	using TClass = AThirdPersonCharacter;
	if (!Z_Registration_Info_UClass_AThirdPersonCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ThirdPersonCharacter"),
			Z_Registration_Info_UClass_AThirdPersonCharacter.InnerSingleton,
			StaticRegisterNativesAThirdPersonCharacter,
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
	return Z_Registration_Info_UClass_AThirdPersonCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_AThirdPersonCharacter_NoRegister()
{
	return AThirdPersonCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AThirdPersonCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ThirdPersonCharacter.h" },
		{ "ModuleRelativePath", "ThirdPersonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "Category", "ThirdPersonCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ThirdPersonCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "ThirdPersonCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ThirdPersonCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AThirdPersonCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AThirdPersonCharacter_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AThirdPersonCharacter, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AThirdPersonCharacter_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AThirdPersonCharacter, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AThirdPersonCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AThirdPersonCharacter_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AThirdPersonCharacter_Statics::NewProp_Camera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AThirdPersonCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AThirdPersonCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Personal_production,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AThirdPersonCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AThirdPersonCharacter_Statics::ClassParams = {
	&AThirdPersonCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AThirdPersonCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AThirdPersonCharacter_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AThirdPersonCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AThirdPersonCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AThirdPersonCharacter()
{
	if (!Z_Registration_Info_UClass_AThirdPersonCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AThirdPersonCharacter.OuterSingleton, Z_Construct_UClass_AThirdPersonCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AThirdPersonCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AThirdPersonCharacter);
AThirdPersonCharacter::~AThirdPersonCharacter() {}
// ********** End Class AThirdPersonCharacter ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_GA2A_Desktop_UE_Game_Personal_production_Source_Personal_production_ThirdPersonCharacter_h__Script_Personal_production_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AThirdPersonCharacter, AThirdPersonCharacter::StaticClass, TEXT("AThirdPersonCharacter"), &Z_Registration_Info_UClass_AThirdPersonCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AThirdPersonCharacter), 2040219644U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_GA2A_Desktop_UE_Game_Personal_production_Source_Personal_production_ThirdPersonCharacter_h__Script_Personal_production_3913764804(TEXT("/Script/Personal_production"),
	Z_CompiledInDeferFile_FID_Users_GA2A_Desktop_UE_Game_Personal_production_Source_Personal_production_ThirdPersonCharacter_h__Script_Personal_production_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_GA2A_Desktop_UE_Game_Personal_production_Source_Personal_production_ThirdPersonCharacter_h__Script_Personal_production_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
