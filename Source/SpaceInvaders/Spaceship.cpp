// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"
#include "Engine/World.h"

// Sets default values
ASpaceship::ASpaceship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	InputComponent->BindAxis("Horizontal", this, &ASpaceship::MoveHorizontal);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ASpaceship::Fire);
}

void ASpaceship::MoveHorizontal(float axisValue)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	float fMove = 1 * deltaTime * axisValue * Movement;
	// float fMove = 1 * deltaTime * Movement;
	FVector vMovement = FVector(0, fMove, 0);
	
	AddActorLocalOffset(vMovement);

	UE_LOG(LogTemp, Warning, TEXT("Moviendo: %f - %f - %f"), axisValue, fMove, deltaTime);
}

void ASpaceship::Fire()
{
	//
	UE_LOG(LogTemp, Warning, TEXT("Disparando"));

	FVector pos = GetActorLocation();
	FRotator rot = FRotator(0, 0, 0);

	GetWorld()->SpawnActor<AActor>(projectile, pos, rot);
}
