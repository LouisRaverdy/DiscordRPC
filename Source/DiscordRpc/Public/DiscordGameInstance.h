// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiscordRpcBlueprint.h"
#include "Engine/GameInstance.h"
#include "DiscordGameInstance.generated.h"

UENUM(BlueprintType)
enum EDiscordPresenceState
{
	Update UMETA(DisplayName = "Update"),
	Clear UMETA(DisplayName = "Clear")
};

/**
 * 
 */
UCLASS()
class DISCORDRPC_API UDiscordGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:	

		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			UDiscordRpc* DiscordRpc;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString ApplicationId;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString OptionalSteamID;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString State;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString Details;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString LargeImageKey;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString LargeImageText;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString SmallImageKey;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString SmallImageText;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString PartyId;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString MatchSecret;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString JoinSecret;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			FString SpectateSecret;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			int PartySize;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			int PartyMax;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			bool Instance;
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
			int64 StampRef;
private:
	virtual void Shutdown() override;

public:

	UFUNCTION(BlueprintCallable)
		void SetDiscordPresence(EDiscordPresenceState PresenceState);
	UFUNCTION(BlueprintCallable)
		void SetBasicPresence(FString instate, FString indetails, FString inlargeimagekey, FString inlargeimagetext);
	UFUNCTION(BlueprintCallable)
		void SetAllPresence(FString instate, FString indetails, FString inlargeimagekey, FString inlargeimagetext, FString insmallimagekey, FString insmallimagetext, FString inpartyid, FString inmatchsecret, FString injoinsecret, FString inspectatesecret, int inpartysize, int inpartymax, bool ininstance);
	UFUNCTION(BlueprintCallable)
		void SetAppIDs(FString inapplicationid, FString inoptionalsteamid);
};
