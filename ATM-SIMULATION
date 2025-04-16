#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PIN_LENGTH  4

int balance = 1000;
char pin[5] = "1234";

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n'  &&
    c ! = EOF);
}

void get_input(char *prompt, char *input, int size) {
    printf("%s", prompt);
    if (fgets(input, size, stdin)) {
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') input[len - 1] = '\0';
        else clear_buffer();
    }
}

int check_pin() {
    char entered_pin[10];
    get_input("Enter your pin: ",entered_pin, sizeof(entered_pin));

    if (strlen(entered_pin) != MAX_PIN_LENGTH || ! isdigit(entered_pin[0])) {
        printf("Invalid PIN format.Must be 4 digits.\n");
        return 0;
    }

    if (strcmp(entered_pin, pin) == 0)
    return 1;

    printf("Incorrect Pin.\n");
    return 0;
}

void check_balance() {
    if (check_pin()) {
        printf("Your current balance is: $%d\n",balance);
    }
}

void deposit_money() {
    if (check_pin()) {
        int amount;
        printf("Enter amount to deposit: ");
        if (scanf("%d", &amount) ! = 1 || amount <= 0) {
            printf("Invalid input. Deposit amount must be a positive number.\n");
                       clear_buffer ();
                       return;
        }
        balance += amount;
        printf("$%d deposited successfully.\n", amount);
        clear_buffer();
    }
}