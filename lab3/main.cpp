#include <iostream>
#include "math.h"
using namespace std;

class Komplex {

private:
    double i, m;

public:
    Komplex()//����������� "�� ���������"
    {};

    Komplex(double i, double m) {//����������� � ����������
        this->i = i;
        this->m = m;
        cout << "�������� ��������" << endl;
    };

    Komplex(const Komplex& F) {//����������� �����������
        this->i = F.i;
        this->m = F.m;
    }

    void set(double i, double m) {//����� ������������
        this->i = i;
        this->m = m;
    }

    void show() {//����� ������
        cout << "�������������� ����� = " << i << endl;
        cout << "������ ����� = " << m << "i" << endl;
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
    Vector() {//����������� "�� ���������"
        i = 0;
    };

    Vector(int i, T* m) {//����������� � ����������
        this->i = i;
        A = new T[i];
        for (int j = 0; j < i; j++)
            A[j] = m[j];
    };

    Vector(int i) {//����������� � ����������
        this->i = i;
        A = new T[i];
    };

    Vector(const Vector& F) {//����������� �����������
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
    cout << "INT ������: " << INT_vector << " --- �����: " << INT_vector.modul() << endl;

    double B[5] = { 0.5, 1.5, 6.2, 8.0, 25.3 };
    Vector<double> DOUBLE_vector(5, B);
    cout << "DOUBLE ������: " << DOUBLE_vector << " --- �����: " << DOUBLE_vector.modul() << endl;

    Komplex Karr[5];
    Komplex temp;

    cout << endl << "KOMPLEX ������: ";
    for (int i = 0; i < 5; i++) {
        temp.set(i * 1.0, (i + 1) * 1.0);
        Karr[i] = temp;

        cout << endl;
        Karr[i].show();
        cout << endl;
    }

    Vector<Komplex> C(5, Karr);
    cout << endl << "��� �����: " << C.modul() << endl;

    return 0;
}

