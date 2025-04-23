// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyCharacter.h"
#include "Data/CharacterMeshData.h"
#include "Enum/GameEnums.h"

// Sets default values
ALobbyCharacter::ALobbyCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 캐릭터 메시 생성.
	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	// 캐릭터 메시 방향 조정.
	CharacterMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	// 캐릭터 데이터 에셋 가져오기.
	static ConstructorHelpers::FObjectFinder<UCharacterMeshData> CharacterMeshDataRef(TEXT("/Game/DataAsset/DA_CharacterMesh.DA_CharacterMesh"));
	if (CharacterMeshDataRef.Object)
	{
		CharacterMeshData = CharacterMeshDataRef.Object;
	}

	// Nicole 캐릭터 할당.
	TSoftObjectPtr<USkeletalMesh> CharacterMeshAsset = CharacterMeshData->CharacterMeshs[ECharacterType::Nicole];

	// Nicole 캐릭터 로드 체크.
	if (CharacterMeshAsset.IsPending())
	{
		CharacterMeshAsset.LoadSynchronous();
	}

	// 캐릭터 메시에 에셋 할당.
	CharacterMesh->SetSkeletalMeshAsset(CharacterMeshAsset.Get());
}

// Called when the game starts or when spawned
void ALobbyCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Nicole 캐릭터 할당.
	TSoftObjectPtr<USkeletalMesh> CharacterMeshAsset = CharacterMeshData->CharacterMeshs[ECharacterType::Lisa];

	// Nicole 캐릭터 로드 체크.
	if (CharacterMeshAsset.IsPending())
	{
		CharacterMeshAsset.LoadSynchronous();
	}

	// 캐릭터 메시에 에셋 할당.
	CharacterMesh->SetSkeletalMeshAsset(CharacterMeshAsset.Get());
}

// Called every frame
void ALobbyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}