Codigo obtenido de la pagina:https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

void obtenerDimensiones(const string& nombreArchivo, int& filas, int& columnas) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        filas = 0;
        columnas = 0;

        while (getline(archivo, linea)) {
            filas++;
            if (filas == 1) {
                stringstream ss(linea);
                int temp;
                while (ss >> temp) {
                    columnas++;
                }
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
}

void leerMatriz(const string& nombreArchivo, vector<vector<int>>& matriz) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            vector<int> filaMatriz;
            int valor;
            while (ss >> valor) {
                filaMatriz.push_back(valor);
            }
            matriz.push_back(filaMatriz);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
}

vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int R1 = mat1.size();
    int C1 = mat1[0].size();
    int C2 = mat2[0].size();

    vector<vector<int>> resultado(R1, vector<int>(C2, 0));

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < C1; k++) {
                resultado[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return resultado;
}

void guardarMatrizEnArchivo(const string& nombreArchivo, const vector<vector<int>>& matriz) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const auto& fila : matriz) {
            for (const auto& elem : fila) {
                archivo << elem << " ";
            }
            archivo << endl;
        }
        archivo.close();
        cout << "Matriz resultante guardada en " << nombreArchivo << endl;
    } else {
        cout << "No se pudo abrir el archivo para escribir el resultado." << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <archivo_matriz1.txt> <archivo_matriz2.txt>" << endl;
        return 1;
    }

    string archivoMat1 = argv[1];
    string archivoMat2 = argv[2];

    int R1, C1, R2, C2;

    obtenerDimensiones(archivoMat1, R1, C1);
    obtenerDimensiones(archivoMat2, R2, C2);

    if (C1 != R2) {
        cout << "Las dimensiones no permiten la multiplicación." << endl;
        return 1;
    }

    vector<vector<int>> mat1;
    vector<vector<int>> mat2;

    leerMatriz(archivoMat1, mat1);
    leerMatriz(archivoMat2, mat2);

    auto inicio = high_resolution_clock::now();

    vector<vector<int>> resultado = multiplicarMatrices(mat1, mat2);

    auto fin = high_resolution_clock::now();
    auto duracion = duration<double>(fin - inicio);

    guardarMatrizEnArchivo("resultado_multiplicacion.txt", resultado);

    cout << "Tiempo de multiplicación: " << duracion.count() << " s" << endl;

    return 0;
}
