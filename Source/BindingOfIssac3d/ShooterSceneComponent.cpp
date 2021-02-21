// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterSceneComponent.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Components/ArrowComponent.h"

// Sets default values for this component's properties
UShooterSceneComponent::UShooterSceneComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

//#if WITH_EDITORONLY_DATA
	ArrowComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	if (ArrowComponent)
	{
		ArrowComponent->ArrowColor = FColor(150, 200, 255);
		ArrowComponent->bTreatAsASprite = true;
		ArrowComponent->SetupAttachment(this);
		ArrowComponent->bIsScreenSizeScaled = true;
	}
//#endif // WITH_EDITORONLY_DATA


}


// Called when the game starts
void UShooterSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UShooterSceneComponent::OnFire()
{
}

void UShooterSceneComponent::BeginShoot()
{
}

void UShooterSceneComponent::EndShoot()
{
}



