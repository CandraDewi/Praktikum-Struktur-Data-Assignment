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