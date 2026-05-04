#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras.

using namespace std;
// Atalho para utilizar std;


// Esse problema também é conhecido como o famoso problema do troco, onde tendo certas possíveis moedas queremos pagar usando a menor quantidade possível de moedas de modo a não sobrar troco;
// Mas neste problemas ele é dado como pontos de magia e potências de magia;

// Pode ser resolvido utilizando a lógica de algoritmo guloso (pegando sempre o mais optimo atual) por conta da potência de 2

int main() {
    
    int numPedra;
    cin >> numPedra;
    // Variável para armazenar quantidade de pedras utilizadas;
    
    vector<int> pedras (numPedra);
    // Cria um vetor do tamanho da quantidade de pedras;
    
    for(int i = 0; i < numPedra; i++){
    	cin >> pedras[i];
    	// Loop que pega todas as pedras e armazena no vetor pedras[i], armazenando todas as potências.
	}
	
	int total;
	cin >> total;
	// Esse é o valor total de pontos de magia que deve ser consumido;
	
	sort(pedras.rbegin(), pedras.rend());
	// A função sort ordena vetores.
	// A função sort(pedras.begin(), pedras.end()); ordena o vetor em ordem crescente, mas como queremos primeiro os maiores valores fazemos um sort reverso
	// Utilizando sort(vetor.rbegin(), vetor.rend()) ordenamos o vetor em ordem decrescente, deixando o maior valor primeiro;
	
	int pedrasUsadas = 0;
	// Inicializa variável para contar quantas pedras utilizamos;
	
	for(int i = 0; i < numPedra; i++){
		pedrasUsadas += total / pedras[i];
		// Como utilizamos int, ele é arredondado sempre para o menor inteiro, portanto dividindo o total pelo valor da pedra atual temos a quantidade daquela pedra que podemos utilizar, acrescentamos isso ao contador;
		total = total % pedras[i];
		// Agora que acrescentamos ao contador, precisamos retirar do total a quantidade acrescentada, pegamos o resto da divisão entre o total e o valor da pedra atual;
	}
	// Loop for, ele passa por todos os valores das pedras, começando no maior até o menor;
    
    
    
    if(total > 0){
    	cout << "frustraka";
	}
	// Ao final do loop, se ainda sobrou algum valor diferente de 0, significa que não foi possível utilizar exatamente todos os pontos, portanto o exercicio especifica que escrevamos "frustraka" na saída;
	else{
		cout << pedrasUsadas;
	}
	// Caso foram utilizados todos os pontos é imprimido quantas pedras foram utilizadas;
	
	cout << "\n";
	// Pula-se uma linha no final;
    
    return 0;
    
    /*
    Pegando como exemplo a primeira entrada
    5		// Quantidade de pedras
    8		// Pedra[0]
    1		// Pedra[1]
    2		// Pedra[2]
    4		// Pedra[3]
    16		// Pedra[4]
    21		// Valor total de pontos
    
    Vetor Pedra ordenado = {16, 8, 4, 2, 1}
    total = 21;
    Tendo lido e armazenado todos os valores, nosso algoritmo pega o valor total e divide pelo primeiro valor do vetor depois de ordenado;
    Ele divide 21 por 16, como podemos dividir 1 vez, ele soma esse 1 na variável pedrasUsadas;
    Ele pega o total e coloca como igual ao resto da divisão ou seja 21 % 16 que é igual à 5;
    pedrasUsadas == 1;
    total == 5;
    No proximo indice ele pega o valor 8, como a divisão de 5 / 8 é igual a 0, nada é adicionado;
    pedrasUsadas == 1;
    total == 5;
    No proximo indice ele pega o valor 4
	Como 5 / 4 é igual a 1 ele incrementa pedrasUsadas em 1;
    Ele pega o resto da divisão entre 5 e 4 e coloca em total;
    pedrasUsadas == 2;
    total == 1;
    quando ele tenta dividir total por 2 dá zero então nada acontece;
    pedrasUsadas == 2;
    total == 1;
    no ultimo indice ele tenta dividir 1 por 1 e o resultado é 1 e resto é 0;
    pedrasUsadas armazena 3;
    total = 0;
    O loop é encerrado e quando chega na verificação ele verifica o total é maior que 0 ?
    Não, total é igual a zero, portantoo ele entra no else e imprime pedrasUsadas que tem o valor 3;
    Caso o valor total não fosse igual a zero (sobrou pontos não utilizados) ele imprimiria "frustraka";
    
    
	// Complexidade:
	// O(n log n)
	
    */
}

