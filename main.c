#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "atm.h"

void newAccount(){
    atm_t account;
    char name[80];

    printf("\nDeseja criar uma nova?(sim - 1 | não - 2)\n");
    int key = scanf("%d", &key);
    switch (key){
    case 1:
        while(1){
        printf("Seu nome completo: ");
        if(fgets(name, sizeof(80), stdin) == NULL) continue;
        initAccount(&account);
        break;
        }
        break;
    
    default:
        break;
    }
    strcpy(account.name, name);
}

void accountExist(){

}
int main(int argc, char const *argv[]){
    atm_t account;
    srand(time(NULL));
    strcpy(account.name, "Pessoa Teste4");
    
    while(1){
        printf("Você já possuí uma conta?\r\n       (sim - 1 | não - 2)");
        int key = scanf("%d", &key);

        switch(key){
        case 1:
            accountExist();
            break;
        case 2:
            newAccount();
            break;
        default:
            printf("\n\nComando invalido, tente novamente.\n\n");
        }
    }

    return 0;
}
