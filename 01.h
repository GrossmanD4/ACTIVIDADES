#ifndef PUCHI_01_H
#define PUCHI_01_H
#endif
#include <iostream>
using namespace std;
#include <vector>

//Método Burbuja
void Ordenamiento(vector<int> &arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//Ingreso de elementos al final
void Ingreso(vector<int> &arr, int elemento) {
    arr.push_back(elemento);
}

// Eliminación de elementos vacíos
void Eliminacion(vector<int> &arr) {
    int n = arr.size();
    int cont = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            swap(arr[i], arr[cont]);
            cont++;
        }
    }
}

//Mostrar elementos
void Mostrar(const vector<int> &arr) {
    cout << "Arreglo Ordenao: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int Ejecucion_01() {
    vector<int> arreglo = {1,2,3,4,5,0,6,0,7,0,8,0,0,0,9,10};


    Ingreso(arreglo, 11);
    Ingreso(arreglo, 0);


    Eliminacion(arreglo);


    Ordenamiento(arreglo, arreglo.size());

    Mostrar(arreglo);

    return 0;
}
