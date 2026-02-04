//Inclue Guard
#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

//Matrix Operations
void matrix_add(double A[][10], double B[][10], double result[][10], int rows, int cols);
void matrix_multiply(double A[][10], double B[][10], double result[][10], int rowsA, int colsA, int colsB);
void matrix_scalar_multiply(double A[][10], double result[][10], int rows, int cols, double scalar);
void matrix_sub(double A[][10], double B[][10], double result[][10], int rows, int cols);
void matrix_transpose(double A[][10], double result[][10], int rows, int cols);
double matrix_determinant(double A[][10],int n); //only in nxn
void matrix_inverse(double A[][10], double result[][10], int n); //only in nxn

//Vector Operations
void vector_add(double A[], double B[], double result[], int size);
void vector_sub(double A[], double B[], double result[], int size);
void vector_scalar_multiply(double A[], double result[], int size, double scalar);
double vector_dot(double A[], double B[], int size);
void vector_cross(double A[], double B[], double result[], int size);
double vector_magnitude(double V[], int size);
void vector_normalize(double V[], double result[], int size);



#endif