// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BlasterComponent.generated.h"

class UArrowComponent;
class ASolidProjectile;
class USoundBase;
class ASolidProjectile;
class USceneComponent;
class UAmmoItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BINDINGOFISSAC3D_API UBlasterComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBlasterComponent();

protected:
	//	// Called when the game starts
	virtual void BeginPlay() override;
	//
	UFUNCTION()
		void OnFire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = melee)
		float ShootDamage=20;

	/**in seconds the pause between bullets*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = melee)
		float ShootRate=0.2f;

	
	UPROPERTY()
		float LastShootTime;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = asthetic)
		USoundBase* FireSound;

	UPROPERTY()
		UArrowComponent* ArrowComponent;

	UPROPERTY()
		UAmmoItem* CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = melee)
		TSubclassOf<ASolidProjectile> ProjectileClass;

	FTimerHandle TimerHandle_TimeBetweenShots;

public:


	UFUNCTION()
		void BeginShoot();

	UFUNCTION()
		void EndShoot();



};
