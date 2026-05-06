#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras.

using namespace std;
// Atalho para utilizar std;

// O exercício pede para que verificamos onde há curvas perigosas. Que são curvas onde, caso o carrinho não consiga efetuar a curva, ele cairia na água.
// Nesse exercício embora a princípio pareça utilizar caminhos em grid, ou grafos, na realidade, como o problema diz que a pista contorna um lago
// Isso significa que a água estará sempre somente na parte de dentro do circuíto, portanto é importante notar quando que teremos essas curvas
// O exercício fica simples se notarmos que o único momento que essas curvas perigosas aparecem é quando temos a pista atual do carrinho;
// Olhamos então para direita, esquerda,cima e abaixo da pista atual, se tivermos 2 quadrados com água e 2 com pista, ele é perigosa;
// Ou seja, os 2 quadrados com pista são o caminho do carrinho e os 2 com água acontecem quando há uma curva em direção a essa água.

bool dentroMapa(int x, int y, int coluna, int linha){
	return x >= 0 && x < coluna && y >= 0 && y < linha;
}
// Função que detecta se estamos ou não dentro do mapa returnando true se estamos dentro e false se não;
// Basicamente verificamos se a posição x e y estão incluidos dentro do mapa;
// Fazemos isso verificando se a posição x é maior ou igual a 0 e menor que o valor limite de coluna e y é maior ou igual a zero e menor que o valor limite de linhas;
// Como usamos todos com && (lógico e) se qualquer um deles não for verdadeiro é retornado falso, ou seja não está dentro do limite

int main() {

	int colunas, linhas;
	cin >> colunas >> linhas;
	// Armazenamos o tamanho limite de linhas e colunas do circuíto;
	
    vector<vector<char>> percurso (colunas, vector<char>(linhas));
    // Vector faz a criação de um vetor;
    // Um vetor dentro de outro vector<vector<variável>> é o mesmo que uma matriz em array ou seja variável[colunas][linhas];
    // Estamos definindo o tamanho do vetor, a função que instancia uma matriz e define seu tamanho ao mesmo tempo é a seguinte:
    // vector<vector<variável>> nome (num Colunas, vector<variável>(num Linhas));
    
    // Estamos usando char para pegarmos como caracteres, mas int também funcionaria;
    
    
    const int dx[] = {-1, 0, 0, 1};
    const int dy[] = {0, 1, -1, 0};
    // Criamos esses vetores com as direções que teremos que verificar, como temos dx e dy significa que temos as quatro possibilidades
    // esquerda, cima, baixo e direita, respectivamente, sempre considerando a posição 0, 0 como atual para somarmos depois;
    // Quando dx[0] = -1 e dy[0] = 0; então temos á esquerda da posição atual
    // Quando dx[1] = 0 e dy[1] = 1; então temos acima da posição atual
    // Quando dx[2] = 0 e dy[2] = -1; então temos abaixo da posição atual
    // Quando dx[3] = 1 e dy[3] = 0; então temos á direita da posição atual
    
    for(int i = 0; i < colunas; i++){
    	for(int j = 0; j < linhas; j++){
    		cin >> percurso[i][j];
		}
	}
	// Fazemos a leitura de todo o percurso, a leitura é deita com dois loops um para i (coluna) e outro para j (linha) na matriz percurso[i][j]
	
	int curvas = 0;
	// Iniciamos uma variável para contar as curvas perigosas feitas;
	
	for(int coluna = 0; coluna < colunas; coluna++){
    	for(int linha = 0; linha < linhas; linha++){
    		if(percurso[coluna][linha] != '1') continue;
    		// Caso aquele quadrado da matriz não seja 1 então é água ou fora da pista e não precisamos analisar;
    		// O comando continue quando dentro de um loop faz com que aquela iteração é ignorada e o loop continua para a próxima iteração;
			// Ou seja, pulamos aquele quadrado e vamos ao próximo até encontrarmos um com pista '1';

    		int countAgua = 0;
    		int countPista = 0;
    		// Iniciamos duas variáveis uma para contarmos a quantidade de água ao lado da pista atual;
    		// Outra para contarmos a quantidade de pista ao lado da pista atual;
    		
    		for(int direcao = 0; direcao < 4; direcao++){
    			
    			int nx = coluna + dx[direcao];
    			int ny = linha + dy[direcao];
    			// Criamos essas posições auxiliares, armazenamos nela a soma entre a posição atual (coluna e linha) com a direção que estamos analisando;
    			// Ou seja, para esquerda (-1, 0) somamos com a posição atual (3, 3) por exemplo e ficamos com (3-1, 3+0) = (2, 3) ou seja a posição à esqueda de (3,3);
    			// Fazemos isso para cada uma das direções, esquerda, cima, baixo e direita e armazenamos o x em nx e y em ny;
    			
    			if(!dentroMapa(nx, ny, colunas, linhas)) continue;
    			// Caso a posição não esteja dentro do mapa, ignoramos ela e testamos a próxima;
			    // O ponto de explamação uma verdade, portanto estamos usando para falar que quando estaDentro retornar falso, devemos pular aquela direção e tentar a próxima;
    			
    			if(percurso[nx][ny] == '1'){
    				countPista++;
				}
				// Com a posição dentro do mapa, verificamos se ela é igual a 1 (pista), se for incrementamos o contador de pista
				else if(percurso[nx][ny] == '2'){
					countAgua++;
				}
				// Verificamos agora se ela é igual a 2 (água), se for incrementamos o contador de água
			}
			// Esse loop percorre as 4 direções que fizemos anteriormente (esquerda, acima, abaixo e direita)
			
			
			if(countAgua >= 2 && countPista >= 2){
				curvas++;
			}
			// Ao final do loop verificamos a quantidade de pista e de água que encontramos ao redor da pista atual
			// Caso tenhamos encontrado 2 quadrados com pista e 2 quadrados com água, então achamos uma curva perigosa
			
			
    	}
	}
	
	cout << curvas << "\n";
	// Imprime a quantidade de curvas perigosas encontradas;
    
    /*
    Pegando por exemplo a primeira entrada
    7 8
	0 0 0 0 1 1 1 1
	0 0 0 0 1 2 2 1
	0 0 0 0 1 2 2 1
	1 1 1 1 1 2 2 1
	1 2 2 2 2 2 2 1
	1 2 2 2 2 2 2 1
	1 1 1 1 1 1 1 1
	Onde 7 é o numero de linhas e 8 o número de colunas;
	Como podemos ver o único ponto onde temos 1 e ao seu lado outras 2 quadrados de pistas (1) e dois quadrados de água (2)
	
	Nosso algoritmo percorre todos os quadrados e quando acha um quadrado de pista (1) olha para seus lados,
	Direita, Cima, Baixo e Esquerda e conta quantos quadrados de água e de pista que encontrou;
	Se encontrou 2 de cada então é uma curva perigosa e incrementamos o contador;
	Isso acontece na única curva 
	0 1 2
	1 1 2
	2 2 2
	Ao final imprimimos esse contador que para esse exercício dá resultado 1;
	
    */
    
    
    
    return 0;
}
