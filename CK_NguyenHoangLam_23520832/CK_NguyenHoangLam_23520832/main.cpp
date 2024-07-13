#include "Hinh.h"

int main(){
  DanhSachHinh danhSachHinh;
  while(true){
    int loai = 0;
    std::cout << "\nNhap loai hinh: \n1: Hinh tron\n2: Hinh tam giac\n"; 
    if(danhSachHinh.getSize() != 0) std::cout << "3: Xuat thong tin trong danh sach\n4: In hinh lon nhat\n";
    std::cout << "Khac: Ket thuc\n"; 

    std::cin >> loai;
    if(danhSachHinh.getSize() == 0 && !(loai == 1 || loai == 2)) return 0;

    switch(loai){
      case 1: {
        danhSachHinh.addCircleToList();
        break;
      }
      case 2:{
        danhSachHinh.addTriangleToList();
        break;
      }
      case 3:{
        danhSachHinh.outputList();
        break;
      }
      case 4:{
        danhSachHinh.outputBiggestToFile();
        break;
      }
      default:
        return 0;
    }
  }
}