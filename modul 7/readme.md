
# <h1 align="center">Laporan Praktikum Algoritma dan Struktur Data Modul-7 Stack & Queue</h1>
<p align="center">A.A Istri Candra Manika Dewi </p>


## Dasar Teori
### Stack
<p>Stack adalah struktur data sederhana yang digunakan untuk menyimpan data. Dengan demikian, stack merupakan salah satu struktur data yang menerapkan prinsip LIFO (Last In First Out). Dimana elemen yang terakhir disimpan dalam stack, menjadi elemen yang pertama diambil. Untuk meletakkan sebuah elemen pada bagian atas dari stack, maka dilakukan operasi push. Sedangkan untuk memindahkan sebuah elemn dari tempat atas tersebut dalam sebuah stack, maka dilakukan operasi pop [1].</p>

<p>Queue atau antrian adalah suatu bentuk khusus dari List Linier dengan operasi penyisipan (insertion) hanya diperbolehkan pada salah satu sisi, yang disebut sisi belakang (REAR), dan operasi penghapusan (deletion) hanya diperbolehkan pada sisi yang lainnya. Queue merupakan kumpulan data dengan penambahan data hanya melalui satu sisi, yaitu belakang (tail) dan penghapusan data hanya melalui sisi depan (head). Berbeda dengan stack yang bersifat LIFO maka queue bersifat FIFO (First In First Out), yaitu data yang pertama masuk akan keluat terlebih dahulu dan data yang terakhir masuk akan keluar terakhir [2].</p>

## Guided 

### 1. Latihan 1
C++
```
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```
### Penjelasan: 
<p>Kode ini mengimplementasikan struktur data stack menggunakan array arrayBuku yang mampu menyimpan hingga 5 elemen bertipe string. Berbagai fungsi disediakan untuk mengelola stack ini, seperti menambah (push), menghapus (pop), mengintip elemen tertentu (peek), mengganti elemen (change), menghitung jumlah elemen (count), menghapus semua elemen (destroy), dan mencetak semua elemen stack (cetak).</p>


### 2. Latihan 2

C++
```
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
### Penjelasan:
<p>Kode ini mengelola antrian menggunakan array queueTeller yang mampu menyimpan hingga 5 elemen bertipe string. Berbagai fungsi disediakan untuk mengelola antrian ini, seperti menambah elemen ke antrian (enqueue), menghapus elemen dari antrian (dequeue), menghitung jumlah elemen dalam antrian (countQueue), menghapus semua elemen dari antrian (clearQueue), dan melihat isi antrian (viewQueue).</p>


## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom atau tidak. Palindrom kalimat yang dibaca dari dengan dan belakang sama. Jelaskan bagaimana kerja programnya. Contoh:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/c52bf731-a2dc-4c84-b108-72db1f11700b)

C++
```
//A.A Istri Candra Manika Dewi
//2311110026
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menghapus spasi dari string
string removeSpaces(const string& str) {
    string processedStr;
    for(size_t i = 0; i < str.length(); ++i) {
        if(str[i] != ' ') {
            processedStr += str[i];
        }
    }
    return processedStr;
}

// Fungsi untuk menentukan apakah sebuah string adalah palindrom atau tidak
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;

    // Perbandingan karakter dari kedua ujung string
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    string processedInput = removeSpaces(input);

    // Cek apakah string yang sudah diproses adalah palindrom atau tidak
    if (isPalindrome(processedInput)) {
        cout << "Kalimat ini adalah palindrom." << endl;
    } else {
        cout << "Kalimat ini bukan palindrom." << endl;
    }
    

    return 0;
}

```
### Penjelasan :
<p>Kode diatas merupakan program untuk menentukan apakah sebuah kata adalah polindrom atau bukan. 

Pertama program akan membersihkan kata/ kalimat dari karakter non-alfanumerik dan mengubah huruf menjadi huruf kecil. Lalu melalui loop setiap karakter akan dicek apakah alfanumerik menggunakan isalnum. Jika iya, maka program akan mengubahnya menjadi huruf kecil menggunakan tolower dan ditambahkan ke string cleaned. 

Selanjutnya program akan memeriksa melalui fungsi is_palindrome apakah kata inputan user merupakan polindrom atau bukan menggunakan stack. Kemudian, karakter dari kata/ kalimat dibandingkan dengan karakter dari top stack. Jika semua karakter cocok, maka kalimat tersebut adalah palindrom Jika ada perbedaan, maka kalimat tersebut bukan palindrom.

Pada main program akan meminta user untuk menginputkan kata menggunakan getline. Lalu kalimat tersebut akan diperiksa menggunakan fungsi is_palindrome dan hasilnya akan dicetak. Jika kata merupakan palindrom maka program akan mencetak Kalimat tersebut adalah palindrom jika bukan maka program akan menampilkan Kalimat tersebut bukan palindrom. Setelah selesai, program akan menampilkan nama pembuat program.</p>


#### Output:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/03344dea-0571-457f-9617-96bed3500ab1)
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/67d04535-91d4-4605-ade6-6a0b5d1fdeac)



#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/82f1d084-04cc-4779-9047-fb9d1b435311)

### 2. Ubah guided queue diatas agar menjadi program inputan user dan program menu.

c++
```
//A.A Istri Candra Manika Dewi
//2311110026

#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; 
int back = 0; 
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    return back == maksimalQueue;
}

bool isEmpty() { 
    return back == 0;
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    int choice;
    string data;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Kurangi Antrian" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Jumlah Antrian" << endl;
        cout << "5. Kosongkan Antrian" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan nama untuk ditambahkan ke antrian: ";
                cin >> data;
                enqueueAntrian(data);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Jumlah antrian = " << countQueue() << endl;
                break;
            case 5:
                clearQueue();
                break;
            case 6:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while(choice != 6);
    
    return 0;
}

```
## Ouput
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/4ad00bc3-021c-41bd-af0a-93780acdea18)
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/af55acc8-d91c-4152-b8aa-e77b19e1919d)
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/dd4ccd71-98af-427b-b74d-d5b3f7bad7d6)


## Full Code SS
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/15c1c31a-7409-40e6-a5f9-826ad3eb565a)


## Penjelasan:
<p>Pertama program akan menentukan ukuran maksimal queue pada `const int maksimalQueue` yaitu 5. `int front = 0`; dan `int back = 0` menandai posisi depan dan belakang dari queue. Elemen-elemen dalam queue disimpan dalam array `string queueTeller[5]`.

- Fungsi `bool isFull()` digunakan untuk mengecek apakah queue penuh atau tidak. 
- Fungsi `bool is Empty` digunakan untuk mengecek apakah queue kosong atau tidak.
- Fungsi `void enqueueAntrian(string data)` digunakan untuk menambahkan elemen baru ke dalam antrian. Jika antrian penuh maka program akan mencetak pesan "Antrian penuh". Jika 
ika antrian kosong, menambahkan elemen pada posisi pertama dan menaikkan `front` dan `back`
- Fungsi `void dequeueAntrian()` digunakan untuk menghapus elemen depan dari antrian.
- `int countQueue()` digunakan untuk mengembalikan jumlah elemen dalam antrian. 
- `void clearQueue` digunakan untuk menghapus semua elemen dalam queue. 
- `void viewQueue` digunakan untuk menampilkan isi queue.

Pertama program akan mendeklarasikan variabel `int choice` untuk menyimpan pilihan menu user dan `string name` yang menyimpan nama yang akan dimasukkan ke queue. Lalu program akan menampilkan opsi menu melalui `void displayMenu()`. Program dapat menambahkan, menghapus, menampilkan, atau menghapus semua elemen dalam antrian sesuai dengan pilihan pengguna. Melalui perulangan `(loop do-while)` program akan menampilkan menu dan memproses inputan user sampai user memilih untuk keluar (opsi 6). Setelah keluar dari loop,program akan mencetak nama pembuat program.
</p>

## Kesimpulan:
Kesimpulan tentang stack dan queue adalah sebagai berikut:

- Stack (tumpukan) adalah suatu koleksi item data yang terorganisasi dalam bentuk urutan linier, dengan operasi pemasukan dan penghapusan datanya dilakukan pada salah satu sisinya. Stack mengikuti prinsip LIFO (Last In First Out), yang berarti elemen yang dimasukkan terakhir akan menjadi elemen pertama yang keluar dari urutan data.
- Queue (antrian) adalah suatu kumpulan data yang mengikuti aturan FIFO (First In First Out), dimana elemen yang pertama masuk akan pertama keluar. Queue digunakan untuk menampung elemen-elemen yang akan diproses secara berurutan, seperti antrian di kasir bank.
- Stack dan queue adalah struktur data yang digunakan dalam pemrograman, seperti dalam pemrograman Java, dan memiliki aplikasi dalam kehidupan sehari-hari.
- Stack dan queue memiliki operasi dasar seperti inisialisasi, push, pop, size, empty, dan full, serta memiliki kelebihan dan kekurangan dalam implementasinya.



## Referensi
[1] "PRAKTIKUM ALGORITMA DAN STRUKTUR DATA". [Online]. Available: (https://elektro.um.ac.id/wp-content/uploads/2016/04/ASD-Modul-4-STACK.pdf) [Accessed 16 Mei 2024].


[2] "Program Studi Teknik Informatika Fakultas Ilmu Komputer Universitas Esa Unggul 2018". [Online]. Available : (https://lms-paralel.esaunggul.ac.id/pluginfile.php?file=%2F92127%2Fmod_resource%2Fcontent%2F1%2FModul%20Struktur%20Data-QUEUE.docx) [Accessed 16 Mei 2024].
