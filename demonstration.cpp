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
    ofstream html("report_sample.html");
    html << "<!DOCTYPE html>";
    html << "<html><head><meta charset='UTF-8'>";
    html << "<title>Matrix & Vector Demo</title>";
    html << "<link rel='stylesheet' href='./style.css'>";
    html << "</head>";
    html << "<body><header>";
    html <<"<h1>Matrix & Vector Operations Report</h1>";
    html << "<h2>Amirhossein Rouhi - Fundamentals of Computer Programming Final Project</h2><hr>";
    html << "</header>";

    //inputs
    html << "<section class='inputs'>";
    html << "<h2>Inputs</h2>";
    double mat_A[10][10], mat_B[10][10], mat_result[10][10];
    int rows_A, cols_A, rows_B, cols_B;

    //Matrix A setup
    cout << "Enter number of rows and columns for Matrix A(max 10): ";
    cin >> rows_A >> cols_A;
    if(rows_A <= 0 || cols_A <= 0 || rows_A > 10 || cols_A > 10){
        cout << "Invalid dimensions for Matrix A!" << endl;
        html << "<p class='error'>&#10060; Invalid dimensions for Matrix A! </p>";
        html << "</section></body></html>";
        return 0;
    }
    html << "<h3>Matrix A (" << rows_A << " &times; " << cols_A << "):</h3>";
    for(int i = 0; i < rows_A; i++){
        for(int j = 0; j < cols_A; j++){
            cout << "Enter the ["<< i << "][" << j <<"] element of matrix A: ";
            cin >> mat_A[i][j];
        }
    }
    print_matrix_html(html, mat_A, rows_A, cols_A);

    //Matrix B setup
    cout << "\nEnter number of rows and columns for Matrix B(max 10): ";
    cin >> rows_B >> cols_B;
    if(rows_B <= 0 || cols_B <= 0 || rows_B > 10 || cols_B > 10){
        cout << "Invalid dimensions for Matrix B!" << endl;
        html << "<p class='error'>&#10060; Invalid dimensions for Matrix B! </p>";
        html << "</section></body></html>";
        return 0;
    }
    html << "<h3>Matrix B (" << rows_B << " &times; " << cols_B << "):</h3>";
    for(int i = 0; i < rows_B; i++){
        for(int j = 0; j < cols_B; j++){
            cout << "Enter the ["<< i << "][" << j <<"] element of matrix B: ";
            cin >> mat_B[i][j];
        }
    }
    print_matrix_html(html, mat_B, rows_B, cols_B);
    
    //Scalar Factor setup
    double k;
    cout << "\nEnter a scalar factor for matrix/vector multiplication: ";
    cin >> k;

    double vec_A[10], vec_B[10], vec_result[10];
    int vec_size_A, vec_size_B;
    //Vector A setup
    cout << "\nEnter size of vector A(max 10): ";
    cin >> vec_size_A;
    if(vec_size_A <= 0 || vec_size_A > 10){
        cout << "Invalid Vector size!" << endl;
        html << "<p class='error'>&#10060; Invalid Vector size!</p>";
        html << "</section></body></html>";
        return 0;
    }
    html << "<h3>Vector A(size = " << vec_size_A << "):</h3>";
    for(int i = 0; i < vec_size_A; i++){
        cout << "Enter the ["<< i << "]element of vector A: ";
        cin >> vec_A[i];
    }
    print_vector_html(html, vec_A, vec_size_A);

    //Vector B setup
    cout << "\nEnter size of vector B(max 10): ";
    cin >> vec_size_B;
    if(vec_size_B <= 0 || vec_size_B > 10){
        cout << "Invalid Vector size!" << endl;
        html << "<p class='error'>&#10060; Invalid Vector size!</p>";
        html << "</section></body></html>";
        return 0;
    }
    html << "<h3>Vector B(size = " << vec_size_B << "):</h3>";
    for(int i = 0; i < vec_size_B; i++){
        cout << "Enter the ["<< i << "]element of vector B: ";
        cin >> vec_B[i];
    }
    print_vector_html(html, vec_B, vec_size_B);

    //matrix operations
    html << "<section class='matrix-operations'>";
    html << "<h2>Matrix Operations</h2>";

    //A + B
    html <<"<h3>A + B</h3>";
    if(matrix_add(mat_A, mat_B, mat_result, rows_A, cols_A, rows_B, cols_B)){
        cout << "\nA + B =" << endl;
        print_matrix(mat_result, rows_A, cols_A);
        html << "<p><b>Result(" << rows_A << " &times; " << cols_A << "):</b></p>";
        print_matrix_html(html, mat_result, rows_A, cols_A);
    }else{
    cout << "Error! Matrix dimensions do not match for addition!" << endl;
    html << "<p class='error'>&#10060; Error! Matrix dimensions do not match for addition</p>";
    }

    //A - B
    html <<"<h3>A - B</h3>";
    if(matrix_sub(mat_A, mat_B, mat_result, rows_A, cols_A, rows_B, cols_B)){
        cout << "\nA - B =" << endl;
        print_matrix(mat_result, rows_A, cols_A);
        html << "<p><b>Result (" << rows_A << " &times; " << cols_A << "):</b></p>";
        print_matrix_html(html, mat_result, rows_A, cols_A);
    }else{
    cout << "Error! Matrix dimensions do not match for subtraction!" << endl;
    html << "<p class='error'>&#10060; Error! Matrix dimensions do not match for subtraction</p>";
    }

    //A x B
    html <<"<h3>A &times; B</h3>";
    if(matrix_multiply(mat_A, mat_B, mat_result, rows_A, cols_A, rows_B, cols_B)){
        cout << "\nA x B =" << endl;
        print_matrix(mat_result, rows_A, cols_B);
        html << "<p><b>Result (" << rows_A << " &times; " << cols_B << "):</b></p>";
        print_matrix_html(html, mat_result, rows_A, cols_B);
    }else{
        cout << "Error! Matrix multiplication not possible (cols_A != rows_B)" << endl;
        html << "<p class='error'>&#10060; Error! Matrix multiplication not possible (cols_A != rows_B)</p>";
    }

    //kA
    html <<"<h3>kA(k = " << k << ")</h3>";
    cout <<"\nkA(k = " << k << ") =" << endl;
    matrix_scalar_multiply(mat_A, mat_result, rows_A, cols_A, k);
    print_matrix(mat_result, rows_A, cols_A);
    html << "<p><b>Result (" << rows_A << " &times; " << cols_A << "):</b></p>";
    print_matrix_html(html, mat_result, rows_A, cols_A);

    //A^T
    html <<"<h3>A<sup>T</sup></h3>";
    cout << "\nA^T =" << endl;
    matrix_transpose(mat_A, mat_result, rows_A, cols_A);
    print_matrix(mat_result, cols_A, rows_A);
    html << "<p><b>Result (" << cols_A << " &times; " << rows_A << "):</b></p>";
    print_matrix_html(html, mat_result, cols_A, rows_A);

    //|A|
    html <<"<h3>|A|</h3>";
    double det = matrix_determinant(mat_A, rows_A, cols_A);
    if(!isnan(det)){
        cout << "\n|A| = " << det << endl;
        html << "<p><b>Result = " << det << "</b></p>";
    }else{
    cout << "Error! Determinant is defined only for square matrix" << endl;
    html << "<p class='error'>&#10060; Error! Determinant is defined only for square matrix</p>";    
    }

    //A⁻¹
    html << "<h3>A<sup>-1</sup></h3>";
    if(matrix_inverse(mat_A, mat_result, rows_A, cols_A)){
        cout << "\nA^(-1) =" << endl;
        print_matrix(mat_result, rows_A, cols_A);
        html << "<p><b>Result (" << rows_A << " &times; " << cols_A << "):</b></p>";
        print_matrix_html(html, mat_result, rows_A, cols_A);
    }else{
        if(rows_A != cols_A){
            cout << "Error! Inverse is defined only for square matrix" << endl;
            html << "<p class='error'>&#10060; Error! Inverse is defined only for square matrix</p>";
        }else{
            cout << "Error! Matrix is singular(det = 0)" << endl;
            html << "<p class='error'>&#10060; Error! Matrix is singular(det = 0)</p>";
        }
    }

    html << "</section>";

    //Vector operations
    html << "<section class='vector-operations'>";
    html << "<h2>Vector Operations</h2>";

    //A + B
    html <<"<h3>A + B</h3>";
    
    if(vector_add(vec_A, vec_B, vec_result, vec_size_A, vec_size_B)){
    cout << "\nA + B =" << endl;
    print_vector(vec_result, vec_size_A);
    html << "<p><b>Result (size = " << vec_size_A << "):</b></p>";
    print_vector_html(html, vec_result, vec_size_A);
    }
    else{
        cout << "Error! Vector dimensions do not match for addition" << endl;
        html << "<p class='error'>&#10060; Error! Vector dimensions do not match for addition</p>";
    }
    
    //A - B
    html <<"<h3>A - B</h3>";
    if(vector_sub(vec_A, vec_B, vec_result, vec_size_A, vec_size_B)){
        cout << "\nA - B =" << endl;
        print_vector(vec_result, vec_size_A);
        html << "<p><b>Result (size = " << vec_size_A << "):</b></p>";
        print_vector_html(html, vec_result, vec_size_A);  
    }else{
        cout << "Error! Vector dimensions do not match for subtraction" << endl;
        html << "<p class='error'>&#10060; Error! Vector dimensions do not match for subtraction</p>";
    }

    //kV
    html <<"<h3>kA(k = " << k << ")</h3>";
    cout <<"\nkA(k = " << k << ") =" << endl;
    vector_scalar_multiply(vec_A, vec_result, vec_size_A, k);
    print_vector(vec_result, vec_size_A);
    html << "<p><b>Result (size = " << vec_size_A << "):</b></p>";
    print_vector_html(html, vec_result, vec_size_A);

    //A . B
    html <<"<h3>A &sdot; B</h3>";
    double dot = vector_dot(vec_A, vec_B, vec_size_A, vec_size_B);
    if(!isnan(dot)){
    cout << "\nA . B = " << dot << endl;
    html << "<p><b>Result = " << dot << "</b></p>";  
    }else{
        cout << "Error! Vector dimensions must match for dot product" << endl;
    }
    
    //A x B
    html <<"<h3>A &times; B</h3>";
    if(vector_cross(vec_A, vec_B, vec_result, vec_size_A, vec_size_B)){
        cout << "\nA x B =" << endl;
        print_vector(vec_result, vec_size_A);
        html << "<p><b>Result (size = " << vec_size_A << "):</b></p>";
        print_vector_html(html, vec_result, vec_size_A);   
    }else{
        cout << "Error! Cross product defined only for 3D vectors" << endl;
        html << "<p class='error'>&#10060; Error! Cross product defined only for 3D vectors</p>";
    }

    //|V|
    double mag = vector_magnitude(vec_A, vec_size_A);
    html <<"<h3>|A|</h3>";
    cout << "\n|A| = " << mag << endl;
    html << "<p><b>Result = " << mag << "</b></p>";  
    
    //V_hat(normalized vector)
    html <<"<h3>V&#770;(Normalized Vector)</h3>";
    if(vector_normalize(vec_A, vec_result, vec_size_A)){
    cout << "\nV_hat(normalized vector) =" << endl;
    print_vector(vec_result, vec_size_A);
    html << "<p><b>Result (size = " << vec_size_A << "):</b></p>";
    print_vector_html(html, vec_result, vec_size_A);
    }else{
        cout << "Error! Cannot normalize zero vector" << endl;
            html << "<p class='error'>&#10060; Error! Cannot normalize zero vector</p>";
    }

    html << "</section>";
    
    html << "<hr><footer><p class='footer'>Generated by Matrix C++ Library</p></footer>";
    html << "</body></html>";
    cout << "\nDemo finished. HTML report generated as report_sample.html" << endl;
    html.close();
    return 0;
}