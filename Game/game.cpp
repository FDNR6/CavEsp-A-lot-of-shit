#include "Game.h"
#include "Offsets.h"
#include <iostream>
#include "Windows.h"
#define WIN32_LEAN_AND_MEAN


namespace RainbowSix
{
	bool CavEsp(uint64_t base_address)
	{
		uintptr_t game_manager = RPM<uintptr_t>(base_address + OFFSET_GAME_MANAGER);

		if (!game_manager) return false;

		uintptr_t entity_list = RPM<uintptr_t>(game_manager + OFFSET_GAME_MANAGER_ENTITY);

		int entity_count = RPM<DWORD>(game_manager + OFFSET_GAME_MANAGER_GAME_INFORMATION_ENTITY_COUNT) & 0x3fffffff;

		if (!entity_list || !entity_count) return false;

		for (int i = 0; i < entity_count; i++)
		{
			uintptr_t entity_object = RPM<uintptr_t>(entity_list + i * OFFSET_GAME_MANAGER_ENTITY_ID);

			if (!entity_object) continue;

			uintptr_t chain2 = RPM<uintptr_t>(entity_object + 0x28); if (!chain2) continue;

			uintptr_t chain3 = RPM<uintptr_t>(chain2 + 0xD8); if (!chain3) continue;

			for (auto current_component = 0x80; current_component < 0xf0; current_component += sizeof(uintptr_t))
			{
				uintptr_t chain4 = RPM<uintptr_t>(chain3 + current_component);
				if (!chain4) continue;
				if (RPM<uintptr_t>(chain4) != (base_address + OFFSET_V_TABLE)) continue;
				WPM<BYTE>(chain4 + 0x552, 0x1);
				WPM<BYTE>(chain4 + 0x554, 0x1);
			}
		}
		return 1;
	}

	uint64_t GetLocalPlayer(uint64_t base_address)
	{
		uint64_t ProfileManager = RPM<uint64_t>(base_address + OFFSET_PROFILE_MANAGER);
		uint64_t ProfileLocal = RPM<uint64_t>(ProfileManager + OFFSET_PROFILE_MANAGER_LOCAL);
		uint64_t ProfileLocalPlayer = RPM<uint64_t>(ProfileLocal + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER);
		uint64_t ProfileLocalPlayerContainer = RPM<uint64_t>(ProfileLocalPlayer + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER);

		return ProfileLocalPlayerContainer;
	}

	uint64_t GetVaultManager(uint64_t base_address)
	{
		uint64_t LocalPLayer = GetLocalPlayer(base_address);

		uint64_t Vault = RPM<uint64_t>(LocalPLayer + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT);
		uint64_t VaultManager = RPM<uint64_t>(Vault + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER);

		return VaultManager;
	}
	uint64_t GetHoldingWeapon(uint64_t base_address)
	{

		uint64_t LocalPlayer = GetLocalPlayer(base_address);

		uint64_t Weapon = RPM<uint64_t>(LocalPlayer + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON);
		uint64_t WeaponHolding = RPM<uint64_t>(Weapon + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING);

		return WeaponHolding;
	}

	uint64_t GetWeaponConfig(uint64_t base_address)
	{

		uint64_t WeaponHolding = GetHoldingWeapon(base_address);
		uint64_t WeaponConfig = RPM<uint64_t>(WeaponHolding + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG);

		return WeaponConfig;
	}

	uint64_t GetNetworkGame(uint64_t base_address)
	{
		uint64_t NetworkManager = RPM<uint64_t>(base_address + OFFSET_NETWORK_MANAGER);
		uint64_t NetworkConnection = RPM<uint64_t>(NetworkManager + OFFSET_NETWORK_MANAGER_CONNECTION);
		uint64_t NetworkConnectionGame = RPM<uint64_t>(NetworkConnection + OFFSET_NETWORK_MANAGER_CONNECTION_GAME);
		return NetworkConnectionGame;
	}

	int Glow(uint64_t base_address, float Red, float Green, float Blue, float DistanceX, float DistanceY, float DistanceZ, float Opacity)
	{

		uint64_t GlowManager = RPM<uint64_t>(base_address + OFFSET_GLOW_MANAGER);
		uint64_t GlowArea = RPM<uint64_t>(GlowManager + OFFSET_GLOW_MANAGER_AREA);

		WPM<float>(GlowArea + OFFSET_GLOW_MANAGER_AREA_RED, Red);
		WPM<float>(GlowArea + OFFSET_GLOW_MANAGER_AREA_GREEN, Green);
		WPM<float>(GlowArea + OFFSET_GLOW_MANAGER_AREA_BLUE, Blue);

		WPM<float>(GlowArea + OFFSET_GLOW_MANAGER_AREA_DISTANCE_X, DistanceX);
		WPM<float>(GlowArea + OFFSET_GLOW_MANAGER_AREA_DISTANCE_Y, DistanceY);
		WPM<float>(GlowArea + OFFSET_GLOW_MANAGER_AREA_DISTANCE_Z, DistanceZ);

		WPM<float>(GlowArea + OFFSET_GLOW_MANAGER_AREA_OPACITY, Opacity);

		return 1;
	}

	int FovGame(uint64_t base_address, float Map, float Gun)
	{
		uint64_t FovManager = RPM<uint64_t>(base_address + OFFSET_FOV_MANAGER);
		uint64_t FovVisual = RPM<uint64_t>(FovManager + OFFSET_FOV_MANAGER_VISUAL);
		uint64_t FovCam = RPM<uint64_t>(FovVisual + OFFSET_FOV_MANAGER_VISUAL_CAM);
		WPM<float>(FovCam + OFFSET_FOV_MANAGER_VISUAL_CAM_FOV_MAP, Map);
		WPM<float>(FovCam + OFFSET_FOV_MANAGER_VISUAL_CAM_FOV_GUN, Gun);
		return 1;
	}

	int ThirdPerson(uint64_t base_address)
	{
		uint64_t FovManager = RPM<uint64_t>(base_address + OFFSET_FOV_MANAGER);
		uint64_t FovVisual = RPM<uint64_t>(FovManager + OFFSET_FOV_MANAGER_VISUAL);
		uint64_t FovCam = RPM<uint64_t>(FovVisual + OFFSET_FOV_MANAGER_VISUAL_CAM);
		WPM<float>(FovCam + OFFSET_FOV_MANAGER_VISUAL_CAM_3RD_PERSON, 0.0);
		WPM<float>(FovCam + OFFSET_FOV_MANAGER_VISUAL_CAM_RENDER, 0.25);
		return 1;
	}

	int unThirdPerson(uint64_t base_address)
	{
		uint64_t FovManager = RPM<uint64_t>(base_address + OFFSET_FOV_MANAGER);
		uint64_t FovVisual = RPM<uint64_t>(FovManager + OFFSET_FOV_MANAGER_VISUAL);
		uint64_t FovCam = RPM<uint64_t>(FovVisual + OFFSET_FOV_MANAGER_VISUAL_CAM);
		WPM<float>(FovCam + OFFSET_FOV_MANAGER_VISUAL_CAM_3RD_PERSON, 1.0f);
		WPM<float>(FovCam + OFFSET_FOV_MANAGER_VISUAL_CAM_RENDER, 0.01f);
		return 1;
	}

	int NoClipGad(uint64_t base_address)
	{
		uint64_t Network = GetNetworkGame(base_address);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_04_X, 0.0);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_04_Y, 0.0);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_04_Z, 0.0);

		return 1;
	}

	int NoClip(uint64_t base_address)
	{
		uint64_t Network = GetNetworkGame(base_address);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_01_X, 0.0);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_02_X, -1.0);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_02_Y, -1.0);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_02_Z, -1.0);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_02_W, -1.0);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_04_X, 0.0);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_04_Y, 0.0);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_04_Z, 0.0);

		return 1;
	}

	int SpottWall(uint64_t base_address)
	{
		uint64_t Network = GetNetworkGame(base_address);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_03_X, -10.0);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_03_Y, -10.0);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_03_W, -10.0);

		return 1;
	}

	int MortePatinho(uint64_t base_address)
	{
		uint64_t Network = GetNetworkGame(base_address);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_ANIMATION_DEATH_02, 1.5);

		return 1;
	}

	int Tornado(uint64_t base_address)
	{
		uint64_t Network = GetNetworkGame(base_address);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_ANIMATION_OBJECTS, -5000.0);

		return 1;
	}

	int NoRecoil(uint64_t base_address)
	{
		uint64_t WeaponConfig = GetWeaponConfig(base_address);

		WPM<float>(WeaponConfig + 0x168, 0.0);
		WPM<float>(WeaponConfig + 0x14C, 0.0);
		WPM<float>(WeaponConfig + 0x15C, 0.0);

		return 1;
	}

	int NoSpread(uint64_t base_address)
	{
		uint64_t WeaponConfig = GetWeaponConfig(base_address);

		WPM<float>(WeaponConfig + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_NS_X, 0.0);

		return 1;
	}

	int SpeedPlayer_1(uint64_t base_address, BYTE Speed)
	{

		uint64_t LocalPlayer = GetLocalPlayer(base_address);

		uint64_t PlayerConfig = RPM<uint64_t>(LocalPlayer + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG);
		uint64_t PlayerProperty = RPM<uint64_t>(PlayerConfig + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY);

		uint64_t PlayerSpeed = RPM<uint64_t>(PlayerProperty + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY_SPEED);
		WPM<int>(PlayerSpeed + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY_SPEED_PLAYER, Speed);

		return 1;
	}

	int SpeedPlayer_2(uint64_t base_address, float Speed)
	{
		uint64_t Network = GetNetworkGame(base_address);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_TIME_X, Speed);

		return 1;
	}

	int SpeedMax(uint64_t base_address)
	{
		SpeedPlayer_1(base_address, 135);
		SpeedPlayer_2(base_address, 2.4f);

		return 1;
	}

	int un_SpeedMax(uint64_t base_address)
	{
		SpeedPlayer_1(base_address, 100);
		SpeedPlayer_2(base_address, 1.6f);

		return 1;
	}

	int GetJumpStyle(uint64_t base_address)
	{
		uint64_t VaultManager = GetVaultManager(base_address);
		int JumpStyle = RPM<int>(VaultManager + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_JUMP_STYLE);

		return JumpStyle;
	}

	int DroneIncreaseJump(uint64_t base_address)
	{
		uint64_t Network = GetNetworkGame(base_address);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_Z, 50.0f);

		Sleep(50);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_Z, 0.6f);


		return 1;
	}

	int FlyTP(uint64_t base_address)
	{
		uint64_t Network = GetNetworkGame(base_address);
		uint64_t VaultManager = GetVaultManager(base_address);

		//WPM<int>(VaultManager + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CtONTAINER_VAULT_MANAGER_FORCE_JUMP_02, 1);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_Z, 105.0f);
		Sleep(75);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_Z, 0.f);
		Sleep(3000);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_Z, 0.6f);

		return 1;
	}

	int DecreaseGravity(uint64_t base_address)
	{
		uint64_t Network = GetNetworkGame(base_address);

		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_Z, 105.0f);
		Sleep(3000);
		WPM<float>(Network + OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_Z, 0.6f);

		return 1;
	}

	int GetDroneState(uint64_t base_address)
	{
		uint64_t GameManager = RPM<uint64_t>(base_address + OFFSET_GAME_MANAGER);
		uint64_t Drone_1 = RPM<uint64_t>(GameManager + OFFSET_GAME_MANAGER_GAME_DRONE_STATE_CHAIN_01);
		uint64_t Drone_2 = RPM<uint64_t>(Drone_1 + OFFSET_GAME_MANAGER_GAME_DRONE_STATE_CHAIN_02);
		uint64_t Drone_3 = RPM<uint64_t>(Drone_2 + OFFSET_GAME_MANAGER_GAME_DRONE_STATE_CHAIN_03);
		int DroneState = RPM<int>(Drone_3 + OFFSET_GAME_MANAGER_GAME_DRONE_STATE_CHAIN_04);

		return DroneState;
	}

	int NoFlash(uint64_t base_address)
	{
		uint64_t LocalPlayer = GetLocalPlayer(base_address);

		uint64_t PlayerConfig = RPM<uint64_t>(LocalPlayer + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG);
		uint64_t PlayerProperty = RPM<uint64_t>(PlayerConfig + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY);

		uint64_t PlayerVisual = RPM<uint64_t>(PlayerProperty + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY_VISUAL);
		WPM<BYTE>(PlayerVisual + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY_VISUAL_NOFLASH, 0);

		return 1;
	}

	int WeaponAuto(uint64_t base_address)
	{
		uint64_t WeaponHelding = GetHoldingWeapon(base_address);

		WPM<int>(WeaponHelding + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_SHOOT_RANGE, 0);

		return 1;
	}

	int NoAnimation(uint64_t base_address)
	{
		uint64_t game_manager = RPM<uint64_t>(base_address + OFFSET_GAME_MANAGER);
		uint64_t GunAnimation01 = RPM<uint64_t>(game_manager + OFFSET_GAME_MANAGER_GUN_ANIMATION_01);
		uint64_t GunAnimation02 = RPM<uint64_t>(GunAnimation01 + OFFSET_GAME_MANAGER_GUN_ANIMATION_01);
		uint64_t GunAnimation03 = RPM<uint64_t>(GunAnimation02 + OFFSET_GAME_MANAGER_GUN_ANIMATION_02);
		uint64_t GunAnimation04 = RPM<uint64_t>(GunAnimation03 + OFFSET_GAME_MANAGER_GUN_ANIMATION_03);
		uint64_t GunAnimation05 = RPM<uint64_t>(GunAnimation04 + OFFSET_GAME_MANAGER_GUN_ANIMATION_04);
		uint64_t GunAnimation06 = RPM<uint64_t>(GunAnimation05 + OFFSET_GAME_MANAGER_GUN_ANIMATION_05);
		uint64_t GunAnimation07 = RPM<uint64_t>(GunAnimation06 + OFFSET_GAME_MANAGER_GUN_ANIMATION_06);

		WPM<int>(GunAnimation07 + OFFSET_GAME_MANAGER_GUN_ANIMATION_07, 0);

		return 1;
	}

	float GetEntityPos_X(uint64_t base_address, int ID)
	{
		uint64_t GameManager = RPM<uint64_t>(base_address + OFFSET_GAME_MANAGER);

		uint64_t EntityList = RPM<uint64_t>(GameManager + OFFSET_GAME_MANAGER_ENTITY);

		uint64_t EntityID = RPM<uint64_t>(EntityList + (OFFSET_GAME_MANAGER_ENTITY_ID * ID));

		uint64_t EntityPos = RPM<uint64_t>(EntityID + OFFSET_GAME_MANAGER_ENTITY_ID_POS);

		return RPM<float>(EntityPos + OFFSET_GAME_MANAGER_ENTITY_ID_POS_X);
	}

	float GetEntityPos_Y(uint64_t base_address, int ID)
	{
		uint64_t GameManager = RPM<uint64_t>(base_address + OFFSET_GAME_MANAGER);

		uint64_t EntityList = RPM<uint64_t>(GameManager + OFFSET_GAME_MANAGER_ENTITY);

		uint64_t EntityID = RPM<uint64_t>(EntityList + (OFFSET_GAME_MANAGER_ENTITY_ID * ID));

		uint64_t EntityPos = RPM<uint64_t>(EntityID + OFFSET_GAME_MANAGER_ENTITY_ID_POS);

		return RPM<float>(EntityPos + OFFSET_GAME_MANAGER_ENTITY_ID_POS_Y);
	}

	float GetEntityPos_Z(uint64_t base_address, int ID)
	{
		uint64_t GameManager = RPM<uint64_t>(base_address + OFFSET_GAME_MANAGER);

		uint64_t EntityList = RPM<uint64_t>(GameManager + OFFSET_GAME_MANAGER_ENTITY);

		uint64_t EntityID = RPM<uint64_t>(EntityList + (OFFSET_GAME_MANAGER_ENTITY_ID * ID));

		uint64_t EntityPos = RPM<uint64_t>(EntityID + OFFSET_GAME_MANAGER_ENTITY_ID_POS);

		return RPM<float>(EntityPos + OFFSET_GAME_MANAGER_ENTITY_ID_POS_Z);
	}


	float GetLastShootPos_X(uint64_t base_address)
	{
		uint64_t WeaponConfig = GetWeaponConfig(base_address);

		float LastShootPos_X = RPM<float>(WeaponConfig + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_LAST_SHOOT_POS_X);

		return LastShootPos_X;
	}
	float GetLastShootPos_Y(uint64_t base_address)
	{
		uint64_t WeaponConfig = GetWeaponConfig(base_address);

		float LastShootPos_Y = RPM<float>(WeaponConfig + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_LAST_SHOOT_POS_Y);

		return LastShootPos_Y;
	}
	float GetLastShootPos_Z(uint64_t base_address)
	{
		uint64_t WeaponConfig = GetWeaponConfig(base_address);

		float LastShootPos_Z = RPM<float>(WeaponConfig + OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_LAST_SHOOT_POS_Z);

		return LastShootPos_Z;
	}

	void TpKnife(uint64_t base_address, float x, float y, float z) {

		uint64_t aa = GetVaultManager(base_address);
		uint64_t LP = GetLocalPlayer(base_address);
		uint64_t pos = RPM<BYTE>(LP + 0x28);
		int x_x = 1;

		while (x_x <= 5000)
		{
			BYTE nowvault = RPM<BYTE>(aa + 0x13F);
			int Style = RPM<int>(aa + 0x140);
			static bool vault25 = true;
			static bool real = true;

			if (vault25)
				WPM<BYTE>((aa + 0xA1), 1);
			if (real) {
				WPM<BYTE>((aa + 0xA1), 1);
				WPM<BYTE>((aa + 0x13F), 1);
				WPM<int>((aa + 0x140), 2);// type
			}
			if (!vault25 && (!nowvault || Style == 0))
				return;

			WPM<BYTE>((aa + 0x140), 2); // type

			//WPM<float>((pos + 0x50), x);
			//WPM<float>((pos + 0x54), y);
			//WPM<float>((pos + 0x58), z);

			WPM<float>((aa + 0x150), x);// funf
			WPM<float>((aa + 0x154), y);// funf
			WPM<float>((aa + 0x158), z);// funf

			WPM<float>((aa + 0x170), x);// funf
			WPM<float>((aa + 0x174), y);// funf
			WPM<float>((aa + 0x178), z);// funf

			//WPM<float>((aa + 0x190), x);// funf
			//WPM<float>((aa + 0x194), y);// funf
			//WPM<float>((aa + 0x198), z);// funf
			x_x += 1;
		}

	}

	void TpToDirection(uint64_t base_address, float x, float y, float z) {

		uint64_t aa = GetVaultManager(base_address);
		uint64_t LP = GetLocalPlayer(base_address);
		uint64_t pos = RPM<BYTE>(LP + 0x28);
		int x_x = 1;
		BYTE type = 3;

		while (x_x <= 5000)
		{
			BYTE nowvault = RPM<BYTE>(aa + 0x13F);
			int Style = RPM<int>(aa + 0x140);
			static bool vault25 = true;
			static bool real = true;

			if (vault25)
				WPM<BYTE>((aa + 0xA1), 1);
			if (real) {
				WPM<BYTE>((aa + 0xA1), 1);
				WPM<BYTE>((aa + 0x13F), 1);
				WPM<int>((aa + 0x140), type);// type
			}
			if (!vault25 && (!nowvault || Style == 0))
				return;

			WPM<BYTE>((aa + 0x140), type); // type

			//WPM<float>((pos + 0x50), x);
			//WPM<float>((pos + 0x54), y);
			//WPM<float>((pos + 0x58), z);

			WPM<float>((aa + 0x150), x);// funf
			WPM<float>((aa + 0x154), y);// funf
			WPM<float>((aa + 0x158), z);// funf

			WPM<float>((aa + 0x170), x);// funf
			WPM<float>((aa + 0x174), y);// funf
			WPM<float>((aa + 0x178), z);// funf

			WPM<float>((aa + 0x190), x);// funf
			WPM<float>((aa + 0x194), y);// funf
			WPM<float>((aa + 0x198), z);// funf

			WPM<float>((aa + 0x1B0), x);// funf
			WPM<float>((aa + 0x1B4), y);// funf
			WPM<float>((aa + 0x1B8), z);// funf

			WPM<float>((aa + 0x1D0), x);// funf
			WPM<float>((aa + 0x1D4), y);// funf
			WPM<float>((aa + 0x1D8), z);// funf

			WPM<float>((aa + 0x1F0), x);// funf
			WPM<float>((aa + 0x1F4), y);// funf
			WPM<float>((aa + 0x1F8), z);// funf

			WPM<float>((aa + 0x210), x);// funf
			WPM<float>((aa + 0x214), y);// funf
			WPM<float>((aa + 0x218), z);// funf

			WPM<float>((aa + 0x230), x);// funf
			WPM<float>((aa + 0x234), y);// funf
			WPM<float>((aa + 0x238), z);// funf

			WPM<float>((aa + 0x250), x);// funf
			WPM<float>((aa + 0x254), y);// funf
			WPM<float>((aa + 0x258), z);// funf

			WPM<float>((aa + 0x270), x);// funf
			WPM<float>((aa + 0x274), y);// funf
			WPM<float>((aa + 0x278), z);// funf

			WPM<float>((aa + 0x290), x);// funf
			WPM<float>((aa + 0x294), y);// funf
			WPM<float>((aa + 0x298), z);// funf

			WPM<float>((aa + 0x2B0), x);// funf
			WPM<float>((aa + 0x2B4), y);// funf
			WPM<float>((aa + 0x2B8), z);// funf

			WPM<float>((aa + 0x2D0), x);// funf
			WPM<float>((aa + 0x2D4), y);// funf
			WPM<float>((aa + 0x2D8), z);// funf

			WPM<float>((aa + 0x2F0), x);// funf
			WPM<float>((aa + 0x2F4), y);// funf
			WPM<float>((aa + 0x2F8), z);// funf

			WPM<float>((aa + 0x310), x);// funf
			WPM<float>((aa + 0x314), y);// funf
			WPM<float>((aa + 0x318), z);// funf

			WPM<float>((aa + 0x330), x);// funf
			WPM<float>((aa + 0x334), y);// funf
			WPM<float>((aa + 0x338), z);// funf
			x_x += 1;
		}

	}

	int Ataque(uint64_t base_address)
	{
		uint64_t game_manager = RPM<uint64_t>(base_address + OFFSET_GAME_MANAGER);

		WPM<int>(game_manager + OFFSET_GAME_MANAGER_GAME_INFORMATION_TEAM_GAME, 4);

		return 1;
	}

	int Defesa(uint64_t base_address)
	{
		uint64_t game_manager = RPM<uint64_t>(base_address + OFFSET_GAME_MANAGER);

		WPM<int>(game_manager + OFFSET_GAME_MANAGER_GAME_INFORMATION_TEAM_GAME, 3);

		return 1;
	}

	void freeze_lobby(uint64_t base_address)
	{
		uint64_t freezegame = RPM<uint64_t>(base_address + OFFSET_SETTINGS_GAME);

		WPM<int>(freezegame + 0x5C, 1);
	}

	void un_freeze_lobby(uint64_t base_address)
	{
		uint64_t freezegame = RPM<uint64_t>(base_address + OFFSET_SETTINGS_GAME);

		WPM<int>(freezegame + 0x5C, 0);
	}
}

