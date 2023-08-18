#include <stdio.h>

#define MAX_SIZE 10

struct Element {
    int row;
    int col;
    int value;
};

void tridiagonalToSparse(int tridiagonal[][MAX_SIZE], int n, struct Element sparse[], int *numSparse) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j + 1 || i == j - 1) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = tridiagonal[i][j];
                k++;
            }
        }
    }
    *numSparse = k;
}

void sparseToTridiagonal(struct Element sparse[], int numSparse, int tridiagonal[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j + 1 || i == j - 1) {
                tridiagonal[i][j] = 0;
            }
        }
    }

    for (int k = 0; k < numSparse; k++) {
        tridiagonal[sparse[k].row][sparse[k].col] = sparse[k].value;
    }
}

void displayMatrix(int matrix[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the tridiagonal matrix: ");
    scanf("%d", &n);

    int tridiagonal[MAX_SIZE][MAX_SIZE];
    printf("Enter the Principal Diagonal elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tridiagonal[i][i]);
    }

    printf("Enter the Upper Diagonal elements:\n");
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &tridiagonal[i][i + 1]);
    }

    printf("Enter the Lower Diagonal elements:\n");
    for (int i = 1; i < n; i++) {
        scanf("%d", &tridiagonal[i][i - 1]);
    }

    struct Element sparse[MAX_SIZE * MAX_SIZE];
    int numSparse;
    tridiagonalToSparse(tridiagonal, n, sparse, &numSparse);

    printf("\nSparse Matrix:\n");
    for (int i = 0; i < numSparse; i++) {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    int reconstructed[MAX_SIZE][MAX_SIZE];
    sparseToTridiagonal(sparse, numSparse, reconstructed, n);

    printf("\nReconstructed Tridiagonal Matrix:\n");
    displayMatrix(reconstructed, n);

    return 0;
}