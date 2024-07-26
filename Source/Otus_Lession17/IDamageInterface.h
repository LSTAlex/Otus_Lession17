#pragma once 

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IDamageInterface.generated.h"

UINTERFACE()
class UDamageInterface : public UInterface
{
	GENERATED_BODY()
};


class OTUS_LESSION17_API IDamageInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void OnDamage(float Damage);
};