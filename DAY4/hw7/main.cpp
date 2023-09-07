/*
   LAPACKE_dgesv Example
   =====================

   The program computes the solution to the system of linear
   equations with a square matrix A and multiple
   right-hand sides B, where A is the coefficient matrix
   and b is the right-hand side matrix:

   Description
   ===========

   The routine solves for X the system of linear equations A*X = B,
   where A is an n-by-n matrix, the columns of matrix B are individual
   right-hand sides, and the columns of X are the corresponding
   solutions.

   The LU decomposition with partial pivoting and row interchanges is
   used to factor A as A = P*L*U, where P is a permutation matrix, L
   is unit lower triangular, and U is upper triangular. The factored
   form of A is then used to solve the system of equations A*X = B.

   LAPACKE Interface
   =================

   LAPACKE_dgesv (col-major, high-level) Example Program Results

  -- LAPACKE Example routine (version 3.7.0) --
  -- LAPACK is a software package provided by Univ. of Tennessee,    --
  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
	 December 2016

*/
/* Includes */
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
#include "lapacke.h"
#include "lapacke_example_aux.h"
#include "myDeque.h"

using namespace std;

/* Main program */
int main() {

    /* Locals */
    lapack_int n = 3, nrhs = 1, lda = n, ldb = n, info;
    /* Local arrays */
    double A[9] = {1, 1, 0, 1, -2, 1, 0, 3, 1};
    double b[3] = {3, 6, 5};
    lapack_int ipiv[3];

    /* Print Entry Matrix */
    print_matrix_colmajor("Entry Matrix A", n, n, A, lda);
    /* Print Right Rand Side */
    print_matrix_colmajor("Right Rand Side b", n, nrhs, b, ldb);
    printf("\n");

    /* Executable statements */
    printf("LAPACKE_dgesv (row-major, high-level) Example Program Results\n");
    /* Solve the equations A*X = B */
    info = LAPACKE_dgesv(LAPACK_COL_MAJOR, n, nrhs, A, lda, ipiv,
                         b, ldb);

    /* Check for the exact singularity */
    if (info > 0) {
        printf("The diagonal element of the triangular factor of A,\n");
        printf("U(%i,%i) is zero, so that A is singular;\n", info, info);
        printf("the solution could not be computed.\n");
        exit(1);
    }
    if (info < 0) exit(1);
    /* Print solution */
    print_matrix_colmajor("Solution", n, nrhs, b, ldb);
    /* Print details of LU factorization */
    //print_matrix_colmajor( "Details of LU factorization", n, n, A, lda );
    /* Print pivot indices */
    //print_vector( "Pivot indices", n, ipiv );

    //对矩阵A进行奇异值分解
    double *U = (double *) malloc(sizeof(double) * n * n);
    double *VT = (double *) malloc(sizeof(double) * n * n);
    double *S = (double *) malloc(sizeof(double) * n);
    double *superb = (double *) malloc(sizeof(double) * (n - 1));
    int lwork = 5 * n;
    double *work = (double *) malloc(sizeof(double) * lwork);
    int i;
    for (i = 0; i < n * n; i++) {
        U[i] = 0;
        VT[i] = 0;
    }
    for (i = 0; i < n; i++) {
        S[i] = 0;
    }
    LAPACKE_dgesvd(LAPACK_COL_MAJOR, 'A', 'A', n, n, A, lda, S, U, lda, VT, lda, superb);
    printf("U:\n");
    print_matrix_colmajor("U", n, n, U, lda);
    printf("VT:\n");
    print_matrix_colmajor("VT", n, n, VT, lda);
    printf("S:\n");
    print_matrix_colmajor("S", n, n, S, lda);
    printf("superb:\n");
    print_matrix_colmajor("superb", n, n, superb, lda);
    printf("work:\n");
    print_matrix_colmajor("work", n, n, work, lda);
    free(U);
    free(VT);
    free(S);
    free(superb);
    free(work);

    myDeque<int> myDeque1;
    myDeque1.push_back(1);
    myDeque1.push_back(2);
    myDeque1.push_back(3);
    cout << "the first element is " << myDeque1.front() << endl;
    cout << "the last element is " << myDeque1.back() << endl;
    cout << "below is the result of push_back" << endl;
    myDeque1.print();
    myDeque1.pop_back();
    cout << "below is the result of pop_back" << endl;
    myDeque1.print();
    myDeque1.pop_front();
    cout << "below is the result of pop_front" << endl;
    myDeque1.print();
    myDeque1.push_front(4);
    cout << "below is the result of push_front" << endl;
    myDeque1.print();
    myDeque1.push_back(5);
    cout << "below is the result of push_back" << endl;
    myDeque1.print();
    myDeque<int> myDeque2 = myDeque1;
    cout << "below is the result of copy constructor" << endl;
    myDeque2.print();
    deque<int> deque1 = {1, 2, 3, 4, 5};
    myDeque1.assign(deque1.begin(), deque1.end());
    cout << "below is the result of assign" << endl;
    myDeque1.print();
    cout << "let's test double" << endl;

    myDeque<double> myDeque3;
    myDeque3.push_back(1.1);
    myDeque3.push_back(2.2);
    myDeque3.push_back(3.3);
    cout << "the first element is " << myDeque3.front() << endl;
    cout << "the last element is " << myDeque3.back() << endl;
    cout << "below is the result of push_back" << endl;
    myDeque3.print();
    myDeque3.pop_back();
    cout << "below is the result of pop_back" << endl;
    myDeque3.print();
    myDeque3.pop_front();
    cout << "below is the result of pop_front" << endl;
    myDeque3.print();
    myDeque3.push_front(4.4);
    cout << "below is the result of push_front" << endl;
    myDeque3.print();
    myDeque3.push_back(5.5);
    cout << "below is the result of push_back" << endl;
    myDeque3.print();
    myDeque<double> myDeque4 = myDeque3;
    cout << "below is the result of copy constructor" << endl;
    myDeque4.print();
    deque<double> deque2 = {1.1, 2.2, 3.3, 4.4, 5.5};
    myDeque3.assign(deque2.begin(), deque2.end());
    cout << "below is the result of assign" << endl;
    myDeque3.print();
    return 0;
}

