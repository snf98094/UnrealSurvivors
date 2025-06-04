// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSURVIVORS_API ALobbyGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ALobbyGameMode();

protected:
	virtual void BeginPlay() override;

	// ���� Ŭ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UUserWidget> LobbyWidgetClass;

	// ���� �ν��Ͻ�
	UPROPERTY()
	class UUserWidget* LobbyWidget;
};