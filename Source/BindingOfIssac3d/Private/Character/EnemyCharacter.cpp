


#include "Character/EnemyCharacter.h"
#include "Components/StaticMeshComponent.h" 

//universal character includes:
#include "Attribute/AttributeComponent.h"
#include "Melee/ActionComponent.h"
#include "Items/InventoryComponent.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	

}

void AEnemyCharacter::DeathHandle() {
	Super::DeathHandle();
	UE_LOG(LogTemp, Warning, TEXT("Enemy Death"));


}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

