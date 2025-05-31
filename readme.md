# ATM - Sistema de Gerenciamento de Contas Bancárias

Este projeto implementa um sistema simples de gerenciamento de contas bancárias em C, simulando operações básicas de um caixa eletrônico (ATM).

## Estrutura do Projeto

- **atm.h**: Interface com a definição da estrutura da conta(`atm_t`) e o esqueleto das seguintes funções:
    ```c
    void atmData(atm_t *person);
    int seek_atm(atm_t *person, char account_number[9]);
    void initAccount(atm_t *person);
    void draw(char account_number[9], long long balance);
    void deposit(char account_number[9], long long balance);
    void resetBin();
    ```

- **atm.c**: Implementação das funções declaradas no header.

- **main.c**: Função principal para interação com o usuário e testes.

## Funcionalidades

- **atmData()**: Faz a visualização de uma conta.
- **seek_atm()**: Faz a busca por uma conta através do número da conta.
- **initAccount()**: Inicializa uma nova conta bancária.
- **draw()**: Permite sacar um valor de uma conta existente.
- **deposit()**: Permite depositar um valor em uma conta existente.
- **resetBin()**: Reseta do o arquivo report.