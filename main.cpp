#include <iostream>
#include <vector>

using namespace std;

string frase_global = "bom dia foz";

/*
 * Letra 1
 */
int contar_caracteres(string param_frase){
    int qtd_caracteres = param_frase.length();
    return qtd_caracteres;
}

/*
 * Letra 2
 */
int contar_palavras(string param_frase){

    int qtd_palavras = 1;
    int pos_espaco = -1;
    string frase = param_frase;

    do {

        pos_espaco = frase.find(' ');

        if (pos_espaco != -1){
            qtd_palavras++;
        }

        frase = frase.substr(pos_espaco + 1);

    }while(pos_espaco != -1);

    return qtd_palavras;

}

vector<string> frase_para_lista(string param_frase){

    int pos_espaco = -1;
    string frase = param_frase;
    string palavra_apagada;
    vector<string> lista_palavras;

    do {
        pos_espaco = frase.find(' ');
        palavra_apagada = frase.substr(0, pos_espaco);

        lista_palavras.push_back(palavra_apagada);

        frase = frase.substr(pos_espaco + 1);

    }while(pos_espaco != -1);

    return lista_palavras;

}

int main() {

//    int qtd = contar_caracteres(frase_global);
//    cout << "quantidade de caracteres: " << qtd;

    for ( string p : frase_para_lista(frase_global)) {
        cout << p << endl;
    }


    return 0;
}