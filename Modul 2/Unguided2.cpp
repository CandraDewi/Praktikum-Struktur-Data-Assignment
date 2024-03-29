#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, y, z;

    cout << "Masukkan ukuran array tiga dimensi (x y z): ";
    cin >> x >> y >> z;

    // Membuat array tiga dimensi dengan ukuran yang diinputkan
    vector<vector<vector<int>>> array3D(x, vector<vector<int>>(y, vector<int>(z)));

    // Input elemen array tiga dimensi
    cout << "Masukkan elemen array tiga dimensi:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Masukkan elemen array[" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    // Menampilkan elemen array tiga dimensi dalam format matriks
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << array3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
