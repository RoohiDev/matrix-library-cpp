//Inclue Guard
#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

//Matrix Operations
void matrix_add(const double A[][10], const double B[][10], double result[][10], int rows, int cols);
void matrix_multiply(const double A[][10], const double B[][10], double result[][10], int rowsA, int colsA, int colsB);
void matrix_scalar_multiply(const double A[][10], double result[][10], int rows, int cols, double scalar);
void matrix_sub(const double A[][10], const double B[][10], double result[][10], int rows, int cols);
void matrix_transpose(const double A[][10], double result[][10], int rows, int cols);
double matrix_determinant(const double A[][10],int n); //only in nxn
void matrix_inverse(const double A[][10], double result[][10], int n); //only in nxn

//Vector Operations
void vector_add(const double A[], const double B[], double result[], int size);
void vector_sub(const double A[], const double B[], double result[], int size);
void vector_scalar_multiply(const double A[], double result[], int size, double scalar);
double vector_dot(const double A[], const double B[], int size);
void vector_cross(const double A[], const double B[], double result[], int size);
double vector_magnitude(const double V[], int size);
void vector_normalize(const double V[], double result[], int size);

#endif