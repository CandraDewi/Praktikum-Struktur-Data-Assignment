
# <h1 align="center">Laporan Praktikum Algoritma dan Struktur Data_Modul 10 </h1>
# <h1 align="center">Graph & Tree</h1>
<p align="center">A.A. Istri Candra Manika Dewi (2311110026)</p>

## Dasar Teori

## GRAPH
Graf (graph) digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut[1]. Dalam bentuk node atau vertex dan sambungan antara node tersebut dalam bentuk sisi atau edge. Graf terdiri dari simpul dan busur yang secara matematis dinyatakan sebagai : `G=(V, E)` Dimana G adalah Graph, V adalah simpul atau vertex dan E sebagai sisi atau edge[2]. Verteks atau simpul disebut juga titik atau noktah[1].

- Node, adalah struktur yang berisi sebuah nilai atau suatu kondisi atau menggambarkan sebuah struktur data terpisah atau sebuah bagian pohon itu sendiri.
- Edge, adalah penghubung antara satu node dengan node yang lain. Sebuah garis harus diawali dan diakhiri titik.
- Path adalah jalur dari satu titik ke titik lain. Sebuah path yang diawali dan diakhiri dengan titik yang sama disebut juga dengan simpul tertutup.[3]

Seringkali graf digunakan untuk merepresentasikan suatu jaringan. Misalkan jaringan jalan raya dimodelkan graf dengan kota sebagai simpul (vertex/node) dan jalan yang menghubungkan setiap kotanya sebagai sisi (edge) yang bobotnya (weight) adalah panjang dari jalan tersebut.[4]


## TREE
Tree/pohon merupakan struktur data yang tidak linear/non linear yang digunakan terutama untuk merepresentasikan hubungan data yang bersifat hierarkis antara elemen-elemennya[5].

Dalam ilmu komputer, pohon/tree adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. Ini terdiri dari satu set node tertaut yang terurut dalam grafik yang terhubung, dimana setiap node memiliki paling banyak satu simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. Struktur data tree digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, skema pertandingan, struktur organisasi[2].

### Operasi pada Tree[2]:
a. `Create` : digunakan untuk membentuk binary tree baru yang masih kosong.
b. `Clear` : digunakan untuk mengosongkan binary tree yang sudah ada atau menghapus semua node pada binary tree.
c. `isEmpty`: digunakan untuk memeriksa apakah binary tree masih kosong atau tidak.
d. `Insert` : digunakan untuk memasukkan sebuah node kedalam tree.
e. `Find` : digunakan untuk mencari root, parent, left child, atau right child dari suatu node dengan syarat tree tidak boleh kosong.
f. `Update` : digunakan untuk mengubah isi dari node yang ditunjuk oleh pointer current dengan syarat tree tidak boleh kosong
g. `Retrive` : digunakan untuk mengetahui isi dari node yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.h. `Delete Sub` : digunakan untuk menghapus sebuah subtree (node beserta seluruh descendant-nya) yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
i. `Characteristic` : digunakan untuk mengetahui karakteristik dari suatu tree. Yakni size, height, serta average lenght-nya.
j. `Traverse` : digunakan untuk mengunjungi seluruh node-node pada tree dengan cara traversal. Terdapat 3 metode traversal yaitu Pre-Order, In-Order, dan Post-Order


## Guided 

### 1. Program Graph

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {"ciamis",
                    "Bandung",
                    "Bekasi",
                    "Tasikmalaya",
                    "Cianjur",
                    "Purwokerto",
                    "Yogyakarta"};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] !=0)
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
#### Output :
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/09d6720c-20a3-4e21-87bb-9f7c0ecd6cae)


Pertama program akan mendeklarasikan array `simpul` yang memiliki panjang 7 untuk menyimpan nama-nama kota. Selanjutnya matriks `busur` dideklarasikan untuk menyimpan jarak antar kota yang ada di `simpul`. Elemen busur[i][j] menyimpan jarak dari kota i ke kota j. Jika jaraknya adalah 0,berarti tidak ada hubungan langsung (jalan) antara dua kota tersebut. 

Melalui fungsi `tampilGraph` program akan melakukan iterasi pada  setiap baris baris dalam matriks busur. Dimana pada setiap baris, nama kota (simpul) pada baris tersebut dicetak. Lalu program akan melakukan iterasi melalui setiap kolom kolom dalam matriks busur. Jika nilai busur[baris][kolom] bukan nol, maka kota kolom tersebut dicetak bersama dengan jaraknya dalam format -> kota(jarak). Hasilnya adalah daftar setiap kota dengan kota-kota yang terhubung dan jaraknya. Pada main, program akan memanggil memanggil fungsi tampilGraph untuk menampilkan graf kota dan jarak antar kota.


### 2. Tree

```C++
#include <iostream>

using namespace std;

//definisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

//Deklarasi variable global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

//fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

//Fungsi untuk membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul ->data = dataMasukkan;
    simpul ->kanan = NULL;
    simpul ->kiri = NULL;
}

//fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silahkan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

//fungsi untuk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j=1, penanda=0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni -> kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni ->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

//fungsi untuk membaca pohon
void bacaPohon() {
    if (root != NULL) {
        int i = 1, n=1, pencacah  = 0;
        cout << endl;
        while (alamat[i] != NULL) {
            saatIni = alamat[i];
            cout << saatIni->data << " ";
            pencacah++;
            if (pencacah == n){
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}

//fungsi utama
int main () {
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```
#### Output :
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/ae8c94da-586f-4d31-83fb-4f1ef7466a50)

Program ini menggunakan struktur pohon yang terdiri dari tiga komponen: `kanan, data, dan kiri`. `Kanan` dan `kiri` adalah pointer yang menunjuk ke simpul anak kanan dan kiri, sedangkan `data` adalah nilai yang disimpan di simpul tersebut.

Beberapa variabel untuk menyimpan informasi tree :
- `simpul` : pointer yang menunjuk ke simpul yang baru dibuat
- `root`: pointer yang menunjuk ke simpul akar pohon
- `saatIni` : pointer yang menunjuk ke simpul yang sedang diproses
- `helperA dan helperB` : pointer yang digunakan sebagai helper untuk memproses pohon
`alamat` : array of pointer yang digunakan untuk menyimpan alamat simpul-simpul di pohon

Fungsi utama mengatur jalannya program:
- `inisialisasi()`:  untuk memulai dengan root kosong.
- `simpulAkar()` : untuk meminta pengguna memasukkan nilai untuk simpul akar.
- `tambahSimpul()` : untuk menambahkan simpul-simpul ke pohon.
- `bacaPohon()` : untuk membaca pohon

Variabel global diinisiasi dengan nilai NULL melalui fungsi `inisialisasi()`. Fungsi `simpulBaru(char dataMasukkan)` digunakan untuk membuat simpul baru dengan nilai `dataMasukkan` Untuk membuat simpul akar tree program menggunakan fungsi `simpulAkar()`.  Fungsi ini akan memasukkan nilai untuk simpul akar, kemudian membuat simpul baru dengan nilai tersebut dan menginisialisasi root dengan simpul baru tersebut. Fungsi `tambahSimpul()` digunakan untuk menambah simpul baru ke tree.


## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/a12fbf37-9a34-49ba-a6d6-d43530d40e52)

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int CandraManikaDewi_2311110026;
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> CandraManikaDewi_2311110026;

    vector<string> nodes(CandraManikaDewi_2311110026);
    vector<vector<int>>
distances(CandraManikaDewi_2311110026,
vector<int>(CandraManikaDewi_2311110026));

// Masukkan nama simpul
    cout << "Silakan masukkan nama simpul" << endl;
    for (int i = 0; i < CandraManikaDewi_2311110026;
i++) {
    cout << "Simpul " << i + 1 << " : ";
    cin >> nodes[i];
}

// Masukkan bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < CandraManikaDewi_2311110026;
i++) {
    for (int j = 0; j < CandraManikaDewi_2311110026; j++) {
    cout << "" << nodes[i] << " ---> " <<
    nodes[j] << " = ";
    cin >> distances[i][j];
    }
}
    cout << "\t";
    for (int i = 0; i < CandraManikaDewi_2311110026; i++) {
    cout << nodes[i] << "\t";
}
    cout << endl;
    for (int i = 0; i < CandraManikaDewi_2311110026; i++) {
    cout << nodes[i] << "\t";
    for (int j = 0; j < CandraManikaDewi_2311110026; j++) {
    cout << distances[i][j] << "\t";
    }
    cout << endl;
    }
return 0;
}

```
#### Output
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/78d868bf-77f7-422e-979a-1d58104dea9a)

### Interpretasi: 
Program akan mendeklarasikan variabel interger `numCities` untuk menyimpan jumlah kota inputan user. Vektor `cities`akan dideklarasikan dan diinisiasi untuk menyimpan nama-nama kota. `vector<vector<int>> distanceMatrix(numCities, vector<int>(numCities, 0));` digunakan untuk deklarasi `distanceMatrix` untuk menyimpan jarak antar kota. 

Pertama program akan meminta user untuk memasukkan jumlah simpul lalu nama-nama kota menggunakan perulangan (loop) dan nama tersebut akan disimpan di vektor `cities`. Selanjutnya user akan diminta untuk memasukkan jarak dari kota  `cities[i]` ke kota `cities[j]`, lalu melalui nested loop `for` setiap jarak antar pasangan kota tersebut akan disimpan. `Loop luar` mengiterasi setiap kota asal `(i)`, dan `loop dalam` mengiterasi setiap kota tujuan `(j)`. 

Selanjutnya program akan menampilkan header matriks dengan nama-nama kota dengan `setw` untuk mengatur lebarnya. Selanjutnya melalui perulangan `(loop)` setiap baris matriks jalan akan ditampilkan di kolom pertama setiap baris dengan lebar kolom 7 karakter. Jarak antar kota `distanceMatrix[i][j]` ditampilkan dengan lebar kolom 4 karakter. Lalu program akan mengembalikan nilai 0 untuk menandakan program telah berakhir.
 
#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/39a82a4f-e575-4c58-bdd5-8dd9333f0950)


### 2.  Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!

```C++
//A.A. Istri Candra Manika Dewi
//2311110026
#include <iostream>
using namespace std;

// Definisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// Deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

// Fungsi untuk membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}
// Fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silahkan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}
// Fungsi untuk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;
        // Memasukkan child
        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri (0 untuk berhenti): ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan (0 untuk berhenti): ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}
// Fungsi untuk pre-order
void preOrder(pohon* node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}
// Fungsi untuk in-order
void inOrder(pohon* node) {
    if (node != NULL) {
        inOrder(node->kiri);
        cout << node->data << " ";
        inOrder(node->kanan);
    }
}
// Fungsi untuk post-order
void postOrder(pohon* node) {
    if (node != NULL) {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << node->data << " ";
    }
}
// Menampilkan menu
void tampilkanMenu() {
    cout << "Menu:" << endl;
    cout << "1. Tambah Root" << endl;
    cout << "2. Tambah Simpul" << endl;
    cout << "3. Tampilkan Pre-order" << endl;
    cout << "4. Tampilkan In-order" << endl;
    cout << "5. Tampilkan Post-order" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih opsi: ";
}

// Fungsi utama
int main() {
    inisialisasi();
    int choice;
    do {
        tampilkanMenu();
        cin >> choice;
        switch (choice) {
            case 1: // input simpul akar
                simpulAkar(); // 
                break;
            case 2: // menambah simpul
                tambahSimpul();
                break;
            case 3: // untuk menampilkan traversal secara pre-order
                cout << "Pre-order: "; 
                preOrder(root);
                cout << endl;
                break;
            case 4: // untuk menampilan traversal secara in-order
                cout << "In-order: "; 
                inOrder(root);
                cout << endl;
                break;
            case 5: // untuk menampilan traversal secara post-order
                cout << "Post-order: ";
                postOrder(root);
                cout << endl;
                break;
            case 6: // untuk mengakhiri menu
                cout << "Keluar dari program." << endl;
                break;
            default: // error message jika inputan tidak valid
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (choice != 6);
    return 0;
}
```
#### Output
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/20f1930c-cc0b-4379-bc8a-5495f45bf893)


![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/47fea0b0-2f7a-4d9c-bd71-9e0d8e722397)



### Interpretasi: 
Program ini menggunakan struktur pohon yang terdiri dari tiga komponen: `kanan, data, dan kiri`. `Kanan` dan `kiri` adalah pointer yang menunjuk ke simpul anak kanan dan kiri, sedangkan `data` adalah nilai yang disimpan di simpul tersebut.

Beberapa variabel untuk menyimpan informasi tree :
- `simpul` : pointer yang menunjuk ke simpul yang baru dibuat
- `root`: pointer yang menunjuk ke simpul akar pohon
- `saatIni` : pointer yang menunjuk ke simpul yang sedang diproses
- `helperA dan helperB` : pointer yang digunakan sebagai helper untuk memproses pohon
`alamat` : array of pointer yang digunakan untuk menyimpan alamat simpul-simpul di pohon

Variabel global diinisiasi dengan nilai NULL melalui fungsi `inisialisasi()`. Fungsi `simpulBaru(char dataMasukkan)` digunakan untuk membuat simpul baru dengan nilai `dataMasukkan` Untuk membuat simpul akar tree program menggunakan fungsi `simpulAkar()`.  Fungsi ini akan meminta user untuk memasukkan nilai untuk simpul akar, kemudian membuat simpul baru dengan nilai tersebut dan menginisialisasi root dengan simpul baru tersebut. Fungsi `tambahSimpul()` digunakan untuk menambah simpul baru ke tree. Fungsi ini akan meminta user untuk memasukkan nilai untuk simpul baru, kemudian membuat simpul baru dengan nilai tersebut dan menambahkannya ke tree.

Fungsi `preOrder(pohon* node), inOrder(pohon* node), dan postOrder(pohon* node)` digunakan untuk melakukan traversal pohon secara pre-order, in-order, dan post-order. Fungsi-fungsi ini akan mencetak nilai-nilai simpul di pohon dalam urutan yang sesuai dengan traversal yang dipilih.

Pada main program akan memanggil fungsi `inisialisasi()` untuk menginisialisasi variabel global. lalu program akan memanggil fungsi `tampilkanMenu()`untuk menampilkan menu kepada user. Opsi dipilih menggunakan angka dari 1 sampai 6. Jika memasukkan inputan selain angka tersebut maka program akan menampilkan error message.

#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/5cb7eab7-4b09-49eb-a934-3aa46723b3de)


## Kesimpulan
Pada materi kali ini kita mempelajari bagaimana implementasi graf dan tree. Graf adalah kumpulan simpul yang terhubung oleh sisi dan digunakan untuk merepresentasikan berbagai hubungan antara entitas. Salah satu jenis graf yaitu, graf terarah dan tak terarah. Contoh: jaringan sosial, jaringan transportasi, graf jalan raya. Tree (pohon) adalah jenis khusus dari graf yang tidak memiliki siklus. Memiliki simpul akar dan setiap simpul memiliki satu simpul induk kecuali simpul akar. Digunakan untuk representasi data hierarkis dan sering digunakan dalam struktur data seperti pohon biner. Contoh struktur direktori pada komputer.

## Referensi
[1]F. Daniel and P. N. L. Taneo, Teori Graf. Deepublish, 2019. Accessed: Jun. 06, 2024. [Online]. Available: https://www.google.co.id/books/edition/Teori_Graf/r0HGDwAAQBAJ?hl=id&gbpv=1&dq=graf&pg=PR10&printsec=frontcover

[2] Karumanchi, N. (2011). Data Structures and Algorithms Made Easy: 700 Data Structure and Algorithmic Puzzles. CreateSpace.

[3] R. Nurul, “Data Structure : Mengenal Graph & Tree,” Ramdannur, Nov. 10, 2020. https://ramdannur.wordpress.com/2020/11/10/data-structure-mengenal-graph-tree/ (accessed Jun. 06, 2024).

[4]“Graf (Graph) dan Pohon (Tree) - Algoritma Pemrograman 2,” ahmadhadari77.blogspot.com. https://ahmadhadari77.blogspot.com/2019/05/graph-graf-dan-tree-pohon-algoritma.html (accessed Jun. 06, 2024).

[5]“Struktur Data -Tree.” Available: https://repository.unikom.ac.id/46090/1/TREE.pdf (accessed Jun. 06, 2024).



