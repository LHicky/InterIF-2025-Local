# InterIF-2025-Local
Resolução dos exercícios do InterIF de 2025 (Fase local)

# Problema A
Esse problema também é conhecido como o famoso problema do troco, onde tendo certas possíveis moedas queremos pagar usando a menor quantidade possível de moedas de modo a não sobrar troco.
Mas neste problema específico ele é dado como pontos de magia e potências de magia ao invés de troco e total;
Pode ser resolvido utilizando a lógica de algoritmo guloso (pegando sempre o mais optimo atual) por conta da potência de 2.
O truque está em sempre pegar a pedra de magia de valor mais alto primeiro, utilizar ela ao máximo possível e pegar a próxima, até acabar todas as pedras;

# Problema B
Esse problema é basicamente encontrar a maior cadeia de caracteres diferentes seguidos sem interupções;
Caso haja caracteres iguais devemos reiniciar a contagem e no final imprimir a maior sequencia de caracteres diferentes encontrada;
O truque está em sempre verificar somente o caracter atual e comparar com o anterior, caso sejem diferentes aumenta um contador, caso sejem iguais armazenamos a cadeia maior e reiniciamos o contador;

# Problema C
A ideia do problema é dividir o grupo de professores em dois grupos menores.
Para cada possível divisão (i e atual - i), calculamos o custo de juntar esses dois grupos.
Esse exercício é um problema de Programação Dinâmica onde utilizamos os valores calculados anteriormente para encontrarmos os valores futuros dos grupos;

