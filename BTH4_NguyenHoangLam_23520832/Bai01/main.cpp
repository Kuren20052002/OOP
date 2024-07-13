#include "PhanSo.h"

int main(){
    PhanSo A;
    cin >> A;
    cout << "Phan so vua nhap la: " << A << "\n";

    PhanSo B(4, 5);

    if(A < B) cout << "Phan so vua nhap be hon " << B << "\n";
    else if(A > B) cout << "Phan so vua nhap lon hon " << B << "\n";
    else if(A == B) cout << "Phan so vua nhap bang " << B << "\n";

    A += B;
    cout << A <<endl;

}