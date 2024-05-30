# <h1 align="center">Laporan Praktikum Algoritma dan Struktur Data-Modul 9</h1>
# <h3 align="center">Rekursif & Hash Table</h3>

<p align="center">A.A. Istri Candra Manika Dewi (2311110026)</p>

## Dasar Teori

## Rekursif
Rekursif adalah konsep dalam pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan tugas yang diberikan [1]. Proses ini berlanjut sampai mencapai kondisi dasar atau batas, yang biasanya disebut sebagai "kondisi dasar" atau "kondisi terminasi", yang menghentikan pemanggilan berulang. Jenis rekursif itu ada dua yaitu:

1. Rekursif Langsung

Rekursif langsung terjadi ketika suatu fungsi memanggil dirinya sendiri secara langsung dalam tubuh fungsi itu sendiri [1]. Dalam rekursi langsung, setiap pemanggilan fungsi menghasilkan pemanggilan baru ke fungsi yang sama dengan parameter yang berbeda, hingga mencapai kondisi dasar.

2. Rekursif Tidak Langsung

Terjadi ketika satu fungsi memanggil fungsi lain, yang kemudian secara tidak langsung memanggil fungsi pertama lagi atau fungsi lain yang pada akhirnya akan memanggil fungsi awal kembali [2]. Dalam rekursi tidak langsung, serangkaian pemanggilan fungsi membentuk siklus di antara beberapa fungsi.

## Hash Table

Hash Table adalah struktur data yang digunakan untuk menyimpan kumpulan item di mana setiap item memiliki kunci unik. Ini memungkinkan pencarian, penyisipan, dan penghapusan item dengan kompleksitas waktu yang cepat. Prinsip dasar dari hash table adalah penggunaan fungsi hash untuk mengonversi kunci unik menjadi indeks array. Indeks ini kemudian digunakan untuk menyimpan atau mengakses nilai terkait. Keuntungan dari hash table termasuk pencarian, penyisipan, dan penghapusan dengan kompleksitas waktu rata-rata O(1) (tergantung pada implementasi dan faktor muatan), yang membuatnya sangat efisien dalam banyak kasus penggunaan. Namun, perlu diingat bahwa kinerja hash table dapat berkurang jika load factor menjadi terlalu tinggi, yang dapat menyebabkan konflik yang lebih sering terjadi. Oleh karena itu, pengelolaan ukuran hash table dan strategi menangani tabrakan sangat penting [3].

Operasi Hash Table:
- Insertion, Untuk menambahkan pasangan kunci-nilai baru ke dalam hash table.
- Search, Untuk mencari nilai yang terkait dengan kunci tertentu dalam hash table.
- Deletion, Untuk menghapus pasangan kunci-nilai tertentu dari hash table.
- Check Availability, Untuk memeriksa apakah kunci tertentu ada dalam hash table atau tidak.
- Iteration, Untuk mengakses semua pasangan kunci-nilai yang disimpan dalam hash table.


## Guided 1

```C++
// Guided 1
#include <iostream>
using namespace std;

// Fungsi ini melakukan hitung mundur dari angka yang diinputkan
void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); // 5 merupakan inputnya
    cout << endl;
    return 0;
}


```


Program ini adalah implementasi  rekursif langsung sederhana yang melakukan hitung mundur dari angka yang diinputkan hingga mencapai 0.
Pertama, fungsi countdown dipanggil dari dalam fungsi main dengan argumen 5, sehingga program akan mencetak output "Rekursif Langsung: " diikuti dengan hasil hitung mundur dari 5 hingga 1.

Berikut adalah cara kerja fungsi countdown:

- Fungsi countdown menerima parameter n.
- Jika n sama dengan 0, maka fungsi akan mengembalikan (base case).
- Jika n tidak sama dengan 0, maka fungsi akan mencetak nilai n, kemudian memanggil kembali fungsi countdown dengan argumen n - 1.

Proses ini akan terus berlanjut hingga mencapai kondisi basis (n == 0), di mana fungsi akan mengembalikan nilai tanpa melakukan pemanggilan rekursif lagi.
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/2018a18c-4ee3-4819-adf2-3d30782bb8e0)

## Guided 2

```C++
// Guided 2
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
	if (n > 0) {
		cout << n << " ";
		functionB(n - 1); // Panggilan rekursif tidak langsung
	}
}

void functionB(int n) {
	if (n > 0) {
		cout << n << " ";
		functionA(n / 2); // Panggilan rekursif tidak langsung
	}
}

int main() {
	int num = 5;
	cout << "Rekursif Tidak Langsung: ";
	functionA(num);
 	return 0;
}


```

Program ini menggunakan dua fungsi yang saling memanggil secara tidak langsung dengan cara melakukan panggilan rekursif satu sama lain. Fungsi functionA memanggil functionB, dan functionB memanggil functionA kembali.

- functionA: Menerima parameter n dan mencetak nilainya jika n lebih besar dari 0. Kemudian, memanggil functionB dengan parameter n - 1.
- functionB: Menerima parameter n dan mencetak nilainya jika n lebih besar dari 0. Kemudian, memanggil functionA dengan parameter n / 2.

Karena kedua fungsi memanggil satu sama lain secara bergantian, ini akan menghasilkan proses rekursif yang tidak terbatas, kecuali jika ada kondisi basis yang menghentikan proses rekursif. Dalam kasus ini, tidak ada kondisi basis yang menghentikan proses rekursif, sehingga akan terjadi penumpukan panggilan fungsi yang akhirnya akan menyebabkan terjadi stack overflow.
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/bc29ade0-939a-434b-9662-0e30f2611342)


## Guided 3

```C++
// Guided 3
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

class HashNode {
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (size_t i = 0; i < key.length(); ++i) {
            hash_val += key[i];
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (size_t i = 0; i < table[hash_val].size(); ++i) {
            if (table[hash_val][i]->name == name) {
                table[hash_val][i]->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (size_t i = 0; i < table[hash_val].size(); ++i) {
            if (table[hash_val][i]->name == name) {
                delete table[hash_val][i]; // Free memory allocated for the node
                table[hash_val].erase(table[hash_val].begin() + i);
                return;
            }
        }
        cout << "Node with name '" << name << "' not found." << endl;
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (size_t i = 0; i < table[hash_val].size(); ++i) {
            if (table[hash_val][i]->name == name) {
                return table[hash_val][i]->phone_number;
            }
        }
        return "";
    }
    
    void print() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            for (size_t j = 0; j < table[i].size(); ++j) {
                if (table[i][j] != NULL) {
                    cout << "[" << table[i][j]->name << ", " << table[i][j]->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    cout << "Phone Hp Ghana : " << employee_map.searchByName("Ghana") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}

```

Program ini adalah implementasi dari tabel hash sederhana menggunakan chaining untuk menangani tabrakan.

- Kelas HashNode merepresentasikan node dalam tabel hash. Setiap node memiliki atribut name dan phone_number.

- Kelas HashMap memiliki metode dan properti untuk memanipulasi tabel hash:

1. hashFunc: Code ini digunakan untuk menghitung nilai hash dari kunci (nama). Ini adalah fungsi sederhana yang menjumlahkan nilai ASCII dari setiap karakter kunci dan mengembalikan sisa hasil pembagian dengan ukuran tabel (11).
   
2. insert: Code ini digunakan untuk menambahkan entri baru ke dalam tabel hash. Jika terjadi tabrakan (kunci yang sama), chaining dilakukan dengan menambahkan node baru ke dalam vektor yang sesuai.
   
3. remove: Code ini digunakan untuk menghapus entri dari tabel hash berdasarkan kunci (nama). Jika entri ditemukan, node yang sesuai dihapus dari vektor.
searchByName: Metode ini digunakan untuk mencari nomor telepon berdasarkan nama. Ini mengembalikan nomor telepon yang sesuai jika nama ditemukan dalam tabel hash.

4. print: Code ini digunakan untuk mencetak seluruh isi tabel hash, termasuk chaining.

- Fungsi main adalah tempat eksekusi program dimulai. Pada fungsi main, beberapa entri ditambahkan ke tabel hash menggunakan metode insert, kemudian nomor telepon dicari menggunakan metode searchByName. Selanjutnya, salah satu entri dihapus menggunakan metode remove, dan isi tabel hash dicetak menggunakan metode print.
### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/722e4037-a34c-49cb-99e7-bd561017f28c)



## Unguided

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
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

```

<p><b>Penjelasan:</b></p>
Program ini adalah implementasi sederhana dari perhitungan faktorial menggunakan rekursi. Fungsi faktorial mengambil sebuah bilangan bulat n dan mengembalikan nilai faktorial dari n.

- Pada fungsi faktorial, jika nilai n adalah 0 atau 1, maka basis kasus tercapai, dan fungsi mengembalikan nilai 1.
- Jika nilai n lebih besar dari 1, maka langkah rekursif diterapkan dengan mengalikan nilai n dengan hasil rekursi dari faktorial(n - 1).
- Pada fungsi main, pengguna diminta untuk memasukkan bilangan bulat positif.
- Input yang dimasukkan akan divalidasi untuk memastikan bahwa bilangan yang dimasukkan adalah bilangan bulat positif. Jika tidak, program akan mencetak pesan kesalahan dan keluar dengan kode error.
- Jika input valid, fungsi faktorial dipanggil dengan input tersebut, dan hasilnya ditampilkan di layar.


#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/f58d7dc7-0922-49c8-a4ba-2c37889c6f55)

#### Full Code Screenshoot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/aef98dc1-17aa-4f6b-a935-e59a23886899)


### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!

```C++
//A.A Istri Candra Manika Dewi
//2311110026

#include <iostream>
using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n);

// Fungsi rekursif tidak langsung untuk menghitung faktorial dari n
int faktorial_rekursif(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int faktorial(int n) {
    return faktorial_rekursif(n);
}

int main() {
    int bilangan;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    if (bilangan < 0) {
        cout << "Masukkan harus bilangan bulat positif." << endl;
        return 1; // Keluar program dengan kode error
    }

    // Memanggil fungsi faktorial dan menampilkan hasilnya
    cout << "Faktorial dari " << bilangan << " adalah: " << faktorial(bilangan) << endl;

    return 0;
}
```

<p><b>Penjelasan:</b></p>
Program ini adalah implementasi rekursi tidak langsung untuk menghitung faktorial dari sebuah bilangan bulat positif. Rekursi tidak langsung terjadi ketika sebuah fungsi memanggil fungsi lainnya untuk menyelesaikan tugas yang sama.

1. faktorial_rekursif: Fungsi ini merupakan fungsi rekursif yang secara langsung menghitung faktorial dari sebuah bilangan bulat n.

2. faktorial: Fungsi ini merupakan fungsi utama yang memanggil fungsi faktorial_rekursif untuk menghitung faktorial. Ini merupakan contoh dari rekursi tidak langsung, di mana fungsi utama hanya bertindak sebagai penghubung untuk memanggil fungsi rekursif.

- Pengguna diminta untuk memasukkan bilangan bulat positif.
- Input divalidasi untuk memastikan bahwa bilangan yang dimasukkan adalah bilangan bulat positif. Jika tidak, program mencetak pesan kesalahan dan keluar dengan kode error.
- Jika input valid, fungsi faktorial dipanggil dengan input tersebut, dan hasilnya ditampilkan di layar.

#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/950f9f04-962c-4a46-b90f-3556fdea3e85)
#### Full Code ScreenShoot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/c1bfdad6-08ce-40e3-a0bf-7af016126f57)


### 3. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
### a. Setiap mahasiswa memiliki NIM dan nilai.
### b. Program memiliki tampilan pilihan menu berisi poin C.
### c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90)

```C++
//A.A Istri Candra Manika Dewi
//2311110026

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    double nilai;
    Mahasiswa(string nim, string nama, double nilai) : nim(nim), nama(nama), nilai(nilai) {}
};

class HashMap {
private:
    vector<Mahasiswa*> table[TABLE_SIZE];

    // Fungsi hash untuk menghasilkan indeks dari sebuah NIM
    int hashFunc(string nim) {
        int hash_val = 0;
        for (size_t i = 0; i < nim.length(); ++i) {
            hash_val += nim[i];
        }
        return hash_val % TABLE_SIZE;
    }

public:
    // Fungsi untuk menambahkan data mahasiswa baru
    void tambahData(string nim, string nama, double nilai) {
        int index = hashFunc(nim);
        table[index].push_back(new Mahasiswa(nim, nama, nilai));
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void hapusData(string nim) {
        int index = hashFunc(nim);
        for (size_t i = 0; i < table[index].size(); ++i) {
            if (table[index][i]->nim == nim) {
                delete table[index][i];
                table[index].erase(table[index].begin() + i);
                return;
            }
        }
        cout << "Mahasiswa dengan NIM '" << nim << "' tidak ditemukan." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void cariByNIM(string nim) {
        int index = hashFunc(nim);
        for (size_t i = 0; i < table[index].size(); ++i) {
            if (table[index][i]->nim == nim) {
                cout << "Mahasiswa dengan NIM '" << nim << "' ditemukan. Nama: " << table[index][i]->nama << ", Nilainya: " << table[index][i]->nilai << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM '" << nim << "' tidak ditemukan." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
    void cariByRange(double minNilai, double maxNilai) {
        bool found = false;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                if (table[i][j]->nilai >= minNilai && table[i][j]->nilai <= maxNilai) {
                    found = true;
                    cout << "NIM: " << table[i][j]->nim << ", Nama: " << table[i][j]->nama << ", Nilai: " << table[i][j]->nilai << endl;
                }
            }
        }
        if (!found) {
            cout << "Mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << " tidak ditemukan." << endl;
        }
    }

    // Destructor untuk membersihkan memori
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                delete table[i][j];
            }
        }
    }
};

int main() {
    HashMap mahasiswa_map;
    int choice;
    string nim, nama;
    double nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Mahasiswa Berdasarkan NIM\n";
        cout << "4. Cari Mahasiswa Berdasarkan Rentang Nilai (80 - 90)\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Nilai Mahasiswa: ";
                cin >> nilai;
                mahasiswa_map.tambahData(nim, nama, nilai);
                break;
            case 2:
                cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
                cin >> nim;
                mahasiswa_map.hapusData(nim);
                break;
            case 3:
                cout << "Masukkan NIM Mahasiswa yang ingin dicari: ";
                cin >> nim;
                mahasiswa_map.cariByNIM(nim);
                break;
            case 4:
                mahasiswa_map.cariByRange(80.0, 90.0);
                break;
            case 5:
                cout << "Thank!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Masukkan pilihan yang benar.\n";
                break;
        }
    } while (choice != 5);
    
    return 0;
}
```

<p><b>Penjelasan:</b></p>
Program ini adalah implementasi sederhana dari struktur data hash map untuk menyimpan data mahasiswa. Program ini memungkinkan pengguna untuk menambahkan data mahasiswa, menghapus data mahasiswa berdasarkan NIM, mencari data mahasiswa berdasarkan NIM, dan mencari data mahasiswa berdasarkan rentang nilai.

- Struktur Mahasiswa digunakan untuk menyimpan data mahasiswa, termasuk NIM, nama, dan nilai.
- Kelas HashMap memiliki vektor table yang berisi pointer ke objek Mahasiswa. Ini adalah struktur utama untuk menyimpan data mahasiswa.
- Fungsi hashFunc digunakan untuk menghasilkan indeks dari sebuah NIM menggunakan fungsi hash sederhana.
- Fungsi tambahData digunakan untuk menambahkan data mahasiswa baru ke dalam hash map.
- Fungsi hapusData digunakan untuk menghapus data mahasiswa berdasarkan NIM dari hash map.
- Fungsi cariByNIM digunakan untuk mencari data mahasiswa berdasarkan NIM.
- Fungsi cariByRange digunakan untuk mencari data mahasiswa berdasarkan rentang nilai.
- Pada fungsi main, pengguna diberi menu untuk memilih operasi yang ingin dilakukan.
- Setelah pengguna memilih operasi, program akan memproses masukan dan memanggil metode yang sesuai dari kelas HashMap.


#### Output:

#### a. Menambah Data

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/5ee1ef3c-b40c-4066-871c-8943da1641e5)

#### b. Menghapus Data

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/6329c632-8f6f-48e2-ba3f-139668019e1a)


#### c. Cari Mahasiswa dengan NIM
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/664ca52b-5cab-4706-9315-5fa83ca42180)


#### d. Cari Mahasiswa dengan Rentang Nilai (80-90)

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/1d6a5e4b-aefd-4696-aed6-166e0451b802)

## Kesimpulan

#### Rekursif:

adalah konsep di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan tugas yang diberikan. Terdiri dari dua komponen utama: kasus basis (base case) yang menghentikan pemanggilan rekursif dan kasus rekursif (recursive case) yang melanjutkan pemanggilan rekursif dengan input yang lebih kecil. Rekursif sering digunakan untuk menyelesaikan masalah yang dapat dipecahkan menjadi submasalah yang lebih kecil, seperti pencarian dan pengurutan dalam struktur data, permutasi, dan algoritma pencarian.

#### Hash Table:

- Hash table adalah struktur data yang digunakan untuk menyimpan kumpulan item dengan kunci unik.
- Menggunakan fungsi hash untuk mengonversi kunci unik menjadi indeks array di mana item disimpan. Operasi dasar pada hash table meliputi penyisipan, pencarian, penghapusan, pemeriksaan ketersediaan, dan iterasi.
- Efisiensi operasi pada hash table adalah O(1) rata-rata (tergantung pada implementasi dan faktor muatan), membuatnya sangat cepat untuk operasi-operasi tersebut.

## Referensi

[1] R. Firliana, R. Rina, dan P. Kasih, "Struktur Data yang Terorganisir," dalam Algoritma dan Pemrograman C++, Adjie Media Nusantara, Hal.1-82, 2019.

[2] M. Musafa' and N. Meli, "Studi Pendugaan Rekursif dan Nilai Dugaan Proses Observasi Model Hidden Markov", Imajiner: Jurnal Matematika dan Pendidikan Matematika, 2020.

[3] N Karumanchi,  "Data Structures and algorithms made easy: Concepts, problems, Interview Questions". CareerMonk Publications. 2016.
