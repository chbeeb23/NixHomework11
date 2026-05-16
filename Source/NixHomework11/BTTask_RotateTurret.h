// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RotateTurret.generated.h"

/**
 * 
 */
UCLASS()
class NIXHOMEWORK11_API UBTTask_RotateTurret : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_RotateTurret();

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector TargetActorKey;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	UPROPERTY()
	TObjectPtr<AActor> CurrentTarget;

	UPROPERTY(EditAnywhere, Category = "Turret")
	float RotationSpeed = 5.f;
};
