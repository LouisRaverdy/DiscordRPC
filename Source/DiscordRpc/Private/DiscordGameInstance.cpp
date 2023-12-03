// Fill out your copyright notice in the Description page of Project Settings.


#include "DiscordGameInstance.h"

void UDiscordGameInstance::Shutdown()
{
	Super::Shutdown();

	if (!DiscordRpc)
		return;

	DiscordRpc->ClearPresence();
}

void UDiscordGameInstance::SetDiscordPresence(EDiscordPresenceState PresenceState)
{
	// Check if DiscordRpc is valid, if not create a new one
	if (!DiscordRpc)
	{
		DiscordRpc = NewObject<UDiscordRpc>();
		DiscordRpc->Initialize(ApplicationId, false, OptionalSteamID);
	}

	// Save the current time stamp
	StampRef = DiscordRpc->GetStartTimeStamp();

	switch (PresenceState)
	{
		case EDiscordPresenceState::Update:
		{
			DiscordRpc->RichPresence.state = State;
			DiscordRpc->RichPresence.details = Details;
			DiscordRpc->RichPresence.largeImageKey = LargeImageKey;
			DiscordRpc->RichPresence.largeImageText = LargeImageText;
			DiscordRpc->RichPresence.smallImageKey = SmallImageKey;
			DiscordRpc->RichPresence.smallImageText = SmallImageText;
			DiscordRpc->RichPresence.partyId = PartyId;
			DiscordRpc->RichPresence.partySize = PartySize;
			DiscordRpc->RichPresence.partyMax = PartyMax;
			DiscordRpc->RichPresence.matchSecret = MatchSecret;
			DiscordRpc->RichPresence.joinSecret = JoinSecret;
			DiscordRpc->RichPresence.spectateSecret = SpectateSecret;
			DiscordRpc->RichPresence.instance = Instance;
			DiscordRpc->RichPresence.startTimestamp = StampRef;

			DiscordRpc->UpdatePresence();
			break;
		}
		case EDiscordPresenceState::Clear:
		{
			DiscordRpc->RichPresence.state = "";
			DiscordRpc->RichPresence.details = "";
			DiscordRpc->RichPresence.largeImageKey = "";
			DiscordRpc->RichPresence.largeImageText = "";
			DiscordRpc->RichPresence.smallImageKey = "";
			DiscordRpc->RichPresence.smallImageText = "";
			DiscordRpc->RichPresence.partyId = "";
			DiscordRpc->RichPresence.partySize = 0;
			DiscordRpc->RichPresence.partyMax = 0;
			DiscordRpc->RichPresence.matchSecret = "";
			DiscordRpc->RichPresence.joinSecret = "";
			DiscordRpc->RichPresence.spectateSecret = "";
			DiscordRpc->RichPresence.instance = false;
			DiscordRpc->RichPresence.startTimestamp = StampRef;
			DiscordRpc->RichPresence.endTimestamp = DiscordRpc->GetStartTimeStamp();

			DiscordRpc->UpdatePresence();

			DiscordRpc->ClearPresence();
			break;
		}
	}
}

void UDiscordGameInstance::SetBasicPresence(FString instate, FString indetails, FString inlargeimagekey, FString inlargeimagetext)
{
	State = instate;
	Details = indetails;
	LargeImageKey = inlargeimagekey;
	LargeImageText = inlargeimagetext;
}

void UDiscordGameInstance::SetAllPresence(FString instate, FString indetails, FString inlargeimagekey, FString inlargeimagetext, FString insmallimagekey, FString insmallimagetext, FString inpartyid, FString inmatchsecret, FString injoinsecret, FString inspectatesecret, int inpartysize, int inpartymax, bool ininstance)
{
	State = instate;
	Details = indetails;
	LargeImageKey = inlargeimagekey;
	LargeImageText = inlargeimagetext;
	SmallImageKey = insmallimagekey;
	SmallImageText = insmallimagetext;
	PartyId = inpartyid;
	MatchSecret = inmatchsecret;
	JoinSecret = injoinsecret;
	SpectateSecret = inspectatesecret;
	PartySize = inpartysize;
	PartyMax = inpartymax;
	Instance = ininstance;
}

void UDiscordGameInstance::SetAppIDs(FString inapplicationid, FString inoptionalsteamid)
{
	ApplicationId = inapplicationid;
	OptionalSteamID = inoptionalsteamid;
}
