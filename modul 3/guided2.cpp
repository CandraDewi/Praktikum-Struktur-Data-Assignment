#include <iostream>
using namespace std;

//fungsi untuk mengurutkan array secara descending menggunakan algortima insertion sort
void insertion_sort(char arr[], int length){
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
    for(int i=0; i<length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

// Main programm
int main(){
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};
    print_array(a, length);

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi insertion sort untuk mengurutkan array secara descending
    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);

    return 0;
}
