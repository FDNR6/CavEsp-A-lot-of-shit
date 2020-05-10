#pragma once

// ------------------------- Section Base Address -------------------------

#define OFFSET_GAME_MANAGER		0x53a6868
#define OFFSET_NETWORK_MANAGER	0x5393ac0
#define OFFSET_GLOW_MANAGER		0x6089468
#define OFFSET_FOV_MANAGER		0x53a6860
#define OFFSET_ROUND_MANAGER	0x5396138
#define OFFSET_PROFILE_MANAGER	0x5393ae8
#define OFFSET_SETTINGS_GAME	0x538fc90
#define OFFSET_V_TABLE			0x3a87220

// ------------------------- Section Game Manager -------------------------

#define OFFSET_GAME_MANAGER_GAME_INFORMATION_TEAM_GAME 0x310
#define OFFSET_GAME_MANAGER_GAME_INFORMATION_ENTITY_COUNT 0xD0

#define OFFSET_GAME_MANAGER_ENTITY 0xC8 // Pointer
#define OFFSET_GAME_MANAGER_ENTITY_ID 0x8 // Pointer

#define OFFSET_GAME_MANAGER_ENTITY_ID_TEAM_CHAIN_01 0xC8 // Pointer
#define OFFSET_GAME_MANAGER_ENTITY_ID_TEAM_CHAIN_02 0x88 // Pointer
#define OFFSET_GAME_MANAGER_ENTITY_ID_TEAM_CHAIN_03 0x30

#define OFFSET_GAME_MANAGER_ENTITY_ID_HEALTHY_CHAIN_01 0x28 // Pointer
#define OFFSET_GAME_MANAGER_ENTITY_ID_HEALTHY_CHAIN_02 0xD8 // Pointer
#define OFFSET_GAME_MANAGER_ENTITY_ID_HEALTHY_CHAIN_03 0x8 // Pointer
#define OFFSET_GAME_MANAGER_ENTITY_ID_HEALTHY_CHAIN_04 0x168

#define OFFSET_GAME_MANAGER_ENTITY_ID_POS 0x28 // Pointer
#define OFFSET_GAME_MANAGER_ENTITY_ID_POS_X 0x50
#define OFFSET_GAME_MANAGER_ENTITY_ID_POS_Y 0x54
#define OFFSET_GAME_MANAGER_ENTITY_ID_POS_Z 0x58

#define OFFSET_GAME_MANAGER_GAME_DRONE_STATE_CHAIN_01 0x140 // Pointer
#define OFFSET_GAME_MANAGER_GAME_DRONE_STATE_CHAIN_02 0xD8 // Pointer
#define OFFSET_GAME_MANAGER_GAME_DRONE_STATE_CHAIN_03 0x60 // Pointer
#define OFFSET_GAME_MANAGER_GAME_DRONE_STATE_CHAIN_04 0x3C8

#define OFFSET_GAME_MANAGER_GUN_ANIMATION_01 0x38 // Pointer
#define OFFSET_GAME_MANAGER_GUN_ANIMATION_02 0xC8 // Pointer
#define OFFSET_GAME_MANAGER_GUN_ANIMATION_03 0x0 // Pointer
#define OFFSET_GAME_MANAGER_GUN_ANIMATION_04 0x90 // Pointer
#define OFFSET_GAME_MANAGER_GUN_ANIMATION_05 0x118 // Pointer
#define OFFSET_GAME_MANAGER_GUN_ANIMATION_06 0xc8 // Pointer
#define OFFSET_GAME_MANAGER_GUN_ANIMATION_07 0x368

#define OFFSET_GAME_MANAGER_PARTY 0x20 // Pointer
#define OFFSET_GAME_MANAGER_PARTY_DETAILS 0x260 // Pointer
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME 0x50 // Pointer
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO 0x0 // Pointer
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO_STATE 0x128
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO_POINTS_X 0x134
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO_POINTS_Y 0x154
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO_KILLS_X 0x138
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO_KILLS_Y 0x144
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO_KILLS_Z 0x170
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO_DEATH 0x148
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO_SUPORT 0x14C
#define OFFSET_GAME_MANAGER_PARTY_DETAILS_GAME_INFO_PING 0x168

// ------------------------- Section Network Manager -------------------------

#define OFFSET_NETWORK_MANAGER_CONNECTION 0xF8 // Pointer
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME 0x8 // Pointer

#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_01_X 0x76C // Write (0) Normal

#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_02_X 0x7F0 // Write (-1) Normal
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_02_Y 0x7F4 // Write (-1) Normal
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_02_Z 0x7F8 // Write (-1) Normal
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_02_W 0x7FC // Write (-1) Normal

#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_03_X 0x800 // Write (-2) No Collision Walls
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_03_Y 0x804 // Write (-2) No Collision Walls
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_03_Z 0x808 // Write (-2) No Collision Walls
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_03_W 0x80C // Write (-2) No Collision Walls

#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_04_X 0x560 // Write (0) No Collision Gadg
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_04_Y 0x564 // Write (0) No Collision Gadg
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_NOCLIP_04_Z 0x568 // Write (0) No Collision Gadg

#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_X 0x870
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_Y 0x874
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_SPACE_Z 0x878

#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_TIME_X 0x880
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_TIME_Y 0x884
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_TIME_Z 0x888

#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_ANIMATION_DEATH_01 0x750 // Write (0)
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_ANIMATION_DEATH_02 0x760 // Write (1.5)
#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_ANIMATION_DEATH_03 0x8B0 // Write (-1) or (0)

#define OFFSET_NETWORK_MANAGER_CONNECTION_GAME_ANIMATION_OBJECTS 0x8BC // Write (negative num)

// ------------------------- Section Glow Manager -------------------------

#define OFFSET_GLOW_MANAGER_AREA 0xB8 // Pointer

#define OFFSET_GLOW_MANAGER_AREA_RED 0xD0
#define OFFSET_GLOW_MANAGER_AREA_GREEN 0xD4
#define OFFSET_GLOW_MANAGER_AREA_BLUE 0xD8

#define OFFSET_GLOW_MANAGER_AREA_DISTANCE_X 0x110
#define OFFSET_GLOW_MANAGER_AREA_DISTANCE_Y 0x114
#define OFFSET_GLOW_MANAGER_AREA_DISTANCE_Z 0x118

#define OFFSET_GLOW_MANAGER_AREA_OPACITY 0x11C

#define OFFSET_GLOW_MANAGER_AREA_ILUMINATION 0x120

// ------------------------- Section Fov Manager -------------------------

#define OFFSET_FOV_MANAGER_VISUAL 0x28 // Pointer
#define OFFSET_FOV_MANAGER_VISUAL_CAM 0x0 // Pointer

#define OFFSET_FOV_MANAGER_VISUAL_CAM_FOV_MAP 0x38
#define OFFSET_FOV_MANAGER_VISUAL_CAM_FOV_GUN 0x3C

#define OFFSET_FOV_MANAGER_VISUAL_CAM_3RD_PERSON 0x48 // Write (0)

#define OFFSET_FOV_MANAGER_VISUAL_CAM_RENDER 0x4C

#define OFFSET_FOV_MANAGER_NR 0x110 // Pointer
#define OFFSET_FOV_MANAGER_NR_LOCAL 0x0 // Pointer
#define OFFSET_FOV_MANAGER_NR_LOCAL_PERMISSION 0xE2D

// ------------------------- Section Game Profile -------------------------

// ------------------------- Section Round Manager -------------------------

#define OFFSET_ROUND_MANAGER_STATE 0x2E8 // offdate
#define OFFSET_ROUND_MANAGER_TEAM 0x310

// ------------------------- Section Profile Manager -------------------------

#define OFFSET_PROFILE_MANAGER_LOCAL 0x68 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER 0x0 // Pointer

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER 0x28 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_LEVEL 0x5C0
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CREDIBILIDADE 0x5CC
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CREDITO 0x5D0

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON 0x90 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING 0xC8 // Pointer

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_SHOOT_RANGE 0x108
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_MAGAZINE_AMMO 0x10C
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_EXTRA_MAGAZINE_AMMO 0x110
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG 0x278 // Pointer

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_NR_X 0xF4 // Always Write (0)
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_NR_Y 0xF8 // Always Write (0)

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_NS_X 0x38

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_LAST_SHOOT_POS_X 0x80
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_LAST_SHOOT_POS_Y 0x84
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_LAST_SHOOT_POS_Z 0x88

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_GUN_POS_X 0xA0
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_GUN_POS_Y 0xA4
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_GUN_POS_Z 0xA8

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_SILENT_ANGLE_X 0x118
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_SILENT_ANGLE_Y 0x11C
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_WEAPON_HOLDING_CONFIG_SILENT_ANGLE_Z 0x120

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT 0x90 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER 0x148 // Pointer

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_JUMP_STYLE 0x140 // Write (3)

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_FORCE_JUMP_01 0x13F // Write (1)
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_FORCE_JUMP_02 0xA1 // Write (1)
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_FORCE_JUMP_03 0xA3 // Write (1) Op
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_FORCE_JUMP_04 0xA4 // Write (1) Op

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_01_X 0x120
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_01_Y 0x124
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_01_Z 0x128

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_02_X 0x150
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_02_Y 0x154
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_02_Z 0x158

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_03_X 0x170
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_03_Y 0x174
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_03_Z 0x178

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_04_X 0x190
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_04_Y 0x194
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_VAULT_MANAGER_POS_JUMP_04_Z 0x198

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG 0x30 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY 0x30 // Pointer

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY_VISUAL 0x28 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY_VISUAL_NOFLASH 0x40

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY_SPEED 0x38 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_CONFIG_PROPERTY_SPEED_PLAYER 0x58

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_TEAM_CAHIN_01 0xC8 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_TEAM_CAHIN_02 0x88 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_TEAM_CAHIN_03 0x30

#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_HEALTHY_CAHIN_01 0x28 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_HEALTHY_CAHIN_02 0xD8 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_HEALTHY_CAHIN_03 0x8 // Pointer
#define OFFSET_PROFILE_MANAGER_LOCAL_PLAYER_CONTAINER_HEALTHY_CAHIN_04 0x168