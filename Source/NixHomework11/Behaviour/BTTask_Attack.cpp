// Fill out your copyright notice in the Description page of Project Settings.


#include "Behaviour/BTTask_Attack.h"
#include "AIController.h"
#include "NixAITurret.h"


EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (auto Controller = Cast<AAIController>(OwnerComp.GetOwner()))
    {
        if (auto Character = Cast<ANixAITurret>(Controller->GetPawn()))
        {
            Character->Attack();
            return EBTNodeResult::Succeeded;
        }
    }

    return EBTNodeResult::Failed;
}
