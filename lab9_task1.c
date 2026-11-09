#include <stdio.h>

float calculateDiscount(char membershipType, float cartValue) {
    float discountRate = 0.0;
    
    // Determine base discount according to membership type
    if (membershipType == 'P' || membershipType == 'p') {
        discountRate = 0.20;
    } else if (membershipType == 'G' || membershipType == 'g') {
        discountRate = 0.10;
    } else if (membershipType == 'S' || membershipType == 's') {
        discountRate = 0.05;
    }
    
    // Additional 2% if shopping amount exceeds PKR 10,000
    if (cartValue > 10000.0) {
        discountRate += 0.02;
    }
    
    return cartValue * discountRate; // Returns discount amount in PKR
}

float calculateFinalBill(float discountedAmount) {
    float tax = discountedAmount * 0.15;
    float shipping = 0.0;
    
    if (discountedAmount <= 5000.0) {
        shipping = 300.0;
    }
    
    return discountedAmount + tax + shipping;
}

int main() {
    char memType;
    float cartValue;
    
    printf("Enter membership type (P for Platinum, G for Gold, S for Standard): ");
    scanf(" %c", &memType);
    printf("Enter total shopping cart value (PKR): ");
    scanf("%f", &cartValue);
    
    float discountAmount = calculateDiscount(memType, cartValue);
    float discountedAmount = cartValue - discountAmount;
    float finalPayable = calculateFinalBill(discountedAmount);
    
    printf("\n--- Bill Summary ---\n");
    printf("Original Cart Value: PKR %.2f\n", cartValue);
    printf("Discount Applied:    PKR %.2f\n", discountAmount);
    printf("Discounted Amount:   PKR %.2f\n", discountedAmount);
    printf("Final Payable Total: PKR %.2f (incl. tax & shipping)\n", finalPayable);
    
    return 0;
}