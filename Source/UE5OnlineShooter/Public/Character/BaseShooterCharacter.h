// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseShooterCharacter.generated.h"

UCLASS()
class UE5ONLINESHOOTER_API ABaseShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseShooterCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Camera")
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* FollowCamera;

public:	
	

};
