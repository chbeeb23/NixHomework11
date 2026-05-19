// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RotateTurret.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "NixAITurret.h"

UBTTask_RotateTurret::UBTTask_RotateTurret()
{
	bNotifyTick = true;
	NodeName = TEXT("Rotate Turret");
}


EBTNodeResult::Type UBTTask_RotateTurret::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return EBTNodeResult::InProgress;
}

void UBTTask_RotateTurret::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	ANixAITurret* Turret = Cast<ANixAITurret>(AIController->GetPawn());
	if (!Turret)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	AActor* Target = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetActorKey.SelectedKeyName));
	if (!Target)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	FRotator LookAt = UKismetMathLibrary::FindLookAtRotation(Turret->GetActorLocation(), Target->GetActorLocation());
	FRotator NewRotation = FMath::RInterpTo(Turret->GetActorRotation(), LookAt, DeltaSeconds, RotationSpeed);
	Turret->SetActorRotation(NewRotation);

	if (NewRotation.Equals(LookAt, 0.01f))
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return;
	}
}