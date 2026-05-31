// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAcuatico.generated.h"

UCLASS()
class NAVESUSFX_012026_3_API AEnemigoAcuatico : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoAcuatico();

protected:
	// Movimiento acuatico: diagonal usando sin en X y cos en Y
	virtual void HacerMovimiento(float DeltaTime) override;
};
