Codigo de insertion sort obtenido de la pagina: https://www.geeksforgeeks.org/insertion-sort-algorithm/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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
    if (n == 0) {
        cout << "El archivo está vacío o no contiene números válidos." << endl;
        return 1;
    }

    cout << "Vector inicial:\n";
    printVector(arr);

    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr);
    auto stop = chrono::high_resolution_clock::now();

    cout << "\nVector ordenado:\n";
    printVector(arr);

    chrono::duration<double> duration = stop - start;
    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;

    return 0;
}
