#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "atm.h"

void freebuf(){
    while(getchar() != '\n' && getchar() != EOF);
}

void newAccount(){
    atm_t account;
    char name[80];

    printf("\nYou wish create a new account?(Yes - 1 | No - 2)\n");
    int key;
    scanf("%d", &key);
    freebuf();
    
    switch(key){
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
    atm_t account;
    int money;
    char account_number[9];

    printf("Enter your account number (000000-0): \n");
    while(1){
        fgets(account_number, sizeof(account_number), stdin);
        account_number[8] = '\n';
        if(seek_atm(&account, account_number) == -1) {
            printf("Invalid account number, try again.\n"); 
            continue;
        }
        break;
    }

    atmData(&account);

    printf("\nWhat you wish: (Nothing - 0 | Draw - 1 | Deposit - 2)\n");
    int key;
    scanf("%d", &key);
    freebuf();

    switch(key){
    case 0:
        break;
    case 1:
        printf("Withdraw amount(Only integer numbers): \n");
        scanf("%d", &money);
        freebuf();
        draw(account_number, money);
        break;
    case 2:
        printf("Depoist amount(Only integer numbers): \n");
        scanf("%d", &money);
        freebuf();
        deposit(account_number, money);
        break;
    default:
        printf("Invalid input.\n");
        break;
    }

}

int main(int argc, char const *argv[]){
    int flag = 1;

    srand(time(NULL));
    
    while(flag){
        flag = 0;
        printf("You have account?(Exit - 0 |Yes - 1 | No - 2)\n");
        int key;
        scanf("%d", &key);
        freebuf();

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
