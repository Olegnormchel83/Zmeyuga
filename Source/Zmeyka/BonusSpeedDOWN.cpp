// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusSpeedDOWN.h"
#include "SnakeBase.h"
#include "Obstacle.h"

ABonusSpeedDOWN::ABonusSpeedDOWN()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABonusSpeedDOWN::BeginPlay()
{
	Super::BeginPlay();
}

void ABonusSpeedDOWN::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABonusSpeedDOWN::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->PickUpBonusSpeedDOWN();
			this->Destroy();
		}
	}
	else
	{
		auto Obstacle = Cast<AObstacle>(Interactor);
		if (IsValid(Obstacle))
		{
			this->Destroy();
		}
	}
}
