#include <iostream>
#include <string>
using namespace std;

class NhanVien{
    private:
        string Ten;
        int NgayLamViec;
        string MaSo;
        string ChucDanh;
        double HeSoLuong;
    public:
        void setTen(string s);
        void setNgayLamViec(int n);
        void setMaSo(string s);
        void setChucDanh(string s);
        void setHeSoLuong (double d);
        string getTen();
        int getNgayLamViec();
        string getMaSo();
        string getChucDanh();
        double getHeSoLuong();
        string giveMaSo(string t, int n);
        string giveChucDanh(int n);
        double giveHeSoLuong(string c);
        NhanVien();
        NhanVien(string t, int n, string m, string c, double h);
        NhanVien(string t, int n);
        NhanVien(const NhanVien& A);
        void xuat();
        void nhap();
        ~NhanVien();
};

void NhanVien::setTen(string s){
    Ten = s;
}

void NhanVien::setNgayLamViec(int n){
    NgayLamViec = n;
}

void NhanVien::setMaSo(string s){
    MaSo = s;
}

void NhanVien::setChucDanh(string s){
    ChucDanh = s;
}

void NhanVien::setHeSoLuong (double d){
    HeSoLuong = d;
}

string NhanVien::getTen(){
    return Ten;
}

int NhanVien::getNgayLamViec(){
    return NgayLamViec;
}

string NhanVien::getMaSo(){
    return MaSo;
}

string NhanVien::getChucDanh(){
    return ChucDanh;
}

double NhanVien::getHeSoLuong(){
    return HeSoLuong;
}

string NhanVien::giveMaSo(string t, int n){
    string m;
    for(char x : t){
        if(x == ' ') continue;
        m.push_back(x);
    }
    return to_string(n) + m;
}

string NhanVien::giveChucDanh(int n)
{
    if(n <= 365) return "Nhan vien";
    if(n >= 366 && n <= 730) return "Quan ly";
    if(n >= 731 && n <= 1460) return "Truong phong";
    return "Truong ban quan ly";
}

double NhanVien::giveHeSoLuong(string c){
    if(c == "Nhan vien") return 1.0;
    if(c == "Quan ly") return 1.5;
    if(c == "Truong phong") return 2.25;
    return 4.0;
}

NhanVien::NhanVien()
{
    Ten = "Nguyen Hoang Lam";
    NgayLamViec = 0;
    MaSo = "0NguyenHoangLam";
    ChucDanh = "Nhan Vien";
    HeSoLuong = 1;     
}

NhanVien::NhanVien(string t, int n, string m, string c, double h)
{
    Ten = t;
    NgayLamViec = n;
    MaSo = m;
    ChucDanh = c;
    HeSoLuong = h;     
}

NhanVien::NhanVien(string t, int n)
{
    Ten = t;
    NgayLamViec = n;
    MaSo = giveMaSo(t, n);
    ChucDanh = giveChucDanh(n);
    HeSoLuong = giveHeSoLuong(ChucDanh);     
}

NhanVien::NhanVien(const NhanVien& A)
{
    this->Ten = A.Ten;
    this->NgayLamViec = A.NgayLamViec;
    this->MaSo = A.MaSo;
    this->ChucDanh = A.ChucDanh;
    this->HeSoLuong = A.HeSoLuong;     
}

void NhanVien::xuat()
{
    cout << "Ten: " << getTen() << "\n"
            << "So ngay lam viec: " << getNgayLamViec() << "\n"
            << "Ma so: " << getMaSo() << "\n"
            << "Chuc danh: " << getChucDanh() << "\n"
            << "He so luong: " << getHeSoLuong() << "\n";
}

void NhanVien::nhap(){
    cout << "Nhap Ten: " << "\n";
    cin.ignore();
    getline(cin,Ten);
    cout << "Nhap so ngay lam viec: " << "\n";
    cin >> NgayLamViec;
    MaSo = giveMaSo(Ten, NgayLamViec);
    ChucDanh = giveChucDanh(NgayLamViec);
    HeSoLuong = giveHeSoLuong(ChucDanh);
}

NhanVien::~NhanVien()
{
    cout << "Nhan vien moi nghi huu." << "\n";   
}