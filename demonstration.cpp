#include "matrix_library.h"
#include <iostream>
#include <cmath>
#include <fstream> //for HTML file
using namespace std;

void print_matrix(const double A[][10], int rows, int cols){
    for(int i = 0; i < rows; i++){
        cout << "\t";
        for(int j = 0; j < cols; j++){
        cout << A[i][j] <<"\t";
        }
    cout << endl;
    }
}

void print_matrix_html(ofstream& html, const double A[][10], int rows, int cols){
    html << "<table class='matrix'>";
    for(int i = 0; i < rows; i++){
        html << "<tr>";
        for(int j = 0; j < cols; j++){
            html << "<td>" << A[i][j] << "</td>";
        }
        html << "</tr>";
    }
    html << "</table><br>";
}

void print_vector(const double V[], int size){
    cout << "\t[";
    for(int i = 0; i < size; i++){
        if(i > 0) cout << ", ";
        cout << V[i];
    }
    cout << "]" << endl;
}

void print_vector_html(ofstream& html, const double V[], int size){
html << "<p>[";
    for(int i = 0; i < size; i++){
        if(i > 0) html << ", ";
        html << V[i];
    }
    html << "]</p>";
}
int main(){
    //HTML setup
    ofstream html("report_sample.html");
    html << "<!DOCTYPE html>";
    html << "<html><head><meta charset='UTF-8'>";
    html << "<title>Matrix & Vector Demo</title>";
    html << "<link rel='stylesheet' href='./style.css'>";
    html << "<style>"; //essential styles
    html << "body{font-family: Arial, Helvetica, sans-serif;}";
    html << "table{border-collapse: collapse;}";
    html << "td{border: 1px solid #333333ff; padding: 8px; text-align: center;}";
    html << ".error{color: red; font-weight: bold;}";
    html << "</style>";
    html << "</head>";
    html << "<body><header>";
    html <<"<h1>Matrix & Vector Operations Report</h1>";
    html << "<h2>Amirhossein Rouhi - Fundamentals of Computer Programming Final Project</h2>";
    html << "</header>";
    //inputs
    html << "<section class='inputs'>";
    html << "<h2>Inputs</h2>";
    double mat_A[10][10], mat_B[10][10], mat_result[10][10];
    int rowsA, colsA, rowsB, colsB;
    //Matrix A setup
    cout << "Enter number of rows and columns for Matrix A(max 10): ";
    cin >> rowsA >> colsA;
    if(rowsA <= 0 || colsA <= 0 || rowsA > 10 || colsA > 10){
        cout << "Invalid dimensions for Matrix A!" << endl;
        html << "<p class='error'>&#10060; Invalid dimensions for Matrix A! </p>";
        html << "</section></body></html>";
        return 0;
    }
    html << "<h3>Matrix A (" << rowsA << " x " << colsA << "):</h3>";
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsA; j++){
            cout << "Enter the ["<< i << "][" << j <<"] element of matrix A: ";
            cin >> mat_A[i][j];
        }
    }
    print_matrix_html(html, mat_A, rowsA, colsA);
    //Matrix B setup
    cout << "\nEnter number of rows and columns for Matrix B(max 10): ";
    cin >> rowsB >> colsB;
    if(rowsB <= 0 || colsB <= 0 || rowsB > 10 || colsB > 10){
        cout << "Invalid dimensions for Matrix B!" << endl;
        html << "<p class='error'>&#10060; Invalid dimensions for Matrix B! </p>";
        html << "</section></body></html>";
        return 0;
    }
    html << "<h3>Matrix B (" << rowsB << " x " << colsB << "):</h3>";
    for(int i = 0; i < rowsB; i++){
        for(int j = 0; j < colsB; j++){
            cout << "Enter the ["<< i << "][" << j <<"] element of matrix B: ";
            cin >> mat_B[i][j];
        }
    }
    print_matrix_html(html, mat_B, rowsB, colsB);

    double vec_A[10], vec_B[10], vec_result[10];
    int vec_size;
    //Vector A setup
    cout << "\nEnter size of vectors(max 10): ";
    cin >> vec_size;
    if(vec_size <= 0 || vec_size > 10){
        cout << "Invalid Vector size!" << endl;
        html << "<p class='error'>&#10060; Invalid Vector size!</p>";
        html << "</section></body></html>";
        return 0;
    }
    html << "<h3>Vector A(size = " << vec_size << "):</h3>";
    for(int i = 0; i < vec_size; i++){
        cout << "Enter the ["<< i << "]element of vector A: ";
        cin >> vec_A[i];
    }
    print_vector_html(html, vec_A, vec_size);

    //Vector B setup
    html << "<h3>Vector B(size = " << vec_size << "):</h3>";
    for(int i = 0; i < vec_size; i++){
        cout << "Enter the ["<< i << "]element of vector B: ";
        cin >> vec_B[i];
    }
    print_vector_html(html, vec_B, vec_size);

    //matrix operations
    html << "<section class='matrix-operations'>";
    html << "<h2>Matrix Operations</h2>";

    //A + B
    html <<"<h3>A + B</h3>";
    if(rowsA == rowsB && colsA == colsB){
        cout << "\nA + B =" << endl;
        matrix_add(mat_A, mat_B, mat_result, rowsA, colsA);
        print_matrix(mat_result, rowsA, colsA);
        html << "<p><b>Result(" << rowsA << " x " << colsA << "):</b></p>";
        print_matrix_html(html, mat_result, rowsA, colsA);
    }else{
    cout << "Error! Matrix dimensions do not match for addition!" << endl;
    html << "<p class='error'>&#10060; Error! Matrix dimensions do not match for addition</p>";
    }
    //A - B
    html <<"<h3>A - B</h3>";
    if(rowsA == rowsB && colsA == colsB){
        cout << "\nA - B =" << endl;
        matrix_sub(mat_A, mat_B, mat_result, rowsA, colsA);
        print_matrix(mat_result, rowsA, colsA);
        html << "<p><b>Result (" << rowsA << " x " << colsA << "):</b></p>";
        print_matrix_html(html, mat_result, rowsA, colsA);
    }else{
    cout << "Error! Matrix dimensions do not match for subtraction!" << endl;
    html << "<p class='error'>&#10060; Error! Matrix dimensions do not match for subtraction</p>";
    }
    //A x B
    html <<"<h3>A x B</h3>";
    if(colsA != rowsB){
        cout << "Error! Matrix multiplication not possible (colsA != rowsB)" << endl;
        html << "<p class='error'>&#10060; Error! Matrix multiplication not possible (colsA != rowsB)</p>";
    }else{
        cout << "\nA x B =" << endl;
        matrix_multiply(mat_A, mat_B, mat_result, rowsA, colsA, colsB);
        print_matrix(mat_result, rowsA, colsB);
        html << "<p><b>Result (" << rowsA << " x " << colsB << "):</b></p>";
        print_matrix_html(html, mat_result, rowsA, colsB);
    }
    //kA
    double k = 3; //scalar multiplication factor
    html <<"<h3>kA(k = " << k << ")</h3>";
    cout <<"\nkA(k = " << k << ") =" << endl;
    matrix_scalar_multiply(mat_A, mat_result, rowsA, colsA, k);
    print_matrix(mat_result, rowsA, colsA);
    html << "<p><b>Result (" << rowsA << " x " << colsA << "):</b></p>";
    print_matrix_html(html, mat_result, rowsA, colsA);
    //A^T
    html <<"<h3>A<sup>T</sup></h3>";
    cout << "\nA^T =" << endl;
    matrix_transpose(mat_A, mat_result, rowsA, colsA);
    print_matrix(mat_result, colsA, rowsA);
    html << "<p><b>Result (" << colsA << " x " << rowsA << "):</b></p>";
    print_matrix_html(html, mat_result, colsA, rowsA);
    //|A|
    html <<"<h3>|A|</h3>";
    if(rowsA != colsA){
        cout << "Error! Determinant is defined only for square matrix" << endl;
        html << "<p class='error'>&#10060; Error! Determinant is defined only for square matrix</p>";
    }else{
        double det = matrix_determinant(mat_A, rowsA);
        cout << "\n|A| = " << det << endl;
        html << "<p><b>Result = " << det << "</b></p>";
    }
    //A⁻¹
    html << "<h3>A<sup>-1</sup></h3>";
    if(rowsA != colsA){
        cout << "Error! Inverse is defined only for square matrix" << endl;
        html << "<p class='error'>&#10060; Error! Inverse is defined only for square matrix</p>";
    }else{
        double det = matrix_determinant(mat_A, rowsA);
        if(det == 0){
            cout << "Error! Determinant is zero. Matrix is not invertible" << endl;
            html << "<p class='error'>&#10060; Error! Determinant is zero. Matrix is not invertible</p>";
        }else{
            matrix_inverse(mat_A, mat_result, rowsA);
            cout << "\nA^(-1) =" << endl;
            print_matrix(mat_result, rowsA, colsA);
            html << "<p><b>Result (" << rowsA << " x " << colsA << "):</b></p>";
            print_matrix_html(html, mat_result, rowsA, colsA);
        }
    }
    html << "</section>";
    //Vector operations
    html << "<section class='vector-operations'>";
    html << "<h2>Vector Operations</h2>";
    //A + B
    html <<"<h3>A + B</h3>";
    cout << "\nA + B =" << endl;
    vector_add(vec_A, vec_B, vec_result, vec_size);
    print_vector(vec_result, vec_size);
    html << "<p><b>Result (size = " << vec_size << "):</b></p>";
    print_vector_html(html, vec_result, vec_size);
    //A - B
    html <<"<h3>A - B</h3>";
    cout << "\nA - B =" << endl;
    vector_sub(vec_A, vec_B, vec_result, vec_size);
    print_vector(vec_result, vec_size);
    html << "<p><b>Result (size = " << vec_size << "):</b></p>";
    print_vector_html(html, vec_result, vec_size);
    //kV (k = 3)
    html <<"<h3>kA(k = " << k << ")</h3>";
    cout <<"\nkA(k = " << k << ") =" << endl;
    vector_scalar_multiply(vec_A, vec_result, vec_size, k);
    print_vector(vec_result, vec_size);
    html << "<p><b>Result (size = " << vec_size << "):</b></p>";
    print_vector_html(html, vec_result, vec_size);
    //A . B
    double dot = vector_dot(vec_A, vec_B, vec_size);
    html <<"<h3>A . B</h3>";
    cout << "\nA . B = " << dot << endl;
    html << "<p><b>Result = " << dot << "</b></p>";    
    //A x B
    html <<"<h3>A x B</h3>";
    cout << "\nA x B =" << endl;
    vector_cross(vec_A, vec_B, vec_result, vec_size);
    print_vector(vec_result, vec_size);
    html << "<p><b>Result (size = " << vec_size << "):</b></p>";
    print_vector_html(html, vec_result, vec_size);
    //|V|
    double mag = vector_magnitude(vec_A, vec_size);
    html <<"<h3>|A|</h3>";
    cout << "\n|A| = " << mag << endl;
    html << "<p><b>Result = " << mag << "</b></p>";    
    //V_hat(normalized vector)
    html <<"<h3>V&#770;(Normalized Vector)</h3>";
    cout << "\nV_hat(normalized vector) =" << endl;
    vector_normalize(vec_A, vec_result, vec_size);
    print_vector(vec_result, vec_size);
    html << "<p><b>Result (size = " << vec_size << "):</b></p>";
    print_vector_html(html, vec_result, vec_size);
    html << "</section>";
    html << "<footer><p>Generated by Matrix C++ Library</p></footer>";
    html << "</body></html>";
    cout << "\nDemo finished. HTML report generated as report_sample.html" << endl;
    html.close();
    return 0;
}