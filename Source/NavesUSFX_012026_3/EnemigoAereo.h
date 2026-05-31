// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereo.generated.h"

UCLASS()
class NAVESUSFX_012026_3_API AEnemigoAereo : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoAereo();

protected:
	// Movimiento aereo: sube y baja (oscilacion vertical con sin)
	virtual void HacerMovimiento(float DeltaTime) override;
};
