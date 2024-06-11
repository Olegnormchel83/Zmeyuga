// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "SnakeBase.h"
#include "Apple.h"
#include "BonusSpeedUP.h"
#include "BonusSpeedDOWN.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObstacle::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->IsDead = true;
			Snake->Destroy();
		}
	}
	else
	{
		auto Apple = Cast<AApple>(Interactor);
		if (IsValid(Apple))
		{
			Apple->Destroy();
		}
		auto BonusSpeedUP = Cast<ABonusSpeedUP>(Interactor);
		if (IsValid(BonusSpeedUP))
		{
			BonusSpeedUP->Destroy();
		}
		auto BonusSpeedDown = Cast<ABonusSpeedDOWN>(Interactor);
		if (IsValid(BonusSpeedDown))
		{
			BonusSpeedDown->Destroy();
		}
	}
}

