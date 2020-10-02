#pragma once

#include "../include/Matrix.hpp"
#include "../include/Polynomial.hpp"
#include "../include/PolynomialHelper.hpp"
#include "../include/Timer.hpp"
#include <vector>
#include <iostream>

/*
 * Returns the leading entry of a given column, and returns -1 if the row is 0.
 */
uint32_t getLeadingEntryColumn(uint32_t i, const Matrix<double>& m);

/*
 * Test if column i contains a leading entry of m.
 */
bool isLeadingEntry(uint32_t i, const Matrix<double>& m);

/*
 * Return the kernel of matrix m, or, more precisely, the vectors that would form the spanning set 
 * of the kernel of m.
 */
std::vector<Matrix<double>> getKernel(const Matrix<double>& m);
/*
 * Return the Eigen values of m.
 */
std::vector<double> getEigenValues(const Matrix<double>& m);
/*
 * Convert a matrix from a double matrix (a matrix of approximate rational numbers) to a matrix of Polynomials with double coefficients.
 */
Matrix<Polynomial> convertMatrix(const Matrix<double>& m);
/*
 * Swap row i and j of matrix m.
 */
template <class T>
void swapRows(uint32_t i, uint32_t j, Matrix<T>& m);
/*
 * Scalar addition of row j to row i.  
 */
template <class T>
void addRow(uint32_t i, uint32_t j, T scale, Matrix<T>& m);
/*
 * Scale row i by scale.
 */
template <class T>
void scaleRow(uint32_t i, float scale, Matrix<T>& m);
/*
 * Get the Echelon form of m (no non zero entries below the diagonal).
 */
Matrix<double> getEchelonForm(Matrix<double> m);
/*
 * Get the reduced Echelon form of m: the Echelon form, but with no non zero entries above the leading row entries, and the 
 * leading entries are normalized.
 */
Matrix<double> getReducedEchelonForm(Matrix<double> m);
/*
 * Get the Eigen vectors of m (Eigen values are computed in the process).
 */
std::vector<Matrix<double>> getEigenVectors(const Matrix<double>& m);
/*
 * Get the Eigen vectors of m when also provided with the Eigen vectors of m. (These are not checked, so it is up to the user to provide correct
 * eigen values.)
 */
std::vector<Matrix<double>> getEigenVectors(const std::vector<double>& eigenValues, const Matrix<double>& m);
