#ifndef atm_h
#define atm_h

typedef struct atm_t{
    char name[80];
    long long balance;
    int id;
    int agence;
    int account_number;
}atm_t;

void initAccount(atm_t *person);
void draw(int id, long long balance);
void deposit(int id, long long balance);

#endif