#include <iostream>
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
    vector<string> pintu = {"Cikampek", "Sadang", "Padalarang", "Cileunyi", "Pasteur"};

    int golongan_kendaraan, jenis_kendaraan, pintu_masuktol, pintu_keluartol;
    float saldo, jarak = 0, gol = 0;

    cout << "=============================================" << endl;
    cout << "\u263A SELAMAT DATANG \u263A" << endl;
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
        if (pintu_keluartol == 2) jarak = 17.4;
        else if (pintu_keluartol == 3) jarak = 66;
        else if (pintu_keluartol == 4) jarak = 98.1;
        else jarak = 75.9;
    } else if (pintu_masuktol == 2) {
        if (pintu_keluartol == 1) jarak = 41.0;
        else if (pintu_keluartol == 3 || pintu_keluartol == 4) jarak = 65.6;
        else jarak = 17.5;
    } else if (pintu_masuktol == 3) {
        if (pintu_keluartol == 1) jarak = 87.8;
        else if (pintu_keluartol == 2) jarak = 50.3;
        else if (pintu_keluartol == 4) jarak = 21.7;
        else jarak = 17.5;
    } else if (pintu_masuktol == 4) {
        if (pintu_keluartol == 1) jarak = 121.4;
        else if (pintu_keluartol == 2) jarak = 87.2;
        else if (pintu_keluartol == 3) jarak = 20.1;
        else jarak = 39.2;
    } else {
        if (pintu_keluartol == 1) jarak = 97.1;
        else if (pintu_keluartol == 2) jarak = 62.8;
        else jarak = 18.0;
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

    if (saldo >= harga) {
        saldo -= harga;
        cout << "Sisa saldo Anda: Rp " << saldo << endl;
    } else {
        cout << "Saldo Anda tidak mencukupi!" << endl;
    }

    cout << "=============================================" << endl;
    return 0;
}
