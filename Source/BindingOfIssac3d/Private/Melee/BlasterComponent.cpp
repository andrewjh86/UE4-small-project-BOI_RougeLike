// Fill out your copyright notice in the Description page of Project Settings.


#include "Melee/BlasterComponent.h"
#include "Components/SphereComponent.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h" 
#include "Components/ArrowComponent.h"
#include "Melee/SolidProjectile.h"

// Sets default values for this component's properties
UBlasterComponent::UBlasterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	//FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	//FP_MuzzleLocation->SetupAttachment(this);


	//#if WITH_EDITORONLY_DATA
	ArrowComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor(FColor::Red);
		ArrowComponent->bTreatAsASprite = true;
		ArrowComponent->SetupAttachment(this);
		ArrowComponent->bIsScreenSizeScaled = true;
	}
	//#endif // WITH_EDITORONLY_DATA

	ShootRate = 0.2f;

}


// Called when the game starts
void UBlasterComponent::BeginPlay()

{
	Super::BeginPlay();



}

void UBlasterComponent::OnFire()
{
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			
				const FRotator SpawnRotation = GetComponentRotation(); //FP_MuzzleLocation->GetComponentRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = GetComponentLocation(); //FP_MuzzleLocation->GetComponentLocation();
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.Owner = GetOwner();
				//ActorSpawnParams.Instigator = GetOwner(); //for if blaster is owned by pawn
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				
				ASolidProjectile *Projectile =World->SpawnActor<ASolidProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
				//Projectile->SetHitDamage(ShootDamage);
		}
	}

	// try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetComponentLocation());
	}
	LastShootTime = GetWorld()->TimeSeconds;

}

void UBlasterComponent::BeginShoot()
{
	if (LastShootTime+ShootRate > GetWorld()->TimeSeconds) {
		return;
	}
	GetOwner()->GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, this, &UBlasterComponent::OnFire, ShootRate, true,0.0F);
}

void UBlasterComponent::EndShoot()
{
	GetOwner()->GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);

}



