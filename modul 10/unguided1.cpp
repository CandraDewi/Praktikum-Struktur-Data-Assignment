
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int CandraManikaDewi_2311110026;
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> CandraManikaDewi_2311110026;

    vector<string> nodes(CandraManikaDewi_2311110026);
    vector<vector<int>>
distances(CandraManikaDewi_2311110026,
vector<int>(CandraManikaDewi_2311110026));

// Masukkan nama simpul
    cout << "Silakan masukkan nama simpul" << endl;
    for (int i = 0; i < CandraManikaDewi_2311110026;
i++) {
    cout << "Simpul " << i + 1 << " : ";
    cin >> nodes[i];
}

// Masukkan bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < CandraManikaDewi_2311110026;
i++) {
    for (int j = 0; j < CandraManikaDewi_2311110026; j++) {
    cout << "" << nodes[i] << " ---> " <<
    nodes[j] << " = ";
    cin >> distances[i][j];
    }
}
    cout << "\t";
    for (int i = 0; i < CandraManikaDewi_2311110026; i++) {
    cout << nodes[i] << "\t";
}
    cout << endl;
    for (int i = 0; i < CandraManikaDewi_2311110026; i++) {
    cout << nodes[i] << "\t";
    for (int j = 0; j < CandraManikaDewi_2311110026; j++) {
    cout << distances[i][j] << "\t";
    }
    cout << endl;
    }
return 0;
}
