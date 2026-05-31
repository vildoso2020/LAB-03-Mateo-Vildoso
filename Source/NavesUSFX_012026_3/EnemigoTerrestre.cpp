// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoTerrestre.h"
#include "Components/StaticMeshComponent.h"

AEnemigoTerrestre::AEnemigoTerrestre()
{
	MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
	RootComponent = MeshEnemigo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
}

void AEnemigoTerrestre::HacerMovimiento(float DeltaTime)
{
	// Oscila de izquierda a derecha
	Tiempo += DeltaTime;
	FVector Pos = PosicionInicial;
	Pos.Y += FMath::Sin(Tiempo * 1.5f) * 250.f;
	SetActorLocation(Pos);
}
