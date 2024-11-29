#include "./memory.h"
#include "./offset.h"
#include <iostream>

int main()
{
	Memory memory("ac_client.exe");
	const auto moduleBase = memory.GetModuleAddress("ac_client.exe");
	const auto localPlayerPtr = memory.Read<std::uintptr_t>(moduleBase + localPlayer);
	const auto healthAddress = localPlayerPtr + m_iHealth;
	
	const int newHealth = 99999;
	memory.Write<int>(healthAddress, newHealth);
	std::cout << "Cambiada con exito";
	return 0;
}
