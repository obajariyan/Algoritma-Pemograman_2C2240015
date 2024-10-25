#include <iostream>

using namespace std;

int main () {
	int nilai_awal, nilai_akhir;
	
	//meminta input dari user
	cout << "masukan nilai awal : ";
	cin >> nilai_awal;
	cout << "masukan nilai akhir : ";
	cin >> nilai_akhir;
	
	//perulangan dari nilai hingga nilai akhir
	for (int i = nilai_awal; i <= nilai_akhir; i++) {
		cout << i << ". classyscience.iu" << endl;
		
	}
	
	return 0;
}