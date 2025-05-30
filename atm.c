#include "atm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void atmData(atm_t *person){
    if(person == NULL) return;
    printf("\n-------Data Account-------\n");
    printf("Name: %s\n", person->name);
    printf("Account number: %s\n", person->account_number);
    printf("Ban Agency: %d\n",person->agence);
    printf("Bank balance: %lld\n\n", person->balance);
}

void seek_atm(atm_t *person, char account_number[9]){
    FILE *stream;
    atm_t current;
    int valid = 0;

    stream = fopen("report.bin", "rb");
    if(stream == NULL){return;}
    while(fread(&current, sizeof(atm_t), 1, stream)){
        if(strcmp(account_number, current.account_number) == 0){
            valid = 1;
            break;
        }
    }
    fclose(stream);

    if(valid == 1){
        *person = current;
    }
}

void initAccount(atm_t *person){
    if(person == NULL){
        fprintf(stderr, "Error: Person is null.\n");
        return;
    }
    if(person->name == NULL){
        fprintf(stderr, "Error: Name is null.\n");
        return;
    }
    FILE *stream;
    int idCount = 0; 

    int mainPart = rand() % 999999;
    int digitalPart = rand() % 10;
    sprintf(person->account_number, "%06d-%d", mainPart, digitalPart);
    person->agence = rand() % 9999;
    person->balance = 0;

    stream = fopen("report.bin", "rb+");
    if(stream == NULL){return;}

    atm_t buffer;
    while(fread(&buffer, sizeof(atm_t), 1, stream) == 1){
        idCount += 1;
    }
    person->id = idCount;
    fwrite(person, sizeof(atm_t), 1, stream);

    fclose(stream);
}

void draw(char account_number[9], long long balance){
    if(strlen(account_number) >= 9){
        fprintf(stderr, "Error: account_number is incorrect\n");
        return;
    }
    if(balance <= 0){
        printf("Saque invalido!\n");
        return;   
    }

    FILE *stream;
    stream = fopen("report.bin", "rb+");
    if(stream == NULL){return;}
    atm_t buffer;
    while(fread(&buffer, sizeof(atm_t), 1, stream) == 1){
        if(strcmp(account_number, buffer.account_number) == 0){
            if(buffer.balance-balance < 0){
                printf("Insufficient balance.\n");
                break;
            }
            //printf("Saldo da buffer: %lld\n", buffer.balance);
            fseek(stream, -(int)sizeof(atm_t), SEEK_CUR);
            buffer.balance = buffer.balance - balance;
            fwrite(&buffer, sizeof(atm_t), 1, stream);
            printf("Withdrawal of %lld dollars was made successfully.\n", balance);
            printf("Final balance: %lld reais.\n", buffer.balance);
            break;
        }
    }
    fclose(stream);
}

void deposit(char account_number[9], long long balance){
    if(strlen(account_number) >= 9){
        fprintf(stderr, "Error: account_number is incorrect\n");
        return;
    }
    if(balance <= 0){
        printf("Saque invalido!\n");
        return;   
    }

    FILE *stream;
    stream = fopen("report.bin", "rb+");
    if(stream == NULL){return;}
    atm_t buffer;
    while(fread(&buffer, sizeof(atm_t), 1, stream) == 1){
        if(strcmp(account_number, buffer.account_number) == 0){
            //printf("Saldo da buffer: %lld\n", buffer.balance);
            fseek(stream, -(int)sizeof(atm_t), SEEK_CUR);
            buffer.balance = buffer.balance + balance;
            fwrite(&buffer, sizeof(atm_t), 1, stream);
            printf("Deposito de %d reais foi feito com sucesso.\n", balance);
            printf("Saldo final: %d reais.\n", buffer.balance);
            break;
        }
    }
    fclose(stream);
}