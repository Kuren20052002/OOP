#include <iostream>
#include <string>
#include <vector>

class CanBo{
  private:
    std::string hoTen, maSo, ngaySinh;
    long luong;
  public:
    CanBo(): hoTen("Nguyen Van A"), maSo("00000001"), ngaySinh("01/01/2000") {};
    virtual void nhapThongTin(){
      std::cout << "Nhap ho ten:\n";
      getline(std::cin, hoTen);
      std::cout << "Nhap ma so:\n";
      std::cin >> maSo;
      std::cout << "Nhap ngay sinh (DD/MM/YY):\n";
      std::cin >> ngaySinh;
      std::cin.ignore();
    }

    virtual void xuatThongTin() {
      std::cout << "Ho ten: " << hoTen << '\n';
      std::cout << "Ma so: "<< maSo << '\n';
      std::cout << "Ngay sinh: " << ngaySinh << '\n';
    }
    virtual ~CanBo() = default;
    virtual long tinhLuong() = 0;
};

class CanBoNhaNuoc : public CanBo{
  private:
    long luongCoBan;
    double heSoLuong, heSoPhuCap;
  public:
    CanBoNhaNuoc(): CanBo(), luongCoBan(0), heSoLuong(0), heSoPhuCap(0) {};

    void nhapThongTin() override{
      CanBo::nhapThongTin();
      std::cout << "Nhap he so luong:\n";
      std::cin >> heSoLuong;
      std::cout << "Nhap he so phu cap:\n";
      std::cin >> heSoPhuCap;
      std::cin.ignore();
    }

    void xuatThongTin() override {
      std::cout << "\nLoai can bo: Can bo bien che\n";
      CanBo::xuatThongTin();
      std::cout << "Luong: " << tinhLuong() << '\n';
    }

    long tinhLuong() override {
      return luongCoBan * heSoLuong * heSoPhuCap;
    }
 
    ~CanBoNhaNuoc() = default;
};

class CanBoHopDong : public CanBo{
  private:
    long tienCong;
    int soNgayCong;
    double heSoVuotGio;
  public:
    CanBoHopDong(): CanBo(), tienCong(0), soNgayCong(0), heSoVuotGio(0){};

    void nhapThongTin() override{
      CanBo::nhapThongTin();
      std::cout << "Nhap tien cong:";
      std::cin >> tienCong;
      std::cout << "Nhap so ngay cong:";
      std::cin >> soNgayCong;
      std::cout << "Nhap he so vuot gio:";
      std::cin >> heSoVuotGio;
      std::cin.ignore();
    }

    void xuatThongTin() override{
      std::cout << "\nLoai can bo: Can bo hop dong\n";
      CanBo::xuatThongTin();
      std::cout << "Luong: " << tinhLuong() << '\n';
    }

    long tinhLuong() override{
      return tienCong * soNgayCong * heSoVuotGio;
    }

    ~CanBoHopDong() = default; 
};

class DanhSachCanBo{
  private:
    int soCanBo;
    std::vector<CanBo*> DanhSachCanBo;
  public:
    void nhapDanhSach(){
      std::cout << "Nhap so can bo can dua vao danh sach: ";
      std::cin >> soCanBo;
      std::cin.ignore();

      CanBoHopDong* cbhd = new CanBoHopDong();
      CanBoNhaNuoc* cbnn = new CanBoNhaNuoc();

      for(int i = 0; i < soCanBo; i++){
        int loai = 0;;
        std::cout << "Nhap loai can bo: \n1: Can bo bien che\n2: Can bo hop dong\n";
        std::cin >> loai;
        std::cin.ignore();

        switch(loai){
          case 1:
            cbnn->nhapThongTin();
            DanhSachCanBo.push_back(cbnn);
            break;
          case 2:
            cbhd->nhapThongTin();
            DanhSachCanBo.push_back(cbhd);
            break;
          default:
            std::cout << "Loai khong hop le, nhap lai: ";
            i--;
        }
      }

      delete cbhd;
      delete cbnn;
    }

    long tongLuong(){
      long tong = 0;
      for(auto cb : DanhSachCanBo){
        tong += cb->tinhLuong();
      }
      return tong;
    }

    void xuatDanhSach(){
      for(auto cb : DanhSachCanBo){
        cb->xuatThongTin();
      }
    }

    void deallocateMemory(){
      for(auto* cb : DanhSachCanBo){
          delete cb;
      }
    }
};
