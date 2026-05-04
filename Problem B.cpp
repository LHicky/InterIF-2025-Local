#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras.

using namespace std;
// Atalho para utilizar std;

// O problema é basicamente encontrar a maior cadeia de caracteres diferentes seguidos
// Caso haja caracteres iguais devemos reiniciar a contagem e no final imprimir a maior sequencia de caracteres diferentes encontrada;

int main() {
    
    char ultimaLetra = 'O';
    // Cria variável que armazena um caractere e atribuií um valor que não é utilizado no exercício ('O')
    
    string palavra;
    cin >> palavra;
    // Lê e armazena tudo como uma String
    
    int sequenciaAtual = 0;
    int sequenciaMaior = 0;
    // Inicializa sequenciaAtual e sequenciaMaior
    
    for(char c : palavra){
    	if(c != ultimaLetra){
    		// Caso c seja diferente da ultima letra, então é a sequencia continua alternando;
    		ultimaLetra = c;
    		// Gravamos a letra atual na ultima letra para podermos comparar com a próxima
    		sequenciaAtual++;
    		// Aumentamos a sequenciaAtual em 1
		}
		else{
			// Caso c seja igual ao c anterior, ou seja, duas letras iguais juntas então inicia-se uma nova sequencia;
			sequenciaMaior = max(sequenciaAtual, sequenciaMaior);
			// a função max faz a comparação de valores, colocando dois valores ele pega sempre o maior entre eles;
			// Verificamos se a sequencia anterior foi a maior até o momento com max, se sim, colocamos ela em sequenciaMaior se não, continua a anterior;
			sequenciaAtual = 1;
			// Resetamos a sequência atual para 1 para verificarmos as novas sequências (1 pois a atual já conta como letra diferente);
		}
	}
	// Loop for(char c : palavra) significa, pegue as variáveis do tipo char que você encontrar dentro da string palavra e coloque uma a uma em uma variável chamada c;
	// Seria a mesma coisa que utilizar for (int i = 0; i < palavra.size(); i++) e depois utilizar char c = palavra[i];
	
	sequenciaMaior = max(sequenciaAtual, sequenciaMaior);
	// É feita a verificação aqui, pois o valor da sequênciaMaior só é atribuído quando há uma quebra na sequência;
	// Essa verificação garante que mesmo que não houve quebra na sequência ele atribui o valor maior a sequenciaMaior;
	
	cout << sequenciaMaior << "\n";
	// Imprime a maior sequência encontrada;
    
    return 0;
    /*
    Pegando a primeira entrada como Exemplo
    ABABBA
    Nosso código lê como uma string inteira e depois verifica letra á letra contando as sequências, comparando o caracter anteriot ao atual;
    No inicio nosso caracter vale 'O' por padrão, ele compara com A e como são diferentes incrementa sequenciaAtual em 1 e coloca ultimaLetra como A;
    sequenciaAtual == 1;
    ultimaLetra == A;
    sequenciaMaior == 0;
    palavra Restante == BABBA;
    Na proxima iteração ele verifica com B, como a ultima letra era A, então continua diferente, acrescentamos a sequenciaAtual e atualizamos a ultimaLetra
    sequenciaAtual == 2;
    ultimaLetra == B;
    sequenciaMaior == 0;
    palavra Restante == ABBA;
    Na proxima iteração ele verifica com A, como a ultima letra era B, então continua diferente novamente, acrescentamos a sequenciaAtual e atualizamos a ultimaLetra
    sequenciaAtual == 3;
    ultimaLetra == A;
    sequenciaMaior == 0;
    palavra Restante == BBA;
    Na proxima iteração ele verifica com B, como a ultima letra era A, então continua diferente novamente, acrescentamos a sequenciaAtual e atualizamos a ultimaLetra
    sequenciaAtual == 4;
    ultimaLetra == B;
    sequenciaMaior == 0;
    palavra Restante == BA;
    Já na próxima iteração ele verifica a letra atual B com a letraAnterior B, como são iguais o padrão foi quebrado, isso significa que a sequência parou alí;
    Como a sequencia foi quebrada pegamos a sequencia que tinhamos até agora e se ela for maior que sequenciaMaior atual, substituimos sequenciaMaior pela sequenciaAtual;
    Resetamos a variavel de sequencia atual para 1;
    sequenciaAtual == 1;
    ultimaLetra == B;
    sequenciaMaior == 4;
    palavra Restante == A;
    Na proxima iteração ele verifica com A, como a ultima letra era B, então são diferentes, acrescentamos a sequenciaAtual e atualizamos a ultimaLetra
    sequenciaAtual == 2;
    ultimaLetra == A;
    sequenciaMaior == 4;
    
    O loop termina e fazemos uma ultima verificação entre sequenciaAtual e sequenciaMaior para verificar, como sequenciaMaior é maior que sequenciaAtual, sequenciaMaior continua como 4;
    imprimimos maior sequência;
    */
}

