#include <iostream>
using namespace std;

int UCLN(int a, int b){
    while(a != b){
        a > b ? a -= b : b -= a; 
    }
    return a;
}

class PhanSo{
    public:
        int Tu, Mau;
    public:
        PhanSo(int a, int b);
        PhanSo();
        void Rutgon();
        bool operator < (const PhanSo &A);
        bool operator > (const PhanSo &A);
        bool operator == (const PhanSo &A);
        bool operator <= (const PhanSo &A);
        bool operator >= (const PhanSo &A);
        bool operator != (const PhanSo &A);
        PhanSo operator = (const PhanSo &A);
        PhanSo operator + (const PhanSo &A);
        PhanSo operator - (const PhanSo &A);
        PhanSo operator * (const PhanSo &A);
        PhanSo operator / (const PhanSo &A);
        PhanSo operator += (const PhanSo &A);
        PhanSo operator -= (const PhanSo &A);
        PhanSo operator *= (const PhanSo &A);
        PhanSo operator /= (const PhanSo &A);
        friend ostream& operator << (ostream& os, const PhanSo& A);
        friend istream& operator >> (istream& is, PhanSo& A);
};

PhanSo::PhanSo(int a, int b){
        Tu = a;
        Mau = b;
}

PhanSo::PhanSo(){
    Tu = 0;
    Mau = 1;
}

void PhanSo::Rutgon(){
    int GCD = UCLN(this->Tu, this->Mau);
    this->Tu /= GCD;
    this->Mau /= GCD;
}

PhanSo PhanSo::operator=(const PhanSo &A){
    this->Tu = A.Tu;
    this->Mau = A.Mau;
    return *this;
}

PhanSo PhanSo::operator+(const PhanSo &A){
    PhanSo temp;
    temp.Tu = this->Tu*A.Mau + this->Mau*A.Tu;
    temp.Mau = this->Mau*A.Mau;
    temp.Rutgon();
    return temp; 
}

PhanSo PhanSo::operator-(const PhanSo &A){
    PhanSo temp;
    temp.Tu = this->Tu*A.Mau - this->Mau*A.Tu;
    temp.Mau = this->Mau*A.Mau;
    temp.Rutgon();
    return temp; 
}

PhanSo PhanSo::operator*(const PhanSo &A){
    PhanSo temp;
    temp.Tu = this->Tu*A.Tu;
    temp.Mau = this->Mau*A.Mau;
    temp.Rutgon();
    return temp; 
}

bool PhanSo::operator == (const PhanSo &A){
    this->Rutgon();
    PhanSo temp = A;
    temp.Rutgon();
    if(this->Tu == temp.Tu && this->Mau == temp.Mau) return true;
    else return false;
}

bool PhanSo::operator < (const PhanSo &A){
  return (this->Tu * A.Mau) < (A.Tu * this->Mau);
}


bool PhanSo::operator <= (const PhanSo &A){
    double f1 = 0, f2 = 0;
    f1 = this->Tu / this->Mau;
    f2 = A.Tu / A.Mau;
    if(f1 <= f2) return true;
    else return false;
}

bool PhanSo::operator >= (const PhanSo &A){
    double f1 = 0, f2 = 0;
    f1 = this->Tu / this->Mau;
    f2 = A.Tu / A.Mau;
    if(f1 >= f2) return true;
    else return false;
}

bool PhanSo::operator > (const PhanSo &A){
    double f1 = 0, f2 = 0;
    f1 = (this->Tu / this->Mau);
    f2 = A.Tu / A.Mau;
    cout << "\n" << f1 <<" " << this->Mau << endl;
    if(f1 > f2) return true;
    else return false;
}

PhanSo PhanSo::operator/(const PhanSo &A){
    PhanSo temp;
    temp.Tu = this->Tu*A.Mau;
    temp.Mau = this->Mau*A.Tu;
    temp.Rutgon();
    return temp; 
}

PhanSo PhanSo::operator+= (const PhanSo &A){
    this->Tu = this->Tu*A.Mau + this->Mau*A.Tu;
    this->Mau = this->Mau*A.Mau;
    this->Rutgon();
    return *this;
}

PhanSo PhanSo::operator-=(const PhanSo &A){
    this->Tu = this->Tu*A.Mau - this->Mau*A.Tu;
    this->Mau = this->Mau*A.Mau;
    this->Rutgon();
    return *this; 
}

PhanSo PhanSo::operator*=(const PhanSo &A){
    this->Tu = this->Tu*A.Tu;
    this->Mau = this->Mau*A.Mau;
    this->Rutgon();
    return *this; 
}

PhanSo PhanSo::operator/=(const PhanSo &A){
    this->Tu = this->Tu*A.Mau;
    this->Mau = this->Mau*A.Tu;
    this->Rutgon();
    return *this; 
}

ostream& operator << (ostream& os, const PhanSo& A){
    os << A.Tu << "/" << A.Mau;
    return os;
}

istream& operator >> (istream& is, PhanSo& A){
    is >> A.Tu >> A.Mau;
    return is;
}