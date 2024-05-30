//A.A Istri Candra Manika Dewi
//2311110026

#include <iostream>
using namespace std;

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    // Langkah rekursif: faktorial(n) = n * faktorial(n-1)
    return n * faktorial(n - 1);
}

int main() {
    int bilangan;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    // Validasi input, pastikan bilangan positif
    if (bilangan < 0) {
        cout << "Masukkan harus bilangan bulat positif." << endl;
        return 1; 
    }
    // Memanggil fungsi faktorial dan menampilkan hasilnya
    cout << "Faktorial dari " << bilangan << " adalah: " << faktorial(bilangan) << endl;
    
    return 0;
}