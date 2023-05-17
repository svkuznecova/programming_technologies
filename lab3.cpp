#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<double>> mat;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        mat.resize(rows, vector<double>(cols));
    }

    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }
    
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+( Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator-(Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator*(Matrix& other) {
        int otherCols = other.cols;
        Matrix result(rows, otherCols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < otherCols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator*(double scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] * scalar;
            }
        }
        return result;
    }

    Matrix operator/(double scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] / scalar;
            }
        }
        return result;
    }
};

int main() { 
    int rows, cols; 
    double scalar; 
 
    cout << "Введите количество строк: "; 
    cin >> rows; 
    cout << "Введите количество столбцов: "; 
    cin >> cols; 
 
    Matrix mat1(rows, cols), mat2(rows, cols); 
 
    cout << "Введите значения для первой матрицы:\n"; 
    mat1.input(); 
    cout << "Введите значения для второй матрицы:\n"; 
    mat2.input(); 
 
    cout << "Введите скаляр:\n"; 
    cin >> scalar; 
 
    Matrix sum = mat1 + mat2; // Сложение матриц 
    Matrix raz = mat1 - mat2; // Вычитание матриц 
    Matrix ymn = mat1 * mat2; // Умножение матриц 
    Matrix ymnskal1 = mat1 * scalar; // Умножение 1-ой матрицы на скаляр  
    Matrix delskal2 = mat2 / scalar; // Деление 2-ой матрицы на скаляр  
    Matrix ymnskal2 = mat2 * scalar; // Умножение 2-ой матрицы на скаляр  
    Matrix delskal1 = mat1 / scalar; // Деление 1-ой матрицы на скаляр  
 
//вывоод 
    cout << "Сумма матриц: " << endl; 
    sum.print(); 
 
    cout << "Разность матриц: " << endl; 
    raz.print(); 
 
    cout << "Умножегние матриц: " << endl; 
    ymn.print(); 
 
    cout << "Умножение 1-ой матрицы на скаляр " << scalar << ": " << endl; 
    ymnskal1.print(); 
    cout << "Деление 1-ой матрицы на скаляр  " << scalar << ": " << endl; 
    delskal1.print(); 
 
    cout << "Умножение 2-ой матрица на скаляр  " << scalar << ": " << endl; 
    ymnskal2.print(); 
    cout << "Деление 2-ой матрицы на скаляр  " << scalar << ": " << endl; 
    delskal2.print(); 
 
    return 0; 
}
