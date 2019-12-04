#include <iostream>
#include <vector>

using namespace std;

string frase_global = "bom dia dia foz";


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


/*  ---------------------------------
 *  i. O número de caracteres dessa frase;
    --------------------------------- */
int contar_caracteres(string param_frase){
    int qtd_caracteres = param_frase.length(); /*a função length() conta o numero de caracteres da frase ou palavra*/
    return qtd_caracteres;
}



/*  ---------------------------------
 *  ii. O número de palavras da frase;
    --------------------------------- */
int contar_palavras(string param_frase){

    /*a estratégia usada para contar a quantidade de palavras foi procurar os espaços e contatá-los*/

    int qtd_palavras = 1;
    int pos_espaco = -1;
    string frase = param_frase;

    do {

        pos_espaco = frase.find(' '); /*procura a posição do espaço na frase*/

        /*
         * IMPORTANTE: o método find retorna a posição que a primeira ocorrência do caractere procurado ocupa na frase;
         * Caso não seja encontrado esse caractere, é retornado o valor -1;
         */

        if (pos_espaco != -1){
            qtd_palavras++;
        }

        /* remove as palavras que já foram contadas*/
        frase = frase.substr(pos_espaco + 1);

    } while(pos_espaco != -1);

    return qtd_palavras;

}

/* -------------------------------------------------------
 * iii. O número de vezes que a letra “a” aparece na frase;
 --------------------------------------------------------- */
int contar_letras_as(string param_frase){

    int quantidade_as = 0;

    for (int i = 0; i < param_frase.length(); ++i) {
        if (param_frase[i] == 'a'){
            quantidade_as++;
        }
    }

    return quantidade_as;
}

/*  --------------------------------------
 *  iv. A quantidade de palavras repetidas;
    -------------------------------------- */
int contar_palavras_repetidas(string param_frase){

    int qtd_palavras_repetidas = 0;
    string palavra;
    vector<string> frase_como_uma_lista_de_palavras = frase_para_lista(param_frase);

    for (int i = 0; i < frase_como_uma_lista_de_palavras.size(); i++) {

        palavra = frase_como_uma_lista_de_palavras[i];

        for (int j = 0; j < frase_como_uma_lista_de_palavras.size(); j++) {
            if (frase_como_uma_lista_de_palavras[j] == palavra && i != j) {

                frase_como_uma_lista_de_palavras.erase(frase_como_uma_lista_de_palavras.begin() + j);
                qtd_palavras_repetidas++;
            }
        }
    }

    return qtd_palavras_repetidas;

}

/*  --------------------------------------------------
 *  v. Troque a primeira palavra da frase pela última;
    -------------------------------------------------- */
string trocar_palavras(string param_frase){

    string nova_frase = "";
    vector<string> frase_como_uma_lista_de_palavras = frase_para_lista(param_frase);

    string primeira_palavra = frase_como_uma_lista_de_palavras[0];
    string ultima_palavra = frase_como_uma_lista_de_palavras[frase_como_uma_lista_de_palavras.size() -1 ];

    frase_como_uma_lista_de_palavras[0] = ultima_palavra;
    frase_como_uma_lista_de_palavras[frase_como_uma_lista_de_palavras.size() -1 ] = primeira_palavra;

    for (int i = 0; i < frase_como_uma_lista_de_palavras.size(); ++i) {
        nova_frase += frase_como_uma_lista_de_palavras[i] + " ";
    }

    return nova_frase;
}

int main() {

    cout << "Quantidade de caracteres: " << contar_caracteres(frase_global) << endl << endl;

    cout << "Numero de palavras: " << contar_palavras(frase_global) << endl << endl;

    cout << "Quantidade de letras 'as': " << contar_letras_as(frase_global) << endl << endl;

    cout << "Contar palavras repetidades: " << contar_palavras_repetidas(frase_global) << endl << endl;

    cout << "A frase, com a primeira e a ultima palavras invertidas, apresenta o texto: " << trocar_palavras(frase_global) << endl << endl;


    return 0;
}