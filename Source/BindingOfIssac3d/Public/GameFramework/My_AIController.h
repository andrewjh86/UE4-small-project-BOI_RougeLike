// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "My_AIController.generated.h"

class UBlackboardComponent;
class UAISenseConfig_Sight;
class UAISenseConfig_Hearing;
class UBehaviorTree;
class UBehaviorTreeComponent;

/**
 *
 */
UCLASS()
class BINDINGOFISSAC3D_API AMy_AIController : public AAIController
{
	GENERATED_BODY()

public:
	AMy_AIController(FObjectInitializer const& object_initializer = FObjectInitializer::Get());
	void BeginPlay() override;
	void OnPossess(APawn* const pawn) override;
	 UBlackboardComponent* get_blackboard() const;
private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		 UBehaviorTreeComponent* behavior_tree_component;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		 UBehaviorTree* btree;

	 UBlackboardComponent* blackboard;

	 UAISenseConfig_Sight* sight_config;

	 UAISenseConfig_Hearing* hearing_config;

	UFUNCTION()
		void on_updated(TArray<AActor*> const& updated_actors);

	void setup_perception_system();
};
