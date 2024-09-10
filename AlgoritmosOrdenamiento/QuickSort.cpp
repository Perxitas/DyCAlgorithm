Codigo quickSort obtenido de la pagina: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    cout << "Vector inicial:\n";
    printVector(arr);

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto stop = chrono::high_resolution_clock::now();

    cout << "\nVector ordenado:\n";
    printVector(arr);

    chrono::duration<double> duration = stop - start;
    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;

    return 0;
}
