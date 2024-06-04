// Fill out your copyright notice in the Description page of Project Settings.


#include "Apple.h"
#include "SnakeBase.h"

AApple::AApple()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AApple::BeginPlay()
{
	Super::BeginPlay();
}

void AApple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AApple::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->AddSnakeElements();
			this->Destroy();
		}
	}
}
