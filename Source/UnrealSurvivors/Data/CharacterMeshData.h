// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Enum/GameEnums.h"
#include "CharacterMeshData.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSURVIVORS_API UCharacterMeshData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	// 캐릭터별 스켈레탈 메시.
	UPROPERTY(EditAnywhere, Category = Character)
	TMap<ECharacterType, TSoftObjectPtr<USkeletalMesh>> CharacterMeshs;
};
