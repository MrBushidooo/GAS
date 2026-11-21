// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BasicAttributeSet.generated.h"

/**
 * 
 */

UCLASS()
class GASTUT_API UBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


	public:

		UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
		FGameplayAttributeData Health;
		ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, Health)

		UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
		FGameplayAttributeData MaxHealth;
		ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, MaxHealth)

		UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Stamina)
		FGameplayAttributeData Stamina;
		ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, Stamina)

		UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxStamina)
		FGameplayAttributeData MaxStamina;
		ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, MaxStamina)
	

public:

	UBasicAttributeSet(); //constructor 

		virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
		//virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

		// Client-side callback when replicated Health changes; OldHealth is the previous value.
		UFUNCTION()
		void OnRep_Health(const FGameplayAttributeData& OldHealth) const {
			// Notify GAS of the replicated change (syncs ASC state, fires change delegates).
			GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicAttributeSet, Health, OldHealth);
		}

		UFUNCTION()
		void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const {
			GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicAttributeSet, MaxHealth, OldMaxHealth);
		}

		UFUNCTION()
		void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const {
			GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicAttributeSet, Stamina, OldStamina);
		}

		UFUNCTION()
		void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const {
			GAMEPLAYATTRIBUTE_REPNOTIFY(UBasicAttributeSet, MaxStamina, OldMaxStamina);
		}

		void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

		void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

};
