#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PhanSo{
    private:
        double Tu, Mau;
    public:
        PhanSo(double a, double b);
        PhanSo();
        ~PhanSo();
        void setTu(double a);
        void setMau(double a);
        double getTu();
        double getMau();
        void NhapPS();
        void XuatPS();
        void Rutgon();
        bool operator < (PhanSo A);
        bool operator > (PhanSo A);
        PhanSo operator + (PhanSo A);
        PhanSo operator - (PhanSo A);
        PhanSo operator * (PhanSo A);
        PhanSo operator / (PhanSo A);
};

int UCLN(int a, int b);
void quicksort(vector<PhanSo>& v, int start, int end);
int partition(vector<PhanSo>& v, int start, int end);
void rquicksort(vector<PhanSo>& v, int start, int end);
int rpartition(vector<PhanSo>& v, int start, int end);

class ListPhanSo{
    private:
        vector<PhanSo> v;
    public:
        void nhapList();
        void xuatList();
        void Listsum();
        void biggestfrac();
        void smallestfrac();
        void sortascend();
        void sortdecend(); 
};

void ListPhanSo::nhapList(){
    int n;

    cout << "Nhap so phan so trong danh sach: \n";
    cin >> n;
    for(int i = 0; i < n; i++){
        PhanSo A;
        A.NhapPS();
        this->v.push_back(A);
    }
}

void ListPhanSo::xuatList(){
    cout << "\nCac phan so trong danh sach la: ";
    for(PhanSo x : this->v) x.XuatPS();
    cout << '\n';
}

void ListPhanSo::Listsum(){
    PhanSo sum;
    for(PhanSo i : this->v) sum = sum + i;
    cout << "\nTong cua cac phan so trong danh sach la: "; 
    sum.XuatPS();
    cout << "\n";
}

void ListPhanSo::biggestfrac(){
    PhanSo biggest(0, 1);
    for(PhanSo i : this->v){
        if(i > biggest) biggest = i;
    }
    cout << "\nPhan so lon nhat trong danh sach la: ";
    biggest.XuatPS(); cout << '\n';
}

void ListPhanSo::smallestfrac(){
    PhanSo smolest(100, 1);
    for(PhanSo i : this->v){
        if(i < smolest) smolest = i;
    }
    cout << "\nPhan so nho nhat trong danh sach la: ";
    smolest.XuatPS(); cout << '\n';
}

void ListPhanSo::sortascend(){
    quicksort(this->v, 0, this->v.size() - 1);
}

void ListPhanSo::sortdecend(){
    rquicksort(this->v, 0, this->v.size() - 1);
}

PhanSo::PhanSo(double a, double b){
    this->Tu = a;
    this->Mau = b;
}

PhanSo::PhanSo(){
    this->Tu = 0;
    this->Mau = 1;
}

PhanSo::~PhanSo() = default;

void setTu(double a){
    this->Tu = a;
}

void setMau(double a){
    if(m == 0){
        Mau = 1;
    }
    Mau = a
}

void PhanSo::NhapPS(){
    cout << "Nhap tu: ";
    cin >> Tu;
    cout << "Nhap mau: ";
    cin >> Mau;
}

void PhanSo::XuatPS(){
    cout << Tu << "/" << Mau << " ";
}

void PhanSo::Rutgon(){
    int GCD = UCLN(this->Tu, this->Mau);
    this->Tu /= GCD;
    this->Mau /= GCD;
}

PhanSo PhanSo::operator+(PhanSo A){
    PhanSo temp;
    temp.Tu = this->Tu*A.Mau + this->Mau*A.Tu;
    temp.Mau = this->Mau*A.Mau;
    temp.Rutgon();
    return temp; 
}

PhanSo PhanSo::operator-(PhanSo A){
    PhanSo temp;
    temp.Tu = this->Tu*A.Mau - this->Mau*A.Tu;
    temp.Mau = this->Mau*A.Mau;
    temp.Rutgon();
    return temp; 
}

PhanSo PhanSo::operator*(PhanSo A){
    PhanSo temp;
    temp.Tu = this->Tu*A.Tu;
    temp.Mau = this->Mau*A.Mau;
    temp.Rutgon();
    return temp; 
}

bool PhanSo::operator < (PhanSo A){
    double f1 = 0, f2 = 0;
    f1 = this->Tu / this->Mau;
    f2 = A.Tu / A.Mau;
    if(f1 < f2) return true;
    else return false;
}

bool PhanSo::operator > (PhanSo A){
    double f1 = 0, f2 = 0;
    f1 = this->Tu / this->Mau;
    f2 = A.Tu / A.Mau;
    if(f1 > f2) return true;
    else return false;
}

PhanSo PhanSo::operator/(PhanSo A){
    PhanSo temp;
    temp.Tu = this->Tu*A.Mau;
    temp.Mau = this->Mau*A.Tu;
    temp.Rutgon();
    return temp; 
}

int UCLN(int a, int b){
    while(a != b){
        a > b ? a -= b : b -= a; 
    }
    return a;
}

int partition(vector<PhanSo>& v, int start, int end){
    PhanSo pivot = v[end];
    int j = start - 1;

    for(int i = start; i <= end; i++){
        if(v[i] < pivot){
            j++;
            PhanSo temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    j++;
    PhanSo temp = v[j];
    v[j] = v[end];
    v[end] = temp;
    return j;
}

void quicksort(vector<PhanSo>& v, int start, int end){
    if(end <= start) return;
    int pivot = partition(v, start, end);
    quicksort(v, start, pivot - 1);
    quicksort(v, pivot + 1, end);
}

int rpartition(vector<PhanSo>& v, int start, int end){
    PhanSo pivot = v[end];
    int j = start - 1;

    for(int i = start; i <= end; i++){
        if(v[i] > pivot){
            j++;
            PhanSo temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    j++;
    PhanSo temp = v[j];
    v[j] = v[end];
    v[end] = temp;
    return j;
}

void rquicksort(vector<PhanSo>& v, int start, int end){
    if(end <= start) return;
    int pivot = rpartition(v, start, end);
    rquicksort(v, start, pivot - 1);
    rquicksort(v, pivot + 1, end);
}