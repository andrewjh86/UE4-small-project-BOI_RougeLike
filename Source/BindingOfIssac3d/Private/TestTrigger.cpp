// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTrigger.h"
#include "Components/BoxComponent.h"
#include "TestInterface.h"

// Sets default values
ATestTrigger::ATestTrigger()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ATestTrigger::BoxTriggered);

}

void ATestTrigger::BoxTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning, TEXT("interact"));

	if (OtherActor->GetClass()->ImplementsInterface(UTestInterface::StaticClass())) {
		ITestInterface::Execute_Interact(OtherActor);

	}
}



// Called when the game starts or when spawned
void ATestTrigger::BeginPlay()
{
	Super::BeginPlay();

}



