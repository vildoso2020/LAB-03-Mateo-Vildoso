// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Enemigo.h"
#include "NavesUSFX_012026_3GameMode.generated.h"

UCLASS(MinimalAPI)
class ANavesUSFX_012026_3GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesUSFX_012026_3GameMode();

protected:
	virtual void BeginPlay() override;

private:
	// Las 20 naves
	TArray<AEnemigo*> Naves;

	bool bEnFormacion;
	FTimerHandle TimerEstado;

	void SpawnNaves();
	void CambiarEstado();
	void ActivarFormacion();
	void DesactivarFormacion();
};
