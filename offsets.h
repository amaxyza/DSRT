#pragma once

#include <stdint.h>

// local player offset
namespace offset
{
	constexpr auto local_player = 0x01C77E50;
	constexpr auto local_player_currency = 0x1C8A530;
	constexpr auto local_player_inventory = 0x01C7A0C8;

	constexpr auto current_health_player_offset1 = 0x68;
	constexpr auto current_health_player_offset2 = 0x3E8;

	constexpr auto player_max_health = 0xD2C;
	constexpr auto souls = 0xDA4;
	constexpr auto humanities = 0xD94;

	constexpr auto titanite_shard_offset1 = 0x70;
	constexpr auto titanite_shard_offset2 = 0x84;
	constexpr auto titanite_shard_offset3 = 0x08;

	constexpr auto right_weapon_offset1 = 0x08;
	constexpr auto right_weapon_offset2 = 0xF38;
}