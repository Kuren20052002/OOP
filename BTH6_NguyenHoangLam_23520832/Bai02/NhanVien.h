#include <iostream>
#include <string> 
#include <vector>

class NhanVien{
  private:
    std::string maNhanVien, hoTen, ngaySinh;
  public:
    NhanVien(): maNhanVien("00000001"), hoTen("Nguyen Van A"), ngaySinh("01/01/2000"){};
    
    virtual void nhapThongTin(){
      std::cout << "Nhap ho ten: \n";
      getline(std::cin, hoTen); 
      std::cout << "Nhap ma nhan vien: \n";
      getline(std::cin, maNhanVien); 
      std::cout << "Nhap ngay sinh: \n";
      getline(std::cin, ngaySinh); 
    }

    virtual void xuatThongTin() const{
      std::cout << "Ho ten: " << hoTen << '\n';
      std::cout << "Ma nhan vien: " << maNhanVien << '\n';
      std::cout << "Ngay sinh: " << ngaySinh << '\n';
    }

    virtual bool checkTieuChuan() = 0;

    virtual ~NhanVien() = default;
};

class GiangVien : public NhanVien{
  private:
    int soTietGiangDay, soDeTaiKhoaLuan;
  public:
    GiangVien(): NhanVien(), soTietGiangDay(0), soDeTaiKhoaLuan(0) {};
    void nhapThongTin() override{
      NhanVien::nhapThongTin();
      std::cout << "Nhap so tiet giang day trong nam: \n";
      std::cin >> soTietGiangDay;
      std::cout << "Nhap so de tai khoa luan giang vien huong dan: \n";
      std::cin >> soDeTaiKhoaLuan;
      std::cin.ignore();
    }

    void xuatThongTin() const override{
      std::cout << "\nLoai nhan vien: Giang vien\n";
      NhanVien::xuatThongTin();
      std::cout << "So tiet giang day trong nam: " << soTietGiangDay << '\n';
      std::cout << "So de tai khoa luan giang vien huong dan: " << soDeTaiKhoaLuan << '\n';
    }

    bool checkTieuChuan() override{
      return (soTietGiangDay >= 300 && soDeTaiKhoaLuan >= 5);
    }

    ~GiangVien() = default;
};

class NghienCuuVien : public NhanVien{
  private:
    int soDeTaiNghienCuu, soBaiBaoKH;
  public:
    NghienCuuVien(): NhanVien(), soDeTaiNghienCuu(0), soBaiBaoKH(0) {};

    void nhapThongTin() override{
      NhanVien::nhapThongTin();
      std::cout << "Nhap so de tai nghien cuu nhan vien da tham gia: \n";
      std::cin >> soDeTaiNghienCuu;
      std::cout << "Nhap so bai bao khoa hoc cua nhan vien: \n";
      std::cin >> soBaiBaoKH;
      std::cin.ignore();
    }

    void xuatThongTin() const override{
      std::cout << "\nLoai nhan vien: Nghien cuu vien\n";
      NhanVien::xuatThongTin();
      std::cout << "So de tai nghien cuu nhan vien da tham gia: " << soDeTaiNghienCuu << '\n';
      std::cout << "So bai bao khoa hoc cua nhan vien: " << soBaiBaoKH << '\n';
    }

    bool checkTieuChuan() override{
      return (soDeTaiNghienCuu >= 1 && soBaiBaoKH >= 2);
    }

    ~NghienCuuVien() = default;
};

class NhanVienVanPhong : public NhanVien{
  private:
    int soLopBoiDuong, soGioLaoDong;
  public:
    NhanVienVanPhong(): NhanVien(), soLopBoiDuong(0), soGioLaoDong(0) {};

    void nhapThongTin() override{
      NhanVien::nhapThongTin();
      std::cout << "Nhap so lop boi duong nhan vien da tham gia: \n";
      std::cin >> soLopBoiDuong;
      std::cout << "Nhap so gio tham gia lao dong cua nhan vien: \n";
      std::cin >> soGioLaoDong;
      std::cin.ignore();
    }

    void xuatThongTin() const override{
      std::cout << "\nLoai nhan vien: Nhan vien van phong\n";
      NhanVien::xuatThongTin();
      std::cout << "So lop boi duong nhan vien da tham gia: " << soLopBoiDuong << '\n';
      std::cout << "So gio tham gia lao dong cua nhan vien: " << soGioLaoDong << '\n';
    }

    bool checkTieuChuan() override{
      return (soLopBoiDuong >= 1 && soGioLaoDong >= 20);
    }

    ~NhanVienVanPhong() = default;
};

class QLNV{
  private:
    int soLuongNhanVien;
    std::vector<NhanVien*> DanhSachNhanVien;
  public:
    QLNV(): soLuongNhanVien(0) {};

    friend std::istream& operator >> (std::istream& is,  QLNV& qlnv){
      std::cout << "Nhap so luong nhan vien: \n";
      is >> qlnv.soLuongNhanVien;

      for(int i = 0; i < qlnv.soLuongNhanVien; i++){
        int loai = 0;
        std::cout << "Nhap loai nhan vien: \n1: Giang vien\n2: Nghien cuu vien\n3: Nhan vien van phong\n";
        is >> loai;
        is.ignore();

        GiangVien* gv = new GiangVien();
        NghienCuuVien* ncv = new NghienCuuVien();
        NhanVienVanPhong* nvvp = new NhanVienVanPhong();

        switch(loai){
          case 1:
            gv->nhapThongTin();
            qlnv.DanhSachNhanVien.push_back(gv);
            break;
          case 2:
            ncv->nhapThongTin();
            qlnv.DanhSachNhanVien.push_back(ncv);
            break;
          case 3:
            nvvp->nhapThongTin();
            qlnv.DanhSachNhanVien.push_back(nvvp);
            break;
          default:
            std::cout << "Loai khong hop le, nhap lai: \n";
            i--;
        }
      }

      return is;
    }

    friend std::ostream& operator << (std::ostream& os, const QLNV& qlnv){
      os << qlnv.DanhSachNhanVien.size() << '\n';
      for(NhanVien* nv : qlnv.DanhSachNhanVien){
        if(nv->checkTieuChuan()){
          nv->xuatThongTin();
        }
      }
      return os;
    }
};