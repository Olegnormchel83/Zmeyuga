// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Apple.h"
#include "BonusSpeedUP.h"
#include "BonusSpeedDOWN.h"
#include "SnakeBase.h"

// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PositionsX = new int[] {-300, -240, -180, -120,
		-60, 0, 60, 120, 180,
		240, 300, 360, 420, 480,
		540, 600, 660, 720, 780,
		840, 900, 960, 1020, 1080,
		1140, 1200, 1260, 1320, 1380,
		1440, 1500, 1560};
	PositionsY = new int[] {420, 360, 300, 240, 180,
		120, 60, 0, -60, -120,
		-180, -240, -300, -360,
		-420, -480, -540, -600,
		-660, -720, -780, -840,
		-900, -960, -1020, -1080,
		-1140, -1200, -1260, -1320,
		-1380, -1440};
	PositionZ = 30;
	CustomTickInterval = 5.f;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickInterval(CustomTickInterval);
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//TODO: Спавнер должен знать, жива змейка или нет. Если жива - спавнить еду, если нет - не спавнить.
	SpawnFood();
	SpawnBonuses();
}

void ASpawner::SpawnFood()
{
	int PosX = rand() % 32;
	int PosY = rand() % 32;
	FVector ApplePosition(PositionsX[PosX], PositionsY[PosY], PositionZ);
	FTransform NewTransform = FTransform(ApplePosition);
	AApple* NewApple = GetWorld()->SpawnActor<AApple>(AppleClass, NewTransform);
}


void ASpawner::SpawnBonuses()
{
	int PosX = rand() % 32;
	int PosY = rand() % 32;
	int RandomBonus = rand() % 2;

	FVector BonusPosition(PositionsX[PosX], PositionsY[PosY], PositionZ);
	FTransform NewTransform = FTransform(BonusPosition);

	if (RandomBonus == 1)
	{
		ABonusSpeedUP* NewBonusSpeedUP = GetWorld()->SpawnActor<ABonusSpeedUP>(BonusSpeedUPClass, NewTransform);
	}
	else
	{
		ABonusSpeedDOWN* NewBonusSpeedDOWN = GetWorld()->SpawnActor<ABonusSpeedDOWN>(BonusSpeedDOWNClass, NewTransform);
	}
}
