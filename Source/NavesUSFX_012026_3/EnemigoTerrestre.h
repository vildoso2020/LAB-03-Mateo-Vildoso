// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoTerrestre.generated.h"

UCLASS()
class NAVESUSFX_012026_3_API AEnemigoTerrestre : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoTerrestre();

protected:
	// Movimiento terrestre: va de lado a lado (oscilacion lateral con sin)
	virtual void HacerMovimiento(float DeltaTime) override;
};
