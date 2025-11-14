/* 1. Crea un archivo 'datos.txt' con varios numeros enteros.

2. El programa debe:
    - Separar los numeros pares e impares en archivos distintos.
    - Ordenar cada archivo de menor a mayor (usando el metodo burbuja).
    - Mostrar el contenido antes y despues del ordenamiento.

    3. Usa funciones para cada tarea:
    - 'leerArchivo()'
    - 'clasificarNumeros()'
    - 'ordenarArchivo()
    - 'mostrarArchivo()

Desafio adicional (10 en cualquier laboratorio):
Agrega un pequeño menu con opciones como:
    - "Clasificar numeros"
    - "Ordenar archivos"
    - "Ver resultados" */

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

int leerArchivo(int numeros[]);
void clasificarNumeros(int numeros[], int cantidad);
void ordenarArchivo(const string& nombreArchivo);
void mostrarArchivo(const string& nombreArchivo);
void burbuja(int arr[], int n);

int main(){
    int numeros[MAX];
    int cantidad = 0;
    int opcion;

    do{
        cout << "\n\tMenu principal\n\n";
        cout << "1. Leer y clasificar numeros\n";
        cout << "2. Ordenar archivos (por pares e impares)\n";
        cout << "3. Ver informacion de archivos\n";
        cout << "4. Salir\n";
        cout << "Introduce una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                cantidad = leerArchivo(numeros);
                clasificarNumeros(numeros, cantidad);
                break;
            case 2:
                ordenarArchivo("pares.txt");
                ordenarArchivo("impares.txt");
                break;
            case 3:
                cout << "\n\tpares.txt\n";
                mostrarArchivo("pares.txt");
                cout << "\n\timpares.txt\n";
                mostrarArchivo("impares.txt");
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    }while(opcion != 4);

    return 0;
}

int leerArchivo(int numeros[]){
    ifstream archivo("datos.txt");
    int num, i = 0;

    if(!archivo){
        cout << "Error al abrir datos.txt\n";
        return 0;
    }

    while(archivo >> num && i < MAX){
        numeros[i++] = num;
    }

    archivo.close();
    cout << "Archivo leido correctamente.\n";

    return i;
}

void clasificarNumeros(int numeros[], int cantidad){
    ofstream pares("pares.txt");
    ofstream impares("impares.txt");

    if(!pares || !impares){
        cout << "Error al crear los archivos.\n";
        return;
    }

    for(int i = 0; i < cantidad; i++){
        if (numeros[i] % 2 == 0)
            pares << numeros[i] << endl;
        else
            impares << numeros[i] << endl;
    }

    pares.close();
    impares.close();

    cout << "Clasificacion completada satisfactoriamente.\n";
}

void ordenarArchivo(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    int arr[MAX];
    int n = 0;

    if (!archivo){
        cout << "Error al abrir " << nombreArchivo << endl;
        return;
    }

    while(archivo >> arr[n] && n < MAX){
        n++;
    }
    archivo.close();

    cout << "\nInformacion de " << nombreArchivo << " antes de ordenar:\n";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    burbuja(arr, n);

    ofstream salida(nombreArchivo);
    for(int i = 0; i < n; i++){
        salida << arr[i] << endl;
    }
    salida.close();

    cout << "Informacion despues de ordenar:\n";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void mostrarArchivo(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    int num;

    if(!archivo){
        cout << "No se pudo abrir " << nombreArchivo << endl;
        return;
    }

    while(archivo >> num){
        cout << num << " ";
    }

    cout << endl;
    archivo.close();
}

void burbuja(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Solicito nota para el laboratorio 6.