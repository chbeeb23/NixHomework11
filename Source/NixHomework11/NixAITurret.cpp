// Fill out your copyright notice in the Description page of Project Settings.


#include "NixAITurret.h"
#include "NixAIController.h"

// Sets default values
ANixAITurret::ANixAITurret()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = true;

	// Create the root scene component
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComponent);

	// Create the static mesh component and attach it to root
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(RootSceneComponent);

	ProjectilePoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectilePoint"));
	ProjectilePoint->SetupAttachment(TurretMesh);

	AIControllerClass = ANixAIController::StaticClass();

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ANixAITurret::Attack()
{
	if (!bCanAttack)
		return;

	bCanAttack = false;

	if (!ProjectileClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("ProjectileClass is null"));
		return;
	}

	FVector SpawnLocation = ProjectilePoint->GetComponentLocation();
	FRotator SpawnRotation = ProjectilePoint->GetComponentRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
	GetWorldTimerManager().SetTimer(FireCooldownHandle, this, &ANixAITurret::ResetAttack, 0.5f, false);
}

void ANixAITurret::ResetAttack()
{
	bCanAttack = true;
}