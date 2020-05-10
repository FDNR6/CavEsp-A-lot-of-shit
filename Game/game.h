#pragma once

#include "../Globals.h"

namespace RainbowSix
{
	bool CavEsp(uint64_t base_address);
	void un_freeze_lobby(uint64_t base_address);
	int Glow (uint64_t base_address, float Red, float Green, float Blue, float DistanceX, float DistanceY, float DistanceZ, float Opacity);
	int FovGame(uint64_t base_address, float Map, float Gun);
	int ThirdPerson(uint64_t base_address);
	int unThirdPerson(uint64_t base_address);
	int NoClipGad(uint64_t base_address);
	int NoClip(uint64_t base_address);
	int SpottWall(uint64_t base_address);
	int Tornado(uint64_t base_address);
	int MortePatinho(uint64_t base_address);
	int NoRecoil(uint64_t base_address);
	int NoSpread(uint64_t base_address);
	int SpeedPlayer_1(uint64_t base_address, BYTE Speed);
	int SpeedPlayer_2(uint64_t base_address, float Speed);
	int SpeedMax(uint64_t base_address);
	int un_SpeedMax(uint64_t base_address);
	int GetJumpStyle(uint64_t base_address);
	int DroneIncreaseJump(uint64_t base_address);
	int FlyTP(uint64_t base_address);
	int DecreaseGravity(uint64_t base_address);
	int GetDroneState(uint64_t base_address);
	int NoFlash(uint64_t base_address);
	int WeaponAuto(uint64_t base_address);
	int NoAnimation(uint64_t base_address);
	float GetEntityPos_X(uint64_t base_address, int ID);
	float GetEntityPos_Y(uint64_t base_address, int ID);
	float GetEntityPos_Z(uint64_t base_address, int ID);
	float GetLastShootPos_X(uint64_t base_address);
	float GetLastShootPos_Y(uint64_t base_address);
	float GetLastShootPos_Z(uint64_t base_address);
	void TpKnife(uint64_t base_address, float x, float y, float z);
	void TpToDirection(uint64_t base_address, float x, float y, float z);
	int Ataque(uint64_t base_address);
	int Defesa(uint64_t base_address);
	void freeze_lobby(uint64_t base_address);
	void un_freeze_lobby(uint64_t base_address);
}