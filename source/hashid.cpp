#include "GarrysMod/Lua/Interface.h"
using namespace GarrysMod::Lua;
constexpr const char* message =
" _____                                                                                    _____ \n"
"( ___ )----------------------------------------------------------------------------------( ___ )\n"
" |   |                                                                                    |   | \n"
" |   | $$$$$$$\\                  $$\\     $$\\ $$\\       $$\\           $$$$$$$\\  $$\\   $$\\  |   | \n"
" |   | $$  __$$\\                 \\$$\\   $$  |\\__|      $$ |          $$  __$$\\ $$$\\  $$ | |   | \n"
" |   | $$ |  $$ |$$\\   $$\\        \\$$\\ $$  / $$\\  $$$$$$$ | $$$$$$\\  $$ |  $$ |$$$$\\ $$ | |   | \n"
" |   | $$$$$$$\\ |$$ |  $$ |        \\$$$$  /  $$ |$$  __$$ |$$  __$$\\ $$$$$$$\\ |$$ $$\\$$ | |   | \n"
" |   | $$  __$$\\ $$ |  $$ |         \\$$  /   $$ |$$ /  $$ |$$$$$$$$ |$$  __$$\\ $$ \\$$$$ | |   | \n"
" |   | $$ |  $$ |$$ |  $$ |          $$ |    $$ |$$ |  $$ |$$   ____|$$ |  $$ |$$ |\\$$$ | |   | \n"
" |   | $$$$$$$  |\\$$$$$$$ |          $$ |    $$ |\\$$$$$$$ |\\$$$$$$$\\ $$$$$$$  |$$ | \\$$ | |   | \n"
" |   | \\_______/  \\____$$ |          \\__|    \\__| \\_______| \\_______|\\_______/ \\__|  \\__| |   | \n"
" |   |           $$\\   $$ |                                                               |   | \n"
" |   |           \\$$$$$$  |                                                               |   | \n"
" |   |            \\______/                                                                |   | \n"
" |___|                                                                                    |___| \n"
"(_____)----------------------------------------------------------------------------------(_____)\n"
"\n[!] HashID Module Initialized!";
#ifdef _WIN32
	#include <windows.h>
#else
	#include <fstream>
	#include <string>
#endif
LUA_FUNCTION(GetHashID)
{
	const char* id = "";
#ifdef _WIN32
	// Windows
	HW_PROFILE_INFO hw;
	if (GetCurrentHwProfile(&hw)) {
		id = hw.szHwProfileGuid;
	}
#else
	// Linux
	std::ifstream file("/etc/machine-id");
	if (file.is_open()) {
		static std::string id_str;
		std::getline(file, id_str);
		if (!id_str.empty()) {
			id = id_str.c_str();
		}
	}
#endif

	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	LUA->GetField(-1, "util");
	LUA->GetField(-1, "SHA256");
	LUA->PushString(id);
	LUA->Call(1, 1);
	const char* hash = LUA->GetString(-1);
	LUA->Pop(3);
	LUA->PushString(hash);
	return 1;
}

GMOD_MODULE_OPEN()
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);

	LUA->GetField(-1, "print");
	LUA->PushString(message);
	LUA->Call(1, 0);

	LUA->PushString("GetHashID");
	LUA->PushCFunction(GetHashID);
	LUA->SetTable(-3);
	return 0;
}


GMOD_MODULE_CLOSE()
{
	return 0;
}