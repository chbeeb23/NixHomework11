// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NixAITurret.generated.h"

class UBehaviorTree;

UCLASS()
class NIXHOMEWORK11_API ANixAITurret : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANixAITurret();

protected:
	// Root component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* RootSceneComponent;

	// Static mesh component for the turret
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TurretMesh;
};
