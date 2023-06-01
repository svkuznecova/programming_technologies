#include <iostream>
#include <vector>
using namespace std;

class Vector; //обьявление класса Vector, чтобы Matrix видел этот класс
class Matrix
{
friend class Vector;
public:
vector<vector<int» matrix;
int row, column;

Matrix(int size1, int size2) {
row = size1;
column = size2;
matrix.resize(row, vector<int>(column));
}

void InputMatrix() {
cout « "input coordinates of matrix: " « endl;
for (int i = 0; i < row; i++) {
for (int j = 0; j < column; j++)
cin » matrix[i][j];
}
}
void PrintMatrix() {
for (int i = 0; i < row; i++) {
for (int j = 0; j < column; j++)
cout « matrix[i][j] « " ";
cout « endl;
}
cout « endl;
}
//сложение матриц
Matrix operator+(Matrix& m) {
Matrix m3(row, column);
for (int i = 0; i < row; i++) {
for (int j = 0; j < column; j++)
m3.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
}
return m3;
}
//вычитание матриц
Matrix operator-(Matrix& m) {
Matrix m3(row, column);
for (int i = 0; i < row; i++) {
for (int j = 0; j < column; j++)
m3.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
}
return m3;
}
//уножение матрицы на число
Matrix operator*(int num) {
Matrix m3(row, column);
for (int i = 0; i < row; i++) {
for (int j = 0; j < column; j++)
m3.matrix[i][j] = matrix[i][j] * num;
}
return m3;
}
//произведение матриц
Matrix operator*(Matrix& m) {
Matrix m3(row, column);
for (int i = 0; i < row; i++)
for (int j = 0; j < column; j++)
m3.matrix[i][j] += matrix[i][j] * m.matrix[j][i];
return m3;
}
Vector operator*(Vector& vector);
};
class Vector
{
friend class Matrix;
public:
vector<int> vector;
int size;

Vector(int length) {
size = length;
vector.resize(size);
}

void InputVector() {
cout « "input coordinates of vector: " « endl;
for (int i = 0; i < size; i++) {
cin » vector[i];
}
}
void PrintVector() {
for (int i = 0; i < size; i++)
cout « vector[i] « " ";
cout « endl;
}
//сложение векторов
Vector operator+(Vector& v) {
Vector v3(size);
for (int i = 0; i < size; i++) {
v3.vector[i] = vector[i] + v.vector[i];
}
return v3;
}
//вычитание векторов
Vector operator-(Vector& v) {
Vector v3(size);
for (int i = 0; i < size; i++) {
v3.vector[i] = vector[i] - v.vector[i];
}
return v3;
}
//уножение вектора на число
Vector operator*(int num) {
Vector v3(size);
for (int i = 0; i < size; i++) {
v3.vector[i] = vector[i] * num;
}
return v3;
}
//скалярное проиведение векторов
int operator*(Vector& v) {
int result = 0;
for (int i = 0; i < size; i++) {
result += vector[i] * v.vector[i];
}
return result;
}
};
Vector Matrix::operator*(Vector &vector)
{
Vector result(row);
for (int i = 0; i < row; i++)
{
for (int j = 0; j < vector.size; j++)
{
result.vector[i] += matrix[i][j] * vector.vector[j];
}
}
return result;
}

int main()
{
int row, column;
int size;
cout « "Размер матрицы (строка x столбец): ";
cin » row » column;
Matrix matrix1(row, column);
cout « "Матрица: " « endl;
matrix1.InputMatrix();

cout « "Матрица: " « endl;
matrix1.PrintMatrix();

cout « "Разиер вектора: ";
cin » size;

Vector vector1(size);
cout « "Вектор: " « endl;
vector1.InputVector();

cout « "Вектор: " « endl;
vector1.PrintVector();

cout « "Матрица * Вектор = " « endl;
Vector multiply = matrix1 * vector1;
multiply.PrintVector();
}

    vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i] += matrix[i][j] * vec[j];
        }
    }

    cout << "Результат умножения матрицы на вектор: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
