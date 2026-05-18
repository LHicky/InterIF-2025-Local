#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras.

using namespace std;
// Atalho para utilizar std;

// Esse exercício trata-se de uma Sifra de César, mas ao invés de somarmos um número fixo
// Devemos alter entre soma e subtração para cada letra, somando ou subtraindo com o valor no alfabeto de outro texto;
// Por exemplo com texto lua e chave aaa como a é a prmieira letra do alfabeto tem valor 1, criptografamos fazendo (l - 1)(u + 1)(a - 1) = kvz (a vira z (ciclico));
// Trata-se de um exercício de manipulação de string e char utilizando a tabela ASCII que dá valores numéricos para caracteres;

int main() {
    
    
    int num;
    string palavra, chave;
    
    
    cin >> num;
    // Pega o primeiro numero;
    
    while(num != 0){
    	
    	cin >> palavra >> chave;
    	// Armazenamos a primeira palavra e sua chave de criptografia / descriptografia;
    	
    	string novaPalavra = "";
    	// Variavel para armazenar letra por letra a string que criptografaremos ou descriptografaremos;
    	int inicio;
    	
    	if(num == 1){
    		inicio = 0;
		}
		else{
			inicio = 1;
		}
		// Como o processo de descriptografar é o oposto do processo de criptografar, o que muda é somente a verificação entre par e impar;
		// A variável inicio fica com 0 se queremos criptografar pois depois analisando i % 2 == inicio temos que i % 2 == 0, ou seja os pares são subtraídos e impares adicionados;
		// Já com para descriptografia fazemos o inverso onde verificamos i % 2 == inicio temos que i % 2 == 1, ou seja os impares são subtraídos e pares adicionados;
    	
		for(int i = 0; i < palavra.size(); i++){
		    int posPalavra = palavra[i] - 'a';
		    // Pega a posição da letra da palavra e faz conversão para inteiro;
			// Fazendo char - 'a' converte de char pra inteiro;		    
			
		    int posChave  = chave[i]  - 'a';
		    // Pega a posição da letra da chave e faz conversão para inteiro;
			// Fazendo char - 'a' converte de char pra inteiro;		    
		    
		    if(i % 2 == inicio){
		    	// verifica se é par ou impar, baseado na escolha de num
		        int posPar = (posPalavra - posChave + 25) % 26;
		        // Fazemos a posição da letra palavra menos a posição da letra da chave;
		        // Adicionamos + 25 e % 26 para garantirmos o loop completo sempre;
		        // Sendo o + 25 por ser a ultima posição possível (z) e 26 pois 26 deve retornar ao 0
		        
		        novaPalavra += (char)(posPar + 'a');
		        // Adicionamos a letra já modificada para palavra final convertida para char;
		        // A conversão de inteiro para char é (char) num + 'a', por conta da tabela ASCII;
		    }
		    else {
		        int posImpar = (posPalavra + posChave + 1) % 26;
		        // Fazemos a posição da letra palavra mais a posição da letra da chave;
		        // Adicionamos + 1 e % 26 para garantirmos o loop completo sempre;
		        // adicionamos 1 pois 'a' começa em zero (base zero) e 26 pois 26 deve retornar ao 0
		        
		        novaPalavra += (char)(posImpar + 'a');
		        // Adicionamos a letra já modificada para palavra final;
		        // A conversão de inteiro para char é (char) num + 'a';
		    }
		}
		cout << novaPalavra << "\n";
		// Imprime a nova palavra;
		
		cin >> num;
		// Pega o próximo número, deixando cin no final garante que num == 0 nunca entre dentro do loop e ele encerre;
	}
	// O loop while continua enquanto num lido for diferente de 0
	
	
	
	
	
	
	/*
	Pegando como exemplo a primeira entrada dos exemplos
	1 institutofederal chaveaseutilizar
	2 ozysnssvpt outrachave
	0
	
	Começamos com 1 então nosso inicio é 0;
	Subtraimos dos valores de letras em posições pares e adicionamos nos valores de letras impares;
	
	Temos a primeira letra da palavra = 'i' e a primeira letra da chave = 'c';
	Convertendo para inteiro começando em 0, temos
	posPalavra = 8; (posição da letra 'i' no alfabeto começando em 0)
	a = 0; b = 1; c = 2; d = 3; e = 4; f = 5; g = 6; h = 7; i = 8;
	
	posChave = 2; (posição da letra 'c' no alfabeto começando em 0)
	a = 0; b = 1; c = 2;
	
	A primeira posição é zero, então subtraimos;
	(8 - 2 + 25) % 26 = 31 % 26 = 5;
	convertendo o valor 5 de volta para char temos a letra 'f' (sexta palavra) (base 0);
	a = 0; b = 1; c = 2; d = 3; e = 4; f = 5;
	adicionamos 'f' na palavraFinal;
	
	A segunda letra da palavra = 'n' e a segunda letra da chave = h;
	posPalavra = 13;
	a = 0; b = 1; c = 2; d = 3; e = 4; f = 5; g = 6; h = 7, i = 8, j = 9, k = 10, l = 11, m = 12, n = 13;
	
	posChave = 7;
	a = 0; b = 1; c = 2; d = 3; e = 4; f = 5; g = 6; h = 7;
	Como antes fizemos a subtração agora fazemos a adição;
	(13 + 7 + 1) % 26 = 21 % 26 = 21;
	convertendo o valor 21 de volta para char temos a letra 'v'
	a = 0; b = 1; c = 2; d = 3; e = 4; f = 5; g = 6; h = 7, i = 8, j = 9, k = 10, l = 11, m = 12,
	n = 13; o = 14; p = 15; q = 16; r = 17; s = 18; t = 19; u = 20; v = 21;
	adicionamos 'v' na palavraFinal;
	
	O mesmo é feito para todas as outras letras;
	
	No caso de descriptografia quanto teremos num == 2, nosso inicio será 1
	O código funciona exatamente igual, mas alterna somente a order de subtrair e adicionar;
	
	*/
	
    
    return 0;
}

