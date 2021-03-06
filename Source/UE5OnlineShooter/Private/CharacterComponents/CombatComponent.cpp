// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterComponents/CombatComponent.h"
#include "Weapon/Weapon.h"
#include "Character/BaseShooterCharacter.h"
#include "Engine/SkeletalMeshSocket.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCombatComponent::EquipWeapon(AWeapon* WeaponToEquip)
{
	if (!ParentChar || !WeaponToEquip)
	{
		return;
	}

	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped);
	const USkeletalMeshSocket* HandSocket = ParentChar->GetMesh()->GetSocketByName(FName("equip_r_socket"));
	if (HandSocket)
	{
		HandSocket->AttachActor(EquippedWeapon, ParentChar->GetMesh());
		EquippedWeapon->SetOwner(ParentChar);
		EquippedWeapon->ShowPickupWidget(false);
	}
}

