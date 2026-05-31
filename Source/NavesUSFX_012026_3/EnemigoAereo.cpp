// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoAereo.h"
#include "Components/StaticMeshComponent.h"

AEnemigoAereo::AEnemigoAereo()
{
	MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
	RootComponent = MeshEnemigo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
}

void AEnemigoAereo::HacerMovimiento(float DeltaTime)
{
	// Oscila hacia arriba y abajo
	Tiempo += DeltaTime;
	FVector Pos = PosicionInicial;
	Pos.Z += FMath::Sin(Tiempo * 2.f) * 200.f;
	SetActorLocation(Pos);
}
