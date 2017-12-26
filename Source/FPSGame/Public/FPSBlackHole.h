// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSBlackHole.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UPrimitiveComponent;

UCLASS()
class FPSGAME_API AFPSBlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSBlackHole();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	//Inner sphere destroys the overlapping components
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* InnerSphereComponent;

	//Outer sphere pulls components (that are physically simulating) towards the center of the actor
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* OuterSphereComponent;

	//Marked with ufunction to bind to overlap event
	UFUNCTION()
		void OverlapInnerSphere(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	const TCHAR* MeshComponentName = (TCHAR*) "MeshComp";

	void CreateStaticMeshComponent();
	void SetRootComponentToStaticMeshComponent();
	void CreateInnerSphereComponent();
	void CreateOuterSphereComponent();

	void PullOverlappingComponentsIntoBlackHole();
	void ApplyInwardRadialForceOnComponent(UPrimitiveComponent* PrimComp, const float OuterSphereRadius);
};
