#include "matrix_library.h"
#include <iostream>
#include <cmath>

using namespace std;

//Matrix Operations
void matrix_add(double A[][10], double B[][10], double result[][10], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}
//result[i][j] = Σ A[i][k] x B[k][j]
void matrix_multiply(double A[][10], double B[][10], double result[][10], int rowsA, int colsA, int colsB){
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsB; j++){
            result[i][j] = 0;
            for(int k = 0; k < colsA; k++){
                result[i][j] += A[i][k] * B[k][j];  
            }
        }
    }
}
void matrix_scalar_multiply(double A[][10], double result[][10], int rows, int cols, double scalar){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = A[i][j] * scalar;
        }
    }
}
void matrix_sub(double A[][10], double B[][10], double result[][10], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}
//result[j][i] = A[i][j]
void matrix_transpose(double A[][10], double result[][10], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[j][i] = A[i][j];
        }
    }
}
//Laplace Expansion(using first row)
double matrix_determinant(double A[][10],int n){
    if(n == 1) return A[0][0];
    if(n == 2) return ((A[0][0] * A[1][1]) - (A[0][1] * A [1][0]));
    double det = 0;
    double submatrix [10][10];
    // col: index of the column to be deleted
    for(int col = 0; col < n; col++) {
        int subi = 0;
        for(int i = 1; i < n; i++){
            int subj = 0;
            for(int j = 0; j < n; j++){
                if(j == col) continue; //delete this column
                submatrix[subi][subj] = A[i][j];
                subj++;
            }
            subi++;
        }
        det += ((col &1 ) ? -1 : 1) * A[0][col] * matrix_determinant(submatrix,n-1);
    }
    return det;
}
// A^(-1) = 1/det(A) x adj(A)
void adjoint(double A[][10], double adj[][10], int n){
    if(n == 1){
        adj[0][0] = 1;
        return;
    }
    double temp[10][10];
    int sign;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int subi = 0;
            for(int row = 0; row < n; row++){
                if(row == i) continue; //delete this row
                int subj = 0;
                for(int col = 0; col < n; col++){
                    if(col == j) continue; //delete this column
                    temp[subi][subj] = A[row][col];
                    subj++;
                }
            subi++;    
            }
            sign = (((i+j) & 1) ? -1 : 1);
            adj[j][i] = sign * matrix_determinant(temp,(n-1)); //cofactor and transpose
        }
    }
}
void matrix_inverse(double A[][10], double result[][10], int n){
    double det = matrix_determinant(A,n);
    if (det == 0){
        cout << "Error! Singular matrix inverse dose not exist." << endl;
        return;
    }
    double adj[10][10];
    adjoint(A,adj,n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result[i][j] = (adj[i][j] / det);
        }
    }
}

//Vector Operations
void vector_add(double A[], double B[], double result[], int size){
    for (int i = 0; i < size; i++){
        result[i] = A[i] + B[i];
    }
}
void vector_sub(double A[], double B[], double result[], int size){
    for (int i = 0; i < size; i++){
        result[i] = A[i] - B[i];
    }
}
void vector_scalar_multiply(double A[], double result[], int size, double scalar){
    for (int i = 0; i < size; i++){
        result[i] = A[i] * scalar;
    }
}
double vector_dot(double A[], double B[], int size){
    double dot_result = 0;
    for (int i = 0; i < size; i++){
        dot_result += A[i] * B[i];
    }
    return dot_result;
}
void vector_cross(double A[], double B[], double result[], int size){
    if(size != 3){
        cout << "Error! Cross product is only defined for 3D vectors.";
        return;
    } 
    result[0] = (A[1] * B[2]) - (A[2] * B[1]);
    result[1] = (A[2] * B[0]) - (A[0] * B[2]);
    result[2] = (A[0] * B[1]) - (A[1] * B[0]);
}
double vector_magnitude(double V[], int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += (V[i] * V[i]);
    }
    return sqrt(sum);    
}
//normalized vector = V[i] / |V| (|V| != 0)
void vector_normalize(double V[], double result[], int size){
    double mag = vector_magnitude(V,size);
    if (mag == 0) return;
    for(int i = 0; i < size; i++){
        result[i] = V[i] / mag; 
    }
}