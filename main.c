#include "atm.h"
#include <string.h>

int main(int argc, char const *argv[]){
    atm_t account;
    strcpy(account.name, "Pessoa Teste");
    account.balance = 1000;

    initAccount(&account);

    return 0;
}
