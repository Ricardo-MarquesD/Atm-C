#ifndef atm_h
#define atm_h

typedef struct atm_t{
    char name[80];
    char account_number[9];
    long long balance;
    int id;
    int agence;
}atm_t;

void atmData(atm_t *person);
void seek_atm(atm_t *person, char account_number[9]);
void initAccount(atm_t *person);
void draw(char account_number[9], long long balance);
void deposit(char account_number[9], long long balance);
void resetBin();

#endif