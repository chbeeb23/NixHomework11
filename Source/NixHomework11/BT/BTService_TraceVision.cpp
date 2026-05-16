// Fill out your copyright notice in the Description page of Project Settings.


#include "BT/BTService_TraceVision.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "NixAITurret.h"
#include "Kismet/GameplayStatics.h"

UBTService_TraceVision::UBTService_TraceVision()
{
	NodeName = TEXT("Trace Vision");
	Interval = 0.2f;
	RandomDeviation = 0.0f;
}

void UBTService_TraceVision::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		return;
	}

	ANixAITurret* Turret = Cast<ANixAITurret>(AIController->GetPawn());
	if (!Turret)
	{
		return;
	}

	AActor* Player = UGameplayStatics::GetPlayerPawn(Turret, 0);
	if (!Player)
	{
		return;
	}

	FVector Start = Turret->GetActorLocation();
	FVector End = Player->GetActorLocation();

	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Turret);

	bool bHit = Turret->GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Pawn, Params);
	bool bFoundPlayer = false;

	AActor* DetectedActor = nullptr;
	if (bHit && Hit.GetActor() == Player)
	{
		DetectedActor = Player;
		bFoundPlayer = true;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(TargetActorKey.SelectedKeyName, DetectedActor);
	DrawDebugLine(Turret->GetWorld(), Start, End, bFoundPlayer ? FColor::Green : FColor::Red, false, 0.0f, 0, 1.f);
}