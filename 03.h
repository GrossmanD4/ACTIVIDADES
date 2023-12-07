#ifndef PUCHI_03_H
#define PUCHI_03_H
#endif
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Ubicacion {
    double latitud;
    double longitud;
    string nombre;
};

void ingresarDatos(vector<Ubicacion> &ubicaciones) {
    for (size_t i = 0; i < ubicaciones.size(); ++i) {
        cout << "Ingrese los datos para la ubicación " << i + 1 << ":\n";
        cout << "Latitud: ";
        cin >> ubicaciones[i].latitud;
        cout << "Longitud: ";
        cin >> ubicaciones[i].longitud;
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, ubicaciones[i].nombre);
    }
}

void mostrarDatos(const vector<Ubicacion> &ubicaciones) {
    cout << "Datos de ubicaciones:\n";
    for (const auto &ubicacion : ubicaciones) {
        cout << "Latitud: " << ubicacion.latitud
             << ", Longitud: " << ubicacion.longitud
             << ", Nombre: " << ubicacion.nombre << endl;
    }
}

void generarAleatorios(vector<Ubicacion> &ubicaciones) {
    for (size_t i = 0; i < ubicaciones.size(); ++i) {
        ubicaciones[i].latitud = (rand() % 201 - 100) * 1.0;
        ubicaciones[i].longitud = (rand() % 201 - 100) * 1.0;
        ubicaciones[i].nombre = "Ubicacion " + to_string(i + 1);
    }
}

bool compararNombres(const Ubicacion &a, const Ubicacion &b) {
    return a.nombre < b.nombre;
}

double calcularDistancia(double latitud1, double longitud1, double latitud2, double longitud2) {
    return sqrt(pow(latitud2 - latitud1, 2) + pow(longitud2 - longitud1, 2));
}

void ordenarPorDistancia(vector<Ubicacion> &ubicaciones, double latitud, double longitud) {
    sort(ubicaciones.begin(), ubicaciones.end(), [&](const Ubicacion &a, const Ubicacion &b) {
        return calcularDistancia(latitud, longitud, a.latitud, a.longitud) <
               calcularDistancia(latitud, longitud, b.latitud, b.longitud);
    });

    cout << "Ubicaciones ordenadas por distancia:\n";
    for (const auto &ubicacion : ubicaciones) {
        double distancia = calcularDistancia(latitud, longitud, ubicacion.latitud, ubicacion.longitud);
        cout << "Nombre: " << ubicacion.nombre << ", Distancia: " << distancia << endl;
    }
}

void menu() {
    cout << "\nMenú:\n";
    cout << "1. Ingresar datos de ubicaciones\n";
    cout << "2. Mostrar datos de ubicaciones\n";
    cout << "3. Generar datos aleatorios para ubicaciones\n";
    cout << "4. Ordenar por nombre\n";
    cout << "5. Ordenar por distancia\n";
    cout << "6. Salir\n";
}

int Ejecucion_03() {
    int cantidadUbicaciones;
    cout << "Ingrese la cantidad de ubicaciones: ";
    cin >> cantidadUbicaciones;
    vector<Ubicacion> ubicaciones(cantidadUbicaciones);

    while (true) {
        menu();

        int opcion;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarDatos(ubicaciones);
                break;
            case 2:
                mostrarDatos(ubicaciones);
                break;
            case 3:
                generarAleatorios(ubicaciones);
                break;
            case 4:
                sort(ubicaciones.begin(), ubicaciones.end(), compararNombres);
                cout << "Ubicaciones ordenadas por nombre:\n";
                mostrarDatos(ubicaciones);
                break;
            case 5: {
                double lat, lon;
                cout << "Ingrese la latitud: ";
                cin >> lat;
                cout << "Ingrese la longitud: ";
                cin >> lon;
                ordenarPorDistancia(ubicaciones, lat, lon);
                break;
            }
            case 6:
                return 0;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida.\n";
        }
    }

    return 0;
}
