#include <iostream>
using namespace std;

class MangSoNguyen{
    private:
        int* dulieu;
        int kichthuoc;
    public:
        MangSoNguyen();
        MangSoNguyen(const MangSoNguyen& A);
        ~MangSoNguyen();
        MangSoNguyen operator=(const MangSoNguyen &A);
        MangSoNguyen operator+(const MangSoNguyen &A);
        MangSoNguyen operator++(int x);
        MangSoNguyen operator++();
        friend ostream& operator<<(ostream& os, const MangSoNguyen& A);
        friend istream& operator>>(istream& is, MangSoNguyen& A);
};

MangSoNguyen::MangSoNguyen(){
    dulieu = NULL;
    kichthuoc = 0;
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& A){
    this->kichthuoc = A.kichthuoc;
    this->dulieu = new int[this->kichthuoc];

    for(int i = 0; i < this->kichthuoc; i++){
        this->dulieu[i] = A.dulieu[i];
    }
}

MangSoNguyen::~MangSoNguyen(){
    delete[] this->dulieu;
}

MangSoNguyen MangSoNguyen::operator=(const MangSoNguyen &A){
    this->kichthuoc = A.kichthuoc;
    this->dulieu = new int[this->kichthuoc];

    for(int i = 0; i < this->kichthuoc; i++){
        this->dulieu[i] = A.dulieu[i];
    }

    return *this;
}

MangSoNguyen MangSoNguyen::operator+(const MangSoNguyen &A){
    MangSoNguyen result;
    int size = 0;
    
    if(A.kichthuoc <= 0 && this->kichthuoc <= 0){
        cout << "2 mang deu khong co phan tu.\n";
        return A;
    }
    else if(A.kichthuoc == 0) return *this;
    else if(this->kichthuoc == 0) return A;

    size = A.kichthuoc <= this->kichthuoc ? A.kichthuoc : this->kichthuoc;
    result.kichthuoc = A.kichthuoc > this->kichthuoc ? A.kichthuoc : this->kichthuoc;

    result.dulieu = new int[result.kichthuoc];

    for(int i = 0; i < size; i++){
        result.dulieu[i] = this->dulieu[i] + A.dulieu[i];
    }

    if(size == A.kichthuoc){
        for(int i = size; i < result.kichthuoc; i++)
            result.dulieu[i] = this->dulieu[i];
    }
    else if(size == this->kichthuoc){
        for(int i = size; i < result.kichthuoc; i++){
            result.dulieu[i] = A.dulieu[i];
        }
    }
    return result;
}

MangSoNguyen MangSoNguyen::operator++(int x){
    MangSoNguyen temp(*this);
    for(int i = 0; i < this->kichthuoc; i++){
        ++this->dulieu[i];
    }

    return temp;
}

MangSoNguyen MangSoNguyen::operator++(){
    for(int i = 0; i < this->kichthuoc; i++){
        ++this->dulieu[i];
    }

    return *this;
}

istream& operator >> (istream& is, MangSoNguyen& A){
    cout << "Nhap kich thuoc cua mang: \n";
    is >> A.kichthuoc;
    while(A.kichthuoc <= 0){
        cout << "Kich thuoc khong hop le xin vui long nhap lai: \n";
        is >> A.kichthuoc;
    }

    A.dulieu = new int[A.kichthuoc];


    cout << "Xin hay nhap du lieu cho mang: \n";
    for(int i = 0; i < A.kichthuoc; i++){
        is >> A.dulieu[i];
    }

    return is;
}

ostream& operator << (ostream& os, const MangSoNguyen& A){
    os << "Cac phan tu cua mang la: \n";
    for(int i = 0; i < A.kichthuoc; i++){
        os << A.dulieu[i] << " ";
    }
    os << "\n";

    return os;
}
