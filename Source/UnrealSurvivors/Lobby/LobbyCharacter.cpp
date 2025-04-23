// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyCharacter.h"
#include "Data/CharacterMeshData.h"
#include "Enum/GameEnums.h"

// Sets default values
ALobbyCharacter::ALobbyCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ĳ���� �޽� ����.
	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	// ĳ���� �޽� ���� ����.
	CharacterMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	// ĳ���� ������ ���� ��������.
	static ConstructorHelpers::FObjectFinder<UCharacterMeshData> CharacterMeshDataRef(TEXT("/Game/DataAsset/DA_CharacterMesh.DA_CharacterMesh"));
	if (CharacterMeshDataRef.Object)
	{
		CharacterMeshData = CharacterMeshDataRef.Object;
	}

	// Nicole ĳ���� �Ҵ�.
	TSoftObjectPtr<USkeletalMesh> CharacterMeshAsset = CharacterMeshData->CharacterMeshs[ECharacterType::Nicole];

	// Nicole ĳ���� �ε� üũ.
	if (CharacterMeshAsset.IsPending())
	{
		CharacterMeshAsset.LoadSynchronous();
	}

	// ĳ���� �޽ÿ� ���� �Ҵ�.
	CharacterMesh->SetSkeletalMeshAsset(CharacterMeshAsset.Get());
}

// Called when the game starts or when spawned
void ALobbyCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Nicole ĳ���� �Ҵ�.
	TSoftObjectPtr<USkeletalMesh> CharacterMeshAsset = CharacterMeshData->CharacterMeshs[ECharacterType::Lisa];

	// Nicole ĳ���� �ε� üũ.
	if (CharacterMeshAsset.IsPending())
	{
		CharacterMeshAsset.LoadSynchronous();
	}

	// ĳ���� �޽ÿ� ���� �Ҵ�.
	CharacterMesh->SetSkeletalMeshAsset(CharacterMeshAsset.Get());
}

// Called every frame
void ALobbyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}