#include <stdio.h>

// Structure to store sparse matrix element
struct SparseElement {
    int row, col, value;
};

// Function to convert tridiagonal matrix to sparse matrix
void tridiagonalToSparse(int n, int principal[], int upper[], int lower[], struct SparseElement sparse[]) {
    int sparseIndex = 0;
    
    for (int i = 0; i < n; i++) {
        if (i > 0)
            sparse[sparseIndex++] = (struct SparseElement){i, i - 1, lower[i]};
        
        sparse[sparseIndex++] = (struct SparseElement){i, i, principal[i]};
        
        if (i < n - 1)
            sparse[sparseIndex++] = (struct SparseElement){i, i + 1, upper[i]};
    }
}

// Function to convert sparse matrix to tridiagonal matrix
void sparseToTridiagonal(int n, struct SparseElement sparse[], int principal[], int upper[], int lower[]) {
    for (int i = 0; i < n; i++) {
        principal[i] = sparse[i * 3 + 1].value;
        
        if (i > 0)
            lower[i] = sparse[i * 3].value;
        
        if (i < n - 1)
            upper[i] = sparse[i * 3 + 2].value;
    }
}

// Function to display a matrix
void displayMatrix(int n, int matrix[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                printf("%d ", matrix[i]);
            else if (i == j - 1)
                printf("%d ", matrix[n + i - 1]);
            else if (i == j + 1)
                printf("%d ", matrix[j - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the tridiagonal matrix: ");
    scanf("%d", &n);
    
    int principal[n], upper[n - 1], lower[n - 1];
    printf("Enter the principal diagonal elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &principal[i]);
    
    printf("Enter the upper diagonal elements:\n");
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &upper[i]);
    
    printf("Enter the lower diagonal elements:\n");
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &lower[i]);
    
    struct SparseElement sparse[3 * n - 2];
    tridiagonalToSparse(n, principal, upper, lower, sparse);
    
    printf("\nSparse Matrix:\n");
    for (int i = 0; i < 3 * n - 2; i++)
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    
    int reconstructedPrincipal[n], reconstructedUpper[n - 1], reconstructedLower[n - 1];
    sparseToTridiagonal(n, sparse, reconstructedPrincipal, reconstructedUpper, reconstructedLower);
    
    printf("\nReconstructed Tridiagonal Matrix:\n");
    displayMatrix(n, reconstructedPrincipal);
    
    return 0;
}
