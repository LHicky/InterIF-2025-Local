#include <bits/stdc++.h>
// Biblioteca bits importa bibliotecas padrão como Vector, String, Math, Pair, Iomanip e muitas outras.

using namespace std;
// Atalho para utilizar std;

struct Palavra{
	string palavra;
	// Armazenamos a palavra;
	int quantidade;
	// Armazenamos a quantidade de vezes que a palavra apareceu;
	
	bool operator<(const Palavra& outra) const{
		// A sintaxe é essa para comparação, pegamos a struct Palavra atual e comparamos com uma struct "outra"
		if(quantidade != outra.quantidade) return quantidade > outra.quantidade;
		// Primeiro verificamos, se uma quantidade for diferente da outra pegamos sempre a maior quantidade primeiro;
		return palavra < outra.palavra;
		// O código entra aqui somente se as duas palavras tiverem mesma quantidade;
		// Comparamos então uma palavra com a outra, a comparação feita palavra < outra.palavra ordena elas em ordem alfabética crescente (a -> z)
	}
	// Essa função dentro da struct sempre como comparador, ou seja, quando usarmos a função sort, a comparação é feita aqui;
	// Ou seja, quaisquer regras que colocarmos aqui serão seguidas pelo sort, podemos então ter controle do sorteamento;
	// ** Muito importante ter isso em suas anotações, como nesse caso queremos sortear primeiro em order decrescente e desempate em crescente;
};
// Struct para armazenar a palavra e contar a quantidade de vezes que aparece;

int main() {

	map <string, int> palavras;
	// um map funciona como um vetor, mas no lugar de posições, como vetor[0] podemos usar qualquer variável;
	// nesse caso fazemos um map string e int <string,int> ou seja map[texto] = 6 armazena 6 na variável de acesso "texto";
	// Dessa maneira podemos contar facilmente as palavras;
	
	string palavra;
	// Variável para leitura da palavra atual
	
	while (cin >> palavra){
		// Como não sabemos quando as palavras acabam de serem digitadas usamos um cin dentro do while, ele continua lendo até o arquivo não ter mais palavras para serem lidas EOF
		string formatada = "";
		// Uma variável string vazia;
		
		for(char c : palavra){
			if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			// Preenche a palavra letra a letra, dessa maneira pegamos apenas letra minusculas (c >= 'a' && c <= 'z') e maiúsculas (c >= 'A' && c <= 'Z') ignorando espaços ou pontuação;
				formatada += tolower(c); 
				// Convertemos a letra para minusculo e armazenamos, visto que no final a saída usa as palavras em minúsculos sem diferenciação;
				
			
		}
		// O for que passa por todas as letras: 'c' (char) da palavra (string) até acabar;
		// Ou seja ela pega letra a letra e atribui ela a variável c, é mesma coisa que for(int i = 0; i < palavra.size(), i++){char c = palavra[i]}, mas mais rápido e simples
		
		if(formatada.empty()) continue;
		// Verificamos se alguma palavra foi realmente lida, se a string formatada estiver vazia então não fazemos nada e buscamos a próxima (continue)
		
		palavras[formatada]++;
		// Se a palavra foi lida e é válida, somamos uma no mapa palavras, ou seja o mapa que antes era palavras[boca] e tinha valor 0 (inicial), agora acrescentamos +1;
		// Fazemos isso para todas as palavras, salvando a quantidade que cada uma aparece;
	}
	
	vector <Palavra> palavrasFinal;
	// O uso do map facilita a contagem das palavras, mas ele não ordena as palavras como queremos, por isso, após armazenarmos todas as quantidades de palavras
	// Criamos um vector do Struct Palavra para passarmos do map para vector e podermos ordenar normalmente;
	
	for(pair<string, int> p : palavras){
		palavrasFinal.push_back({p.first, p.second});
		// A biblioteca pair utiliza first e second para acessarmos o seu primeiro e segundo valor, respectivamente,
		// A função push_back é uma das mais importantes e ela que permite adicionar um novo valor no vetor ao final do vetor;
		// Então passamos agora os pares de valores encontrados para nosso vetor de Struct palavrasFinal, que armazena palavra e quantidade {palavra, quantidade};
		
	}
	// A biblioteca pair funciona como o vector, mas armazena duas variáveis, o map que utilizamos pode ser convertido em pair para acessarmos suas variáveis;
	// Pegamos então todos os pares de variáveis que tinhamos no map palavras, e colocamos em um pair de nome p;
	
	sort(palavrasFinal.begin(), palavrasFinal.end());
	// A função sort ordena vetores.
	// A função sort(pedras.begin(), pedras.end()); ordena o vetor em ordem crescente;
	// Mas como temos nosso operator dentro da struct a ordenação segue a ordem do operator;
	
	int tamanho = 0;
	
	bool primeiro = true;
	// variável somente pra verificar se e a primeira para não imprimirmos quebra de linha nela;
	
	for(int i = 0; i < palavrasFinal.size(); i++){
		if(palavrasFinal[i].quantidade != tamanho){
			if(!primeiro)
				cout << "\n";
			primeiro = false;
			tamanho = palavrasFinal[i].quantidade;
			cout << tamanho << ": " << palavrasFinal[i].palavra;
		}
		// Se mudou o tamanho da palavra, pulamos uma linha e colocamos o tamanho antes de escrever a palavra;
		else{
			cout << " " << palavrasFinal[i].palavra;;
		}
		// Se não mudou o tamanho da palavra, só damos um espaço e escrevemos a palavra;
	}
	// Percorre todas as palavras do vetor ordenado palavra
	
	cout << "\n";
	// Quebra de linha final
    
    /*
    Pegando por exemplo a primeira entrada,
    Quem tem boca vai a Roma.
	Que tem boca vaia Roma.
	O filosofo se perguntava:
	Quem tem boca "vai a" ou "vaia" Roma?
    
    Nosso código pega palavra por palavra, formata, retirando pontos, e deixando tudo em minusculo;
    Ele então utiliza um map <string, int> para incrementar o valor do inteiro referente aquela palavra;
    "Quem" vira "quem" e é adicionado em 1, como ainda não tinhamos quem então map automaticamente cria quem com int 0 e adiciona 1;
    Portanto palavras[quem] == 1;
    O mesmo ocorre para todas as outras palavras, uma a uma, adicionando +1 em cada encontro;
    
    Após finalizar todas as palavras temos o maps pronto e passamos um a um de maps para vetor;
    O primeiro do maps fica como um pair p<quem, 3> e adicionamos no vetor em forma de struct com struct.palavra = quem struct.quantidade = 3;
    Ordenamos o vetor de forma decrescente por quantidade e em caso de empate crescente por alfabética;
    Imprimimos o vetor;
    */
    
    
    return 0;
}
