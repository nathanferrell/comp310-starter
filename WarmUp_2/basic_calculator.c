#include <stdio.h>

int main() {
    double num1, num2;

    printf("Enter two numbers separated by a space: ");
    scanf("%lf %lf", &num1, &num2);

    printf("Sum: %lf\n", num1 + num2);
    printf("Difference: %lf\n", num1 - num2);
    printf("Product: %lf\n", num1 * num2);

    if (num2 != 0) {
        printf("Quotient: %lf\n", num1 / num2);
    } else {
        printf("Cannot divide by zero.\n");
    } 

    return 0;
}
