#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atm.h"


int main(int argc, char const *argv[]){
    atm_t account;
    strcpy(account.name, "Pessoa Teste");
    account.balance = 1000;
    
    srand(time(NULL));
    initAccount(&account);

    return 0;
}
