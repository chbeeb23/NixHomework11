// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_TraceVision.generated.h"

/**
 * 
 */
UCLASS()
class NIXHOMEWORK11_API UBTService_TraceVision : public UBTService
{
	GENERATED_BODY()
	
public:
	UBTService_TraceVision();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector TargetActorKey;

	UPROPERTY(EditAnywhere, Category = "Vision")
	float TraceDistance = 2500.f;
};
