// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "TimerManager.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	// GetWorldTimerManager().SetTimer();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector movement = FVector(
		velocityX * directionX * DeltaTime,
		velocityY * directionY * DeltaTime,
		0
	);

	AddActorLocalOffset(movement);

}
