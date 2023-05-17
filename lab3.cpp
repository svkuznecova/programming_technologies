#include <iostream> 
#include <vector> 
 
using namespace std; 
 
class Matrix { 
private: 
    int a; // строки 
    int b; // столбцы 
    vector<vector<double>>mat; 
 
public: 
    Matrix(int numA, int numB) : a(numA), b(numB) { 
        mat.resize(a, vector<double>(b)); 
    } 
// Ввод матрицы 
    void input() { 
        for (int i = 0; i < a; i++) { 
            for (int j = 0; j < b; j++) { 
                cin >> mat[i][j]; 
            } 
        } 
    } 
// Вывод матрицы 
    void print() { 
        for (int i = 0; i < a; i++) { 
            for (int j = 0; j < b; j++) { 
                cout << mat[i][j] << " "; 
            } 
            cout << endl; 
        } 
    } 
// Оператор сложение матриц 
    Matrix operator+(Matrix& other) { 
        Matrix result(a, b); 
        for (int i = 0; i < a; i++) { 
            for (int j = 0; j < b; j++) { 
                result.mat[i][j] = mat[i][j] + other.mat[i][j]; 
            } 
        } 
        return result; 
    } 
// Оператор вычитания матриц 
    Matrix operator-(Matrix& other) { 
        for (int i = 0; i < a; i++) { 
            for (int j = 0; j < b; j++) { 
                result.mat[i][j] = mat[i][j] - other.mat[i][j]; 
            } 
        } 
        return result; 
    } 
// Оператор умножения матриц 
    Matrix operator*(Matrix& other) { 
        int otherb = other.b; 
        Matrix result(a, otherb); 
        for (int i = 0; i < a; i++) { 
            for (int j = 0; j < otherb; j++) { 
                for (int k = 0; k < b; k++) { 
                    result.mat[i][j] += mat[i][k] * other.mat[k][j]; 
                } 
            } 
        } 
        return result; 
    } 
// Оператор умножения матриц на скаляр  
    Matrix operator*(double scal) { 
        Matrix result(a, b); 
        for (int i = 0; i < a; i++) { 
            for (int j = 0; j < b; j++) { 
                result.mat[i][j] = mat[i][j] * scal; 
            } 
        } 
        return result; 
    } 
// Оператор деления матриц на скаляр 
    Matrix operator/(double scal) { 
        Matrix result(a, b); 
        for (int i = 0; i < a; i++) { 
            for (int j = 0; j < b; j++) { 
                result.mat[i][j] = mat[i][j] / scal; 
            } 
        } 
        return result; 
    } 
}; 
 
int main() { 
    int a, b; 
    double scal; 
 
    cout << "Введите количество строк: "; 
    cin >> a; 
    cout << "Введите количество столбцов: "; 
    cin >> b; 
 
    Matrix mat1(a, b), mat2(a, b); 
 
    cout << "Введите значения для первой матрицы:\n"; 
    mat1.input(); 
    cout << "Введите значения для второй матрицы:\n"; 
    mat2.input(); 
 
    cout << "Введите скаляр:\n"; 
    cin >> scal; 
 
    Matrix sum = mat1 + mat2; // Сложение матриц 
    Matrix raz = mat1 - mat2; // Вычитание матриц 
    Matrix ymn = mat1 * mat2; // Умножение матриц 
    Matrix ymnskal1 = mat1 * scal; // Умножение 1-ой матрицы на скаляр  
    Matrix delskal2 = mat2 / scal; // Деление 2-ой матрицы на скаляр  
    Matrix ymnskal2 = mat2 * scal; // Умножение 2-ой матрицы на скаляр  
    Matrix delskal1 = mat1 / scal; // Деление 1-ой матрицы на скаляр  
 
//вывоод 
    cout << "Сумма матриц: " << endl; 
    sum.print(); 
 
    cout << "Разность матриц: " << endl; 
    raz.print(); 
 
    cout << "Умножегние матриц: " << endl; 
    ymn.print(); 
 
    cout << "Умножение 1-ой матрицы на скаляр " << scal << ": " << endl; 
    ymnskal1.print(); 
    cout << "Деление 1-ой матрицы на скаляр  " << scal << ": " << endl; 
    delskal1.print(); 
 
    cout << "Умножение 2-ой матрица на скаляр  " << scal << ": " << endl; 
    ymnskal2.print(); 
    cout << "Деление 2-ой матрицы на скаляр  " << scal << ": " << endl; 
    delskal2.print(); 
 
    return 0; 
}
