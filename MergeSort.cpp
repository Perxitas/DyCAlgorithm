Codigo de merge sort obtenido de la pagina: https://www.geeksforgeeks.org/merge-sort/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n - 1);
    auto stop = chrono::high_resolution_clock::now();

    cout << "\nVector ordenado:\n";
    printVector(arr);

    chrono::duration<double> duration = stop - start;
    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;

    return 0;
}
