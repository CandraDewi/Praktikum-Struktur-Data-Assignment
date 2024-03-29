#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> data;
    int num;

    //Meminta inputan sebanyak 10 data array kepada user
    cout << "Masukkan 10 data array:\n";

    //meminta input sebanyak 10 kali dan menyimpan input tersebut ke dalam vektor 'data'.
    for (int i = 0; i < 10; i++) {
        cin >> num;
        data.push_back(num);
    }

    //memisahkan elemen array yang terdapat dalam vektor data menjadi genap dan ganjil
    vector<int> genap, ganjil;

    for (int i = 0; i < data.size(); i++) {
        if (data[i] % 2 == 0) {
            genap.push_back(data[i]);
        } else {
            ganjil.push_back(data[i]);
        }
    }

    //Menampilkan data array yang diinputkan user di awal
    cout << "Data array: ";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    //menampilkan nomor genap hasil pemisahan dari vektor data
    cout << "Nomor genap: ";
    for (int i = 0; i < genap.size(); i++) {
        cout << genap[i];
        if (i < genap.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    //menampilkan nomor ganjil hasil pemisahan dari vektor data
    cout << "Nomor ganjil: ";
    for (int i = 0; i < ganjil.size(); i++) {
        cout << ganjil[i];
        if (i < ganjil.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
