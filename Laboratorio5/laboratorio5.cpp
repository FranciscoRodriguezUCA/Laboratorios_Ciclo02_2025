#include <iostream>
using namespace std;

int main(){
    int numero, factorial = 1;

    cout << endl << "CALCULAR FACTORIAL" << endl;

    cout << endl << "Digite un numero: ";
    cin >> numero;

    if(numero < 0){
        cout << endl << "Numero Invalido" << endl << endl;
    }else{
        for(int i = 1; i <= numero; i++)
        factorial = factorial * i;
        cout << endl << "El factorial del numero es: " << factorial << endl << endl;
    }

    return 0;
}