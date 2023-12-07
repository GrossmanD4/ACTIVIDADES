def ordenar_arreglo_bidimensional(arr):
    arr.sort(key=lambda x: x[1])
    arr.sort(key=lambda x: x[0] == 0)

def ingresar_datos_arreglo_unidimensional(arr):
    dato = int(input("Ingrese un número: "))
    arr.append(dato)

def ingresar_datos_arreglo_bidimensional(arr):
    for i in range(20):
        fila = []
        dato1 = int(input(f"Ingrese el número para la fila {i+1}, columna 1: "))
        dato2 = int(input(f"Ingrese el número para la fila {i+1}, columna 2: "))
        fila.append(dato1)
        fila.append(dato2)
        arr.append(fila)

def menu():
    arreglo_bidimensional = []
    arreglo_unidimensional = []

    while True:
        print("\n--- Menú ---")
        print("1. Ingresar datos a arreglo unidimensional")
        print("2. Ingresar datos a arreglo bidimensional")
        print("3. Ordenar arreglo bidimensional")
        print("4. Mostrar arreglos")
        print("5. Salir")

        opcion = int(input("Seleccione una opción: "))

        if opcion == 1:
            ingresar_datos_arreglo_unidimensional(arreglo_unidimensional)
        elif opcion == 2:
            ingresar_datos_arreglo_bidimensional(arreglo_bidimensional)
        elif opcion == 3:
            ordenar_arreglo_bidimensional(arreglo_bidimensional)
        elif opcion == 4:
            print("\nArreglo unidimensional:", arreglo_unidimensional)
            print("Arreglo bidimensional:", arreglo_bidimensional)
        elif opcion == 5:
            break
        else:
            print("Opción inválida. Intente de nuevo.")


menu()
