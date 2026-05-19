#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras;

using namespace std;
// Atalho para utilizar std;


// Esse exercício pede o número com maior número de divisores, portanto tentamos dividilo por números de 2 até numero/2 e contamos quantos encontramos;


int main() {
    
    int num;
    cin >> num;
    
    int maior = -1;
    int maiorNum = 0;
    // Começamos com maior = -1 e maiorNum com 0 somente para mudarmos depois;
    
    for(int i = 0; i < num; i++){
    	int numero;
    	cin >> numero;
    	// Pegamos o primeiro número;

    	int cont = 0;
    	// Iniciamos o contador em 0;
    	
    	for(int j = 2; j <= numero/2; j++){
    		// percorremos um loop de 2 até numero;
    		if(numero % j == 0){
				cont++;
				// Incrementamos o contador quando encontramos algum j que é divisível por num; seu seja, o resto da divisão entre numero e j é igual a zero;
			}
		}
		
		if(cont > maior){
			maior = cont;
			maiorNum = numero;
		}
		// Verificamos se a contagem que encontramos é maior que a nossa menor armazenada, se sim, armazenamos ela no lugar e qual número que possui as maiores divisões;
		
		
		else if(cont == maior){
			maiorNum = min(maiorNum, numero);
		}
		// Como o exercício pede que em caso de empate, deve ser mostrado o menos número, se o numero contado for igual ao nosso maior armazenado, pegamos o menor possível;
		
	}
	
	cout << maiorNum << "\n";
	// Imprimimos o maior número
    
    
    
    /*
    	Pegando como exemplo a primeira entrada do exemplo do exemplo do exercício;
    	5
		10 15 12 8 9
		
		Temos 5 números de entrada, primeira pegamos o número 10 e testamos até sua metade, começando em 2 e contando quantos divisores encontramos;
		cont = 0;
		10 % 2 == 0; cont++;
		cont == 1;
		10 % 3 == 1
		cont == 1;
		10 % 4 == 2
		cont == 1;
		10 % 5 == 0; cont++;
		cont == 2;
		Como o nosso maior tinha o valor -1 inicial, ele sempre será menor, então nosso maior agora pega o valor 2 e armazena em maiorNum o valor 10;
		maior == 2; numMaior == 10;
		
		O mesmo é feito para os outros números, contando os divisíveis;
		15:
		cont == 0;
		15 % 2 == 1;
		15 % 3 == 0;
		cont == 1;
		15 % 4 == 3;
		15 % 5 == 0;
		cont == 2;
		15 % 6 == 3;
		15 % 7 == 1;
		cont == 2;
		Como o nosso maior tinha o valor 2, e 15 também teve valor 2, ele armazena o menor entra 10 e 15, portanto continua como 10;
		maior == 2; numMaior == 10;
		
		12:
		cont == 0;
		12 % 2 == 0;
		cont == 1;
		12 % 3 == 0;
		cont == 2;
		12 % 4 == 0;
		cont == 3;
		12 % 5 == 2;
		12 % 6 == 0;
		cont == 4;
		Como nosso maior tinha valor 2, encontramos um valor maior, armazenamos o valor maior como 4 e maiorNum como 12;
		
		8:
		cont == 0;
		8 % 2 == 0;
		cont == 1;
		8 % 3 == 2;
		8 % 4 == 0;
		cont == 2;
		Portanto nosso maior continua como 4;
		
		9:
		cont = 0;
		9 % 2 == 1;
		9 % 3 == 0;
		cont == 1;
		9 % 4 == 1;
		cont == 1;
		
		Portanto nosso maior continua como 4;
		
		Imprimimos então o numMaior que tem valor 12, que possuiu o maior número de divisores: 4;
    
    
    */
    
    return 0;
}


