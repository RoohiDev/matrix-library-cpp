//Inclue Guard
#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

//Matrix Operations
bool matrix_add(const double A[][10], const double B[][10], double result[][10], int rows_A, int cols_A, int rows_B, int cols_B);
bool matrix_multiply(const double A[][10], const double B[][10], double result[][10], int rows_A, int cols_A, int rows_B, int cols_B);
void matrix_scalar_multiply(const double A[][10], double result[][10], int rows, int cols, double scalar);
bool matrix_sub(const double A[][10], const double B[][10], double result[][10], int rows_A, int cols_A, int rows_B, int cols_B);
void matrix_transpose(const double A[][10], double result[][10], int rows, int cols);
double matrix_determinant(const double A[][10],int rows_A, int cols_A);
bool matrix_inverse(const double A[][10], double result[][10], int rows_A, int cols_A);

//Vector Operations
bool vector_add(const double A[], const double B[], double result[], int size_A, int size_B);
bool vector_sub(const double A[], const double B[], double result[], int size_A, int size_B);
void vector_scalar_multiply(const double A[], double result[], int size, double scalar);
double vector_dot(const double A[], const double B[], int size_A, int size_B);
bool vector_cross(const double A[], const double B[], double result[], int size_A, int size_B);
double vector_magnitude(const double V[], int size);
bool vector_normalize(const double V[], double result[], int size);

#endif