
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
