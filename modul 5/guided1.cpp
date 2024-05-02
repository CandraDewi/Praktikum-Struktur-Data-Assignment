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

