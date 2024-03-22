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
