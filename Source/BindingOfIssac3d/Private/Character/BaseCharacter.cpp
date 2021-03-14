

#include "Character/BaseCharacter.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h" 
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/Engine.h" 
//universal character includes:
#include "Attribute/AttributeComponent.h"
#include "Melee/ActionComponent.h"
#include "Items/InventoryComponent.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	//3d space:
	GetCapsuleComponent()->InitCapsuleSize(35.f, 96.0f);

	PrimaryActorTick.bCanEverTick = false;

	GetMesh()->SetupAttachment(GetCapsuleComponent());
	GetMesh()->SetGenerateOverlapEvents(false);
	GetMesh()->SetSimulatePhysics(false);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//gameplay:
	SetCanBeDamaged(true);
	AttributeComponent = CreateDefaultSubobject<UAttributeComponent>(TEXT("AttributeSet"));
	ActionComponent =CreateDefaultSubobject<UActionComponent>(TEXT("ActionComponent"));
	AttributeComponent->OnDeath.BindUFunction(this, FName("DeathHandle"));
	InventoryComponent= CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	

	//Debug only:
	ShootDebugSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ShootDebugSceneComponent"));
	ShootDebugSceneComponent->SetupAttachment(GetRootComponent());
	ShootDebugSceneComponent->ResetRelativeTransform();
	ShootDebugSceneComponent->SetRelativeLocation(FVector(80, 0, 60));
}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	AttributeComponent->AddHealth(-DamageAmount);

	UE_LOG(LogTemp, Warning, TEXT("take damage "));
	return -DamageAmount;
}

void ABaseCharacter::DeathHandle() {


	UE_LOG(LogTemp, Warning, TEXT("Death"));
	

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//
//UAttributeComponent* ABaseCharacter::GetAttributeComponent_Implementation()
//{
//	return AttributeComponent;
//}

void ABaseCharacter::DebugCheckAssignVariables()
{
	
}




