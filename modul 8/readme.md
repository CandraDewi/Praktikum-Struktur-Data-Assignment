
# <h1 align="center">Laporan Praktikum Algoritma dan Struktur Data-Modul 8</h1>
# <h1 align="center">Priority Queue and Heaps</h1>
<p align="center">A.A Istri Candra Manika Dewi</p>

## Dasar Teori
## Priority Queue
Priority queue adalah jenis queue yang mengatur elemen berdasarkan nilai prioritasnya. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil sebelum elemen dengan nilai prioritas lebih rendah[1]. Priority Queue sangat bermanfaat dalam situasi di mana beberapa elemen memiliki kepentingan yang berbeda dan harus diprioritaskan dalam proses pengelolaan antrian

Dalam priority queue, setiap elemen memiliki nilai prioritas yang terkait dengannya. Ketika menambahkan elemen ke antrian, elemen tersebut dimasukkan ke dalam posisi berdasarkan nilai prioritasnya. Misalnya, jika menambahkan elemen dengan nilai prioritas tinggi ke priority queue, elemen tersebut mungkin dimasukkan di dekat bagian depan antrian, sementara elemen dengan nilai prioritas rendah mungkin dimasukkan di dekat bagian belakang.[1]

Dalam implementasi ini ada 3 pokok atribut yaitu heaps, comparator, dan last. Dengan menggunakan fasilitas heap ini kita bisa melakukan insert atau remove elemen dalam kompleksitas waktu logaritmik. Pada priority Queue ini, akan dibentuk sebuah pohon biner yang seimbang yang dapat disebut dengan Heap.[2] 


## Heaps

Heap adalah suatu data structure yang mirip dengan pohon binary, tetapi memiliki sifat khusus yaitu setiap node memiliki nilai yang lebih besar atau lebih kecil daripada nilai node-node anaknya. Heap dapat dibagi menjadi dua jenis, yaitu max heap dan min heap. Max heap adalah heap yang memiliki sifat nilai node induk lebih besar atau sama dengan nilai node anaknya, sedangkan min heap adalah heap yang memiliki sifat nilai node induk lebih kecil atau sama dengan nilai node anaknya.

### Operasi pada heap :[3]
- `insert(p)`: Menambahkan elemen baru kedalam heap.
- `extractMax()`: Mengambil elemen dengan prioritas terbesar.
- `remove(i)`: Menghapus elemen tertentu.
- `getMax()`: Mengembalikan nilai maksimum. 
- `changePriority(i, p)`: mengubah nilai tertentu dari priority queue.


## Guided 

### 1. 

```C++
#include <iostream>
#include <algorithm>
int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }

    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
    
    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax()
<< "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);

    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
#### Output :

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/55ad0e3a-8c0a-4be3-ba72-bcd256b66562)

Kode diatas merupakan program untuk menentukan priority queue menggunakan heap.

Pertama program akan mendeklarasikan array `H` untuk menyimpan elemen-elemen dari priority queue. Variabel `heapSize` digunakan untuk menyimpan jumlah elemen yang ada dalam priority queue.

Setelah itu program akan memasukkan nilai elemen-elemen kedalam priority queue menggunakan fungsi `insert()`. Melalui fungsi `shiftDown` program akan terus menggeser node ke bawah sampai semua child node memiliki nilai yang lebih kecil atau sama dengan nilai node tersebut. Lalu program akan mengambil angka dengan nilai terbesar menggunakan fungsi `extractMax()` dan mencetak hasilnya. Kemudian prioritas dari indeks ke-2 akan diubah menjadi 49 melalui fungsi `changePriority`. Terakhir program akan menghapus angka yang berada pada indeks ke-3 dengan fungsi `remove()`. Setelah setiap perubahan program akan menampilkan hasil priority queue. 



#### Full code Screenshot:

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/078c3765-74bc-46c2-a59b-cd5df7b8cd7a)


## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

```C++

#include <iostream>
#include <algorithm>
using namespace std;

int H[50]; 
int heapSize = -1; 

// menentukan letak parents
int parent(int i) {
    return (i - 1) / 2;
}
// menentukan left child
int leftChild(int i) {
    return (2 * i) + 1;
}
// menentukan right child
int rightChild(int i) {
    return (2 * i) + 2;
}
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i; 
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) { 
        maxIndex = l;  
    }

    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) { 
        maxIndex = r; 
    }

    if (i != maxIndex) { 
        swap(H[i], H[maxIndex]); 
        shiftDown(maxIndex); 
    }
}

// menambahkan elemen baru
void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}
// menghapus elemen dengan nilai maksimum dari heap
int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}
// mengubah prioritas elemen dlm heap
void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}
// mengembalikan nilai maksimum
int getMax() {
    return H[0];
}
// menghapus elemen 
void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}
// mencetak isi heap
void printHeap() {
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << endl;
}
// main program
int main() {
    int n, element;
    cout << "Enter number of elements to insert into the heap: "; 
    cin >> n;
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        insert(element);
    }
    // Menampilkan heap
    cout << "Priority Queue: ";
    printHeap();

    // mengeluarkan nilai maximum
    cout << "Node dengan maximum priority: " << extractMax() << "\n";
    cout << "Priority queue setelah mengekstrak maximum: ";
    printHeap();

    cout << "Masukan index untuk mengganti value priority lama dan priority baru : ";
    int index, newPriority;
    cin >> index >> newPriority;
    changePriority(index, newPriority); 
    
    // heap setelah mengubah elemen tertentu
    cout << "Priority queue setelah prioritas diganti: ";
    printHeap();

    // Memasukkan indeks dari elemen yg ingin dihapus
    cout << "Masukkan index element yang akan di remove: ";
    cin >> index;
    remove(index);

    cout << "Priority queue setelah menghapus elemen: ";
    printHeap();

    return 0;
} 

```
#### Output

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/f33d9536-829e-4754-a43c-5f5cdf7facb4)

### Interpretasi: 
Pertama program akan mendeklarasikan variabel `int H[50]` untuk menyimpan elemen-elemen dalam heap. Variabel `int heapSize = -1` digunakan untuk menyimpan jumlah elemen dalam heap. Variabel `int n, element` digunakan untuk menyimpan jumlah elemen dan elemen yang diinputkan user

Setelah itu program akan meminta user untuk memasukkan panjang elemen dan nilai elemen. Kemudian program akan menambahkan elemen kedalam heap dan mencetaknya. Melalui fungsi `parent(int i), leftChild(int i), dan rightChild(int i)` program akan menentukan indeks parent, left child, dan right child. Jika nilai parent lebih kecil dari nilai child program akan memindahkan node ke bawah dengan memanggil fungsi `shiftDown(int i)` dan jika nilai child lebih besar dari parent program akan memindahkan node ke atas dengan fungsi `shiftUp(int i)`. 

Kemudian, melalui `extractMax()` program akan mengambil elemen dengan nilai maksimum dan mencetaknya. Lalu program akan mencetak isi heap setelah nilai maksimum diambil. Setelah itu user akan diminta untuk memasukkan indeks elemen yang ingin diubah dan nilai elemen barunya dan hasilnya akan ditampilkan. Terakhir user akan diminta untuk memasukkan indeks dari elemen yang ingin dihapus lalu program akan mencetak isi heap. 

#### Full code Screenshot:

![image](https://github.com/CandraDewi/Praktikum-Struktur-Data-Assignment/assets/87966244/d123a883-2911-4bdf-a8e8-a7e24822f92b)


## Kesimpulan
Priority queue adalah jenis queue yang mengatur elemen berdasarkan nilai prioritasnya. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil sebelum elemen dengan nilai prioritas lebih rendah. Pada priority Queue, akan dibentuk sebuah pohon biner yang seimbang yang dapat disebut dengan Heap. Heap adalah suatu data structure yang mirip dengan pohon binary, tetapi memiliki sifat khusus yaitu setiap node memiliki nilai yang lebih besar atau lebih kecil daripada nilai node-node anaknya. Heap dapat dibagi menjadi dua jenis, yaitu max heap dan min heap. Max heap adalah heap yang memiliki sifat nilai node induk lebih besar atau sama dengan nilai node anaknya, sedangkan min heap adalah heap yang memiliki sifat nilai node induk lebih kecil atau sama dengan nilai node anaknya.

Pada Unguided kali ini kita belajar bagaimana mengimplementasikan priority queue menggunakan heap dengan inputan dari user dengan fungsi seperti shiftUp, shiftDown, insert, extractMax(), changePriority(), getmax, dan remove.


## Referensi
[1] GeeksforGeeks. (2023), What is Priority Queue | Introduction to Priority Queue [Online]. Available : https://www.geeksforgeeks.org/priority-queue-set-1-introduction/ [diakses 20 Mei 2024]

[2] A. Nurcholis, S. Batara N, and M. Octamanullah, “Penerapan struktur data Heap Priority Queue pada algoritma Djikstra untuk mendapatkan kompleksitas O((n + m)log n),” pp. 1–4, 1959.

[3] GeeksforGeeks. (2023), Priority Queue using Binary Heap [Online]. Available : https://www.geeksforgeeks.org/priority-queue-using-binary-heap/ 
