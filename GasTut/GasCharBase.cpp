// Fill out your copyright notice in the Description page of Project Settings.


#include "GasCharBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AGasCharBase::AGasCharBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	AbilitySystemComp->SetIsReplicated(true);
	AbilitySystemComp->SetReplicationMode(ReplicationMode);

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(35.0f, 90.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	
	BasicAttributeSet = CreateDefaultSubobject<UBasicAttributeSet>(TEXT("BasicAttributeSet"));	


}

void AGasCharBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(AbilitySystemComp)
	{
		AbilitySystemComp->InitAbilityActorInfo(NewController, this);
	}	
}

void AGasCharBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if(AbilitySystemComp)
	{
		AbilitySystemComp->InitAbilityActorInfo(GetController(), this);
	}
}

// Called when the game starts or when spawned
void AGasCharBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGasCharBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Fill out your copyright notice in the Description page of Project Settings.

	

}

// Called to bind functionality to input
void AGasCharBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AGasCharBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

