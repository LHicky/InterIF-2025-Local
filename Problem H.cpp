#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras.

using namespace std;
// Atalho para utilizar std;

// O exercício pede que dado um tamanho de grid, e a posição de uma casa dentro desse grid e a distância desejada;
// Verificamos com outras casas a distância entre a casa inicial e essas outras casas verificando se estão dentro da distancia desejada ou não;
// Caso alguma casa esteja dentro da distância imprimimos "Uma casinha no meio de todas" caso contrário (nenhuma casa dentro da distância) imprimimos "Uma casinha no meio do nada";
// Esse exercício é basicamente calcular a distância Euclidiana entre as casas verificando com a distância dada;

/*
	Distância Euclidiana
	A distância Euclidiana pode ser visualizada como vemos Pitágoras onde a^2 + b^2 = c^2; mas descobrimos a distância fazendo
	
	d = sqrt((x0-x1)^2 + (y0-y1)^2);
	Ou seja, (x0, y0) são pontos (nesse caso da casa inicial) e (x1, y1) são pontos (da casa para comparação);
	Para evitarmos utilizar a função de raiz quadrada, como já temos o valor da distância podemos elevar ambos os lados ao quadrado e tiramos a raiz, ficando com
	
	Fórmula da Distância que utilizamos no exercício;
	d^2 = (x0-x1)^2 + (y0-y1)^2;
	
*/



int main() {
	int gridX, gridY, casaX, casaY, distancia;
	// Instanciamos as variável que serão utilizadas
		
	cin >> gridX >> gridY >> casaX >> casaY >> distancia;
	// Lemos as variáveis de tamanho do grid, posição da casa e distância;
	// O tamanho do grid pode ser ignorado, visto que não influencia na distância;
	
	int casas;
	cin >> casas;
	// Quantas casas serão verificadas;
	
	
	distancia *= distancia;
	// Usaremos a distância ao quadrado para os cálculos para evitar usar raiz quadrada;
	// Sempre que possível o melhor é evitar usar funções como pow (potência) e sqrt (raiz quadrada), pois podem gerar erros de flutuação na resposta;
	
	bool noMeio = false;
	// Uma flag para que caso ao menos uma casa seja encontrada mudamos noMeio para true, e imprimimos no final
	
	for(int i = 0; i < casas; i++){
		int x, y;
		cin >> x >> y;
		// Lê e armazena as posições x e y da casa para comparação;
		
		if(noMeio) continue;
		// Caso já encontramos uma casa com distância menor não precisamos mais calcular, pois o exercício diz que se ao menos uma foi encontrada devemos imprimir a mesma coisa sempre;
		// Caso ainda não tenhamos encontrado nenhuma casa com distância menor, continuamos verificando com as outras;
		
		int xdif = x - casaX;
		// Calculamos a diferença entre o x da casa que estamos comparando e o x da casa inicial;
		int ydif = y - casaY;
		// Calculamos a diferença entre o y da casa que estamos comparando e o y da casa inicial;
		
		if(((xdif * xdif) + (ydif * ydif)) <= distancia){
			// Pegamos e somamos o quadrado de xdif + o quadrado de ydif e comparamos com a distância, conforme a equação Euclidiana de distância (explicado em cima);
			noMeio = true;
			// Marcamos nossa flag como verdadeiro se encontramos uma distância igual ou menos a especificada;
		}
	}
	// Passamos por todas as casas, verificando se alguma delas tem distância menor ou igual à especificada;
	// ** Note que, mesmo encontrando alguma casa que satisfaça a condição, devemos ainda ler todos os valores, é essencial para que o juiz não de a resposta como inválida (time limit);
	
	
	if(noMeio)
		cout << "Uma casinha no meio de todas\n";
	else 
		cout << "Uma casinha no meio do nada\n";
	// Imprimimos conforme especificado no exercício;
	
	
	/*
		Pegando como exemplo a primeira entrada
		10 10 3 3 2
		3
		1 1 
		5 5
		8 8
		
		O tamanho do grid em X e Y não precisa ser utilizado, mas a posição (3, 3) da casa e a distância 2 são importantes;
		Como usamos o quadrado da distância temos que d = 2 * 2; Ou seja d = 4;
		
		Iniciamos nossa flag boleana noMeio com valor false;
		
		Agora comparamos com os outros 3 casos de teste;
		para (1, 1) fazemos
		(3 - 1)*(3 - 1) + (3 - 1)*(3 - 1) => 2*2 + 2*2 => 4 + 4 => 8
		Comparamos 8 com a nossa distância ao quadrado 4, como 8 é maior que 4 não está no meio;
		
		para (5, 5) fazemos
		(3 - 5)*(3 - 5) + (3 - 5)*(3 - 5) => -2*-2 + -2*-2 => 4 + 4 => 8
		Comparamos 8 com a nossa distância ao quadrado 4, como 8 é maior que 4 não está no meio;
		
		para (8, 8) fazemos
		(3 - 8)*(3 - 8) + (3 - 8)*(3 - 8) => -5*-5 + -5*-5 => 25 + 25 => 50
		Comparamos 50 com a nossa distância ao quadrado 4, como 50 é maior que 4 não está no meio;
		
		A nossa flag booleana (noMeio) que iniciamos no começo não foi alterada (continuou false), então imprimimos
		"Uma casinha no meio do nada";
		
	*/
		
	return 0;
}

