
# <h1 align="center">Laporan Praktikum Algoritma dan Struktur Data Modul-7 Stack & Queue</h1>
<p align="center">A.A Istri Candra Manika Dewi </p>


## Dasar Teori
### Stack
<p>Stack adalah struktur data sederhana yang digunakan untuk menyimpan data. Dalam tumpukan, urutan kedatangan data sangat penting</p>
<p>Linked List adalah struktur data linier yang terdiri dari serangkaian node yang dihubungkan oleh pointer. Setiap node berisi data dan referensi ke node berikutnya dalam daftar. Tidak seperti array, daftar tertaut memungkinkan penyisipan atau penghapusan elemen secara efisien dari posisi mana pun dalam daftar, karena node tidak disimpan secara berdekatan di memori [1].</p>
<p><b>Type Of Linked List</b></p>

- Singly Linked List

- Doubly Linked List

- Circular Linked List

- Circular Doubly Linked List

- Header Linked List

## Guided 

### 1. Latihan Single Linked List
C++
```
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```
### Penjelasan: 
<p>Kode di atas merupakan implementasi program Single Linked List Non-Circular. Struktur data ini terdiri dari node-node yang terhubung secara berantai dengan pointer next. Struktur data ini dapat digunakan untuk merepresentasikan kumpulan data terurut, seperti daftar kontak atau daftar pembelian. Fungsi-fungsi yang disediakan memungkinkan operasi dasar seperti menambah, menghapus, mengubah, dan menampilkan data pada list. Kode ini dilengkapi dengan contoh penggunaan untuk mendemonstrasikan fungsionalitasnya.</p>




### 2. Latihan Double Linked List

C++
```
#include <iostream>
using namespace std;
 
class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
### Penjelasan:
Kode C++ ini mengimplementasikan struktur data bernama Double Linked List. Dengan Double Linked List, kita dapat mengatur daftar item data di mana setiap item dapat diakses dengan maju atau mundur di dalam daftar. Kode ini mendefinisikan kelas Node yang menyimpan data itu sendiri dan pointer ke node sebelumnya dan selanjutnya di dalam daftar. Kelas DoublyLinkedList mengelola kumpulan node ini dengan pointer head dan tail. 

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/65a1b1e0-8b59-45a0-9393-d87ba1037360)

C++
```
//A.A Istri Candra Manika Dewi
//2311110026
#include <iostream>
using namespace std;

struct Node {
    string nama;
    int usia;
    Node* next;
};

// deklarasi head node
Node* head = NULL;

// fungsi untuk menambahkan node di awal
void tambahDiAwal(string nama, int usia) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = head;
    head = newNode;
}

// fungsi untuk menambahkan node di akhir
void tambahDiAkhir(string nama, int usia) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

// fungsi untuk menambahkan node di tengah
void tambahDiTengah(string nama, int usia, int pos) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* curr = head;
    int i = 1;
    while (i < pos-1 && curr->next != NULL) {
        curr = curr->next;
        i++;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

// fungsi untuk menghapus node dengan nama tertentu
void hapus(string nama) {
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL && curr->nama != nama) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    if (prev == NULL) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }

    delete curr;
}

// fungsi untuk mengubah data node dengan nama tertentu
void ubah(string nama, string newNama, int newUsia) {
    Node* curr = head;

    while (curr != NULL && curr->nama != nama) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    curr->nama = newNama;
    curr->usia = newUsia;
}

//show data
void tampilkan() {
    if (head == NULL) {
        cout << "List kosong" << endl;
        return;
    }

    Node* curr = head;

    while (curr != NULL) {
        cout << curr->nama << " " << curr->usia << endl;
        curr = curr->next;
    }
}

int main() {
    // input data pertama 
    string namaAnda;
    int usiaAnda;
    cout << "Masukkan nama anda: ";
    cin >> namaAnda;
    cout << "Masukkan usia anda: ";
    cin >> usiaAnda;
    tambahDiAwal(namaAnda, usiaAnda);
    // input data lainnya
    tambahDiAkhir("John", 19);
    tambahDiAkhir("Jane", 20);
    tambahDiAkhir("Michael", 18);
    tambahDiAkhir("Yusuke", 19);
    tambahDiAkhir("Akechi", 20);
    tambahDiAkhir("Hoshino", 18);
    tambahDiAkhir("Karin", 18);

// menampilkan semua data
cout << "Data awal:" << endl;
tampilkan();

// delete data Akechi
hapus("Akechi");
cout << endl << "Setelah menghapus data Akechi: " << endl;
tampilkan();

// add data Futaba di antara Carol dan Ann
tambahDiTengah("Futaba", 18, 3);
cout << endl << "Setelah menambahkan data Futaba di antara John dan Jane: " << endl;
tampilkan();

// add data Igor di awal
tambahDiAwal("Igor", 20);
cout << endl << "Setelah menambahkan data Igor di awal: " << endl;
tampilkan();

// update data Carol menjadi Reyn
ubah("Michael", "Reyn", 18);
cout << endl << "Setelah mengubah Michael menjadi Reyn: " << endl;
tampilkan();

// show all data after update
cout << endl << "Data setelah perubahan:" << endl;
tampilkan();

return 0;
}

```
### Penjelasan :
<p>Kode C++ di atas mengimplementasikan struktur data Daftar Tertaut Sederhana (Single Linked List) untuk menyimpan informasi orang. Daftar ini memungkinkan user untuk menambah, menghapus, mengubah, dan menampilkan data orang dengan nama dan usia mereka.</p>


#### Output:

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/b255bfc6-7986-474d-ae0a-033ad39986ae)
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/72b81cdc-194d-426e-85a5-1e9360bf29cf)

#### Full code Screenshot:
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/ba3c7cc6-1681-461f-b7f9-0759f80b3dc9)

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/4a978d67-9b1c-484d-b61a-43ec5c4e8459)

c++
```
//A.A Istri Candra Manika Dewi
//2311110026
#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
    string nama_produk;
    int harga;
    Node* prev;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    void tambahData(string nama_produk, int harga) {
        Node* newNode = new Node;
        newNode->nama_produk = nama_produk;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void hapusData(string nama_produk) {
        Node* currentNode = head;
        while (currentNode != NULL) {
            if (currentNode->nama_produk == nama_produk) {
                if (currentNode == head) {
                    head = head->next;
                    head->prev = NULL;
                }
                else if (currentNode == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else {
                    currentNode->prev->next = currentNode->next;
                    currentNode->next->prev = currentNode->prev;
                }
                delete currentNode;
                break;
            }
            currentNode = currentNode->next;
        }
    }
    void updateData(string nama_produk, string new_nama_produk, int new_harga) {
        Node* currentNode = head;
        while (currentNode != NULL) {
            if (currentNode->nama_produk == nama_produk) {
                currentNode->nama_produk = new_nama_produk;
                currentNode->harga = new_harga;
                break;
            }
            currentNode = currentNode->next;
        }
    }
    void tambahDataUrutan(string nama_produk, int harga, int urutan) {
        Node* newNode = new Node;
        newNode->nama_produk = nama_produk;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (urutan == 1) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            Node* currentNode = head;
            int i = 1;
            while (i < urutan - 1) {
                currentNode = currentNode->next;
                i++;
            }
            newNode->prev = currentNode;
            newNode->next = currentNode->next;
            currentNode->next->prev = newNode;
            currentNode->next = newNode;
        }
    }
    void hapusDataUrutan(int urutan) {
        if (urutan == 1) {
            head = head->next;
            head->prev = NULL;
        }
        else {
            Node* currentNode = head;
            int i = 1;
            while (i < urutan) {
                currentNode = currentNode->next;
                i++;
            }
            if (currentNode == tail) {
                tail = tail->prev;
                tail->next = NULL;
            }
            else {
                currentNode->prev->next = currentNode->next;
                currentNode->next->prev = currentNode->prev;
            }
        }
    }
    void hapusSeluruhData() {
        while (head != NULL) {
            Node* currentNode = head;
            head = head->next;
            delete currentNode;
        }
        tail = NULL;
    } // <-- add closing bracket here


    void tampilkanData() {
        Node* currentNode = head;
        cout << setw(15) <<left<< "Nama Produk" << setw(10)<<"Harga"<< endl;
        while (currentNode != NULL) {
            cout <<  setw(15) << left <<  currentNode->nama_produk << setw(10) << currentNode->harga << endl;
            currentNode = currentNode->next;
        }
    }
    void tampilkanMenu() {
        int pilihan, harga, urutan;
        string nama_produk, new_nama_produk;
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        do {
            cout << "Pilih menu: ";
            cin >> pilihan;
            switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Produk: ";
                cin >> nama_produk;
                cout << "Masukkan Harga: ";
                cin >> harga;
                tambahData(nama_produk, harga);
                break;
            case 2:
                cout << "Masukkan Nama Produk yang akan dihapus: ";
                cin >> nama_produk;
                hapusData(nama_produk);
                break;
            case 3:
                cout << "Masukkan Nama Produk yang akan diupdate: ";
                cin >> nama_produk;
                cout << "Masukkan Nama Produk baru: ";
                cin >> new_nama_produk;
                cout << "Masukkan Harga baru: ";
                cin >> harga;
                updateData(nama_produk, new_nama_produk, harga);
                break;
            case 4:
                cout << "Masukkan Nama Produk: ";
                cin >> nama_produk;
                cout << "Masukkan Harga: ";
                cin >> harga;
                cout << "Masukkan Urutan: ";
                cin >> urutan;
                tambahDataUrutan(nama_produk, harga, urutan);
                break;
            case 5:
                cout << "Masukkan Urutan: ";
                cin >> urutan;
                hapusDataUrutan(urutan);
                break;
            case 6:
                hapusSeluruhData();
                break;
            case 7:
                tampilkanData();
                break;
            case 8:
                cout << "Terima kasih." << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia." << endl;
            }
        } while (pilihan != 8);
    }
};

int main() {
    LinkedList list;
    list.tambahData ("Originote",60000);
    list.tambahData ("Somethinc",150000);
    list.tambahData ("Skintific",100000);
    list.tambahData ("Wardah"   ,50000);
    list.tambahData ("Hanasui"  ,30000);
    list.tampilkanMenu();
    return 0;
}
```
## Ouput
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/a70e2b2f-c08a-4c19-90b3-ddb1dc4d2023)
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/d5a298a7-cf56-4819-b31d-4ce662a9d4a0)

## Full Code SS
![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/54a1f8c0-c3ae-401c-bd5b-321bd45a09b0)

## Penjelasan:
<p>Jadi secara keseluruhan program diatas adalah suatu program untuk menambahkan data,menghapus data,mengupdate data,dan masih banyak lagi. Program ini terdapat struct Node dan kelas LinkedList. Struktur Node mewakili sebuah node dalam daftar tertaut dan berisi nama produk, harga, dan penunjuk ke node sebelumnya dan berikutnya dalam daftar. Kelas LinkedList menyediakan sekumpulan metode untuk mengelola daftar tertaut, seperti menambahkan, memperbarui, dan menghapus node. Fungsi main() dari program menampilkan menu opsi untuk dipilih pengguna. Opsinya termasuk menambah, memperbarui, dan menghapus node, serta menampilkan data dalam daftar tertaut. Secara keseluruhan, program ini mendemonstrasikan cara menggunakan struktur data daftar tertaut ganda di C++ untuk menyimpan dan mengelola data</p>

## Kesimpulan:
<p>Kedua jenis linked list ini yaitu Single Linked List dan Double Linked List memiliki kegunaan yang beragam tergantung pada kebutuhan dari aplikasi yang akan digunakan. Single Linked List cocok untuk aplikasi yang memerlukan operasi penambahan atau penghapusan data di akhir linked list dan tidak memerlukan navigasi mundur yang kompleks. Sedangkan Double Linked List cocok untuk aplikasi yang memerlukan navigasi maju dan mundur yang cepat,serta operasi penghapusan atau penambahan data di tengah-tengah Linked List yang simple.</p>

## Referensi
[1] "Linked List Data Structure" www.geeksforgeeks.org. [Online]. Available: (https://www.geeksforgeeks.org/data-structures/linked-list/) [Accessed 09 Mei 2024].
