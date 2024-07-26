// Copyright Epic Games, Inc. All Rights Reserved.

#include "Otus_Lession17GameMode.h"
#include "Otus_Lession17Character.h"
#include "UObject/ConstructorHelpers.h"

AOtus_Lession17GameMode::AOtus_Lession17GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
