#include "MangMotChieu.h"

int main(){
    MangMotChieu A;
    A.fillRan();
    A.xuat();
    A.countnum();
    A.isascend();

    cout << "So le nho nhat trong day so la: " << A.smolodd() << "\n";
    cout << "So nguyen to lon nhat trong day so la: " << A.bigprime() << "\n";
    return 0;
}