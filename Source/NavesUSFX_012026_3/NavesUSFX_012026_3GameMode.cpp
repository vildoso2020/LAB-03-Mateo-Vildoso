// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesUSFX_012026_3GameMode.h"
#include "NavesUSFX_012026_3Pawn.h"
#include "EnemigoAereo.h"
#include "EnemigoTerrestre.h"
#include "EnemigoAcuatico.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

ANavesUSFX_012026_3GameMode::ANavesUSFX_012026_3GameMode()
{
	DefaultPawnClass = ANavesUSFX_012026_3Pawn::StaticClass();
	bEnFormacion = false;
}

void ANavesUSFX_012026_3GameMode::BeginPlay()
{
	Super::BeginPlay();
	SpawnNaves();

	// Cada 5 segundos alterna entre movimiento libre y formacion corazon
	GetWorldTimerManager().SetTimer(TimerEstado, this, &ANavesUSFX_012026_3GameMode::CambiarEstado, 5.f, true);
}

void ANavesUSFX_012026_3GameMode::SpawnNaves()
{
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// 7 naves aereas (esfera) - Z alto
	for (int32 i = 0; i < 7; i++)
	{
		FVector Pos(FMath::RandRange(-800.f, 800.f), FMath::RandRange(-800.f, 800.f), FMath::RandRange(300.f, 500.f));
		AEnemigoAereo* Nave = GetWorld()->SpawnActor<AEnemigoAereo>(AEnemigoAereo::StaticClass(), Pos, FRotator::ZeroRotator, Params);
		if (Nave) Naves.Add(Nave);
	}

	// 7 naves terrestres (tubo) - Z bajo
	for (int32 i = 0; i < 7; i++)
	{
		FVector Pos(FMath::RandRange(-800.f, 800.f), FMath::RandRange(-800.f, 800.f), FMath::RandRange(50.f, 150.f));
		AEnemigoTerrestre* Nave = GetWorld()->SpawnActor<AEnemigoTerrestre>(AEnemigoTerrestre::StaticClass(), Pos, FRotator::ZeroRotator, Params);
		if (Nave) Naves.Add(Nave);
	}

	// 6 naves acuaticas (capsula) - Z medio
	for (int32 i = 0; i < 6; i++)
	{
		FVector Pos(FMath::RandRange(-800.f, 800.f), FMath::RandRange(-800.f, 800.f), FMath::RandRange(150.f, 250.f));
		AEnemigoAcuatico* Nave = GetWorld()->SpawnActor<AEnemigoAcuatico>(AEnemigoAcuatico::StaticClass(), Pos, FRotator::ZeroRotator, Params);
		if (Nave) Naves.Add(Nave);
	}
}

void ANavesUSFX_012026_3GameMode::CambiarEstado()
{
	bEnFormacion = !bEnFormacion;
	if (bEnFormacion)
		ActivarFormacion();
	else
		DesactivarFormacion();
}

void ANavesUSFX_012026_3GameMode::ActivarFormacion()
{
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Pawn) return;

	FVector Centro = Pawn->GetActorLocation();
	float Escala = 55.f;
	int32 Total = Naves.Num();

	for (int32 i = 0; i < Total; i++)
	{
		if (!Naves[i]) continue;

		// Formula parametrica de corazon
		float t = (2.f * PI * i) / Total;
		float sinT = FMath::Sin(t);
		float HeartX = 16.f * sinT * sinT * sinT;
		float HeartY = 13.f * FMath::Cos(t)
			- 5.f * FMath::Cos(2.f * t)
			- 2.f * FMath::Cos(3.f * t)
			-       FMath::Cos(4.f * t);

		FVector Pos;
		Pos.X = Centro.X + HeartX * Escala;
		Pos.Y = Centro.Y + HeartY * Escala;
		Pos.Z = Centro.Z + 150.f;

		Naves[i]->PosicionFormacion = Pos;
		Naves[i]->bEnFormacion = true;
	}
}

void ANavesUSFX_012026_3GameMode::DesactivarFormacion()
{
	for (AEnemigo* Nave : Naves)
	{
		if (Nave)
			Nave->bEnFormacion = false;
	}
}
