#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras.

using namespace std;
// Atalho para utilizar std;

// O exercício explica que cada pessoa levanta o mesmo peso 3 vezes ganha mais pontos que todos;
// A pessoa que levanta o mesmo peso 2 vezes ganha mais pontos que o que levanta só 1 vez;
// O exercício dá os 2 pesos que já foram levantados, então para fazer mais pontos o mais ótimo é sempre você levantar o maior;


// O exercício se resume a imprimir o maior ou igual valor entre os dois números;

int main() {

    int num1, num2;
    // Inicializamos 2 variaveis do tipo inteiro
    cin >> num1 >> num2;
    // Fazemos a leitura dos dois números
    
    cout << max(num1, num2) << "\n";
    // A função max sempre retorna o maior valor entre comparações de números, se forem iguais também retorna aquele valor, perfeito nesse caso.
    // Imprimimos o maior ou igual número entre num1 e num2;
    
    
    return 0;
    
	/*
		Usando a primeira entrada como exemplo
		125 112
		Após leitura a gente faz a comparação em cout, ou seja, imprima o maior número possível entre esses dois;
		Portanto a resposta é 125
	*/ 
}


