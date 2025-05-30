#include "atm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void atmData(atm_t *person){
    printf("\n-------Dados da Conta-------\n");
    printf("Nome: %s\n", person->name);
    printf("Número da Conta: %s\n", person->account_number);
    printf("Agência Bancaria: %d\n",person->agence);
    printf("Saldo bancario: %lld\n\n", person->balance);
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
    if(person->balance == 0){
        person->balance = 0;
    }

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
                printf("Saldo insuficiente.\n");
                break;
            }
            //printf("Saldo da buffer: %lld\n", buffer.balance);
            fseek(stream, -(int)sizeof(atm_t), SEEK_CUR);
            buffer.balance = buffer.balance - balance;
            fwrite(&buffer, sizeof(atm_t), 1, stream);
            printf("Saque de %d reais foi feito com sucesso.\n", balance);
            printf("Saldo final: %d reais.\n", buffer.balance);
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