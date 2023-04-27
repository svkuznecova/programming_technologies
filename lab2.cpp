#include <iostream>
#include <vector>
using namespace std;

class Vector {
private:
int n;
vector<double> v;
public:
Vector(int size) {
n = size;
v.resize(n);
}
void input() {
for (int i = 0; i < n; i++) {
cin >> v[i];
}
}
void print() {
for (int i = 0; i < n; i++) {
cout << v[i] << " ";
}
cout << endl;
}
//Сумма векторов
Vector operator+ (const Vector& other) const {
Vector res(n);
for (int i = 0; i < n; i++) {
res.v[i] = v[i] + other.v[i];
}
return res;
}
//Разность векторов
Vector operator- (const Vector& other) const {
Vector res(n);
for (int i = 0; i < n; i++) {
res.v[i] = v[i] - other.v[i];
}
return res;
}
//Умножение векоров
double operator* (const Vector& other) const {
double res = 0;
for (int i = 0; i < n; i++) {
res += v[i] * other.v[i];
}
return res;
}
//Умножение на скаляр
Vector operator* (double scal) const {
Vector res(n);
for (int i = 0; i < n; i++) {
res.v[i] = v[i] * scal;
}
return res;
}
//Деление на скаляр
Vector operator/ (double scal) const {
Vector res(n);
for (int i = 0; i < n; i++) {
res.v[i] = v[i] / scal;
}
return res;
}
};

int main() {
int n;
double scal;

cout << "Введите размер векторов: ";
cin >> n;
Vector vect1(n), vect2(n);

cout << "Введите значения для первого вектора:\n";
vect1.input();
cout << "Введите значения для второго вектора:\n";
vect2.input();

cout << "Введите значение для скаляра:\n";
cin >> scal;

Vector sum = vect1 + vect2;
Vector razn = vect1 - vect2;
double ymn_vect = vect1 * vect2;
Vector ymn1 = vect1 * scal;
Vector del1 = vect2 / scal;
Vector ymn2 = vect2 * scal;
Vector del2 = vect1 / scal;

cout << "Сумма векторов: ";
sum.print();

cout << "Разница векторов: ";
razn.print();

cout << "Умножение векторов: " << ymn_vect << endl;

cout << "Вектор первый умножается на скаляр " << scal << ": ";
ymn1.print();
cout << "Вектор первый делится на скаляр " << scal << ": ";
del1.print();

cout << "Вектор второй умножается на скаляр " << scal << ": ";
ymn2.print();
cout << "Вектор второй делится на скаляр " << scal << ": ";
del2.print();

return 0;
}

