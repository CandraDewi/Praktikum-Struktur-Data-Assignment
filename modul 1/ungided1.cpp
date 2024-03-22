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
