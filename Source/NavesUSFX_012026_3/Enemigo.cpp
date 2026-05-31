// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemigo.h"

AEnemigo::AEnemigo()
{
	PrimaryActorTick.bCanEverTick = true;
	bEnFormacion = false;
	Tiempo = 0.f;
}

void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

// Movimiento por defecto (circulo). Las subclases lo sobreescriben.
void AEnemigo::HacerMovimiento(float DeltaTime)
{
	Tiempo += DeltaTime;
	FVector Pos = PosicionInicial;
	Pos.X += FMath::Cos(Tiempo) * 200.f;
	Pos.Y += FMath::Sin(Tiempo) * 200.f;
	SetActorLocation(Pos);
}

void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bEnFormacion)
	{
		// Acercarse suavemente a la posicion de formacion
		FVector Actual = GetActorLocation();
		FVector Dir = PosicionFormacion - Actual;
		if (Dir.Size() > 10.f)
		{
			SetActorLocation(Actual + Dir.GetSafeNormal() * 1200.f * DeltaTime);
		}
		return;
	}

	HacerMovimiento(DeltaTime);
}
