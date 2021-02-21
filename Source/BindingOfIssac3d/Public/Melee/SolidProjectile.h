// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SolidProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UStaticMeshComponent;

UCLASS()
class BINDINGOFISSAC3D_API ASolidProjectile : public AActor
{
	GENERATED_BODY()


protected:	
	// Sets default values for this actor's properties
	ASolidProjectile();

	/** Sphere collision component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
		USphereComponent* CollisionComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = melee)
		float HitDamage = 0;
		
	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;

public:
	void SetHitDamage(float amount);
	/** called when projectile hits something */
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

};
