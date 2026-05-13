# InterIF-2025-Local
Resolução dos exercícios do InterIF de 2025 (Fase local)

# Problema A (Dificuldade 5/10)
A ideia do problema é conhecida como o famoso problema do troco, onde tendo certas possíveis moedas queremos pagar usando a menor quantidade possível de moedas de modo a não sobrar troco.
Mas neste problema específico ele é dado como pontos de magia e potências de magia ao invés de troco e total;
Pode ser resolvido utilizando a lógica de algoritmo guloso (pegando sempre o mais optimo atual) por conta da potência de 2.
O truque está em sempre pegar a pedra de magia de valor mais alto primeiro, utilizar ela ao máximo possível e pegar a próxima, até acabar todas as pedras;

# Problema B (Dificuldade 4/10)
A ideia do problema é basicamente encontrar a maior cadeia de caracteres diferentes seguidos sem interupções;
Caso haja caracteres iguais devemos reiniciar a contagem e no final imprimir a maior sequencia de caracteres diferentes encontrada;
O truque está em sempre verificar somente o caracter atual e comparar com o anterior, caso sejem diferentes aumenta um contador, caso sejem iguais armazenamos a cadeia maior e reiniciamos o contador;
Esse exercício é uma manipulação de caracteres de string;

# Problema C (Dificuldade 8/10)
A ideia do problema é dividir o grupo de professores em dois grupos menores.
Para cada possível divisão (i e atual - i), calculamos o custo de juntar esses dois grupos.
Esse exercício é um problema de Programação Dinâmica onde utilizamos os valores calculados anteriormente para encontrarmos os valores futuros dos grupos;

# Problema D (Dificuldade 2/10)
A ideia do problema é que devemos tentar fazer a maior pontuação possível, em uma competição de levantamento de peso onde valores iguais triplos e duplos valem mais;
Como ele nos dá 2 valores das duas primeiras tentativas e pede o maior valor para a maior quantidade possível de pontos, caso tenhamos feito 2 valores diferentes então o maior garantirá a maior pontuação (duplo);
Caso ele tenha levantado nas 2 tentativas o mesmo valor então a terceira deve ser também igual a ele, fazendo um triplo;
A maior dificuldade do exercício é entender o enúnciado, mas mesmo sem lermos o enúnciado e verificando as saídas de exemplo, é possível fazer esse problema, podendo ser resumido à "imprima o maior valor";

# Problema E (Dificuldade 4/10)
A ideia é encontrar onde há curvas perigosas, que são curvas que caso o carro não fizesse, ele cairia na água de um lago que fica no interior da pista;
Embora pareça um exercício de grafo ou de percorrer caminho, ele pode ser simplificado de modo que tendo os dados em uma matriz, somente precisamos olhar para o quadrado atual e seus arredores;
A dificuldade maior é notar que curvas perigosas estão sempre em um quadrado com pista, em seus arredores temos exatamente 2 quadrados de água e 2 de pista, caso isso seja verdadeiro é uma curva perigosa;
O exercício então se resume a percorrer a matriz e caso seja pista, olhar, em cima, esquerda, direita e abaixo e contar quantos quadrados são água e quantos são pista, se for 2 de cada, incrementa um contador;

# Problema F (Dificuldade 7/10)
A ideia do problema é contar a quantidade de vezes que cada palavra aparece em um texto dado, ignorando maiusculas e pontuação e mostrar em ordem decrescente de aparição e crescente alfabética todas as palavras;
A maior dificuldade está em limpar a palavra corretamente antes de armazena-lá, a ordenação também precisa de uma regra específica decrescente e depois crescente que deve ser modificada na função sort;
O exercício requer basicamente manipulação de strings e armazenamento e controle de vetores;

# Problema G (Dificuldade 1/10)
A ideia do problema é dado uma palavra você deve imprimir a primeira letra daquela palavra;
Basicamente pegamos um caracter dentro de uma cadeira de caracteres (ou vetor de caracteres) string;

# Problema H (Dificuldade 4/10)
A ideia do problema é dado uma posição (x, y) de uma casa inicial comparamos com outras posições (x, y) de outras casas verificando se a distância é menor ou igual a distância dada;
Caso ao menos uma casa tenha a distância menor devemos imprimir conforme o exercício especifica, caso nenhuma seja encontrada, imprimos outra mensagem;
Basicamente temos os pontos x0 e y0 da casa inicial e comparamos um a um com outros pontos x1 e y0 para encontrarmos a distância euclidiana;
Ou seja utilizamos a fórmula da distância euclidiana onde d = sqrt((x0-x1)^2 + (y0-y1)^2)

