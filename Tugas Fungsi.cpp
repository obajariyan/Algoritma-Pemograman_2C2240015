#include <iostream>

using namespace std;

int fungsiF(int x) {
    return x * x - 2 * x + 5;
}

int main() {
    int A, B;

    cout << "Masukan Nilai Awal: " << endl;
    cin >> A;
    cout << "Masukan Nilai Akhir: " << endl;
    cin >> B;

    for (int x = A; x <= B; ++x) {
        cout << "f(" << x <<") = " << fungsiF(x) << endl;
    }



    return 0;
}
