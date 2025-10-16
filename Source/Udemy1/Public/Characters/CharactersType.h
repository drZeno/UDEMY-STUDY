#pragma once
#include "CoreMinimal.h"   // <- важно
#include "CharactersType.generated.h"


UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName = "One-Handed Weapon"),
	ECS_EquippedTwoHandedWeapon UMETA(DisplayName = "Two-Handed Weapon"),
	
};