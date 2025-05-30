#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "atm.h"

void newAccount(){
    atm_t account;
    char name[80];

    printf("\nYou wish create a new account?(Yes - 1 | No - 2)\n");
    int key;
    scanf("%d", &key);
    while(getchar() != '\n' && getchar() != EOF);
    
    switch (key){
    case 1:
        while(1){
            printf("Your full name: ");
            fgets(name, sizeof(name), stdin);
            if(strlen(name) == 0 || strlen(name) == 1) continue;
            strcpy(account.name, name);
            initAccount(&account);
            atmData(&account);
            break;
        }
        break;
    case 2:
        break;
    default:
        printf("Error of input underspected.\n");
        break;
    }
}

void accountExist(){

}

int main(int argc, char const *argv[]){
    int flag = 1;

    srand(time(NULL));
    
    while(flag){
        flag = 0;
        printf("You have account?\r\n(Exit - 0 |Yes - 1 | No - 2)\n");
        int key;
        scanf("%d", &key);

        switch(key){
        case 0:
            printf("Program closed.\n");
            break;
        case 1:
            accountExist();
            break;
        case 2:
            newAccount();
            flag = 1;
            break;
        default:
            printf("\n\nInvalid command, try again.\n\n");
            flag = 1;
            break;
        }
    }

    return 0;
}
