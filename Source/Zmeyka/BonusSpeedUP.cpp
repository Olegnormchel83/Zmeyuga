// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusSpeedUP.h"
#include "SnakeBase.h"
#include "Obstacle.h"

ABonusSpeedUP::ABonusSpeedUP()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABonusSpeedUP::BeginPlay()
{
	Super::BeginPlay();
}

void ABonusSpeedUP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABonusSpeedUP::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->PickUpBonusSpeedUP();
			this->Destroy();
		}
	}
	else if (!bIsHead)
	{
		auto Obstacle = Cast<AObstacle>(Interactor);
		if (IsValid(Obstacle))
		{
			this->Destroy();
		}
	}
}
