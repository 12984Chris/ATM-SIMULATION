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
void withdraw_money() {ss
    if (check_point()) {
        int amount;
        printf("Enter amount to withdraw: ");
        if (scanf("%d", &amount) != 1 || amount <= 0) {
            printf("Invalid input. Withdrawal amount must be a positive number. \n");
            clear_buffer();
            return;
        }
        if (amount > balance) {
            printf("Insufficient balance.\n");
        }else{
            balance -= amount;
            printf("$%d withdrawn successfully.\n", amount);
        }
        clear_buffer();
    }
}
void change_pin() {
    if (check_pin()) {
        char new_pin[10], confirm_pin[10];
        get_input("Enter new 4-digit PIN: ", new_pin, sizeof(new_pin));
        get_input("Confirm new PIN: ", confirm_pin, sizeof(confirm_pin));

        if (strlen(new_pin) != MAX_PIN_LENGTH || strlen(confirm_pin) != MAX_PIN_LENGTH) {
            printf("PIN must be exactly 4 digits.\n");
            return;
        }

        if (strcmp(new_pin, confirm_pin) == 0) {
            strcpy(pin, new_pin);
            printf("PIN changed successfully.\n");
        } else {
            printf("PINs do not match.\n");
        }
    }
}
