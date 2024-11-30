#include "../utils/offset.h"
#include "../utils/memory.h"
#include <iostream>

void balas_infinitas(){
	Memory memory("ac_client.exe");
	const auto moduleBase = memory.GetModuleAddress("ac_client.exe");
	const auto localPlayerPtr = memory.Read<std::uintptr_t>(moduleBase + localPlayer);
	const auto BalasAddress = localPlayerPtr + m_Balas;
	const auto BalasPistolaAddress = localPlayerPtr + m_Balas_Pistola;
	const int newBalas = 99999;
	memory.Write<int>(BalasAddress, newBalas);
	memory.Write<int>(BalasPistolaAddress, newBalas);
	std::cout << "Cambiada con exito";
}

