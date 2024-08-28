Projeto criado para a disciplina de Linguagem e Programação 2024.2 feito pelos alunos: Daniel Gudin, Dionysio Rangel, Gilson Batista, Pedro Henrique de Oliveira e Matheus Xavier

Atividade:
Desafio de Programação: "Banco de Dados de Produtos"
Descrição do Problema:
Você foi contratado para desenvolver uma aplicação simples em C para gerenciar um pequeno banco de dados de produtos. O sistema deve permitir ao usuário inserir novos produtos, listar todos os produtos, buscar um produto por nome e excluir um produto pelo nome. Cada produto terá as seguintes informações:
• Código (inteiro)
• Nome (string)
• Preço (float)
• Quantidade em estoque (inteiro)
Requisitos
1 Inserir Produto: O programa deve permitir ao usuário inserir um novo produto, incluindo código, nome, preço e quantidade em estoque. O código de cada produto é único.
2 Listar Produtos: O programa deve listar todos os produtos cadastrados, mostrando suas informações completas.
3 Buscar Produto por Nome: O programa deve permitir ao usuário buscar um produto pelo nome e exibir suas informações.
4 Excluir Produto por Nome: O programa deve permitir ao usuário excluir um produto pelo nome.
5 Menu de Opções: O programa deve apresentar um menu de opções para o usuário escolher a operação desejada. O programa deve continuar executando até que o usuário escolha a opção de sair.
Entrada e Saída
• O programa deve receber a entrada do usuário por meio de um menu com as opções:
1 Inserir produto
2 Listar todos os produtos
3 Buscar produto por nome
4 Excluir produto por nome
5 Sair
• Para cada opção, o programa deve solicitar as informações necessárias e apresentar as saídas de acordo com a escolha do usuário.
Regras e Considerações
• Use arrays para armazenar os produtos.
• O número máximo de produtos que podem ser armazenados é 100.
• Utilize funções para modularizar o código (ex.: uma função para inserir produtos, outra para listar produtos, etc.).
• O programa deve ser robusto contra entradas inválidas (por exemplo, ao tentar excluir ou buscar um produto que não existe).

Output esperado:

=== Menu de Opções ===
1. Inserir produto
2. Listar todos os produtos
3. Buscar produto por nome
4. Excluir produto por nome
5. Sair
Escolha uma opção: 1

Digite o código do produto: 101
Digite o nome do produto: Caneta
Digite o preço do produto: 1.50
Digite a quantidade em estoque: 100

Produto inserido com sucesso!

=== Menu de Opções ===
1. Inserir produto
2. Listar todos os produtos
3. Buscar produto por nome
4. Excluir produto por nome
5. Sair
Escolha uma opção: 2

Código: 101, Nome: Caneta, Preço: 1.50, Quantidade: 100

=== Menu de Opções ===
1. Inserir produto
2. Listar todos os produtos
3. Buscar produto por nome
4. Excluir produto por nome
5. Sair
Escolha uma opção: 5

Saindo do programa...
