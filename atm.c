#include "atm.h"
#include <stdio.h>
#include <stdlib.h>

void initAccount(atm_t *person){
    if(person == NULL){
        fprintf(stderr, "Error: Person is null.");
        return;
    }
    if(person->name == NULL){
        fprintf(stderr, "Error: Name is null.");
        return;
    }
    FILE *stream;
    int idCount = 0;

    int mainPart = rand() %  999999;
    int digitalPart = rand() % 10;
    sprintf(person->account_number, "%06d-%d", mainPart, digitalPart);
    person->agence = rand() % 9999;
    if(person->balance == 0){
        person->balance = 0;
    }

    stream = fopen("report.bin", "rb+");
    if(stream == NULL){
        return;
    }

    atm_t buffer;
    while(fread(&buffer, sizeof(atm_t), 1, stream) == 1){
        idCount += 1;
    }
    person->id = idCount;
    fwrite(person, sizeof(atm_t), 1, stream);

    fclose(stream);
}