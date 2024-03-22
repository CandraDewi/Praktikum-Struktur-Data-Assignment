#include <iostream>
using namespace std;

int main() {
    int maks, a, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;

    if (a <= 0) {
        cout << "Panjang array harus lebih besar dari 0." << endl;
        return 1;
    }

    int array[a];
    cout << "Masukkan " << a << " angka\n";

    for (int i=0; i<a; i++) {
        cout << "Array ke-" << (i+1) << ": ";
        cin >> array[i];
    }

    maks = array[0];
    lokasi = 0;

    for (int i=1; i<a; i++) {
        if (array[i] > maks) {
            maks = array[i];
            lokasi = i;
        }
    }

    cout << "Nilai maksimum adalah " << maks << " berada di array ke " << (lokasi + 1) << endl;
    return 0;
}
