#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

void createSparseMatrix(Element sparse[], int tridiagonal[], int n) {
    int k = 0;
    
    // Storing principal diagonal
    for (int i = 0; i < n; i++) {
        sparse[k].row = i;
        sparse[k].col = i;
        sparse[k].value = tridiagonal[i];
        k++;
    }
    
    // Storing upper diagonal
    for (int i = 0; i < n - 1; i++) {
        sparse[k].row = i;
        sparse[k].col = i + 1;
        sparse[k].value = tridiagonal[n + i];
        k++;
    }
    
    // Storing lower diagonal
    for (int i = 0; i < n - 1; i++) {
        sparse[k].row = i + 1;
        sparse[k].col = i;
        sparse[k].value = tridiagonal[2 * n - 1 + i];
        k++;
    }
}

void displaySparseMatrix(Element sparse[], int count) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

void convertToTridiagonal(int tridiagonal[], Element sparse[], int n) {
    for (int i = 0; i < n; i++) {
        tridiagonal[i] = sparse[i].value;
    }
    for (int i = 0; i < n - 1; i++) {
        tridiagonal[n + i] = sparse[n + i].value;
    }
    for (int i = 0; i < n - 1; i++) {
        tridiagonal[2 * n - 1 + i] = sparse[2 * n - 1 + i].value;
    }
}

int main() {
    int n;
    printf("Enter the size of the tridiagonal matrix: ");
    scanf("%d", &n);
    
    int tridiagonal[MAX_SIZE];
    Element sparse[MAX_SIZE * 3];
    
    printf("Enter the principal diagonal elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tridiagonal[i]);
    }
    
    printf("Enter the upper diagonal elements:\n");
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &tridiagonal[n + i]);
    }
    
    printf("Enter the lower diagonal elements:\n");
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &tridiagonal[2 * n - 1 + i]);
    }
    
    createSparseMatrix(sparse, tridiagonal, n);
    displaySparseMatrix(sparse, 3 * n - 2);
    
    int convertedTridiagonal[MAX_SIZE];
    convertToTridiagonal(convertedTridiagonal, sparse, n);
    
    printf("Converted Tridiagonal Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", convertedTridiagonal[i]);
    }
    printf("\n");
    
    return 0;
}