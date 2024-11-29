#include "./memory.h"
#include "./offset.h"
#include <iostream>

using namespace std;

int main()
{
	Memory memory("ac_client.exe");
	cout << "1-Vida infinita" << endl;
	cout << "2-Balas infinitas" <<endl;
	int rta;
	cin >> rta;
	while(rta != 0){
		
		const auto moduleBase = memory.GetModuleAddress("ac_client.exe");
		const auto localPlayerPtr = memory.Read<std::uintptr_t>(moduleBase + localPlayer);
		if(rta == 1){
			const auto healthAddress = localPlayerPtr + m_iHealth;
			const int newHealth = 99999;
			memory.Write<int>(healthAddress, newHealth);
			cout << "Cambiada con exito";
		}
		if(rta == 2){
			const auto balasAddress = localPlayerPtr + m_Balas;
			const auto balasPistolAddress = localPlayerPtr + m_Balas_Pistola;
			const int newBalas = 100000;
			memory.Write<int>(balasAddress, newBalas);
			memory.Write<int>(balasPistolAddress, newBalas);
		}
		cout << "1-Vida infinita" << endl;
		cout << "2-Balas infinitas" <<endl;
		cin >> rta;
	}
	
	return 0;
}
