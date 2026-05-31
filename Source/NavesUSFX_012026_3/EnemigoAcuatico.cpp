// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoAcuatico.h"
#include "Components/StaticMeshComponent.h"

AEnemigoAcuatico::AEnemigoAcuatico()
{
	MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
	RootComponent = MeshEnemigo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	if (MeshAsset.Succeeded())
	{
		MeshEnemigo->SetStaticMesh(MeshAsset.Object);
	}
}

void AEnemigoAcuatico::HacerMovimiento(float DeltaTime)
{
	// Movimiento diagonal: sin en X y cos en Y a distinta velocidad
	Tiempo += DeltaTime;
	FVector Pos = PosicionInicial;
	Pos.X += FMath::Sin(Tiempo * 1.2f) * 300.f;
	Pos.Y += FMath::Cos(Tiempo * 0.8f) * 200.f;
	SetActorLocation(Pos);
}
