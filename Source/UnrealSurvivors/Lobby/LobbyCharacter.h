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

public:
	// 캐릭터 메시 변수.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<class USkeletalMeshComponent> CharacterMesh;

	// 데이터 에셋 변수.
	UPROPERTY()
	TObjectPtr<class UCharacterMeshData> CharacterMeshData;

	// UI 에셋 변수.
	UPROPERTY()
	TSubclassOf<UUserWidget> LobbyWidgetClass;
};