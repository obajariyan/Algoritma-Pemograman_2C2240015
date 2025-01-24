#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Fungsi untuk menampilkan pilihan
void pilihan(const vector<string> &pil) {
    for (size_t i = 0; i < pil.size(); i++) {
        cout << "[" << i + 1 << "] " << pil[i] << endl;
    }
    cout << "Tuliskan angka pilihan Anda: ";
}

// Fungsi untuk menghitung harga berdasarkan jarak dan golongan kendaraan
float hargatol(float jarak, float gol) {
    return (jarak * 500) + (gol * 1000);
}

int main() {
    vector<string> golongan = {"Gol I", "Gol II", "Gol III", "Gol IV", "Gol V"};
    vector<string> kendaraan = {"Sedan", "Jip", "Bus"};
    vector<string> pintu = {"Padalarang", "Baros", "Pasteur", "Moh.Toha", "Cileunyi"};

    int golongan_kendaraan, jenis_kendaraan, pintu_masuktol, pintu_keluartol;
    float saldo, jarak = 0, gol = 0;

    ofstream fileOutput("rincian_perjalanan.txt", ios::app); // Membuka file dalam mode append
    if (!fileOutput.is_open()) {
        cerr << "Gagal membuka file untuk menyimpan hasil." << endl;
        return 1;
    }

    cout << "============================================= "<< endl;
    cout << "                SELAMAT DATANG                "<< endl;
    cout << "                DI RUAS JALAN                 "<< endl;
    cout << "                TOL PADALEUNYI                "<< endl;                        
    cout << "=============================================" << endl;

    // A. Meminta user memilih golongan kendaraan
    cout << "\nSilakan Pilih Golongan Kendaraan Anda" << endl;
    pilihan(golongan);
    cin >> golongan_kendaraan;

    while (golongan_kendaraan < 1 || golongan_kendaraan > 5) {
        cout << "Silakan input angka antara 1 sampai 5: ";
        cin >> golongan_kendaraan;
    }

    if (golongan_kendaraan == 1) {
        cout << "\nPilih Jenis Kendaraan Anda" << endl;
        pilihan(kendaraan);
        cin >> jenis_kendaraan;

        while (jenis_kendaraan < 1 || jenis_kendaraan > 3) {
            cout << "Silakan input angka antara 1 sampai 3: ";
            cin >> jenis_kendaraan;
        }
    }

    // B. Meminta user memilih pintu masuk tol
    cout << "\nSilakan Pilih Pintu Masuk Tol" << endl;
    pilihan(pintu);
    cin >> pintu_masuktol;

    while (pintu_masuktol < 1 || pintu_masuktol > 5) {
        cout << "Silakan input angka antara 1 sampai 5: ";
        cin >> pintu_masuktol;
    }

    // C. Meminta user memilih pintu keluar tol
    cout << "\nSilakan Pilih Pintu Keluar Tol" << endl;
    pilihan(pintu);
    cin >> pintu_keluartol;

    while (pintu_keluartol < 1 || pintu_keluartol > 5 || pintu_keluartol == pintu_masuktol) {
        cout << "Pilih pintu keluar tol yang berbeda: ";
        cin >> pintu_keluartol;
    }

    // D. Meminta user memasukan saldo E-Tol
    cout << "\nSilakan masukkan saldo E-Tol Anda: ";
    cin >> saldo;

    // E. Menentukan jarak berdasarkan pintu masuk dan pintu keluar tol
    if (pintu_masuktol == 1) {
        if (pintu_keluartol == 2) jarak = 8.5;
        else if (pintu_keluartol == 3) jarak = 12;
        else if (pintu_keluartol == 4) jarak = 20;
        else jarak = 39;
    } else if (pintu_masuktol == 2) {
        if (pintu_keluartol == 1) jarak = 8.2;
        else if (pintu_keluartol == 3) jarak = 4.2;
        else if (pintu_keluartol == 4) jarak = 14;
        else jarak = 33;
    } else if (pintu_masuktol == 3) {
        if (pintu_keluartol == 1) jarak = 13.8;
        else if (pintu_keluartol == 2) jarak = 4.5;
        else if (pintu_keluartol == 4) jarak = 17;
        else jarak = 36;
    } else if (pintu_masuktol == 4) {
        if (pintu_keluartol == 1) jarak = 23.3;
        else if (pintu_keluartol == 2) jarak = 14.5;
        else if (pintu_keluartol == 3) jarak = 22;
        else jarak = 21;
    } else if (pintu_masuktol == 5) {
        if (pintu_keluartol == 1) jarak = 39;
        else if (pintu_keluartol == 2) jarak = 35;
        else if (pintu_keluartol == 3) jarak = 38;
        else jarak = 22;
    }

    // F. Menentukan harga berdasarkan golongan kendaraan dan jarak
    if (golongan_kendaraan == 1) {
        if (jenis_kendaraan == 1) gol = 1.1;
        else if (jenis_kendaraan == 2) gol = 1.2;
        else gol = 1.3;
    } else if (golongan_kendaraan == 2) {
        gol = 2;
    } else if (golongan_kendaraan == 3) {
        gol = 3;
    } else if (golongan_kendaraan == 4) {
        gol = 4;
    } else {
        gol = 5;
    }

    float harga = hargatol(jarak, gol);
    cout << fixed << setprecision(2);
    cout << "\n=============================================" << endl;
    cout << "Rincian Perjalanan" << endl;
    cout << "Dari: " << pintu[pintu_masuktol - 1] << endl;
    cout << "Ke: " << pintu[pintu_keluartol - 1] << endl;
    cout << "Jarak: " << jarak << " km" << endl;
    cout << "Harga: Rp " << harga << endl;

    fileOutput << fixed << setprecision(2);
    fileOutput << "\n=============================================" << endl;
    fileOutput << "Rincian Perjalanan" << endl;
    fileOutput << "Dari: " << pintu[pintu_masuktol - 1] << endl;
    fileOutput << "Ke: " << pintu[pintu_keluartol - 1] << endl;
    fileOutput << "Jarak: " << jarak << " km" << endl;
    fileOutput << "Harga: Rp " << harga << endl;

    if (saldo >= harga) {
        saldo -= harga;
        cout << "Sisa saldo Anda: Rp " << saldo << endl;
        fileOutput << "Sisa saldo Anda: Rp " << saldo << endl;
    } else {
        cout << "Saldo Anda tidak mencukupi!" << endl;
        fileOutput << "Saldo Anda tidak mencukupi!" << endl;
    }

    cout << "=============================================" << endl;
    fileOutput << "=============================================" << endl;
    fileOutput.close();

    return 0;
}
