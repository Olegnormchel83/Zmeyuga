// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeBase.generated.h"

class ASnakeElementBase;

UENUM()
enum class EMovementDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

UCLASS()
class ZMEYKA_API ASnakeBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASnakeBase();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASnakeElementBase> SnakeElementClass;

	UPROPERTY(EditDefaultsOnly)
	float ElementSize;

	UPROPERTY(EditDefaultsOnly)
	float NormalMovementSpeed;

	UPROPERTY()
	bool CanChangeDirection;

	UPROPERTY()
	TArray<ASnakeElementBase*> SnakeElements;

	UPROPERTY()
	EMovementDirection LastMoveDirection;

	float FasterMovementSpeed;

	float SlowerMovementSpeed;

	float CurrentMovementSpeed;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void AddSnakeElements(int ElementsNum = 1);

	UFUNCTION(BlueprintCallable)
	void Move();

	UFUNCTION()
	void SnakeELementOverlap(ASnakeElementBase* OverlappedBlock, AActor* Other);

	void SetNewBlockPosition(FVector NewBlockPosition);

	void PickUpBonusSpeedUP();

	void PickUpBonusSpeedDOWN();
};
