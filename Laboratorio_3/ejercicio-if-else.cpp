#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    cout << "CALCULADORA EN C++" << endl << endl;
    string usuario;
    const string usuarioTrue = "1234";
    int intentos = 0;
    bool guardado = false;

    while (intentos < 3){
        cout << "Ingrese su usuario: ";
        cin >> usuario;
        intentos++;
        if (usuario == usuarioTrue){
            guardado = true;
            break;
        }
        else{
            cout << "Usuario incorrecto. Intentos restantes: " << (3 - intentos) << endl;
        }
    }

    if (!guardado){
        cout << "Intentos agotados. Saliendo del programa" << endl;
        return 0;
    }

    int opcion = 0;
    double num1 = 0, num2 = 0;

    do{
        cout << endl << "Hola, " << usuario << ". CALCULADORA." << endl;
        cout << "Menu:" << endl;
        cout << "1- Sumar" << endl;
        cout << "2- Restar" << endl;
        cout << "3- Multiplicar" << endl;
        cout << "4- Dividir" << endl;
        cout << "5- Salir" << endl;
        cout << "Ingrese la opcion: ";

        if (!(cin >> opcion)){
            cout << "Entrada invalida. Intente de nuevo." << endl;
        }

        if (opcion == 5){
            cout << "Saliste de la calculadora." << endl;
            break;
        }

        cout << "Ingrese el primer numero: ";
        while (!(cin >> num1)){
            cout << "Entrada invalida. Ingrese un numero: ";
        }

        cout << "Ingrese el segundo numero: ";
        while (!(cin >> num2)){
            cout << "Entrada invalida. Ingrese un numero: ";
        }

        switch (opcion){
            case 1:
                cout << "Resultado: " << num1 + num2 << endl;
                break;
            case 2:
                cout << "Resultado: " << num1 - num2 << endl;
                break;
            case 3:
                cout << "Resultado: " << num1 * num2 << endl;
                break;
            case 4:
                if (num2 != 0)
                    cout << "Resultado: " << num1 / num2 << endl;
                else
                    cout << "No es posible dividir entre cero" << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }

    } while (opcion != 5);

    return 0;
}