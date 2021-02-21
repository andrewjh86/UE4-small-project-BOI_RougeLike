// Fill out your copyright notice in the Description page of Project Settings.


#include "Melee/ShooterComponent.h"
#include "Components/SphereComponent.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h" 
#include "Components/ArrowComponent.h"

// Sets default values for this component's properties
UShooterComponent::UShooterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	//FP_MuzzleLocation->SetupAttachment(this);


	//#if WITH_EDITORONLY_DATA
	ArrowComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor(150, 200, 255);
		ArrowComponent->bTreatAsASprite = true;
		//ArrowComponent->SetupAttachment(this);
		ArrowComponent->bIsScreenSizeScaled = true;
	}
	//#endif // WITH_EDITORONLY_DATA


}


// Called when the game starts
void UShooterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void UShooterComponent::OnFire()
{
	//if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			//if(ProjectileClass!= nullptr)
			{
				const FRotator SpawnRotation = FP_MuzzleLocation->GetComponentRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = FP_MuzzleLocation->GetComponentLocation();
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				//World->SpawnActor<ASolidProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			}
		}
		}

		// try and play the sound if specified
		if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, FP_MuzzleLocation->GetComponentLocation());
		}
		
}

void UShooterComponent::BeginShoot()
{
	if (LastShootTime > GetWorld()->TimeSeconds) {
		return;
	}
	GetOwner()->GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, this, &UShooterComponent::OnFire, ShootRate, true);

}

void UShooterComponent::EndShoot()
{
	GetOwner()->GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
	LastShootTime = GetWorld()->TimeSeconds + ShootRate;
	
}



