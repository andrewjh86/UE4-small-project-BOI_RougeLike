// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action/ActionObject.h"
#include "BlasterAction.generated.h"

class USoundBase;
class ASolidProjectile;
class USceneComponent;
class UWorld;


/**
 *
 */
UCLASS()
class BINDINGOFISSAC3D_API UBlasterAction : public UActionObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = melee)
		float ShootDamage = 20;

	/**in seconds the pause between bullets*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = melee)
		float ShootRate = 0.2f;

	UPROPERTY()
		float LastShootTime;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = asthetic)
		USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = melee)
		TSubclassOf<ASolidProjectile> DebugProjectileClass;

	FTimerHandle TimerHandle_TimeBetweenShots;

	USceneComponent* ShootSceneComponent;

	UWorld* CurrentWorld;

	AActor* OwningActor;

	virtual void ActionImplementation()override;


public:
	virtual void ActionStart() override;
	virtual void ActionStop() override;
		virtual void InitializeAction(UActionComponent* _OwningActionComponent)override;
		virtual void UninitializeAction()override;
		virtual bool CheckIfActionCanRun()override;


};


