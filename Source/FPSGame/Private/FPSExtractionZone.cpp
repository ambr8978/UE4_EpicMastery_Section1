// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"

const FVector COMPONENT_SIZE_VECTOR(200.0f);

AFPSExtractionZone::AFPSExtractionZone()
{
	SetupOverlapComponent();
	SetupDecalComponent();

	RootComponent = OverlapComp;

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtractionZone::HandleOverlap);
}

void AFPSExtractionZone::SetupOverlapComponent()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(COMPONENT_SIZE_VECTOR);
}

void AFPSExtractionZone::SetupDecalComponent()
{
	DecalComp= CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = COMPONENT_SIZE_VECTOR;
	DecalComp->SetupAttachment(RootComponent);
}

void AFPSExtractionZone::HandleOverlap(
	UPrimitiveComponent * OverlappedComponent, 
	AActor * OtherActor, 
	UPrimitiveComponent * OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult & SweepResult)
{

}
