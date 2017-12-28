// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSBlackHole.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/PrimitiveComponent.h"

#include <string>

const int INNER_SPHERE_RADIUS = 200;
const int OUTER_SPHERE_RADIUS = 3000;

//Negative value to make it pull towards the origin instead of pushing away
const int INWARD_PULLING_FORCE = -2000;

// Sets default values
AFPSBlackHole::AFPSBlackHole()
{
	PrimaryActorTick.bCanEverTick = true;

	CreateStaticMeshComponent();
	SetRootComponentToStaticMeshComponent();
	CreateInnerSphereComponent();
	CreateOuterSphereComponent();
}

void AFPSBlackHole::CreateStaticMeshComponent()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AFPSBlackHole::SetRootComponentToStaticMeshComponent()
{
	RootComponent = MeshComp;
}

void AFPSBlackHole::CreateInnerSphereComponent()
{
	InnerSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("InnerSphereComp"));
	InnerSphereComponent->SetSphereRadius(INNER_SPHERE_RADIUS);
	InnerSphereComponent->SetupAttachment(MeshComp);
	InnerSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSBlackHole::OverlapInnerSphere);
}

void AFPSBlackHole::CreateOuterSphereComponent()
{
	OuterSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("OuterSphereComp"));
	OuterSphereComponent->SetSphereRadius(OUTER_SPHERE_RADIUS);
	OuterSphereComponent->SetupAttachment(MeshComp);
}

void AFPSBlackHole::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFPSBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PullOverlappingComponentsIntoBlackHole();
}

void AFPSBlackHole::PullOverlappingComponentsIntoBlackHole()
{
	TArray<UPrimitiveComponent*> ComponentsOverlappingWithOuterSphere;
	OuterSphereComponent->GetOverlappingComponents(ComponentsOverlappingWithOuterSphere);

	//Grabbing scaled radius here to save computational time in for loop.
	const float OuterSphereRadius = OuterSphereComponent->GetScaledSphereRadius();

	for (int32 i = 0; i < ComponentsOverlappingWithOuterSphere.Num(); i++)
	{
		UPrimitiveComponent* PrimComp = ComponentsOverlappingWithOuterSphere[i];
		if (PrimComp && PrimComp->IsSimulatingPhysics())
		{
			ApplyInwardRadialForceOnComponent(PrimComp, OuterSphereRadius);
		}
	}
}

void AFPSBlackHole::ApplyInwardRadialForceOnComponent(UPrimitiveComponent* PrimComp, const float OuterSphereRadius)
{
	PrimComp->AddRadialForce(
		GetActorLocation(),
		OuterSphereRadius,
		INWARD_PULLING_FORCE,
		ERadialImpulseFalloff::RIF_Constant,
		true);
}

void AFPSBlackHole::OverlapInnerSphere(
	UPrimitiveComponent * OverlappedComponent, 
	AActor * OtherActor, 
	UPrimitiveComponent * OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		OtherActor->Destroy();
	}
}
