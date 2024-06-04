// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusSpeedDOWN.h"
#include "SnakeBase.h"

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
			Snake->PickUpBonusSpeedDOWN();// (Тестируется)
			//TODO: написать в змейке логику подбора бонуса ументшения скорости + создать блюпринтового наследника этого класса в ContentDrawer
			this->Destroy();
		}
	}
}
