#include "pch.h"
#include "Process.h"
#include "memoryinterface.h"
#include "memory.h"
#include "offsets.h"
#include "weapons.h"

static uintptr_t base_address = 0;
static Weapon weapons;

int dsr_init()
{
    base_address = memory.GetModuleAddress("DarkSoulsRemastered.exe");
	if (!base_address)
	{
		return -1;
	}
	return 0;
}

// Player functions
void dsr_player_godmode()
{
	int new_health = 999999999;

	const auto local_player_maxhp_ptr = memory.Read<std::uintptr_t>(base_address + offset::local_player_currency);
	const auto max_health_address = local_player_maxhp_ptr + offset::player_max_health;

	const auto local_player_ptr = memory.Read<std::uintptr_t>(base_address + offset::local_player);
	const std::uintptr_t health_temp_1 = local_player_ptr + offset::current_health_player_offset1;
	const auto health_address = memory.Read<std::uintptr_t>(health_temp_1) + offset::current_health_player_offset2;

	memory.Write<int>(max_health_address, new_health);
	memory.Write<int>(health_address, new_health);
}

void dsr_player_setsouls(int souls)
{
	// 999999999 is the max number of souls handled by the game by default.
	souls = (souls > 999999999)
		? 999999999
		: souls;

	const auto local_plr_currency = memory.Read<std::uintptr_t>(base_address + offset::local_player_currency);
	const auto souls_address = local_plr_currency + offset::souls;

	memory.Write<int>(souls_address, souls);
}

void dsr_player_sethumanity(int humanities)
{
	// 99 is the max number of humanity per player handled by the game by default.
	humanities = (humanities > 99)
		? 99
		: humanities;

	const auto local_plr_currency = memory.Read<std::uintptr_t>(base_address + offset::local_player_currency);
	const auto humanities_address = local_plr_currency + offset::humanities;

	memory.Write<int>(humanities_address, humanities);
}

// Equipment
void dsr_equipment_righthand(int weapon_id)
{
	const auto local_player_ptr = memory.Read<std::uintptr_t>(base_address + offset::local_player_currency);
	const std::uintptr_t weapon_temp = memory.Read<std::uintptr_t>(local_player_ptr + offset::right_weapon_offset1);
	const auto weapon_address = weapon_temp + offset::right_weapon_offset2;

	memory.Write<int>(weapon_address, weapons.small_to_true(weapon_id));
}

// Items
