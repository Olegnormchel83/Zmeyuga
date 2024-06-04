// Fill out your copyright notice in the Description page of Project Settings.

#include "SnakeBase.h"
#include "SnakeElementBase.h"
#include "Interactable.h"

// Sets default values
ASnakeBase::ASnakeBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ElementSize = 60.f;
	CurrentMovementSpeed = 0.0f;
	NormalMovementSpeed = 0.15f;
	FasterMovementSpeed = 0.08f;
	SlowerMovementSpeed = 0.25f;
	CanChangeDirection = true;
	LastMoveDirection = EMovementDirection::LEFT;
}

// Called when the game starts or when spawned
void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentMovementSpeed = NormalMovementSpeed;
	SetActorTickInterval(CurrentMovementSpeed);
	AddSnakeElements(4);
}

// Called every frame
void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CanChangeDirection)
	{
		Move();
	}
	
}

void ASnakeBase::AddSnakeElements(int ElementsNum)
{
	for (int i = 0; i < ElementsNum; i++)
	{
		if (SnakeElements.IsValidIndex(i))
		{
			FVector NewBlockPosition(SnakeElements.Last()->GetActorLocation());
			SetNewBlockPosition(NewBlockPosition);
		}
		else
		{
			FVector NewBlockPosition(0, 0, 0);
			SetNewBlockPosition(NewBlockPosition);
		}
	}
}

void ASnakeBase::SetNewBlockPosition(FVector NewBlockPosition)
{
	FTransform NewTransform = FTransform(NewBlockPosition);
	ASnakeElementBase* NewSnakeElem = GetWorld()->SpawnActor<ASnakeElementBase>(SnakeElementClass, NewTransform);
	NewSnakeElem->SnakeOwner = this;
	int32 ElemIndex = SnakeElements.Add(NewSnakeElem);

	if (ElemIndex == 0)
	{
		NewSnakeElem->SetFirstElementType();
	}
}

void ASnakeBase::PickUpBonusSpeedUP()
{
	if (CurrentMovementSpeed == SlowerMovementSpeed)
	{
		CurrentMovementSpeed = NormalMovementSpeed;
		SetActorTickInterval(CurrentMovementSpeed);
	}
	else if (CurrentMovementSpeed == NormalMovementSpeed)
	{
		CurrentMovementSpeed = FasterMovementSpeed;
		SetActorTickInterval(CurrentMovementSpeed);
	}
}

void ASnakeBase::PickUpBonusSpeedDOWN()
{
	if (CurrentMovementSpeed == FasterMovementSpeed)
	{
		CurrentMovementSpeed = NormalMovementSpeed;
		SetActorTickInterval(CurrentMovementSpeed);
	}
	else if (CurrentMovementSpeed == NormalMovementSpeed)
	{
		CurrentMovementSpeed = SlowerMovementSpeed;
		SetActorTickInterval(CurrentMovementSpeed);
	}
	//Уменьшать скорость на 1 тир. Если текущая скорость Быстрая, делать ее Нормальной. Если текущая скорость Нормальная, делать ее Медленной.
}

void ASnakeBase::Move()
{
	FVector MovementVector(ForceInitToZero);

	switch (LastMoveDirection)
	{
	case EMovementDirection::UP:
		MovementVector.X += ElementSize;
		CanChangeDirection = false;
		break;
	case EMovementDirection::DOWN:
		MovementVector.X -= ElementSize;
		CanChangeDirection = false;
		break;
	case EMovementDirection::LEFT:
		MovementVector.Y += ElementSize;
		CanChangeDirection = false;
		break;
	case EMovementDirection::RIGHT:
		MovementVector.Y -= ElementSize;
		CanChangeDirection = false;
		break;
	}

	SnakeElements[0]->ToggleCollision();

	for (int i = SnakeElements.Num() - 1; i > 0; i--)
	{
		auto CurrentElement = SnakeElements[i];
		auto PrevElement = SnakeElements[i - 1];
		FVector PrevLocation = PrevElement->GetActorLocation();
		CurrentElement->SetActorLocation(PrevLocation);
	}

	SnakeElements[0]->AddActorWorldOffset(MovementVector);
	SnakeElements[0]->ToggleCollision();
	CanChangeDirection = true;
}

void ASnakeBase::SnakeELementOverlap(ASnakeElementBase* OverlappedBlock, AActor* Other)
{
	if (IsValid(OverlappedBlock))
	{
		int32 ElemIndex;
		SnakeElements.Find(OverlappedBlock, ElemIndex);
		bool bIsFirst = ElemIndex == 0;
		IInteractable* InteractableInterface = Cast<IInteractable>(Other);
		if (InteractableInterface)
		{
			InteractableInterface->Interact(this, bIsFirst);
		}
	}
}