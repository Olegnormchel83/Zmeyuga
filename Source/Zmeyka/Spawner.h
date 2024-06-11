// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Food2.h"
#include "SnakeBase.h"
#include "Spawner.generated.h"

class AApple;
class ABonusSpeedUP;
class ABonusSpeedDOWN;

UCLASS()
class ZMEYKA_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AApple> AppleClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABonusSpeedUP> BonusSpeedUPClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABonusSpeedDOWN> BonusSpeedDOWNClass;

	ASnakeBase* Snake;

	AApple* Apple;

	TArray<AApple*> ActiveApples;

	ABonusSpeedUP* BonusSpeedUP;

	TArray<ABonusSpeedUP*> ActiveSonusesSpeedUP;

	ABonusSpeedDOWN* BonusSpeedDOWN;

	TArray<ABonusSpeedDOWN*> ActiveSonusesSpeedDOWN;

	TArray<AActor*> OutActors;

	int *PositionsX;

	int *PositionsY;
	
	int PositionZ;

	float CustomTickInterval;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SpawnFood();

	virtual void SpawnBonuses();

	virtual bool CheckSnakeIsAlive();

	virtual void DestroyActiveBonuses();

	virtual void Clean(TArray<AActor*> TargetArray);
};
