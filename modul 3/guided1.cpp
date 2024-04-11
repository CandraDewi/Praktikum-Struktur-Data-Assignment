#include <iostream>
using namespace std;

// fungsi untuk mengurutkan array menggunakan algoritma bubble sort
void bubble_sort(double arr[], int length){
    bool not_sorted =true;
    int j = 0;
    double tmp;

    // melakukan pengurutan hingga array sudah teurut
    while(not_sorted){
        not_sorted = false;
        j++;

        // membandingkan dan menukar eleman
        for (int i = 0; i < length - j; i++){
            if(arr[i] > arr[i+1]){
                //menukar elemen
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;

                // set not_sorted ke true karena ada perubahan posisi elemen
                not_sorted = true;

            }
        }
    }
}

// fungsi untuk mencetak isi array
void print_array(double a[], int length){
    for(int i=0; i<length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

// Main programm
int main(){
    int length = 6; // jumlah elemen dalam array
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99,99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    // memanggil fungsi bubble sort untuk mengurutkan array
    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);

    return 0;
}
