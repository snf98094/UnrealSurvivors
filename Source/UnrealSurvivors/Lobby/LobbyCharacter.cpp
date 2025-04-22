// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyCharacter.h"
#include "../Data/CharacterMeshData.h"

// Sets default values
ALobbyCharacter::ALobbyCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALobbyCharacter::BeginPlay()
{
	Super::BeginPlay();

	static ConstructorHelpers::FObjectFinder<UCharacterMeshData> CharacterMeshDataRef(TEXT("/Game/DataAsset/DA_CharacterMesh.DA_CharacterMesh"));
	if (CharacterMeshDataRef.Object)
	{
		CharacterMeshData = CharacterMeshDataRef.Object;
	}
	
	CharacterMesh = FindComponentByClass<USkeletalMeshComponent>();
	if (CharacterMesh)
	{
		CharacterMesh->SetVisibility(false);

		if (CharacterMeshData->CharacterMeshs[TEXT("Anbi")].IsPending())
		{
			CharacterMeshData->CharacterMeshs[TEXT("Anbi")].LoadSynchronous();
			
		}

		CharacterMesh->SetSkeletalMeshAsset(CharacterMeshData->CharacterMeshs[TEXT("Anbi")].Get());
	}
}

// Called every frame
void ALobbyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}