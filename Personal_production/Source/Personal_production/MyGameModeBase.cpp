// MyGameModeBase.cpp
#include "MyGameModeBase.h"
#include "ThirdPersonCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
    DefaultPawnClass = AThirdPersonCharacter::StaticClass();
}