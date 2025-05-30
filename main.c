#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "atm.h"


int main(int argc, char const *argv[]){
    atm_t account;
    strcpy(account.name, "Pessoa Teste4");
    account.balance = 1000;
    
    srand(time(NULL));
    //initAccount(&account);

    draw("003882-2", 500);
    deposit("003882-2", 1500);

    return 0;
}
