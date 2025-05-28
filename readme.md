# ATM - Sistema de Gerenciamento de Contas Bancárias

Este projeto implementa um sistema simples de gerenciamento de contas bancárias em C, simulando operações básicas de um caixa eletrônico (ATM).

## Estrutura do Projeto

- **atm.h**: Interface com a definição da estrutura da conta(`atm_t`) e o esqueleto das seguintes funções:
    ```
    void initAccount(atm_t *person);
    void draw(int id, long long balance);
    void deposit(int id, long long balance);
    ```

- **atm.c**: Implementação das funções declaradas no header.

- **main.c**: Função principal para interação com o usuário e testes.

## Funcionalidades

- **Criar conta**: Inicializa uma nova conta bancária.
- **Saque**: Permite sacar um valor de uma conta existente.
- **Depósito**: Permite depositar um valor em uma conta existente.