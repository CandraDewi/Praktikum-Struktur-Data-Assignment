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