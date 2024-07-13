#include "NhanVien.h"

int main(){
    NhanVien A("Hoang Pham Khanh Han", 28);
    A.xuat();

    cout <<"\n";
    A.nhap();
    A.xuat();
    return 0;
}