#pragma once

#include "../include/Matrix.hpp"
#include "../include/PolynomialHelper.hpp"
#include <vector>
#include <iostream>

//Returns a square n x n matrix with 1s down the diagonal. 
size_t getLeadingEntryColumn(size_t i, const Matrix<double>& m);
bool isLeadingEntry(size_t i, const Matrix<double>& m);
std::vector<Matrix<double>> getKernel(const Matrix<double>& m);
std::vector<double> getEigenValues(const Matrix<double>& m);
Matrix<Polynomial> convertMatrix(const Matrix<double>& m);



template <class T>
void swapRows(size_t i, size_t j, Matrix<T>& m);
template <class T>
void addRow(size_t i, size_t j, T scale, Matrix<T>& m);
template <class T>
void scaleRow(size_t i, float scale, Matrix<T>& m);
Matrix<double> getEchelonForm(Matrix<double> m);
Matrix<double> getReducedEchelonForm(Matrix<double> m);
std::vector<Matrix<double>> getEigenVectors(const Matrix<double>& m);
std::vector<Matrix<double>> getEigenVectors(const std::vector<double>& eigenValues, const Matrix<double>& m);
