#include "matrix_library.h"
#include <iostream>
#include <cmath>

using namespace std;

//Matrix Operations
bool matrix_add(const double A[][10], const double B[][10], double result[][10], int rows_A, int cols_A, int rows_B, int cols_B){
    if(rows_A != rows_B || cols_A != cols_B) return false;
    for(int i = 0; i < rows_A; i++){
        for(int j = 0; j < cols_A; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return true;
}
//result[i][j] = Σ A[i][k] x B[k][j]
bool matrix_multiply(const double A[][10], const double B[][10], double result[][10], int rows_A, int cols_A, int rows_B, int cols_B){
    if(cols_A != rows_B) return false;
    for(int i = 0; i < rows_A; i++){
        for(int j = 0; j < cols_B; j++){
            result[i][j] = 0;
            for(int k = 0; k < cols_A; k++){
                result[i][j] += A[i][k] * B[k][j];  
            }
        }
    }
    return true;
}
void matrix_scalar_multiply(const double A[][10], double result[][10], int rows, int cols, double scalar){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = A[i][j] * scalar;
        }
    }
}
bool matrix_sub(const double A[][10], const double B[][10], double result[][10], int rows_A, int cols_A, int rows_B, int cols_B){
    if(rows_A != rows_B || cols_A != cols_B) return false;
    for(int i = 0; i < rows_A; i++){
        for(int j = 0; j < cols_A; j++){
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return true;
}
//result[j][i] = A[i][j]
void matrix_transpose(const double A[][10], double result[][10], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[j][i] = A[i][j];
        }
    }
}
//Laplace Expansion(using first row)
double matrix_determinant(const double A[][10],int rows_A, int cols_A){
    if(rows_A != cols_A) return NAN;
    if(rows_A == 1) return A[0][0];
    if(rows_A == 2) return ((A[0][0] * A[1][1]) - (A[0][1] * A [1][0]));
    double det = 0;
    double submatrix [10][10];
    // col: index of the column to be deleted
    for(int col = 0; col < rows_A; col++) {
        int subi = 0;
        for(int i = 1; i < rows_A; i++){
            int subj = 0;
            for(int j = 0; j < rows_A; j++){
                if(j == col) continue; //delete this column
                submatrix[subi][subj] = A[i][j];
                subj++;
            }
            subi++;
        }
        det += ((col & 1) ? -1 : 1) * A[0][col] * matrix_determinant(submatrix, (rows_A-1), (cols_A-1));
    }
    return det;
}
// A^(-1) = 1/det(A) x adj(A)
bool matrix_adjoint(const double A[][10], double adj[][10], int rows_A, int cols_A){
    if(rows_A != cols_A) return false;
    if(rows_A == 1){
        adj[0][0] = 1;
        return true;
    }
    double temp[10][10];
    int sign;

    for(int i = 0; i < rows_A; i++){
        for(int j = 0; j < rows_A; j++){
            int subi = 0;
            for(int row = 0; row < rows_A; row++){
                if(row == i) continue; //delete this row
                int subj = 0;
                for(int col = 0; col < rows_A; col++){
                    if(col == j) continue; //delete this column
                    temp[subi][subj] = A[row][col];
                    subj++;
                }
            subi++;    
            }
            sign = (((i+j) & 1) ? -1 : 1);
            adj[j][i] = sign * matrix_determinant(temp, (rows_A-1), (cols_A-1)); //cofactor and transpose
        }
    }
    return true;
}
bool matrix_inverse(const double A[][10], double result[][10], int rows_A, int cols_A){
    if(rows_A != cols_A) return false;
    double det = matrix_determinant(A, rows_A, cols_A);
    if (fabs(det) < 1e-10) return false;
    double adj[10][10];
    if(!matrix_adjoint(A, adj, rows_A, cols_A)) return false;
    for(int i = 0; i < rows_A; i++){
        for(int j = 0; j < rows_A; j++){
            result[i][j] = (adj[i][j] / det);
        }
    }
    return true;
}

//Vector Operations
void vector_add(const double A[], const double B[], double result[], int size){
    for (int i = 0; i < size; i++){
        result[i] = A[i] + B[i];
    }
}
void vector_sub(const double A[], const double B[], double result[], int size){
    for (int i = 0; i < size; i++){
        result[i] = A[i] - B[i];
    }
}
void vector_scalar_multiply(const double A[], double result[], int size, double scalar){
    for (int i = 0; i < size; i++){
        result[i] = A[i] * scalar;
    }
}
double vector_dot(const double A[], const double B[], int size){
    double dot_result = 0;
    for (int i = 0; i < size; i++){
        dot_result += A[i] * B[i];
    }
    return dot_result;
}
bool vector_cross(const double A[], const double B[], double result[], int size){
    if(size != 3){
        return false;
    } 
    result[0] = (A[1] * B[2]) - (A[2] * B[1]);
    result[1] = (A[2] * B[0]) - (A[0] * B[2]);
    result[2] = (A[0] * B[1]) - (A[1] * B[0]);
    return true;
}
double vector_magnitude(const double V[], int size){
    if(size <= 0) return NAN;
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += (V[i] * V[i]);
    }
    return sqrt(sum);    
}
//normalized vector = V[i] / |V| (|V| != 0)
bool vector_normalize(const double V[], double result[], int size){
    double mag = vector_magnitude(V,size);
    if (fabs(mag) < 1e-10) return false;
    for(int i = 0; i < size; i++){
        result[i] = V[i] / mag; 
    }
    return true;
}