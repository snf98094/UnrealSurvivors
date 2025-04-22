// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LobbyCharacter.generated.h"

UCLASS()
class UNREALSURVIVORS_API ALobbyCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALobbyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class USkeletalMeshComponent> CharacterMesh;
	UPROPERTY()
	TObjectPtr<class UCharacterMeshData> CharacterMeshData;
};