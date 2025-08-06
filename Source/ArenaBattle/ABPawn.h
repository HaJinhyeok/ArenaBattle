// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "ABPawn.generated.h"

UCLASS()
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 폰의 움직임 담당하는 충돌 컴포넌트. 폰을 대표해 월드에서 움직임을 담당하므로 루트 컴포넌트로 설정
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UCapsuleComponent* Capsule;

	// 캐릭터 애셋을 보여주고 애니메이션도 담당
	UPROPERTY(VisibleAnywhere, Category = "Visual")
	USkeletalMeshComponent* Mesh;

	// 중력을 고려하지 않은 간단한 움직임을 플레이어 입력에 따라 설정해줌
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	UFloatingPawnMovement* Movement;

	// 삼인칭 시점으로 카메라 구도를 편리하게 설정할 수 있는 부가 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	// 카메라 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);

};
