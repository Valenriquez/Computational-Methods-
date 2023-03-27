// Programando un DFA 
// Valeria Enríquez Limón A00832782
// 17 de marzo del 2023

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//   1          2       3      4         5             6        7          8       9      
// entero, flotante, suma , resta, multiplicacion, división, potencia, asignacion, variable
//   10          11      12
//simbolos, comentario, invalido;

struct Token {
    int tipo;
    string valor;
};

bool esFloatante(string input) {
    int contador = 0;
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            if (input[i] == '.' || input[i] == 'e' || input[i] == 'E' || input[i] == '-') {
                contador++;
                if (contador >= 1) {
                    return true;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

bool esVariable(string input) {
    char c = input[0];
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int variable = 0; int contTotal = 0; int contadorCom = 0;
Token getToken(string input) {
    Token token;

    // Entero
    bool esEntero = true;
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            esEntero = false;
            break;
        }
    }
    // Entero
    
    if(input.length() >= 1){
        if(input.substr(0, 2) == "//"){
            token.tipo = 11; //comentario
            token.valor = input;
            contadorCom += 1;
            contTotal += 1;
        }
        else if(contadorCom >= 1){
            token.tipo = 11; //comentario
            token.valor = input;
            contadorCom += 1;
            contTotal += 1;
        }
        else if(esVariable(input)){
            token.tipo = 9;  //variable 
            token.valor = input;
            contTotal += 1; 
        }
        else if(input.length() == 1 && input.substr(0, 1) == "="){
            token.tipo = 8; //asignacion
            token.valor = input;
            contTotal += 1;
        }
        else if(input.length() == 1 && input.substr(0, 1) == "+"){
            token.tipo = 3; //suma
            token.valor = input;
            contTotal += 1;
        }
        else if(input.length() == 1 && input.substr(0, 1) == "-"){
            token.tipo = 4; //resta
            token.valor = input;
            contTotal += 1;
        }
        else if(input.length() == 1 && input.substr(0, 1) == "*"){
            token.tipo = 5; //multiplicacion
            token.valor = input;
            contTotal += 1;
        }
        else if(input.length() == 1 && input.substr(0, 1) == "/"){
            token.tipo = 6; //division
            token.valor = input;
            contTotal += 1;
        }
        else if(input.length() == 1 && input.substr(0, 1) == "^"){
            token.tipo = 7; //potencia
            token.valor = input;
            contTotal += 1;
        }
        else if(input.substr(0, 1) == "(" || input.substr(0, 1) == ")"){
            token.tipo = 10; //simbolos especiales 
            token.valor = input;
            contTotal += 1;
        }else if(esEntero){
            token.tipo = 1;  //entero
            token.valor = input;
            contTotal += 1;
        }
        else if(esFloatante(input)){
            token.tipo = 2;  // flotante
            token.valor = input;
            contTotal += 1;
        }
        else{
            token.tipo = 12; //invalido
            token.valor = input;
            contTotal += 1;
        }
        return token;
    } 
}

int main() {

    cout << "---------------INICIO---------------" << endl;    
    string input;
    cout << "Ingresa un texto: ";
    getline(cin, input);
    stringstream ss(input);
    string tokenStr;
    

//   1          2       3      4         5             6        7           8       9      
// entero, flotante, suma , resta, multiplicacion, división, potencia, asignacion, variable
//   10          11      12
//simbolos, comentario, invalido;


    while (ss >> tokenStr) {
      Token token = getToken(tokenStr);
       cout << "-----------------------------------" << endl;    
        cout << "Tipo: ";
        switch (token.tipo) {
            case 1:
                cout << "Entero";
                break;
            case 2:
                cout << "Flotante";
                break;
            case 3:
                cout << "Suma";
                break;
            case 4:
                cout << "Resta";
                break;
            case 5:
                cout << "Multiplicacion";
                break;
            case 6:
                cout << "Division";
                break;
            case 7:
                cout << "Potencia";
                break;
            case 8:
                cout << "Asignacion";
                break;
            case 9:
                cout << "Variable";
                break;
            case 10:
                cout << "Simbolo Especial";
                break;
            case 11:
                cout << "Comentario";
                break;
            default:
                cout << "Invalido";
        }
        cout << ", Token: " << token.valor << endl;
    }
    return 0;
}


