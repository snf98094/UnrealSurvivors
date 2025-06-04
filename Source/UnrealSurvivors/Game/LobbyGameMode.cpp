// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

ALobbyGameMode::ALobbyGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/02_Blueprints/BP_LobbyPlayer.BP_LobbyPlayer_C"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class; 
	}

	// 위젯 클래스 설정
	static ConstructorHelpers::FClassFinder<UUserWidget> LobbyWidgetBPClass(TEXT("/Game/02_Blueprints/WBP_Lobby.WBP_Lobby_C"));
	if (LobbyWidgetBPClass.Class != nullptr)
	{
		LobbyWidgetClass = LobbyWidgetBPClass.Class;
	}
}

void ALobbyGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (LobbyWidgetClass)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
		if (PC)
		{
			LobbyWidget = CreateWidget<UUserWidget>(PC, LobbyWidgetClass);
			if (LobbyWidget)
			{
				LobbyWidget->AddToViewport();
			}
		}
	}
}