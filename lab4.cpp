#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "Введите размер матрицы (n * m): ";
    cin >> n >> m;

    int matrix[n][m];
    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int size;
    cout << "Введите размер вектора: ";
    cin >> size;

    vector<int> vec(size);
    cout << "Введите элементы вектора: ";
    for (int i = 0; i < size; i++) {
        cin >> vec[i];
    }

    if (m != size) {
        cout << "Ошибка: Количество столбцов в матрице должно быть равно размеру вектора." << endl;
        return 0;
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
