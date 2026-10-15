# Ardu-Gameboy

**Status:** Em desenvolvimento  
**Plataforma:** Arduino  
**Linguagem:** C++  
**Ambiente de desenvolvimento:** VS Code + PlatformIO  
**Interface:** Monitor Serial  

## 1. Sobre o projeto

O **Ardu-Gameboy** é um projeto desenvolvido para Arduino que reúne jogos simples executados por meio do Monitor Serial. Seu desenvolvimento tem como objetivo praticar conceitos de programação embarcada, lógica de programação e organização de código.

O projeto também possui uma **finalidade educacional**, sendo pensado para utilização em sala de aula como recurso de apoio ao ensino de programação e lógica. Por meio de jogos simples e interativos, busca demonstrar conceitos como estruturas condicionais, laços de repetição, matrizes, variáveis e validação de entradas.

A proposta é desenvolver os jogos de forma incremental, permitindo que novas funcionalidades sejam implementadas e utilizadas como exemplos práticos durante as aulas.

## 2. Objetivos

### 2.1. Objetivo geral

Desenvolver uma coleção de jogos simples para Arduino, utilizando o Monitor Serial como interface, com foco no aprendizado de programação e na aplicação prática de conceitos de lógica.

### 2.2. Objetivos específicos

- Aplicar conceitos de lógica de programação em projetos práticos.
- Exercitar o uso de estruturas condicionais e laços de repetição.
- Trabalhar com matrizes, variáveis e manipulação de dados.
- Praticar a validação de entradas fornecidas pelo usuário.
- Utilizar o projeto como recurso didático em sala de aula.
- Desenvolver e testar funcionalidades de forma incremental.

3. Funcionalidades

O menu principal prevê três jogos e uma opção de saída.

Opção

Funcionalidade

Estado

1

Jogo da Velha

Implementação funcional em andamento

2

Jogo da Forca

Planejado

3

Jogo do Dinossauro

Planejado

0

Sair

Opção exibida no menu; comportamento pendente

3.1 Jogo da Velha

O jogo da velha é a primeira funcionalidade implementada no projeto.

O tabuleiro é representado por uma matriz de caracteres com três linhas e três colunas. Os jogadores alternam entre os símbolos X e O, selecionando as posições por meio de números de 0 a 8.

Funcionalidades implementadas:

Inicialização do tabuleiro com posições vazias.

Exibição do tabuleiro no Serial Monitor.

Conversão da posição escolhida em índices de linha e coluna.

Alternância entre os jogadores.

Verificação de posições ocupadas.

Detecção das oito combinações possíveis de vitória.

Identificação e exibição do jogador vencedor.

Encerramento da partida após a vitória.

Retorno ao fluxo do menu principal após o término da partida.

Funcionalidades pendentes:

Detecção de empate.

Refinamento do tratamento de entradas inválidas e caracteres extras.

Ajustes finais no fluxo de apresentação do menu.

4. Requisitos funcionais

Os requisitos funcionais descrevem os comportamentos que o sistema deve oferecer.

ID

Requisito

Estado

RF01

Exibir o menu principal com as opções de jogos.

Implementado

RF02

Permitir a seleção do Jogo da Velha.

Implementado

RF03

Apresentar um tabuleiro de 3 × 3.

Implementado

RF04

Receber posições de 0 a 8 pelo Serial Monitor.

Implementado

RF05

Converter a posição escolhida em linha e coluna.

Implementado

RF06

Impedir que uma posição ocupada seja sobrescrita.

Implementado

RF07

Alternar entre os jogadores X e O após uma jogada válida.

Implementado

RF08

Identificar as combinações de vitória.

Implementado

RF09

Informar o vencedor e encerrar a partida.

Implementado

RF10

Detectar empate quando o tabuleiro estiver cheio.

Pendente

RF11

Implementar o comportamento da opção de saída.

Pendente

RF12

Desenvolver os jogos da Forca e do Dinossauro.

Planejado

5. Requisitos não funcionais

ID

Requisito

Descrição

RNF01

Plataforma

Executar no ambiente Arduino compatível com o projeto.

RNF02

Interface

Utilizar comunicação serial para entrada e saída de dados.

RNF03

Usabilidade

Apresentar mensagens claras e instruções objetivas.

RNF04

Organização

Manter o código compreensível e passível de evolução.

RNF05

Desempenho

Executar as operações do jogo com resposta adequada à interação do usuário.

6. Tecnologias e ferramentas

C++: implementação da lógica dos jogos.

Arduino: plataforma de execução do software embarcado.

Visual Studio Code: edição e organização do código-fonte.

PlatformIO: gerenciamento do ambiente de desenvolvimento e compilação.

Serial Monitor: interação com o usuário durante a execução.

Git e GitHub: controle de versão e hospedagem do código-fonte, previstos para o versionamento do projeto.

7. Organização técnica

A implementação atual utiliza funções para separar responsabilidades e facilitar a leitura do programa.

Elemento

Responsabilidade

setup()

Inicializar a comunicação serial e apresentar o menu inicial.

loop()

Monitorar entradas e encaminhar a execução conforme a opção selecionada.

printMenu()

Exibir as opções disponíveis.

jogoDaVelha()

Controlar a partida, o tabuleiro, as jogadas e as condições de vitória.

A estrutura do jogo da velha utiliza uma matriz bidimensional de caracteres:

char area_Do_Jogo[3][3]

Os caracteres representam o estado de cada posição: X, O ou -, sendo o hífen utilizado para indicar uma posição vazia.

A posição recebida do usuário é convertida em índices por meio de divisão inteira e resto da divisão:

Linha: posicaoEscolhida / 3

Coluna: posicaoEscolhida % 3

Essa abordagem permite relacionar uma entrada numérica de 0 a 8 às nove posições da matriz.

8. Lógica de vitória

A detecção de vitória considera oito combinações:

Três linhas horizontais.

Três colunas verticais.

Duas diagonais.

Cada condição verifica se as três posições correspondentes contêm o mesmo símbolo e se a posição inicial não está vazia.

Quando uma combinação válida é encontrada, o programa apresenta o símbolo vencedor e interrompe o laço da partida.

A detecção de empate será adicionada posteriormente, verificando se todas as posições estão ocupadas sem que exista uma combinação vencedora.

9. Testes realizados

Os testes manuais foram executados pelo Serial Monitor.

Cenário

Resultado observado

Inicialização e exibição do tabuleiro

Funcionou

Seleção de posições válidas

Funcionou

Recusa de posição ocupada

Funcionou

Alternância entre X e O

Funcionou nos testes realizados

Vitória horizontal

Funcionou

Vitória diagonal

Funcionou

Identificação do símbolo vencedor

Funcionou

Retorno ao menu após a partida

Funcionou, com ajustes de fluxo ainda necessários

Detecção de empate

Ainda não implementada

Tratamento completo de entradas inválidas

Pendente de refinamento

Os testes realizados até o momento validam o funcionamento básico do jogo da velha, mas não representam uma cobertura completa de todos os cenários possíveis.

10. Limitações atuais

O projeto ainda está em desenvolvimento. A opção de saída está presente visualmente no menu, mas seu comportamento ainda não foi implementado. O tratamento de entradas seriais também pode ser refinado para evitar que caracteres residuais sejam interpretados como opções inválidas.

Os jogos da Forca e do Dinossauro ainda fazem parte do escopo planejado, mas não estão implementados na versão atual.

11. Próximas etapas

Implementar e testar a detecção de empate no Jogo da Velha.

Refinar o fluxo do menu e o tratamento das entradas seriais.

Implementar o comportamento da opção de saída.

Planejar e desenvolver o Jogo da Forca.

Planejar e desenvolver o Jogo do Dinossauro.

Atualizar a documentação conforme as funcionalidades forem concluídas.

12. Considerações finais

O Ardu-Gameboy constitui um projeto prático de aplicação de conceitos de programação em um ambiente embarcado. Seu desenvolvimento incremental permite implementar, testar e aprimorar cada funcionalidade antes de avançar para a próxima.

A implementação inicial do Jogo da Velha estabelece uma base para a inclusão dos demais jogos e para o aprofundamento dos conhecimentos de C++, estruturas de dados e controle de fluxo.

O projeto continuará evoluindo conforme novas funcionalidades forem desenvolvidas e validadas.