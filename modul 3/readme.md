
# <h1 align="center">Laporan Praktikum Algoritma dan Struktur Data Modul-3 Sorting</h1>
<p align="center">A.A Istri Candra Manika Dewi</p>


## Dasar Teori

Sorting mengacu pada pengurutan data dengan cara yang meningkat atau menurun sesuai dengan beberapa hubungan linier di antara item data[1]. Sorting juga bisa didefinisikan proses mengatur item data (angka/string) dalam suatu urutan dan/atau dalam set atau kelompok yang berbeda[3]. Sorting dapat dilakukan dari nilai terkecil ke nilai terbesar (ascending) atau sebaliknya (descending)[2]. 

### 1. Insertion Sorting

#### Konsep Dasar Algoritma Insertion Sort
Insertion sorting mengacu pada algoritma pengurutan sederhana yang membangun larik (atau daftar) yang diurutkan akhir satu per satu[1]. Cara kerja insertion sort sebagaimana namanya. Pertama-tama, dilakukan iterasi, dimana di setiap iterasi insertion sort memindahkan nilai elemen, kemudian menyisipkannya berulang-ulang sampai ke tempat yang tepat. Begitu seterusnya dilakukan. Dari proses iterasi, seperti biasa, terbentuklah bagian yang telah di-sorting dan bagian yang belum[2].

Algoritma Insertion Sort juga terdiri dari 2 kalang bersarang. Dimana terjadi N-1 Pass (dengan N adalah banyak elemen struktur data), dengan masing-masing Pass terjadi i kali operasi perbandingan. i tersebut bernilai 1 untuk Pass pertama, bernilai 2 untuk Pass kedua, begitu seterusnya hingga Pass ke N-1[2].

#### Pseudocode Algoritma Insertion Sort
```C++
for i = 1 to n-1
    set j = i
    set t = a[j]
    repeat while j > 0 and a[j-1] > t
        move a[j-1] to right
    end repeat
    set a[j] = t
end for
```

#### Prosedur Insertion Sort dalam bahasa C++
```C++
void insertion_sort(int arr[], int length) {
    int i, j ,tmp;
        for (i = 1; i < length; i++) {
            j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
         }//end of while loop
    }//end of for loop
}
```

### 2. Bubble Sort

#### Konsep Dasar Algoritma Bubble Sort
Bubble sorting yang mengacu pada teknik pengurutan yang biasanya digunakan untuk mengurutkan daftar kecil[1]. Dimulai dengan membandingkan item pertama dengan item kedua, item kedua dengan item ketiga dan seterusnya hingga menemukan satu item yang tidak berurutan. Kemudian menukar dua item dan memulai kembali. Konsep dari ide dasarnya adalah seperti “gelembung air” untuk elemen struktur data yang semestinya berada pada posisi awal. Cara kerjanya adalah dengan berulang-ulang melakukan traversal (proses looping) terhadap elemen-elemen struktur data yang belum diurutkan. Di dalam traversal tersebut, nilai dari dua elemen struktur data dibandingkan. Jika ternyata urutannya tidak sesuai dengan “pesanan”, maka dilakukan pertukaran (swap). Algoritma sorting ini disebut juga dengan comparison sort dikarenakan hanya mengandalkan perbandingan nilai elemen untuk mengoperasikan elemennya[2].

Algoritma di dalam bubble sort terdiri dari 2 kalang (loop) bertingkat. Kalang pertama berlangsung selama N-1 kali. Indeks untuk kalang pertama adalah Pass. Kemudian kalang tingkat kedua berlangsung dari N sampai dengan Pass+1. Algoritma bubble sort, jika dikembangkan, kompleksitasnya mencapai Ω(n)[4]. Hal ini hanya terjadi jika memanfaatkan tipe data boolean untuk menyatakan bahwa proses penukaran tak perlu dilakukan lagi.

#### Prosedur Bubble Sort dalam bahasa C++
```C++
void bubble_sort(int arr[], int length) {
    bool not_sorted = true;
    int j=0,tmp;

    while (not_sorted) {
        not_sorted = false;
        j++;

        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort
```
### 3. Selection Sort

#### Konsep dasar Algoritma Selection Sort
Selection sort mengacu pada teknik pengurutan yang pada dasarnya digunakan untuk mengurutkan daftar kecil item[1]. Dimulai dengan membandingkan seluruh daftar untuk item terendah dan memindahkannya ke posisi #1. Kemudian membandingkan sisa daftar untuk item terendah berikutnya dan menempatkannya di posisi # 2 dan seterusnya hingga semua item berada dalam urutan yang diperlukan[3]. Ide dasarnya adalah melakukan beberapa kali pass untuk melakukan penyeleksian elemen struktur data. Untuk sorting ascending (menaik), elemen yang paling kecil di antara elemenelemen yang belum urut, disimpan indeksnya, kemudian dilakukan pertukaran nilai elemen dengan indeks yang disimpan tersebut dengan elemen yang paling depan yang belum urut. Sebaliknya, untuk sorting descending (menurun), elemen yang paling besar yang disimpan indeksnya kemudian ditukar[2]. 

Algoritma di dalam Selection Sort terdiri dari kalang bersarang. Dimana kalang tingkat pertama (disebut pass) berlangsung N-1 kali. Di dalam kalang kedua, dicari elemen dengan nilai terkecil. Jika didapat, indeks yang didapat ditimpakan ke variabel min. Lalu dilakukan proses penukaran. Begitu seterusnya untuk setiap Pass. Namun, melalui uji empiris, didapatkan bahwa Selection Sort lebih efisien daripada Bubble Sort[2]. 

#### Konsep dasar Algoritma Selection Sort
```C++
void selectSort(int arr[], int n) {
     int pos_min,temp;
        for (int i=0; i < n-1; i++) {
             pos_min = i;
                for (int j=i+1; j < n; j++) {
                if (arr[j] < arr[pos_min])
                pos_min=j;
            }

         if (pos_min != i) {
            temp = arr[i];
            arr[i] = arr[pos_min];
            arr[pos_min] = temp;
         }
    }
}
```

## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length) {
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted) {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            } //end of if
        } //end of for loop
    } //end of while loop
} //end of bubble_sort

void print_array(double a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99, 99.99};
 
    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);
 
    bubble_sort(a, length);
    cout << "\nUrutan bilangan setelah sorting: " << endl;
 
    print_array(a, length);

    return 0;
}
```
Kode di atas digunakan untuk mencetak urutan bilangan secara ascending untuk data numerik yang bertipe double menggunakan Algoritma Bubble Sort. Pertama kita membuat 2 variable, variable `bubble_sort` dan `print_array`. Variable `bubble_sort` befungsi untuk mengurutkan data dan variable `print_array` berfungsi untuk mencetak array. Dalam variable `bubble_sort` kita membuat variable `not_shorted` yang berfungsi untuk menandakan apakah array sudah di sorting atau belum. Jika variable `not_shorted` sama dengan `true` maka array belum di sorting, namun jika variable `not_shorted` sama dengan `false` maka menandakan bahwa array sudah di sorting, sehingga perulangan atau looping harus dihentikan. Lalu ada variable `tmp` yang berfungsi sebagai variable temporary yang berguna untuk menampung array ketika melakukan swapping. Selanjutnya kita membuat variable `print_array` yang berisi looping atau perulangan untuk menampilkan array. Pada `main` program, kita bisa menginisialisasikan panjang array, dan mengisikan data ke dalam array. Lalu kita menampilkan urutan bilangan sebelum sorting dan kemudian menampilkan urutan bilangan setelah sorting menggunakan bubble sort secara ascending menggunakan function `print_array`

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        } //end of while loop
    } //end of for loop
}

void print_array(char a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};
    
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);
    
    insertion_sort(a, length);
    cout << "\nUrutan karakter setelah sorting secara descending: " << endl;
    
    print_array(a, length);

    return 0;

}
```
Kode di atas digunakan untuk mencetak karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Intertion Sort. Disini kita membuat 2 variable yaitu `insertion_sort` dan variable `print_array`. Pada variable `insertion_sort` berfungsi untuk mengurutkan character berdasarkan algoritma insertion sort. Dalam variable tersebut terdapat variable `tmp` yang berfungsi sebagai variable temporary yang berguna untuk menampung array ketika melakukan swapping. Selanjutnya kita membuat variable `print_array` yang berisi looping atau perulangan untuk menampilkan array. Pada `main` program, kita bisa menginisialisasikan panjang array, dan mengisikan data ke dalam array. Lalu kita menampilkan urutan karakter sebelum sorting dan kemudian menampilkan urutan karakter setelah sorting menggunakan insertion sort secara descending menggunakan function `print_array`

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!

```C++
//A.A Istri Candra Manika Dewi
//2311110026

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

```
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/5bdcfccb-13e5-42ac-a23b-dd26285b28db)

Kode di atas digunakan untuk mengurutkan elemen-elemen dalam sebuah array secara descending. Terdapat dua variable pada program tersebut, yaitu `selection` dan `printArr`. Pada variable `selection` proses sorting dimulai dengan melakukan iterasi melalui setiap elemen array kecuali elemen terakhir. Pada setiap iterasi, variabel `small` diinisialisasi sebagai indeks dari elemen dengan nilai terbesar yang belum diurutkan. Kemudian, dalam iterasi dalam, elemen-elemen array dibandingkan satu sama lain. Jika ditemukan elemen dengan nilai yang lebih besar dari `small`, maka `small` akan diupdate dengan indeks elemen tersebut. Setelah itu, elemen dengan nilai terbesar tersebut ditukar posisinya dengan elemen pertama pada iterasi saat ini.

Kemudian pada variable `printArr` digunakan untuk mencetak isi dari array. Di dalam fungsi `main`, array `a` diinisialisasi dengan beberapa nilai, kemudian cetak isi array tersebut sebelum proses sorting. Kemudian, variable `selection` dipanggil untuk mengurutkan array, dan setelah itu isi array tersebut dicetak kembali untuk menampilkan hasil setelah proses sorting

#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/f635bba6-2bea-4f65-b26b-0f624b55aa4d)

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
//A.A Istri Candra Manika Dewi
//2311110026
#include <iostream>
using namespace std;

// Fungsi untuk mengurutkan array secara ascending menggunakan algoritma bubble sort
void bubble_sort(string arr[], int length){
    bool not_sorted = true;
    int j = 0;
    string tmp;

    // melakukan pengurutan hingga array sudah teurut
    while (not_sorted){
        not_sorted = false;
        j++;

        // membandingkan dan menukar eleman
        for (int i = 0; i < length -j; i++){
            if (arr[i] > arr[i + 1]){
                //menukar elemen
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;

                // set not_sorted ke true karena ada perubahan posisi elemen
                not_sorted =true;

            }
        }
    }
}

// Fungsi untuk mencetak isi array
void print_array(string arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

// Main programm
int main(){

    // Deklarasi array dan panjang elemen dalam array
    int length = 10;
    string arr[] = {"tata", "tika", "titi", "sasa", "sandra", "reja", "cika", "dede", "dewa", "kadi"};

    // Menampilkan array sebelum diurutkan secara descending
    cout << "Urutan nama sebelum sorting secara ascending: " << endl;
    print_array(arr, length);

     // Memanggil fungsi bubble sort untuk mengurutkan array secara ascending
    bubble_sort(arr, length);

    // Menampilkan array setelah diurutkan secara descending
    cout << "Urutan nama setelah sorting secara ascending: " << endl;
    print_array(arr, length);

    return 0;
}

```
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/2f4f0534-e9fa-40e8-8ca2-43e53c414cd7)

Kode di atas digunakan untuk mengurutkan array dua dimensi berisi string. Dalam variable `BubbleSort`, terdapat dua nested loop yang berfungsi untuk membandingkan dan menukar posisi setiap pasangan string dalam array. Untuk membandingkan dua string, digunakan function `strcmp` yang berasal dari C Standard Library. Jika ditemukan bahwa string pertama lebih besar dari string kedua, maka posisi kedua string tersebut ditukar menggunakan function `strcpy`. Setelah proses sorting selesai, array yang sudah diurutkan dicetak dengan urutan dari yang terkecil ke yang terbesar menggunakan fungsi `printf` dalam fungsi `main`

#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/40c26bb6-2511-4435-b47d-67331396d4c6)

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

```C++
//A.A Istri Candra Manika Dewi
//2311110026
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


```
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/990ea83b-8812-4f5f-a260-2ea0624839be)

Kode di atas digunakan untuk mengurutkan array karakter menggunakan algoritma insertion sort. Variable `ASCSort` digunakan untuk mengurutkan array karakter secara ascending, sedangkan variable `DESCSort` digunakan untuk mengurutkan array karakter secara descending. Dalam kedua variable tersebut, algoritma insertion sort digunakan untuk membandingkan dan menukar posisi setiap elemen array sesuai dengan urutan yang diinginkan. Untuk variable `ASCSort`, elemen-elemen array dibandingkan satu sama lain dengan menggunakan operator > dan untuk variable `DESCSort`, elemen-elemen array dibandingkan satu sama lain dengan menggunakan operator <.

Dalam variable `main`, program akan meminta input dari pengguna untuk menentukan panjang array dan karakter-karakter yang akan dimasukkan ke dalam array. Setelah itu, program akan mencetak array sebelum proses sorting, kemudian mengurutkan array secara ascending dengan menggunakan variable `ASCSort` dan mencetak array setelah proses sorting. Selanjutnya, program akan mengurutkan array secara descending dengan menggunakan variable `DESCSort` dan mencetak array setelah proses sorting.

#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/304e7c81-deac-4157-a7ee-25c2a3da1f1e)

## Kesimpulan
Pada modul 3 guided ini kita belajar mengenai sorting, terutama pada bubble sorting dan insertion sorting. Bubble sorting yang mengacu pada teknik pengurutan yang biasanya digunakan untuk mengurutkan daftar kecil[1]. Dimulai dengan membandingkan item pertama dengan item kedua, item kedua dengan item ketiga dan seterusnya hingga menemukan satu item yang tidak berurutan. Kemudian menukar dua item dan memulai kembali. Lalu insertion sorting yang mengacu pada algoritma pengurutan sederhana yang membangun larik (atau daftar) yang diurutkan akhir satu per satu[1]. 

Lalu untuk modul 3 unguided kita belajar cara mengimplementasikan sorting, yaitu membuat program untuk mengurutkan Indeks Prestasi Mahasiswa dari terbesar hingga terkecil menggunakan selection sort, membuat program untuk mengurutkan 10 nama warga sesuai alfabet dengan menggunakan bubble sort, dan membuat program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending).

## Referensi
[1] Donald Knuth,The art of computer programming, volume 3: sorting and searching , Third Edition . Addison-Wesley, 1997

[2] W. F.  Wisudawan, “Kompleksitas Algoritma Sorting yang Populer Dipakai.”  Program Studi Teknik Informatika Institut Teknologi Bandung, Bandung, Indonesia

[3] Robert Sedgewick. Algorithms in C++, Part 1-4 Fundamentals, Data structures, sorting, Searching: Pts 1-4, Second Edition. Addison Wesley Longman, 1998

[4] Wikipedia, the free encyclopedia. 2007. Tanggal akses: 11 April 2024 pukul 23.00 WIB

[5] Z. Ullah, “Understanding Sorting Techniques Using C++.” Sam Higginbottom Institute of Agriculture, Technology & Sciences, Allahabad, India, Apr. 2016
