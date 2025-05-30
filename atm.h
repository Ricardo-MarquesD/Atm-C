#ifndef atm_h
#define atm_h

typedef struct atm_t{
    char name[80];
    char account_number[9];
    long long balance;
    int id;
    int agence;
}atm_t;

void initAccount(atm_t *person);
void draw(char account_number[9], long long balance);
void deposit(char account_number[9], long long balance);

#endif