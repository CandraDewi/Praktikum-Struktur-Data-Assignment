
# <h1 align="center">Laporan Praktikum Algoritma dan Struktur Data Modul-4 Searching</h1>
<p align="center">A.A Istri Candra Manika Dewi </p>


## Dasar Teori

Dalam ilmu komputer, algoritma searching adalah sebuah algoritma yang menerima masukan berupa sebuah masalah dan menghasilkan sebuah solusi untuk masalah tersebut, yang biasanya didapat dari evaluasi beberapa kemungkinan solusi[1]. Searching adalah salah satu operasi dasar dari Struktur Data, yang digunakan untuk mencari data tertentu dari sebuah list data. Searching dapat beroperasi pada list yang diurutkan dan tidak diurutkan[2]. Setelah proses pencarian dilaksanakan, akan diperoleh salah  satu dari dua kemungkinan, yaitu data yang dicari ditemukan (successful) atau tidak ditemukan (unsuccessful). 

Metode pencarian data dapat dilakukan dengan dua cara yaitu pencarian internal (internal searching) dan pencarian eksternal (external searching). Selain itu metode pencarian data juga dapat dikelompokka menjadi pencarian statis (static searching) dan pencarian dinamis (dynamic searching). Ada dua macam teknik pencarian yaitu sequential search dan binary search. Perbedaan dari dua teknik ini terletak pada keadaan data. Sequential search digunakan apabila data dalam keadaan acak atau tidak terurut. Sebaliknya, binary search digunakan pada data yang sudah dalam keadaan urut.

### 1. Sequential Search

Sequential search yang sering disebut pencarian linear merupakan metode pencarian yang paling sederhana. Sequential search menggunakan prinsip sebagai berikut : data yang ada dibandingkan satu per satu secara berurutan dengan yang dicari sampai data tersebut ditemukan atau tidak ditemukan.

Pada dasarnya, pencarian ini hanya melakukan pengulangan dari 1 sampai dengan jumlah data. Pada setiap pengulangan, dibandingkan data ke-i dengan yang dicari. Apabila sama, berarti data telah ditemukan. Sebaliknya apabila sampai akhir pengulangan tidak ada data yang sama, berarti data tidak ada. Pada kasus yang paling buruk, untuk N elemen data harus dilakukan pencarian sebanyak N kali pula.

### 2. Binary Search

Salah satu syarat agar binary search dapat dilakukan adalah data sudah dalam keadaan urut. Dengan kata lain, apabila data belum dalam keadaan urut, binary search tidak dapat dilakukan. Dalam kehidupan sehari-hari, sebenarnya kita juga sering menggunakan binary search. Misalnya saat ingin mencari suatu kata dalam kamus.

Prinsip dari binary search dapat dijelaskan sebagai berikut : mula-mula diambil posisi awal 0 dan posisi akhir = N - 1, kemudian dicari posisi data tengah dengan rumus (posisi awal + posisi akhir) / 2. Kemudian data yang dicari dibandingkan dengan data tengah. Jika lebih kecil, proses dilakukan kembali tetapi posisi akhir dianggap sama dengan posisi tengah –1. Jika lebih besar, porses dilakukan kembali tetapi posisi awal dianggap sama dengan posisi tengah + 1. Demikian seterusnya sampai data tengah sama dengan yang dicari.

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data

```C++
//A.A Istri Candra Manika Dewi
//2311110026

#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential Search
    for (i = 0; i < n; i++){
        if(data[i] == cari){
            ketemu = true;
            break;
        }
    }
    cout << "\n\t Program Sequential Search Sederhana\n" << endl;
    cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;

}

```
Kode ini menunjukkan contoh sederhana algoritma pencarian sekuensial untuk mencari nilai tertentu dalam daftar data. Algoritma ini bekerja dengan cara membandingkan setiap elemen dalam daftar secara berurutan hingga nilai yang dicari ditemukan. Pertama kita menginputkan library `iostream` dan menggunakan `using namespace std`. Lalu pada main program variable `n` digunakan untuk menentukan panjang array. Kemudian kita membuat variable `data` yang berisi data array. Lalu kita membuat variable `cari` yang diisi dengan angka berapa yang ingin kita cari, dan variable `ketemu` diinisialisasi dengan `false` karena sebelum proses pencarian dilakukan, belum ada kepastian bahwa angka yang dicari `cari` ada dalam array `data`. Dengan menginisialisasi `ketemu` sebagai `false`, kita mempersiapkan kondisi awal untuk proses pencarian.

Kemudian kita membuat looping untuk mencari data menggunakan algoritma sequential search yang dilakukan perbandingan antara nilai elemen array `data[i]` dengan variable `cari`. Jika ditemukan kecocokan antara `data[i] == cari` maka variable ketemu akan diubah menjadi `true` dan looping akan dihentikan. Lalu pada kode dibawahnya digunakan untuk menampilkan data dan hasil. Jika ditemukan angka 10 maka akan menampilkan indeks ke berapa dan jika tidak ditemukan maka akan muncul pesan bahwa angka tidak ditemukan.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
//A.A Istri Candra Manika Dewi
//2311110026

#include <iostream>
#include <iomanip>

using namespace std;

int bil_data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(bil_data[j] < bil_data[min]) {
                min = j;
            }
        }
        temp = bil_data[i];
        bil_data[i] = bil_data[min];
        bil_data[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(bil_data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(bil_data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main() {
    cout << "\t BINARY SEARCH\n";
    cout << "\n Data : ";
    // tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    binary_search();
    return 0;
}

```
Kode program ini menunjukkan implementasi binary search dengan menggunakan sorting selection sort. Pertama kita menginputkan library. Lalu kita membuat variable `bil_data` dengan panjang array 7 dan membuat variable `cari`. Kemudian kita membuat 2 function, yaitu `selection_sort` dan `binary_search`. Function `selection_sort` digunakan untuk mengurutkan data menggunakan sorting selection sort dan function `binary_search` digunakan untuk mencari bilangan dengan menggunakan algoritma binary search. Pada function `selection_sort` looping for dijalankan dari elemen pertama yaitu `i = 0` sampai elemen terakhir `i < 7`. Dalam looping variable `min` digunakan untuk menyimpan indeks elemen terkecil. Selanjutnya buat nested loop untuk membandingkan elemen `bil_data[j]` dengan dengan elemen terkecil saat ini `bil_data[min]`. Setelah looping selesai, elemen terkecil `bil_data[min]` ditukar dengan elemen pada indeks `i`. 

Kemudian untuk function `binary_search` kita menentukan indeks awal, tengah, dan akhir. `awal` diinisialisasi dengan 0, `akhir` diinisialisasi dengan 6, dan `tengah` dihitung sebagai rata-rata `awal` dan `akhir`. Lalu kita membandingkan nilai dengan cara diperiksa apakah nilai pada indeks `tengah` `bil_data[tengah]` sama dengan `cari`. Jika sama, maka nilai ditemukan dan proses dihentikan, namun jika `bil_data[tengah]` lebih kecil dari `cari`, maka awal diperbarui menjadi `tengah + 1` dan jika `bil_data[tengah]` lebih besar dari `cari`, maka `akhir` diperbarui menjadi `tengah - 1`. Kemudian pada main program digunakan untuk menampilkan nilai. Jika nilainya ditemukan maka indeksnya ditampilkan, namun jika nilai tidak ditemukan maka akan muncul pesan.

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
//A.A Istri Candra Manika Dewi
//2311110026

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int binarySearch(string kalimat, char target) {
  int left = 0;
  int right = kalimat.length() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    char midChar = kalimat[mid];

    if (midChar == target) {
      return mid;
    } else if (midChar < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  string kalimat;
  char target;

  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Urutkan kalimat sebelum melakukan pencarian
  sort(kalimat.begin(), kalimat.end());

  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> target;

  int position = binarySearch(kalimat, target);


  if (position == -1) {
    cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
  } else {
    cout << "Huruf '" << target << "' ditemukan pada posisi ke-" << position + 1 << "." << endl;
  }

  return 0;
}



```
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/20ee411c-43d0-48f4-bffc-2707a682a956)

Kode di atas digunakan untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search. Pertama kita mengimport library yang akan digunakan. Lalu kita membuat 2 function yaitu `selection_sort` yang digunakan untuk mengurutkan data dan `binarySearchString` yang digunakan untuk mencari data dengan menggunakan algoritma binary search. Program dimulai dengan meminta pengguna untuk memasukkan sebuah kalimat. Setelah kalimat dimasukkan, program menggunakan `stringstream` untuk memisahkan kalimat menjadi kata-kata. Jumlah kata dalam kalimat dihitung untuk menentukan ukuran array yang akan digunakan untuk menyimpan kata-kata tersebut. Selanjutnya, kata-kata tersebut disimpan dalam array `arr`.

Setelah kata-kata disimpan dalam array, program akan mengurutkannya menggunakan function `selection_sort`. Kemudian, program akan menampilkan kata-kata yang sudah diurutkan. Selanjutnya, pengguna diminta untuk memasukkan kata yang ingin dicari. Kata tersebut akan dicari dalam array `arr` menggunakan function `binarySearchString`. Jika kata ditemukan dalam array `arr`, program akan menampilkan indeks dimana kata tersebut ditemukan. Namun, jika kata tidak ditemukan, program akan menampilkan pesan bahwa data tidak ditemukan.

#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/a9b45df0-a1b3-4a35-9efb-0b0ddd4b46df)

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
//A.A Istri Candra Manika Dewi
// 2311110026

#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat;
    int jumlah_vokal = 0;

    cout << "Masukkan kalimat: "; getline(cin, kalimat);

    for(int i = 0; i < kalimat.length(); i++) {
    if(kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' || kalimat[i] == 'e' || kalimat[i] == 'o' || kalimat[i] == 'A' || kalimat[i] == 'I' || kalimat[i] == 'U' || kalimat[i] == 'E' || kalimat[i] == 'O') {
        jumlah_vokal++;
        }
    }

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlah_vokal;

    return 0;
}


```
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/b2bb2caf-cca2-452e-b297-5ce3d9fa1fa6)

Kode di atas digunakan untuk menghitung banyaknya huruf vocal dalam sebuah kalimat. Pertama kita mengimport library yang akan digunakan. Lalu kita membuat function `vokal` untuk menentukan apakah sebuah karakter merupakan huruf vokal atau bukan. Fungsi ini mengembalikan `true` jika karakter yang diberikan merupakan salah satu dari huruf vokal (A, E, I, O, U), dan `false` jika tidak. Lalu pada main program, sudah diinisialisasi array dengan variable `str` dengan panjang 100 yang sudah diisi dengan kata. Program ini kemudian menampilkan kata yang ada dalam string tersebut. Selanjutnya, program melakukan iterasi melalui setiap karakter dalam string menggunakan loop akan me looping menggunakan looping `for`. Lalu program akan memeriksa apakah karakter tersebut merupakan huruf vokal dengan menggunakan function `vokal`. Jika karakter tersebut adalah huruf vokal, maka variabel `vokals` akan ditambah satu. Setelah selesai, program akan menampilkan jumlah total huruf vokal yang ditemukan dalam string `str`.

#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/4e7e725d-ed5f-4bfb-a927-fbab1065ec6e)

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
//A.A Istri Candra Manika Dewi
//2311110026

#include <iostream>
using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int length = sizeof(data)/sizeof(data[0]);
    int searchNum = 4;
    int count = 0;

    cout << "Data: ";
    for(int i=0; i<length; i++)
        { cout << data[i] << " ";
        if(data[i] == searchNum) {
            count++;
        }
    }
    cout << endl;

    cout << "Jumlah angka " << searchNum << " pada data tersebut adalah: " << count << endl;

    return 0;
}


```
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/87ce396a-7874-4fc6-a3dc-f0b9deb012d9)

Kode di atas digunakan untuk menghitung berapa banyak angka 4 dengan menggunakan algoritma Sequential Search. Pertama kita menginputkan library `iostream` dan menggunakan `using namespace std`. Lalu pada main program variable `n` digunakan untuk menentukan panjang array. Kemudian kita membuat variable `data` yang berisi data array. Lalu kita membuat variable `cari` yang diisi dengan angka berapa yang ingin kita cari, dan variable `count` diinisialisasi dengan `0`.

Kemudian kita membuat looping untuk mencari data menggunakan algoritma sequential search yang dilakukan perbandingan antara nilai elemen array `data[i]` dengan variable `cari`. Jika ditemukan kecocokan antara `data[i] == cari` maka variable ketemu akan diubah menjadi `true` dan looping akan dihentikan. Lalu pada kode dibawahnya digunakan untuk menampilkan data dan hasil. Jika ditemukan angka 4 maka akan menampilkan indeks ke berapa dan jika tidak ditemukan maka akan muncul pesan bahwa angka tidak ditemukan.

#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/67793253-b81b-49e9-a234-3dd3ceb3641d)

## Kesimpulan
Pada guided kita belajar mengenai algoritma searching. Ada dua macam teknik pencarian yaitu sequential search dan binary search. Perbedaan dari dua teknik ini terletak pada keadaan data. Sequential search digunakan apabila data dalam keadaan acak atau tidak terurut. Sebaliknya, binary search digunakan pada data yang sudah dalam keadaan urut.

Lalu pada unguided kita belajar mengenai bagaimana cara membuat program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search, membuat program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat, dan menghitung berapa banyak angka 4 dengan menggunakan algoritma Sequential Search.

## Referensi
[1] "Algoritma pencarian," Wikipedia, 03 Maret 2024. [Online]. Available: https://id.wikipedia.org/wiki/Algoritma_pencarian. [Accessed 25 April 2024].

[2] N. Sultana, S. Paira, S. Chandra, and S. K. Alam, “A brief study and analysis of different searching algorithms,” 2017 Second International Conference on Electrical, Computer and Communication Technologies (ICECCT), Feb. 2017. doi:10.1109/icecct.2017.8117821 
