// MathLibrary.h - Contains declarations of math functions
#pragma once

#ifdef PROCESS_EXPORTS
#define PROCESS_API __declspec(dllexport)
#else
#define PROCESS_API __declspec(dllimport)
#endif

// Must have DSR running before calling
extern "C" PROCESS_API int dsr_init();

// Player functions
extern "C" PROCESS_API void dsr_player_godmode();
extern "C" PROCESS_API void dsr_player_setsouls(int souls);
extern "C" PROCESS_API void dsr_player_sethumanity(int humanities);

// Equipment functions
extern "C" PROCESS_API void dsr_equipment_righthand(int weapon_id);

// Item functions