#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int findMax(int a, int b) {
    if (a > b) return a;
    return b;
}

int compute(int a, int b, int (*op)(int, int)) {
    return op(a, b);
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    
    int s = compute(x, y, add);
    int m = compute(x, y, multiply);
    int mx = compute(x, y, findMax);
    
    printf("Sum: %d\n", s);
    printf("Product: %d\n", m);
    printf("Max: %d\n", mx);
    
    return 0;
}