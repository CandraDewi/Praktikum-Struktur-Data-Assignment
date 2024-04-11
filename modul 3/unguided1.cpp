#include <iostream>
using namespace std;

// Fungsi untuk mengurutkan array secara descending menggunakan algoritma selection sort
void selection_sort(float arr[], int n){
    int pos_max;
    float tmp;

    for (int i = 0; i < n - 1; i++){
        pos_max = i;

        // Membandingkan dan menukar elemen
        for (int j = i +1; j < n ; j++){
            if (arr[j] > arr[pos_max]){
                pos_max = j;
            }
        }

        //Menukar angka jika posisi maximum bukan di posisi saat ini
        if (pos_max != i){
            // Menukar elemen
            tmp = arr[i];
            arr[i] = arr[pos_max];
            arr[pos_max] = tmp;
            i--;
        }
    }
}

// Fungsi untuk mencetak isi array
void print_array(float arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

// Main programm
int main(){
    // Deklarasi array dan panjang elemen dalam array
    int n = 5;
    float arr[] = {2.3, 5.8, 1.9, 4.7, 2.5};

    // Menampilkan array sebelum diurutkan secara descending
    cout << "Urutan angka sebelum sorting secara descending: " << endl;
    print_array(arr, n);

    // Memanggil fungsi selection sort untuk mengurutkan array secara descending
    selection_sort(arr, n);

    // Menampilkan array setelah diurutkan secara descending
    cout << "Urutan angka setelah sorting secara descending: " << endl;
    print_array(arr, n);

    return 0;
} // end of main programm
