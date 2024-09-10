#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

using namespace std;


vector<int> readFile(const string& filename) {
    ifstream file(filename);
    vector<int> arr;
    string line;
    int num;

    if (file.is_open()) {
        getline(file, line);
        stringstream ss(line);


        while (ss >> num) {
            arr.push_back(num);
        }
    }
    file.close();
    return arr;
}

void printVector(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <archivo_entrada.txt>" << endl;
        return 1;
    }
    string filename = argv[1];
    vector<int> arr = readFile(filename);

    int n = arr.size();
    cout << "Vector inicial:\n";
    printVector(arr);

    auto start = chrono::high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    auto stop = chrono::high_resolution_clock::now();

    cout << "\nVector ordenado:\n";
    printVector(arr);

    chrono::duration<double> duration = stop - start;
    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;

    return 0;
}