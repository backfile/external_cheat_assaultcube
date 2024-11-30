#include "./features/godmode.h"
#include "./features/balas_infinitas.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "1-Vida infinita" << endl;
	cout << "2-Balas infinitas" <<endl;
	int rta;
	cin >> rta;
	while(rta != 0){
		if(rta == 1){
			godmode();
		}
		if(rta == 2){
			balas_infinitas();
		}
		cout << "1-Vida infinita" << endl;
		cout << "2-Balas infinitas" <<endl;
		cin >> rta;
	}
	
	return 0;
}
