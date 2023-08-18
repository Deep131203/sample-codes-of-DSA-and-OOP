#include <stdio.h>

#define MAX_SIZE 10

void inputDiagonals(int principal[], int upper[], int lower[], int n) {
    printf("Enter the Principal Diagonal elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &principal[i]);
    }

    printf("Enter the Upper Diagonal elements:\n");
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &upper[i]);
    }

    printf("Enter the Lower Diagonal elements:\n");
    for (int i = 1; i < n; i++) {
        scanf("%d", &lower[i - 1]);
    }
}

void displayMatrix(int diagonal[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                printf("%d ", diagonal[i]);
            } else if (i == j + 1 || i == j - 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the tridiagonal matrix: ");
    scanf("%d", &n);

    int principal[MAX_SIZE];
    int upper[MAX_SIZE - 1];
    int lower[MAX_SIZE - 1];

    inputDiagonals(principal, upper, lower, n);

    printf("\nTridiagonal Matrix:\n");
    displayMatrix(principal, n);

    return 0;
}