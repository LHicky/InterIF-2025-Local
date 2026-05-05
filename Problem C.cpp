#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras.

using namespace std;
// Atalho para utilizar std;

// A ideia do problema é dividir o grupo de professores em dois grupos menores.
// Para cada possível divisão (i e atual - i), calculamos o custo de juntar esses dois grupos.
// Esse exercício é um problema de Programação Dinâmica;

int main() {
    
    int professores;
    cin >> professores;
    // Armazena o número de professores a serem reunidos
    
    vector<long long> dp(professores + 1, 0);
    // A estrutura de criação do vetor é basicamente vector <variável> nome(tamanho, valor);
    // Cria um vetor do tipo long long (mais casas que int) de tamanho igual ao numero de professores + 1 e atribui a todos os valores do vetor o número 0;
    

    dp[1] = 2;
    // Coloca o valor de dp[1] = 2, pois caso haja 1 professor o problema diz que a energia gasta é 2;
    if (professores >= 2) {
        dp[2] = 3;
        // Coloca o valor de dp[2] = 3, pos caso haja 2 professores o problema diz que a energia gasta é 3;
    }
    
    // Para mais do que 2 professores a energia gasta é min(enegia(i) * energia(N-1)) isso significa que precisamos saber a energia de todos os N anteriores até chegarmos ao N atual;
    // Temos os valores para N = 1 e N = 2, que são 2 e 3 respectivamente que o exercício deu, para os outros temos que percorrer até chegarmos em N;
	
    for (int atual = 3; atual <= professores; atual++) {
        
        long long menorEnergia = 1e18; 
        // Iniciamos a variável menorEnergia com um número bem alto (1e18 = 1000000000000000000), para garantir que peguemos um novo quando compararmos.

        for (int i = 1; i < atual; i++) {
            
            long long custoDessaDivisao = dp[i] * dp[atual - i];    
            // Encontra o custo da divisão atual fazendo a divisão anterior vezes a atual (energia(i) * energia(i-1));
            menorEnergia = min(menorEnergia, custoDessaDivisao);
            // Armazena o menor valor de energia que conseguiu até o momento entre os custos anteriores e o calculado com valor atual;
            
            
        }
        // Esse loop começa em 1 até atual, ou seja ele salva a menor energia possível para o número de professores atual (que muda a cada iteração do outro loop);
        // Por exemplo, um grupo com 4 professores pode formar grupos {4, 0} {1, 3} {2, 2} {3, 1}
		// Para cada divisão, calculamos o custo e pegamos o menor entre eles.
		
        
        dp[atual] = menorEnergia;
    }
    // Fazemos um loop para descobrir os valores das energias de 3 professores até o valor de N professores que queremos;
    // Calculamos dp[3], dp[4], ..., até dp[N] ou seja, calculamos primeiro para 3 professores {1, 2} {2, 1} com esse resultado armazenamos em dp[3] e utilizamos ele na próxima iteração
	// Isso é programação dinâmica: reutilizar resultados anteriores para montar respostas maiores.

    cout << dp[professores] << "\n";
    // Imprime o valor final do dp ou seja o min(enegia(i) * energia(N-1))

    return 0;
    
    
	/*
    Pegando por exemplo a primeira entrada
    3
    O nosso código instancia dp com tamanho 4 e já aloca para ele que
	dp[1] = 2;
	dp[2] = 3;
	Que são os valores de energia para 1 e 2 professores respectivamente, queremos para 3 professores;
	Então entramos no primeiro loop e colocamos menor energia como um número extremamente alto (1e18)
	Entramos no segundo loop, iniciamos i em 1 até atual (3) - 1 ou seja, loop de 1 até 2;
	Ele testa as diferentes formas de conseguirmos combinar 3 professores, mas que neste caso são somente duas
	Com 3 professores podemos fazer os grupo {2, 1} e {1, 2} e ambos dão o mesmo resultado;
	Como dito no exercício fazemos energia = energia(i) * energia (atual-i);
	Portanto para {2, 1} temos dp[2] * dp[1] que é 2 * 3 = 6
	É feita a comparação da menorEnergia atual com essa divisão e pega a menor, como a menorEnergia atual é um número muito grande
	menorEnergia = 6;
	Já na próxima iteração para {1, 2} temos dp[1] * dp[2] que é 3 * 2 = 6;
	Portanto menorEnergia = 6;
	O loop é concluído e impresso a menor energia: 6;	
	
	
	Uma coisa legal de notar é que sempre pegamos grupos de 2, por exemplo para 5 professores usamos
	{1, 4} {2, 3} {3, 2} {4, 1}
	Porque não precisamos testar {1, 1, 1, 1, 1} ou {2, 2, 1} ?
	Porque estamos usando os valores anteriores (Programação dinâmica) ou seja,
	Testar {2, 2, 1} é a mesma coisa que testar {4, 1} pois já fizemos em iterações anteriores a menor energia de 4 e salvamos em dp[4]
	Então todas as possibilidades estão sendo calculadas uma a uma, mas não refazemos o trabalho que já foi feito anteriormente
    */
    
}
