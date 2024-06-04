// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food2.h"
#include "Interactable.h"
#include "BonusSpeedUP.generated.h"

/**
 * 
 */
UCLASS()
class ZMEYKA_API ABonusSpeedUP : public AFood2, public IInteractable
{
	GENERATED_BODY()
	
public:
	ABonusSpeedUP();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;
};
