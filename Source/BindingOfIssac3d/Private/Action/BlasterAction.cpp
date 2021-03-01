// Fill out your copyright notice in the Description page of Project Settings.


#include "Action/BlasterAction.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

//Bullet only:
#include "Items/BaseItem.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h" 
#include "Melee/SolidProjectile.h"

//Debug Includes: 
#include "Components/SceneComponent.h"

//#include "Components/ActorComponent.h"




void UBlasterAction::ActionImplementation()
{
		//const FRotator SpawnRotation = GetComponentRotation(); //FP_MuzzleLocation->GetComponentRotation();
		//// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		//const FVector SpawnLocation = GetComponentLocation(); //FP_MuzzleLocation->GetComponentLocation();
		//FActorSpawnParameters ActorSpawnParams;
		//ActorSpawnParams.Owner = GetOwner();
		////ActorSpawnParams.Instigator = GetOwner(); //for if blaster is owned by pawn
		//ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		ASolidProjectile* Projectile = CurrentWorld->SpawnActor<ASolidProjectile>(ShootSceneComponent->GetComponentLocation(), ShootSceneComponent->GetComponentRotation());
		//ASolidProjectile* Projectile= World->SpawnActor<ASolidProjectile>(DebugProjectileClass, ShootSceneComponent->GetComponentTransform());

		Projectile->InitializeProjectile(ShootDamage, OwningActionComponent->GetOwningBaseCharacter());
//if (FireSound != nullptr)
//{
//	UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetComponentLocation());
//}
		LastShootTime = CurrentWorld->TimeSeconds;
}

void UBlasterAction::ActionStart()
{

	if (LastShootTime + ShootRate > CurrentWorld->TimeSeconds) {
		return;
	}

	OwningActor->GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, this, &UBlasterAction::ActionImplementation, ShootRate, true, 0.0f);

}

void UBlasterAction::ActionStop()
{
	//GetOwner()->GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
	OwningActor->GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
}
void UBlasterAction::ActionEdit() {
	
 }
void UBlasterAction::InitializeAction(UActionComponent* _OwningActionComponent)
{
	
	Super::InitializeAction(_OwningActionComponent);
	ShootSceneComponent = GetOwningActionComponent()->GetOwningBaseCharacter()->GetShootDebugSceneComponent();

	OwningActor = GetOwningActionComponent()->GetOwner();
	CurrentWorld=OwningActor->GetWorld();

	UE_LOG(LogTemp, Warning, TEXT("Ititialize blaster"));

}

void UBlasterAction::SwitchToNextAmmo()
{

}

void UBlasterAction::UninitializeAction()
{
	Super::UninitializeAction();
}

bool UBlasterAction::CheckIfActionCanRun()
{

	return Super::CheckIfActionCanRun();
}

