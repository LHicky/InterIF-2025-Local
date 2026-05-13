#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras.

using namespace std;
// Atalho para utilizar std;

// O exercício pede que, dado uma palavra imprimimos a primeira letra dessa palavra

int main() {
    
    string palavra;
    // Instancia a variável palavra do tipo string;
	    
    cin >> palavra;
    // Lê a palavra
    
    cout << palavra[0] << endl;
    // Imprime somente a primeira posição da palavra
    // Lembrando que a string pode ser tratada como um vetor de caracteres, começando na posição 0 até palavra.size()-1;
    
    /*
    Pegando como exemplo a primeira entrada
    ABELHA
    Imprimimos a primeira letra
    A
    
    */
    
    return 0;
}

