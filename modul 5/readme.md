# <h1 align="center">Laporan Praktikum Algoritma dan Struktur Data Modul-5 Struct</h1>
<p align="center">A.A Istri Candra Manika Dewi </p>


## Dasar Teori

<p> Pada ilmu komputer variabel merupakan suatu tempat dimana sebuah kuantitas akan disimpan. Variabel berbeda dengan konstanta, yang diartikan sebagai suatu yang bisa diketahui dan tak dapat diubah.[1]</p>
<p>Structure (disebut juga struct) merupakan cara mengelompokkan beberapa variabel terkait ke dalam suatu tempat. Setiap Variabel dalam struct dikenal sebagai member of struct. Berbeda dengan arrya, struct dapat berisi banyak tipe data yang berbeda (int, string, double, bool, dll).[2]</p>


## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.


C++
```
#include <iostream> //input preprocessor directive
#include <string>
using namespace std;

// Mendefinisikan struct untuk buku
struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    float harga_buku;
};

int main() {
    // Membuat objek buku dan menginisialisasi nilainya
    Buku buku1;
    buku1.judul_buku = "Belajar Bahasa C++";
    buku1.pengarang = "John Doe";
    buku1.penerbit = "Penerbit A";
    buku1.tebal_halaman = 300;
    buku1.harga_buku = 150.0;

    Buku buku2;
    buku2.judul_buku = "Belajar Struktur Data";
    buku2.pengarang = "tika";
    buku2.penerbit = "penerbit B";
    buku2.tebal_halaman = 230;
    buku2.harga_buku = 100.0;


    // Menampilkan informasi buku
    cout << "Informasi Buku:" << endl;
    cout << "Judul       : " << buku1.judul_buku << endl;
    cout << "Pengarang   : " << buku1.pengarang << endl;
    cout << "Penerbit    : " << buku1.penerbit << endl;
    cout << "Tebal Halaman: " << buku1.tebal_halaman << " halaman" << endl;
    cout << "Harga       : Rp " << buku1.harga_buku << endl;

    // Menampilkan informasi buku
    cout << "Informasi Buku:" << endl;
    cout << "Judul       : " << buku2.judul_buku << endl;
    cout << "Pengarang   : " << buku2.pengarang << endl;
    cout << "Penerbit    : " << buku2.penerbit << endl;
    cout << "Tebal Halaman: " << buku2.tebal_halaman << " halaman" << endl;
    cout << "Harga       : Rp " << buku2.harga_buku << endl;

    return 0;
}
```



### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/697cff42-4039-400e-985a-5214c9c0e743)

C++
```
#include <iostream> //input preprocessor directive
#include <string>
using namespace std;

struct Hewan{
    string nama_hewan;
    string jenis_kelamin;
    string kembangbiak;
    string pernapasan;
    string tempat_hidup;
    bool karnivora;
}; Hewan info_hewan;

struct hewan_drt{
    Hewan info_hewan;
    int jumlah_kaki;
    bool apakah_menyusui;
    string suara;
}; hewan_drt hewan1;

struct hewan_lt{
    Hewan info_hewan;
    string bentuk_sirip;
    string pertahanan_diri;
};hewan_lt hewan2;

int main() {

    //hewan darat
    hewan1.info_hewan.nama_hewan = "Kucing";
    hewan1.info_hewan.jenis_kelamin = "Jntn";
    hewan1.info_hewan.kembangbiak = "Melahirkan";
    hewan1.info_hewan.pernapasan = "Paru-paru";
    hewan1.info_hewan.tempat_hidup = "Darat";
    hewan1.info_hewan.karnivora = true;
    hewan1.jumlah_kaki = 4;
    hewan1.apakah_menyusui = true;
    hewan1.suara = "Meowwwww";

    //hewan 2
    hewan2.info_hewan.nama_hewan = "penyu";
    hewan2.info_hewan.jenis_kelamin = "Bntn";
    hewan2.info_hewan.kembangbiak = "Bertelur";
    hewan2.info_hewan.pernapasan = "Paru-paru dan Insang";
    hewan2.info_hewan.tempat_hidup = "Laut";
    hewan2.info_hewan.karnivora = false;
    hewan2.bentuk_sirip = "sirip dan ekor";
    hewan2.pertahanan_diri = "Cangkang yang kuat";



    //menampilkan data 
    cout << "\tHewan Darat" << endl;
    cout << "Nama Hewan : " << hewan1.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin : " << hewan1.info_hewan.jenis_kelamin << endl;
    cout << "kembangbiak : " << hewan1.info_hewan.kembangbiak << endl;
    cout << "Pernapasan : " << hewan1.info_hewan.pernapasan << endl;
    cout << "Tempat Hidup : " << hewan1.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora? : " << hewan1.info_hewan.karnivora << endl;
    cout << "Jumlah Kaki : " << hewan1.jumlah_kaki << endl;
    cout << "Apakah Menyusui? : " << hewan1.apakah_menyusui << endl;
    cout << "Suara : " << hewan1.suara << endl;
    cout <<     "========================================================================" << endl;

    cout << "\tHewan Laut" << endl;
    cout << "Nama Hewan : " << hewan2.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin : " << hewan2.info_hewan.jenis_kelamin << endl;
    cout << "kembangbiak : " << hewan2.info_hewan.kembangbiak << endl;
    cout << "Pernapasan : " << hewan2.info_hewan.pernapasan << endl;
    cout << "Tempat Hidup : " << hewan2.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora? : " << hewan2.info_hewan.karnivora << endl;
    cout << "Bentung Sirip : " << hewan2.bentuk_sirip << endl;
    cout << "Cara Bertahan Hidup : " << hewan2.pertahanan_diri << endl;


    return 0;

}
```


## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

C++
```
//A.A Istri Candra Manika Dewi
//2311110026
#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul_buku;        
    string pengarang;         
    string penerbit;          
    int tebal_halaman;        
    double harga_buku;           
};

int main() {
    const int jumlah_buku = 5; // ukuran array
    Buku daftar_buku[jumlah_buku]; 

    // Data buku
    string judul_buku[] = {"Bumu Manusia", "Laskar Pelangi", "Anak Semua Bangsa", "Ronggeng Dukuh Paruk", "Negeri 5 Menara"};
    string pengarang[] = {"Pramoedya Ananta Toer", "Andrea Hirata", "Pramoedya Ananta Toer", "Ahmad Tohari", "Ahmad Fuadi"};
    string penerbit[] = {"Lentera Dipantara : Jakarta., 2005", "Yogyakarta : Back Bay Books, 2008", "Lentera Dipantara : Jakarta., 2006", "Jakarta : Gramedia Pustaka Utama, 2003", "PT Gramedia Pusat Utama"};
    int tebal_halaman[] = {231, 198, 200, 79, 135};
    double harga_buku[] = {50000, 35000, 80000, 75000, 65000};

    // Fill the array of Buku structs with data
    for (int i = 0; i < jumlah_buku; ++i) {
        daftar_buku[i].judul_buku = judul_buku[i];
        daftar_buku[i].pengarang = pengarang[i];
        daftar_buku[i].penerbit = penerbit[i];
        daftar_buku[i].tebal_halaman = tebal_halaman[i];
        daftar_buku[i].harga_buku = harga_buku[i];
    }

    // menampilkan informasi buku
    for (int i = 0; i < jumlah_buku; ++i) {
        cout << "Informasi Buku ke-" << i + 1 << ":" << endl;
        cout << "Judul: " << daftar_buku[i].judul_buku << endl;
        cout << "Pengarang: " << daftar_buku[i].pengarang << endl;
        cout << "Penerbit: " << daftar_buku[i].penerbit << endl;
        cout << "Tebal Halaman: " << daftar_buku[i].tebal_halaman << " halaman"<< endl;
        cout << "Harga Buku: Rp " << daftar_buku[i].harga_buku << endl;
        cout << endl;
    }

    return 0;
}
```




#### Output:

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/365707ed-4aed-491e-a96b-42911d0536b9)


#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/6f58a1b5-da24-4eca-b53b-6cfa5a9fbe1f)

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided 1, berjenis array. Bagaimana cara mengisi data dan menampilkannya?



## Kesimpulan


## Referensi
[1] Ridwan Effendi, "Keunikan variabel dalam pemrograman visual C++", 2009 Jurnal Manajemen Informatika - Politeknik Negeri 
Sriwijaya
[2] "C++ Structures (struct)" w3schools. [Online]. Available: https://www.w3schools.com/cpp/cpp_structs.asp [Accessed 02 Mei 2024].
