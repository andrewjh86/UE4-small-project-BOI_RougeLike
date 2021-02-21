// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ShooterSceneComponent.generated.h"

class UArrowComponent;
class ASolidProjectile;
class USoundBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BINDINGOFISSAC3D_API UShooterSceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShooterSceneComponent();


protected:
//	// Called when the game starts
	virtual void BeginPlay() override;
//
	UFUNCTION()
		void OnFire();


	UPROPERTY()
		float ShootRate;
	UPROPERTY()
		float LastShootTime;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;

	FTimerHandle TimerHandle_TimeBetweenShots;

	UPROPERTY()
		UArrowComponent* ArrowComponent;

//	//UPROPERTY()
//		//TSubclassOf<ASolidProjectile> ProjectileClass;
//
//
//
public:


	UFUNCTION()
		void BeginShoot();

	UFUNCTION()
		void EndShoot();

};
