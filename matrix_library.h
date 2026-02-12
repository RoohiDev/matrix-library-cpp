//Inclue Guard
#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

//Matrix Operations
bool matrix_add(const double A[][10], const double B[][10], double result[][10], int rowsA, int colsA, int rowsB, int colsB);
bool matrix_multiply(const double A[][10], const double B[][10], double result[][10], int rowsA, int colsA, int rowsB, int colsB);
void matrix_scalar_multiply(const double A[][10], double result[][10], int rows, int cols, double scalar);
bool matrix_sub(const double A[][10], const double B[][10], double result[][10], int rowsA, int colsA, int rowsB, int colsB);
void matrix_transpose(const double A[][10], double result[][10], int rows, int cols);
double matrix_determinant(const double A[][10],int rowsA, int colsA);
bool matrix_inverse(const double A[][10], double result[][10], int rowsA, int colsA);

//Vector Operations
void vector_add(const double A[], const double B[], double result[], int size);
void vector_sub(const double A[], const double B[], double result[], int size);
void vector_scalar_multiply(const double A[], double result[], int size, double scalar);
double vector_dot(const double A[], const double B[], int size);
bool vector_cross(const double A[], const double B[], double result[], int size);
double vector_magnitude(const double V[], int size);
bool vector_normalize(const double V[], double result[], int size);

#endif