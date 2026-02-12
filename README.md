# Matrix & Vector Operations in C++

**Name:** Amirhossein Rouhi Kalourazi  
**Student ID:** 1404010121113  
**Course:** Fundamentals of Computer Programming - Guilan University  

This project is a simple C++ library to do basic operations with matrices and vectors. There is also a demo program that makes an HTML report.

---

## MAIN ALGORITHMS

- **Matrix Addition/Subtraction:** Adds or subtracts matrices element by element. Only works if the matrices have the same size.
- **Matrix Multiplication:** Uses the rule Σ A[i][k] × B[k][j]. Only works if columns of A equals rows of B.
- **Scalar Multiplication:** Multiplies all numbers in a matrix or vector by one number.
- **Transpose:** Switches rows and columns (result[j][i] = A[i][j]).
- **Determinant:** Calculated with Laplace expansion using first row. Only works for square matrices.
- **Inverse:** A⁻¹ = 1/det(A) × adj(A). Only works for square matrices that are not singular.
- **Vector Operations:** Addition, subtraction, scalar multiplication, dot product, cross product (3D only), magnitude, and normalization.

> **Note:** If an operation needs only one matrix (like transpose, determinant, inverse), the demo uses Matrix A.

---

## ERROR HANDLING

- Checks if matrix sizes are okay for addition, subtraction, and multiplication.
- Checks if matrix is square for determinant and inverse.
- Checks if determinant is zero before trying to find inverse.
- Checks vector sizes for addition, subtraction, dot product, cross product, and normalization.
- Checks for zero magnitude before normalization.

---

## HOW TO USE DEMONSTRATION

### How to Compile & Run

**On Windows (using MinGW / g++):**
```bash
g++ matrix_library.cpp demonstration.cpp -o demo.exe
demo.exe
```

**On macOS or Linux:**
```bash
g++ matrix_library.cpp demonstration.cpp -o demo
./demo
```

> **Note:** Put `matrix_library.cpp` and `demonstration.cpp` in the same folder. After running, the demo creates `report_sample.html` automatically.

The demo asks the user to enter the size and numbers for matrices and vectors. Results show in the terminal and also are saved in an HTML report (`report_sample.html`). The HTML report has different parts for matrix and vector operations. If there is an error, it shows clearly.

---

## LIMITATIONS

- Matrix and vector size cannot be more than 10.
- Numbers are stored as doubles.

---

## FILES

- `matrix_library.h` – Header with function declarations
- `matrix_library.cpp` – Code for matrix & vector operations
- `demonstration.cpp` – Demo program that takes input and makes HTML
- `style.css` – Optional CSS for HTML report
- `README.txt` – This summary
- `README.md` – A longer version of the project description
- `LICENSE` – License information for the project

---

## SOURCES

1. How to create a library in C++:  
   [https://www.geeksforgeeks.org/cpp/how-do-i-create-a-library-in-cpp/](https://www.geeksforgeeks.org/cpp/how-do-i-create-a-library-in-cpp/)

2. Matrix multiplication algorithm:  
   [https://fa.wikipedia.org/wiki/الگوریتم‌های_ضرب_ماتریس](https://fa.wikipedia.org/wiki/الگوریتم‌های_ضرب_ماتریس)

3. Laplace Expansion (Determinant):  
   [https://youtu.be/c0N0itfpjFU](https://youtu.be/c0N0itfpjFU)

4. Adjoint Method (Inverse):  
   [https://youtu.be/P3l7gGeHXC8](https://youtu.be/P3l7gGeHXC8)

5. ofstream class in C++:  
   [https://www.w3schools.com/cpp/ref_fstream_ofstream.asp](https://www.w3schools.com/cpp/ref_fstream_ofstream.asp)

6. CSS border-collapse Property:  
   [https://www.w3schools.com/cssref/pr_border-collapse.php](https://www.w3schools.com/cssref/pr_border-collapse.php)

7. UTF-8 Mathematical Operators:  
   [https://cloford.com/resources/charcodes/utf-8_mathematical.htm](https://cloford.com/resources/charcodes/utf-8_mathematical.htm)  
   [https://www.fileformat.info/info/unicode/char/00d7/index.htm](https://www.fileformat.info/info/unicode/char/00d7/index.htm)

8. isnan function in C++:  
   [https://en.cppreference.com/w/cpp/numeric/math/isnan](https://en.cppreference.com/w/cpp/numeric/math/isnan)