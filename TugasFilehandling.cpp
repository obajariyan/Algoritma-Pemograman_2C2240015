#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    double a, b, c;
    double discriminant, x1, x2;
    
    // Meminta input koefisien a, b, dan c
    cout << "Masukkan koefisien a, b, dan c untuk persamaan ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;

    // Validasi jika a = 0
    if (a == 0) {
        cout << "Bukan persamaan kuadrat karena koefisien a = 0" << endl;
        return 0;
    }

    // Menghitung diskriminan
    discriminant = b * b - 4 * a * c;

    // Memeriksa nilai diskriminan
    if (discriminant > 0) {
        // Dua akar real berbeda
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        // Menyimpan hasil ke dalam file
        ofstream outfile("hasil_persamaan.txt");
        if (outfile.is_open()) {
            outfile << "Akar persamaan: x1 = " << x1 << ", x2 = " << x2 << endl;
            outfile.close();
            cout << "Hasil perhitungan berhasil disimpan ke dalam file 'hasil_persamaan.txt'" << endl;
        } else {
            cout << "Gagal membuka file untuk menulis hasil." << endl;
        }
    } else if (discriminant == 0) {
        // Satu akar real
        x1 = -b / (2 * a);

        // Menyimpan hasil ke dalam file
        ofstream outfile("hasil_persamaan.txt");
        if (outfile.is_open()) {
            outfile << "Akar persamaan: x1 = x2 = " << x1 << endl;
            outfile.close();
            cout << "Hasil perhitungan berhasil disimpan ke dalam file 'hasil_persamaan.txt'" << endl;
        } else {
            cout << "Gagal membuka file untuk menulis hasil." << endl;
        }
    } else {
        // Tidak ada akar real
        ofstream outfile("hasil_persamaan.txt");
        if (outfile.is_open()) {
            outfile << "Persamaan tidak memiliki akar real." << endl;
            outfile.close();
            cout << "Hasil perhitungan berhasil disimpan ke dalam file 'hasil_persamaan.txt'" << endl;
        } else {
            cout << "Gagal membuka file untuk menulis hasil." << endl;
        }
    }

    return 0;
}
