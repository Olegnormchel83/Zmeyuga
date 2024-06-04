// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Food2.h"
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

	UPROPERTY()
	AApple* Apple;

	UPROPERTY()
	ABonusSpeedUP* BonusSpeedUP;

	UPROPERTY()
	ABonusSpeedUP* BonusSpeedDOWN;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SpawnFood(AApple* apple);

	virtual int GetActiveFood();

	virtual int GetActiveBonuses();
};
