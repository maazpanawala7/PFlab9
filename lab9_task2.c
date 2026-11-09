#include <stdio.h>

void withdraw(float *balance, float amount) {
    if (amount <= *balance) {
        *balance -= amount;
        printf("Transaction Successful! Withdrawn: PKR %.2f\n", amount);
    } else {
        printf("Transaction Declined: Insufficient Balance\n");
    }
}

void deposit(float *balance, float amount) {
    *balance += amount;
    printf("Deposit Successful! Deposited: PKR %.2f\n", amount);
    printf("Updated Balance: PKR %.2f\n", *balance);
}

int main() {
    float balance = 25000.0; // Initial account balance
    int choice;
    float amount;
    
    printf("Initial Account Balance: PKR %.2f\n", balance);
    printf("Select transaction type:\n1. Withdraw (Debit)\n2. Deposit (Credit)\nEnter choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("Enter amount: ");
    scanf("%f", &amount);
    
    if (choice == 1) {
        withdraw(&balance, amount);
    } else if (choice == 2) {
        deposit(&balance, amount);
    } else {
        printf("Invalid transaction type selected.\n");
    }
    
    printf("Final Account Balance: PKR %.2f\n", balance);
    return 0;
}