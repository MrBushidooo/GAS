// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"
#include "AttributeSet/BasicAttributeSet.h"
#include "GameFramework/Character.h"
#include "GasCharBase.generated.h"

UCLASS()
class GASTUT_API AGasCharBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGasCharBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	class UAbilitySystemComponent* AbilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	class UBasicAttributeSet* BasicAttributeSet;


protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	EGameplayEffectReplicationMode ReplicationMode = EGameplayEffectReplicationMode::Mixed;

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
