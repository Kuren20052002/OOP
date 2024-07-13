#include "CanBo.h"

int main(){
  DanhSachCanBo A;
  A.nhapDanhSach();
  A.xuatDanhSach();
  std::cout << "Tong luong can tra: " << A.tongLuong() << "\n";
  A.deallocateMemory();
}