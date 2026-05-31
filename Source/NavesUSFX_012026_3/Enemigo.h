// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

UCLASS()
class NAVESUSFX_012026_3_API AEnemigo : public AActor
{
	GENERATED_BODY()

public:
	AEnemigo();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshEnemigo;

	// El NaveContenedor pone esto en true y asigna PosicionFormacion
	bool bEnFormacion;
	FVector PosicionFormacion;

protected:
	virtual void BeginPlay() override;

	FVector PosicionInicial;
	float Tiempo;

	// Cada subclase implementa su propio movimiento aqui
	virtual void HacerMovimiento(float DeltaTime);

public:
	virtual void Tick(float DeltaTime) override;
};
