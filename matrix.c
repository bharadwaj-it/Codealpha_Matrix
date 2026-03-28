#include<stdio.h>
void inputMatrix(int rows, int cols, int matrix[rows][cols])
{
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void displayMatrix(int rows, int cols, int matrix[rows][cols]) 
{
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
void addMatrix(int r, int c, int A[r][c], int B[r][c], int R[r][c]) 
{
    for(int i = 0; i < r; i++) 
    {
        for(int j = 0; j < c; j++) 
        R[i][j] = A[i][j] + B[i][j];
    }
}
void multiplyMatrix(int r1, int c1, int A[r1][c1],int r2, int c2, int B[r2][c2],int R[r1][c2]) 
{
    for(int i = 0; i < r1; i++) 
    {
        for(int j = 0; j < c2; j++) 
        {
            R[i][j] = 0;
            for(int k = 0; k < c1; k++)
            R[i][j] += A[i][k] * B[k][j];
        }
    }
}
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transpose[cols][rows])
{
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++)
        transpose[j][i] = matrix[i][j];
    }
}
int main() 
{
    int r1, c1, r2, c2;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    int A[r1][c1], B[r2][c2];
    printf("\nEnter elements of Matrix A:\n");
    inputMatrix(r1, c1, A);
    printf("\nEnter elements of Matrix B:\n");
    inputMatrix(r2, c2, B);
    if(r1 == r2 && c1 == c2)
    {
        int sum[r1][c1];
        addMatrix(r1, c1, A, B, sum);
        printf("\nMatrix Addition Result:\n");
        displayMatrix(r1, c1, sum);
    } 
    else
    printf("\nAddition not possible (different sizes)\n");

    if(c1 == r2) 
    {
        int product[r1][c2];
        multiplyMatrix(r1, c1, A, r2, c2, B, product);
        printf("\nMatrix Multiplication Result:\n");
        displayMatrix(r1, c2, product);
    } 
    else
    printf("\nMultiplication not possible (c1 != r2)\n");

    int transposeA[c1][r1];
    transposeMatrix(r1, c1, A, transposeA);
    printf("\nTranspose of Matrix A:\n");
    displayMatrix(c1, r1, transposeA);
    return 0;
}