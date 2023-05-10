#include <iostream>
using namespace std;
class Matrix
{
private:
  int rows, cols; // Размерность
  double* pMatrix; // Массив
  int number; // Номер
public:
  static int Count; // Кол-во созданных объектов

  // Операторы
  Matrix operator + (Matrix& r); // Сложение двух матриц
  Matrix operator - (Matrix& r); // Вычитание двух матриц
  Matrix operator * (Matrix& r); // Произведение двух матриц
  Matrix operator * (double n); // Произведение матрицы на число

  // Вывод объекта
  void Print()
  {
    cout << "\x1B[36mМатрица \033[0m" << "№ " << number << "\x1B[36m, размер \033[0m" << rows << "x" << cols << "\x1B[36m:\033[0m" << endl;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cout << pMatrix[i * cols + j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }


  ///// КОНСТРУКТОРЫ 

  // Конструкор по умолчанию
  Matrix()
  {
    rows = 3;
    cols = 3;
    Count++;
    number = Count;

    pMatrix = new double[rows * cols];

    for (int i = 0; i < rows * cols; i++)
    {
      (i % (rows + 1) == 0) ? pMatrix[i] = 1 : pMatrix[i] = 0;
    }

    cout << "\x1B[90m~ Вызван конструктор \033[0m" << "Matrix() " << "\x1B[90mсоздан объект \033[0m" << "№" << number << endl << endl;
  }


  // Конструктор принимающий размерность (2 значения)
  Matrix(int n, int m)
  {

    rows = n;
    cols = m;
    Count++;
    number = Count;

    pMatrix = new double[rows * cols];

    for (int i = 0; i < rows * cols; i++)
    {
      pMatrix[i] = 0;
    }

    cout << "\x1B[90m~ Вызван конструктор \033[0m" << "Matrix(int n, int m) " << "\x1B[90mсоздан объект \033[0m" << "№" << number << endl << endl;
  }


  // Конструктор принимающий размерность (1 значение)
  Matrix(int n)
  {

    rows = n;
    cols = n;
    Count++;
    number = Count;

    pMatrix = new double[rows * cols];

    for (int i = 0; i < rows * cols; i++)
    {
      (i % (rows + 1) == 0) ? pMatrix[i] = 1 : pMatrix[i] = 0;
    }

    cout << "\x1B[90m~ Вызван конструктор \033[0m" << "Matrix(int n) " << "\x1B[90mсоздан объект \033[0m" << "№" << number << endl << endl;
  }


  // Конструктор принимающий размерность и элементы массива
  Matrix(int n, int m, double* x)
  {
    rows = n;
    cols = m;
    Count++;
    number = Count;

    pMatrix = new double[rows * cols];

    for (int i = 0; i < rows * cols; i++)
    {
      pMatrix[i] = x[i];
    }

    cout << "\x1B[90m~ Вызван конструктор \033[0m" << "Matrix(int n, int m, double* x) " << "\x1B[90mсоздан объект \033[0m" << "№" << number << endl << endl;
  };


  // Конструктор копирования
  Matrix(const Matrix& matrix)
  {
    rows = matrix.rows;
    cols = matrix.cols;
    Count++;
    number = Count;

    pMatrix = new double[rows * cols];

    for (int i = 0; i < rows * cols; i++)
    {
      pMatrix[i] = matrix.pMatrix[i];
    }

    cout << "\x1B[90m~ Вызван конструктор \033[0m" << "Matrix(const Matrix& matrix) " << "\x1B[90mсоздан объект \033[0m" << "№" << number << endl << endl;
  };


  // Деструктор
  ~Matrix()
  {
    delete[] pMatrix;
    Count--;
  }
};

///// РЕАЛИЗАЦИЯ ОПЕРАТОРОВ

// Сложение двух матриц
Matrix Matrix :: operator +(Matrix& r)
{
  // Проверка размерностей матриц
  if (rows == r.rows && cols == r.cols)
  {
    Matrix result(rows, cols);

    cout << "\x1B[90m~ Сложение объектов \033[0m" << "№" << number << "\x1B[90m и \033[0m" << "№" << r.number << "\x1B[90m, в объект \033[0m" << "№" << result.number + 1;
    cout << endl << endl;

    for (int i = 0; i < rows * cols; i++)
    {
      result.pMatrix[i] = pMatrix[i] + r.pMatrix[i];
    }
      result.Print();

    return result;
  }

  // Вывод ошибки
  else cout << "\x1B[90m~ Не удалось сложить объекты \033[0m" << "№" << number << "\x1B[90m и \033[0m" << "№" << r.number << endl << endl;
}

// Вычитание двух матриц
Matrix Matrix :: operator -(Matrix& r)
{
  // Проверка размерностей матриц
  if (rows == r.rows && cols == r.cols)
  {
    Matrix result(rows, cols);
cout << "\x1B[90m~ Вычитание объектов \033[0m" << "№" << number << "\x1B[90m и \033[0m" << "№" << r.number << "\x1B[90m, в объект \033[0m" << "№" << result.number + 1;
    cout << endl << endl;

    for (int i = 0; i < rows * cols; i++)
    {
      result.pMatrix[i] = pMatrix[i] - r.pMatrix[i];
    }
    result.Print();
    return result;
  }

  // Вывод ошибки
  else cout << "\x1B[90m~ Не удалось вычесть объекты \033[0m" << "№" << number << "\x1B[90m и \033[0m" << "№" << r.number << endl << endl;
}

// Произведение двух матриц
Matrix Matrix :: operator *(Matrix& r)
{
  // Проверка размерностей матриц
  if (cols == r.rows)
  {
    Matrix result(rows, r.cols);

    cout << "\x1B[90m~ Произведение объектов \033[0m" << "№" << number << "\x1B[90m и \033[0m" << "№" << r.number << "\x1B[90m, в объект \033[0m" << "№" << result.number + 1;
    cout << endl << endl;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < r.cols; j++) {
        result.pMatrix[i * result.cols + j] = 0;
        for (int k = 0; k < cols; k++) {
          result.pMatrix[i * result.cols + j] += pMatrix[i * cols + k] * r.pMatrix[k * r.cols + j];
        }
      }
    }

    return result;
  }

  // Вывод ошибки
  else cout << "\x1B[90m~ Не удалось умножить объекты \033[0m" << "№" << number << "\x1B[90m и \033[0m" << "№" << r.number << endl << endl;
}


// Произведение матрицы на число
Matrix Matrix :: operator *(double n)
{
  Matrix result(rows, cols);

  cout << "\x1B[90m~ Произведение объекта \033[0m" << "№" << number << "\x1B[90m на число \033[0m" << n << "\x1B[90m, в объект \033[0m" << "№" << result.number + 1;
  cout << endl << endl;

  for (int i = 0; i < rows * cols; i++)
  {
    result.pMatrix[i] = pMatrix[i] * n;
  }

  return result;
}


// Объявление статической переменной
int Matrix::Count = 0;


// Вывод количества созданных векторов
void Total()
{
  cout << "\x1B[36mСоздано объектов: \033[0m" << Matrix::Count << endl << endl;
}


int main()
{
  setlocale(LC_ALL, "Russian");

  double* A;
  int x, y; 

  cin >> x>> y;
  
  int size = x * y;
  A = new double[size];
  
  for (int i = 0; i < size; i++)
  {
    cin >> A[i];
  }
  Matrix a(x,y,A);
  
  a.Print();

  double* B;

  cin >> x >> y;

  size = x * y;
  B = new double[size];

  for (int i = 0; i < size; i++)
  {
    cin >> B[i];
  }
  Matrix b(x, y, B);
  a + b;
  a.Print();
  b.Print();

  Total();
}
