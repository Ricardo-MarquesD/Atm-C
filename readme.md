# ATM - Sistema de Gerenciamento de Contas Bancárias

Este projeto implementa um sistema simples de gerenciamento de contas bancárias em C, simulando operações básicas de um caixa eletrônico (ATM).

## Estrutura do Projeto

- **atm.h**: Interface com a definição da estrutura da conta(`atm_t`) e o esqueleto das seguintes funções:
    ```c
    void initAccount(atm_t *person);
    void draw(int id, long long balance);
    void deposit(int id, long long balance);
    ```

- **atm.c**: Implementação das funções declaradas no header.

- **main.c**: Função principal para interação com o usuário e testes.

## Funcionalidades

- **initAccount()**: Inicializa uma nova conta bancária.
- **draw()**: Permite sacar um valor de uma conta existente.
- **deposit()**: Permite depositar um valor em uma conta existente.