// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSLaunchPad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

const FVector OVERLAP_COMP_SIZE(75, 75, 50);
const int LAUNCH_STRENGTH_DEFAULT = 1500;
const int LAUNCH_PITCH_ANGLE_DEFAULT = 35.0f;

AFPSLaunchPad::AFPSLaunchPad()
{
	SetupOverlapComponent();
	SetOverlapComponentAsRootComponent();
	SetupMeshComponent();
	SetLaunchVariableDefaults();
}

void AFPSLaunchPad::SetupOverlapComponent()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetBoxExtent(OVERLAP_COMP_SIZE);
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSLaunchPad::OverlapLaunchPad);
}

void AFPSLaunchPad::SetOverlapComponentAsRootComponent()
{
	RootComponent = OverlapComp;
}

void AFPSLaunchPad::SetupMeshComponent()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
}

void AFPSLaunchPad::SetLaunchVariableDefaults()
{
	LaunchStrength = LAUNCH_STRENGTH_DEFAULT;
	LaunchPitchAngle = LAUNCH_PITCH_ANGLE_DEFAULT;
}

void AFPSLaunchPad::OverlapLaunchPad(
	UPrimitiveComponent * OverlappedComponent, 
	AActor * OtherActor, 
	UPrimitiveComponent * OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult & SweepResult)
{
	FVector LaunchVelocity = GetDesiredLaunchVelocity();
	ACharacter* OtherCharacter = Cast<ACharacter>(OtherActor);
	if (OtherCharacter)
	{
		LaunchCharacter(OtherCharacter, LaunchVelocity);
	}
	else if (OtherComp && OtherComp->IsSimulatingPhysics())
	{
		LaunchComponent(OtherComp, LaunchVelocity);
	}
}

FVector AFPSLaunchPad::GetDesiredLaunchVelocity()
{
	FRotator LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch += LaunchPitchAngle;
	FVector LaunchVelocity = LaunchDirection.Vector() * LaunchStrength;
	
	return LaunchVelocity;
}

void AFPSLaunchPad::LaunchCharacter(ACharacter* CharacterToLaunch, FVector LaunchVelocity)
{
	CharacterToLaunch->LaunchCharacter(LaunchVelocity, true, true);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ActiveLaunchPadEffect, GetActorLocation());
}

void AFPSLaunchPad::LaunchComponent(UPrimitiveComponent* CompToLaunch, FVector LaunchVelocity)
{
	CompToLaunch->AddImpulse(LaunchVelocity, NAME_None, true);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ActiveLaunchPadEffect, GetActorLocation());
}