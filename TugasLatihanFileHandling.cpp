#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
    double a, b, c, D, x1, x2;

    // Meminta input dari pengguna untuk koefisien a, b, c
    cout << "Masukkan koefisien a, b, dan c untuk persamaan ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;

    // Validasi jika a = 0, maka bukan persamaan kuadrat
    if (a == 0) {
        cout << "Persamaan ini bukan persamaan kuadrat karena a = 0." << endl;
        return 0;
    }

    // Menghitung diskriminan
    D = b * b - 4 * a * c;

    // Membuka file untuk menyimpan hasil
    ofstream file("hasil_persamaan.txt");

    if (!file) {
        cout << "Error membuka file." << endl;
        return 1;
    }

    // Mengecek nilai diskriminan
    if (D > 0) {
        // Dua akar real berbeda
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        file << "Akar persamaan: x1 = " << x1 << ", x2 = " << x2 << endl;
        cout << "Akar persamaan telah disimpan di hasil_persamaan.txt." << endl;
    }
    else if (D == 0) {
        // Satu akar real
        x1 = -b / (2 * a);
        file << "Akar persamaan: x1 = " << x1 << endl;
        cout << "Akar persamaan telah disimpan di hasil_persamaan.txt." << endl;
    }
    else {
        // Tidak ada akar real
        file << "Persamaan kuadrat tidak memiliki akar real." << endl;
        cout << "Persamaan tidak memiliki akar real, hasil disimpan di hasil_persamaan.txt." << endl;
    }

    // Menutup file setelah selesai
    file.close();

    return 0;
}
