#include <iostream>
#include "math.h"
using namespace std;

class Komplex {

private:
    double i, m;

public:
    Komplex()//Конструктор "по умолчанию"
    {};

    Komplex(double i, double m) {//Конструктор с параметром
        this->i = i;
        this->m = m;
        cout << "Комплекс создался" << endl;
    };

    Komplex(const Komplex& F) {//Конструктор копирования
        this->i = F.i;
        this->m = F.m;
    }

    void set(double i, double m) {//Метод присваивания
        this->i = i;
        this->m = m;
    }

    void show() {//Метод вывода
        cout << "Действительная часть = " << i << endl;
        cout << "Мнимая часть = " << m << "i" << endl;
    }

    double modul() {
        return sqrt(i * i + m * m);
    }
};

//---------------------------------------------------

template <class T> class Vector {
private:
    T* A;
    int i;

public:
    Vector() {//Конструктор "по умолчанию"
        i = 0;
    };

    Vector(int i, T* m) {//Конструктор с параметром
        this->i = i;
        A = new T[i];
        for (int j = 0; j < i; j++)
            A[j] = m[j];
    };

    Vector(int i) {//Конструктор с параметром
        this->i = i;
        A = new T[i];
    };

    Vector(const Vector& F) {//Конструктор копирования
        this->i = F.i;
        A = new T[i];
        for (int j = 0; j < i; j++)
            A[j] = F.A[j];
    }

    int modul();

    friend ostream& operator << (ostream& out, const Vector& F) {
        for (int j = 0; j < F.i; j++)
            out << F.A[j] << " ";

        return out;
    }

    friend istream& operator >> (istream& in, Vector& F)    {
        in >> F.i;
        for (int j = 0; j < F.i; j++)
            in >> F.A[j];

        return in;
    }

    ~Vector()   {
        delete[] A;
    }
};

//---------------------------------------------------

template <>
int Vector<int>::modul()    {
    double k = 0;

    for (int j = 0; j < i; j++)
        k += A[j] * A[j];

    return static_cast<int>(sqrt(k));
}

template <>
int Vector<double>::modul() {
    double k = 0;

    for (int j = 0; j < i; j++)
        k += A[j] * A[j];

    return static_cast<int>(sqrt(k));
}

template <>
int Vector<Komplex>::modul()    {
    int k = 0;
    for (int j = 0; j < i; j++)
        k += 1;

    return k;
}

//-------------------------------------------

int main()
{
    setlocale(LC_ALL, "Russian");

    int A[5] = { 1,2,3,4,5 };
    Vector<int> INT_vector(5, A);
    cout << "INT вектор: " << INT_vector << " --- длина: " << INT_vector.modul() << endl;

    double B[5] = { 0.5, 1.5, 6.2, 8.0, 25.3 };
    Vector<double> DOUBLE_vector(5, B);
    cout << "DOUBLE вектор: " << DOUBLE_vector << " --- длина: " << DOUBLE_vector.modul() << endl;

    Komplex Karr[5];
    Komplex temp;

    cout << endl << "KOMPLEX вектор: ";
    for (int i = 0; i < 5; i++) {
        temp.set(i * 1.0, (i + 1) * 1.0);
        Karr[i] = temp;

        cout << endl;
        Karr[i].show();
        cout << endl;
    }

    Vector<Komplex> C(5, Karr);
    cout << endl << "Его длина: " << C.modul() << endl;

    return 0;
}

