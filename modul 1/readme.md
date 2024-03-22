
# <h1 align="center">Laporan Praktikum Algoritma dan Struktur Data-Modul Tipe Data</h1>
<p align="center">A.A Istri Candra Manika Dewi</p>


## Dasar Teori

Data type atau tipe data adalah klasifikasi value suatu variable yang membantu operasi komputer untuk mengenali nilai data tanpa menghasilkan output error [3]. Dalam C++, terdapat 3 tipe data yang dijelaskan yaitu tipe data primitif, tipe data abstrak, dan tipe data koleksi.

### 1. Tipe Data Primitif
Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem, tipe data primitif ini disediakan oleh banyak bahasa pemrograman, perbedaannya terletak pada jumlah bit yang dialokasikan untuk setiap bit pada tipe data primitif tergantung pada bahasa pemrograman, compiler dan sistem operasinya. Contoh tipe data primitif adalah :
- Int adalah tipe data yang digunakan untuk menyimpan bilangan bulat seperti 12, 1, 4, dan sebagainya
- Float adalah tipe data yang digunakan untuk menyimpan bilangan desimal seperti 1.5, 2.1, 3.14, dan sebagainya
- Char berfungsi untuk menyimpan data berupa sebuah huruf. Biasanya digunakan untuk simbol seperti A, B, C dan seterusnya
- Bool tipe data ini digunakan untuk menyimpan nilai boolean yang hanya memiliki dua nilai yaitu true dan false

### 2. Tipe Data Abstrak
Tipe data abstrak atau yang biasa disebut Abstrak Data Tipe(ADT) merupakan tipe data yang dibentuk oleh programer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data. Fitur Class adalah fitur Object Oriented Program(OPP) pada bahasa C++ yang mirip dengan fitur data structures Struct pada bahasa C. Keduanya berfungsi untuk membungkus tipe data di dalamnya sebagai anggota. Menurut learn.microsoft.com perbedaan antara Struct dan Class adalah pada akses defaultnya dimana Struct bersifat public dan Class bersifat private.

### 3. Tipe Data Koleksi
Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. Ada beberapa tipe data koleksi yang umum digunakan dalam pemrograman, dan di antaranya adalah:
- Array adalah struktur data statis yang menyimpan elemen-elemen dengan tipe data yang sama. Elemen-elemen tersebut dapat diakses dengan menggunakan indeks. Array memiliki ukuran tetap yang ditentukan saat deklarasi.
- Vector adalah Standard Template Library (STL) jika di dalam C/C++ memiliki bentuk std::vector . Umumnya, vector mirip seperti array yang memiliki kemampuan untuk menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan otomatis dan bersebelahan. Kemampuan vector bukan hanya pada jumlah elemen yang dinamis, vector pada C/C++ juga dilengkapi dengan fitur-fitur pelengkap seperti element access, iterators, capacity, modifiers
- Map terasa mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer. Pada map, indeks tersebut diberi nama “key”. Pada std::map digunakan Self-Balancing Tree khususnya Red-Black Tree.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>

using namespace std;

// Main program
int main() 
{
    char op;
    float num1, num2;

    //It allows user to enter operator i.e. +, -, *, /
    cout << "Enter a Operator: " << endl;
    cin >> op;

    //It allows user to enter the operations
    cout << "Enter Number 1 & 2: " << endl;
    cin >> num1 >> num2;

    //Switch statement begins
    switch (op)
    {
    //If user enter +
    case '+':
        cout << num1 + num2;
        break;

    //If user enter -
    case '-':
        cout << num1 - num2;
        break;

    //If user enter *
    case '*':
        cout << num1 * num2;
        break;

    //If user enter /
    case '/':
        cout << num1 / num2;
        break;

    //If the operatior is other that +, -, * or /,
    //error message will display
    default:
        cout << "Error! operator is not correct";
    }//switch statement ends
    return 0;
}
```
### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/3c3bcb70-83ef-4a91-81d2-69c1e0ea823d)

Kode diatas merupakan program untuk menampilkan aritmatika dasar (penjumlahan, pengurangan, perkalian, dan pembagian) untuk dua bilangan. Pada awal program user diminta untuk menginputkan operator yang akan dipilih untuk melakukan operasi aritmatika dasar. Setelah menginputkan operator, user diminta untuk menginputkan angka pertama dan angka kedua. Lalu program akan menjalankannya sesuai dengan inputan dari user. Program ini menggunakan `switch-case` untuk menjalankan operasinya. Kemudian jika user menginputkan tidak sesuai dengan operator yang sudah ditentukan, maka program akan menampilkan pesan error.

### 2. Tipe Data Abstrak

```C++
#include <iostream>
using namespace std;

//struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //menggunakan struct
    struct Mahasiswa mhs1, mhs2;

    //mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    //mencetak isi struct
    cout << "-----Mahasiswa 1-----" << endl;
    cout << "Nama: " << mhs1.name <<endl;
    cout << "Alamat: " << mhs1.address <<endl;
    cout << "Umur: " << mhs1.age <<endl;
    cout << "-----Mahasiswa 2-----" << endl;
    cout << "Nama: " << mhs2.name <<endl;
    cout << "Alamat: " << mhs2.address <<endl;
    cout << "Umur: " << mhs2.age <<endl;

    return 0;
}
```
### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/6cd722c4-6b09-445f-ae85-168347801b22)

Kode diatas merupakan contoh program yang menggunakan tipe data abstrak, yaitu struct. Program diatas menggunakan struct `Mahasiswa` yang memuat tiga nilai yaitu `name` dan `address` yang sama-sama bertipe data character, dan ada `age` yang bertipe data integer. Lalu terdapat `const` pada nilai `name` dan `address` yang berfungsi supaya object atau variabel tidak dapat dimodifikasi. Setelah itu kita bisa mengisi data dengan membuat dua variabel yang bertipe data struct `Mahasiswa`, yaitu `mhs1` dan `mhs2`. Setelah itu kita tinggal mengisi data tersebut ke masing-masing variabel dan menampilkannya menggunakan fungsi `cout`.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;

int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
}
```
### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/5d4724b4-21d0-4ac4-8a92-f59641f82842)

Kode diatas adalah contoh program yang menggunakan tipe data koleksi. Pertama kita mendeklarasikan dan menginialiasikan array `nilai` yang mempunyai tipe data integer. Untuk `[5]` adalah merupakan ukuran panjang array yang akan kita gunakan. Lalu kita bisa mengisikan data ke dalam variabel `nilai`, seperti `nilai[0]` atau elemen pertama dalam array kita isi dengan angka 23, lalu untuk elemen ke dua kita isi dengan angka 50, untuk elemen ketiga kita isi dengan angka 34, untuk elemen keempat kita isi dengan angka 78, dan elemen ke lima kita isi dengan angka 90. Setelah kita selesai mengisikan nilai ke setiap elemen dalam array kita bisa menampilkan setiap nilai dalam array menggunakan fungsi `cout`.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

char menu; //mendefinisikan variabel menu dengan tipe data character
int luas, tinggi, alas, keliling, sisi1, sisi2, sisi3; //mendefinisikan variabel dengan type data float

void choice() { //variable choice difungsikan untuk memilih menu yang ingin digunakan
	cout <<"===Geometry Calculator==="<< endl; //menu
	cout << "1. Luas SegiTiga" << endl;
	cout << "2. Keliling Segitiga" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> menu;
}

int wide() {
	cout << "Input Alas SegiTiga: "; //menginputkan  alas segitiga
	cin >> alas;
    cout << "Input Tinggi SegiTiga: "; //menginputkan tinggi segitiga
	cin >> tinggi;

	luas = (alas*tinggi/2); //rumus menghitung luas segitiga

	cout << "Luas SegiTiga: " << luas << "Cm" << endl; //menampilkan output
	return luas = (alas*tinggi/2);
}

int kll() {
    cout << "Input Panjang Sisi 1: "; //menginputkan sisi pertama
    cin >> sisi1;
    cout << "Input Panjang Sisi 2: "; //meninputkan sisi kedua
    cin >> sisi2;
    cout << "Input Panjang Sisi 3: "; //menginputkan sisi ketiga
    cin >> sisi3;

    keliling = (sisi1 + sisi2 + sisi3); //rumus menghitung keliling segitiga

    cout << "Keliling SegiTiga: " <<keliling<<"Cm"<<endl; //menampilkan output
    return keliling = (sisi1 + sisi2 + sisi3);
}

int main() { //main menu
    do { //menggunakan looping do - while
        choice(); //memanggil variable choice
        switch (menu) {
            case '1': //jika mengiputkan angka "1" maka akan menghitung luas segitiga
                wide(); //menampilkan variable luas segitiga
                break;

            case '2': //jika menginputkan angka "2" maka akan menghitung keliling segitiga
                kll(); //menampilkan variabel keliling segitiga
                break;

            case '0': //jika ingin keluar dari looping maka bisa menginputkan angka 0
                cout << "Thank you user. See u!" << endl;
                break;

            default: //error message jika menginputkan selain anka 1, 2, dan angka 0
    			cout << "Invalid input. Please enter either '1', '2', or '0'." << endl;
    			break;
        }
    } while (menu != '0'); //jika user menginputkan angka selain 0 maka program otomatis akan mengulang hingga user menginputkan angka 0 untuk mengakhiri loop
    return 0;
}

```
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/bb0bdd17-c898-4874-bf03-1f22f839d3da)

Kode diatas merupakan program yang digunakan untuk menghitung luas dan keliling segitiga. Pertama kita mendeklarasikan variabel yang akan digunakan untuk memilih menu, menginputkan panjang sisi1, sisi2, sisi3, alas, dan tinggi, sertia menampilkan hasil perhitungan dalam satuan cm. untuk variabel `menu` kita menggunakan tipe data character, `luas`, `alas`, `tinggi`, `sisi1`, `sisi2`, dan `sisi3` yang digunakan untuk menginputkan nilai panjang yang diketahui. Langkah selanjutnya kita membuat variabel `choice` yang berfungsi untuk menampilkan menu. Selanjutnya kita membuat variabel `wide` yang berfungsi untuk menghitung luas segitiga. Kemudian kita membuat variabel `kll` yang berfungsi untuk menghitung keliling segitiga.

Setelah selesai membuat variabel yang akan digunakan untuk mengonversikan suhu, lalu kita akan menggunakan looping `do-while`. Looping ini berfungsi supaya jika user menginputkan angka atau huruf selain 0 atau `menu != 0`, maka program akan terus berjalan menampilkan menu. Lalu kita menggunakan `switch-case` supaya jika user menginputkan angka `1` maka akan melakukan perhitungan luas dan jika menginputkan angka `2` maka akan melakukan perhitungan keliling. Lalu jika menginputkan angka `0` maka program otomatis akan berhenti dan menampilkan pesan, namun jika user menginputkan selain ketiga huruf dan angka diatas, maka akan muncul pesan error yang membuat program akan terus berjalan sehingga user harus memasukan operator yang tepat untuk menggunakan program diatas ataupun untuk menghentikan program.

Kesimpulan dari materi tipe data primitif ini adalah tipe data ini merupakan tipe data yang sederhana, karena tipe data ini merupakan tipe data bawaan dari bahasa pemrograman. Tipe data ini bisa menyimpan niali seperti digit, byte, ataupun karakter. Namun, tipe data primitif tidak bisa menjangkau data kompleks yang memiliki tingkat kerumitan tinggi.

#### Code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/120793cd-95ef-4b56-9985-85b2a69e82dc)

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

```C++
#include <iostream> //input preprocessor directive
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

struct figure { //membuat struct figure
	string name; //berisi variable name yang bertipe data string
	int age; //dan variable age yang bertipe data int

};

class character { //membuat class character
	public:
		string species; //berisi variable species yang bertipe data string
		string habitat; //variable citizenship yang bertipe data string
		string pets; //variable pets yang bertipe data string
};

int main() { //program utama atau main program
	struct figure one; //memanggil struct figure yang sudah dibuat diatas

	//memasukan data ke dalam struct
	one.name = "Mario Dandy";
	one.age = 23;

	//menampilkan data struct yang sudah masukan tadi
	cout << "===STRUCT===" << endl;
	cout << "Name: " << one.name << endl;
	cout << "Age: " << one.age << endl;

	//memanggil class character
	character two;

	//memasukan data ke dalam class
	two.species = "Predator";
	two.habitat = "Samudra hindia";
	two.pets = "Paus, Hiu, Marlin, Swordfish";

	//menampilkan data class yang sudah dimasukkan
	cout << "=====CLASS=====" << endl;
	cout << "Species: " << two.species << endl;
	cout << "habitat: " << two.habitat << endl;
	cout << "Pets: " << two.pets << endl;

	return 0;
}
```
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/cbe89930-33eb-45cb-91ca-be4d901f1bc5)

Class merupakan blueprint (cetak biru) untuk menciptakan suatu instance dari objek dimana terdiri dari sekumpulan objek dengan kemiripan data / properties / attributes, fungsi / behavior / method dan relasi ke objek lain. Permograman C++ memungkinkan pembuatan class lebih dari 1. Ketika data dan fungsi yang terkait disimpan di dalam sebuah class mampu membantu mem-visualisasikan permasalahan yang kompleks dengan efisien dan efektif.[1] 

Structures (struct) pada C++ adalah keyword di bahasa pemrograman C++ yang dapat digunakan untuk mengelompokkan data dan fungsi. Struct dapat mengelompokkan data/variabel – variabel dan fungsi – fungsi yang saling berhubungan dalam satu nama. Variabel – variabel di dalam struct dapat disebut dengan anggota dari struct. Anggota dari struct dapat memiliki tipe data yang berbeda satu sama lain. Tidak seperti array yang semua anggotanya memiliki tipe data yang sama. Struct menjadi tipe data baru yang mengelompokkan anggota anggotanya. Lalu, anggotanya dapat diakses melalui struct tersebut.[2]

Struct mirip dengan class. Keduanya sama – sama mengelompokkan data dan fungsi. Perbedaan antara keduanya, diantaranya: default member access struct adalah public sedangkan default member access class adalah private, struct tidak dapat digunakan sebagai parent di pewarisan sedangkan class dapat digunakan sebagai parent di pewarisan, dan masih banyak lagi. [3]

Contoh program yang menggunakan struct yaitu program diatas. Program diatas mengandung tipe data `struct` dengan variabel `figure`. Di dalam variabel `figure`, terdapat variabel `name` yang mempunyai tipe data character dan `age` yang bertipe data integer. Lalu kita membuat `class` dengan variabel `character` yang berisikan variabel `species`, `citizenship`, dan `pets` yang bertipe data string dengan akses public. Lalu kita masukkan nilainya pada main program dengan cara membuat variabel baru yang dinamakan `one` untuk memasukkan data pada struct dan `two` untuk variabel untuk memasukan data ke dalam `class`. Setelah dimasukan kita bisa menampilkannya menggunakan variabel `cout`.

#### Code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/a58e0632-da2a-4c95-a7f0-4255a5471d4f)

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map

```C++
#include <iostream> //input preprocessor directive
#include <map> //input map
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

int main() { //main program
	map <int, string> character; //membuat map dengan key int dan bertipe data string

	//menginputkan karakter
	character[0] = "Aca";
	character[1] = "Aya";
	character[2] = "Sara";
	character[3] = "Ade";
	character[4] = "Vania";

	//menampilkan karakter yang sudah dibuat
	cout << "====CHARACTER LIST====" << endl;
	cout << "Karakter pertama : " << character[0] << endl;
	cout << "Karakter kedua : " << character[1] << endl;
	cout << "Karakter ketiga : " << character[2] << endl;
	cout << "Karakter keempat : " << character[3] << endl;
	cout << "Karakter kelima : " << character[4] << endl;

	return 0;
}
```
#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/4f8004c3-7b3b-4229-8ac9-3c5bdc64d7fd)

Kode diatas merupakan contoh program yang menggunakan fungsi map. Pertama kita deklarasikan dulu map nya dengan menggunakan `#include <map>`, lalu pada main program kita menggunakan fungsi map dengan menginputkan `<int, string> character`. Code tersebut digunakan untuk membuat map dengan key int yang bertipe data string dengan nama variabel `character`. Lalu kita tinggal menambahkan datanya ke dalam variabel `character` dan menampilkannya menggunakan fungsi `cout`.

Perbedaan antara map dan array adalah array digunakan untuk menyelesaikan masalah matriks, mudah dalam menerapkan algoritma sorting, penjadwalan CPU, diterapkan sebagai tabel pencarian di komputer. Map digunakan ketika kita ingin menghasilkan array baru berdasarkan array asli.

#### Code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/ca0373bd-d71d-4231-acdd-3d00e4cfa87a)

## Kesimpulan
Pada modul 1 guided ini kita belajar mengenai tipe data yang ada pada bahasa C++. Ada 3 tipe data yang ada yaitu tipe data primitif, tipe data abstrak, dan tipe data koleksi. Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem. Untuk tipe data abstrak merupakan tipe data yang dibentuk oleh programer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data, dan yang terakhir tipe data koleksi adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan.

Kemudian untuk modul 1 unguided kita belajar mengenai membuat program menggunakan tipe data primitif minimal dua fungsi, membuat program yang menggunakan fungsi class dan struct, dan yang terakhir membuat program yang menggunakan fungsi map.

## Referensi

[1] Binus University, Class and Object : Object Oriented Programming using C++, diakses dari https://socs.binus.ac.id/2016/12/13/class-and-object-object-oriented-programming-using-c/

[2] Josi Kie, Apa Itu Struct di C++?, diakses dari https://josikie.com/apa-itu-struct-di-c/

[3] Revou.co, Apa itu Tipe Data dalam Pemrograman?, diakses dari https://revou.co/kosakata/tipe-data
