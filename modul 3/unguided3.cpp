
#include <iostream>
using namespace std;

//fungsi untuk mengurutkan array secara ASCENDING menggunakan algortima insertion sort
void insertion_sort_ascending(char arr[], int length){
    int i, j;
    char tmp;

    for (i=1; i < length; i++){
        j=i;
        // membandingkan dan menukar elemen
        while (j > 0 && arr[j-1] > arr[j]){ //perubahan terjadi disini
            // Menukar elemen
            tmp = arr[j]; // variabel kosong untuk menyimpan data sementara
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }
}

//fungsi untuk mengurutkan array secara DESCENDING menggunakan algortima insertion sort
void insertion_sort_descending(char arr[], int length){
    int i, j;
    char tmp;

    for (i=1; i < length; i++){
        j=i;

        // membandingkan dan menukar elemen
        while (j > 0 && arr[j-1] < arr[j]){ //perubahan terjadi disini
            // Menukar elemen
            tmp = arr[j]; // variabel kosong untuk menyimpan data sementara
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }
}

// Fungsi untuk mencetak isi array
void print_array(char a[], int length){
    for(int i = 0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

// Main Programm
int main(){
    // Meminta user untuk menginputkan panjang array
    int length;
    cout << "Masukkan jumlah karakter yang ingin di input: ";
    cin >> length;

    char a[length]; // Membuat array 'a' dengan panjang sesuai dengan jumlah karakter yang diinputkan user

    // Meminta user untuk memasukkan karakter sebanyak 'length'
    cout << "Masukkan " << length << " karakter: ";
    for (int i = 0; i < length; i++){
        cin >> a[i];
    }

    // Menampilkan array sebelum diurutkan secara descending
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    // Memanggil fungsi insertion sort untuk mengurutkan array secara ASCENDING
    insertion_sort_ascending(a, length);

    // Menampilkan array setelah diurutkan secara ascending
    cout << "Urutan karakter setelah ascending sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi insertion sort untuk mengurutkan array secara DESCENDING
    insertion_sort_descending(a,length);

    // Menampilkan array setelah diurutkan secara descending
    cout << "Urutan karakter setelah descending sorting: " << endl;
    print_array(a, length);
}
