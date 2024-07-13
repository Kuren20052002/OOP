#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>


class Hinh{
  protected:
    double chuVi;
    double dienTich;
  public:
    Hinh(double p, double s): chuVi(p), dienTich(s) {};

    double getChuVi() const { return chuVi; }
    double getDienTich() const { return dienTich; }
    virtual void inRaFile(std::ostream& File) = 0;

    virtual void xuatThongTin() = 0;

};

class HinhTron : public Hinh{
  private:
    double x, y;
    double r;
  public:
    HinhTron(double x, double y, double r):
      Hinh(2 * 3.141 * r, 3.141 * r * r),
      x(x), y(y), r(r) {};

    void xuatThongTin() override{
      std::cout << "\nTam hinh tron: I(" << x << ", " << y << ")\n";
      std::cout << "Ban kinh hinh tron: " << r << '\n';
      std::cout << "Chu vi hinh tron: " << getChuVi() << '\n';
      std::cout << "Dien tich hinh tron: " << getDienTich() << '\n';
    }

    void inRaFile(std::ostream& File) override{
      File << "\nTam hinh tron: I(" << x << ", " << y << ")\n";
      File << "Ban kinh hinh tron: " << r << '\n';
      File << "Chu vi hinh tron: " << getChuVi() << '\n';
      File << "Dien tich hinh tron: " << getDienTich() << '\n';
    }
};

class HinhTamGiac : public Hinh{
  private:
    double x1, y1, x2, y2, x3, y3;
    std::string loaiTamGiac;
  public:
    void xacDinhLoaiTamGiac(){
      double AB = tinhCanh(x1, x1, y1, y2);
      double AC = tinhCanh(x1, y1, x3, y3);
      double BC = tinhCanh(x2, y2, x3, y3);

      if(AB == AC && AB == BC){
        loaiTamGiac = "Tam giac deu";
      }
      else if((AB * AB + AC * AC == BC * BC) || 
              (AB * AB + BC * BC == AC * AC) || 
              (BC * BC + AC * AC == AB * AB)){
        loaiTamGiac = "Tam giac vuong";
        if(AB == AC || AB == BC || BC == AC){
          loaiTamGiac = "Tam giac vuong can";
        }
      }
      else if(AB == AC || AB == BC || BC == AC){
        loaiTamGiac = "Tam giac can";
      }
      else if(AB + AC <= BC || AB + BC <= AC || BC + AC <= AB){
        loaiTamGiac = "Khong phai tam giac";
        dienTich = 0;
        chuVi = 0;
      }
      else loaiTamGiac = "Tam giac khac";

    }

    double tinhCanh(double x1, double y1, double x2, double y2){
      return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    }

    HinhTamGiac(double x1, double y1, double x2, double y2, double x3, double y3):
      Hinh(0, 0), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
            double AB = tinhCanh(x1, y1, x2, y2);
            double AC = tinhCanh(x1, y1, x3, y3);
            double BC = tinhCanh(x2, y2, x3, y3);

            double p = (AB + AC + BC) / 2;
            double s = sqrt(p * (p - AB) * (p - AC) * (p - BC));
            chuVi = AB + AC + BC;
            dienTich = s;

            xacDinhLoaiTamGiac();
        }


      void xuatThongTin() override{
        std::cout << "\nLoai tam giac: " << loaiTamGiac << '\n';
        std::cout << "Chu vi hinh tam giac: " << getChuVi() << '\n';
        std::cout << "Dien tich hinh tam giac: " << getDienTich() << '\n';     
      }

      void inRaFile(std::ostream& File) override{
        File << "\nLoai tam giac: " << loaiTamGiac << '\n';
        File << "Chu vi hinh tam giac: " << getChuVi() << '\n';
        File << "Dien tich hinh tam giac: " << getDienTich() << '\n';  
      }
};

class DanhSachHinh{
  private:
    std::vector<Hinh*> danhSachHinh;
  public:
    int getSize(){
      return danhSachHinh.size();
    }

    void addCircleToList(){
        double x, y, r;
        std::cout << "Nhap Diem I(x, y): \n";
        std::cin >> x >> y;
        std::cout << "Nhap ban kinh hinh tron: \n";
        std::cin >> r;
        while(r < 1){
          std::cout << "Ko hop le, vui long nhap lai: \n";
          std::cin >> r;
        }
        HinhTron* ht = new HinhTron(x, y, r);
        danhSachHinh.push_back(ht);
    }

    void addTriangleToList(){
        double x1, x2, x3, y1, y2, y3;
        std::cout << "Nhap Diem A(x, y): \n";
        std::cin >> x1 >> y1;
        std::cout << "Nhap Diem B(x, y): \n";
        std::cin >> x2 >> y2;
        std::cout << "Nhap Diem Cx, y): \n";
        std::cin >> x3 >> y3;
        HinhTamGiac* htg = new HinhTamGiac(x1, y1, x2, y2, x3, y3);
        danhSachHinh.push_back(htg);
    }

    void outputList(){
        for(auto hinh : danhSachHinh){
          hinh->xuatThongTin();
        }
        std::string str;
        std::cout << "\nNhap bat ki de tiep tuc.";
        std::cin >> str;
    }

    void outputBiggestToFile(){
      int biggest = danhSachHinh[0]->getDienTich();
      int index = 0;
      for(long unsigned int i = 1; i < danhSachHinh.size(); i++){
        if(danhSachHinh[i]->getDienTich() > biggest) index = i;
      }
      std::ofstream HinhLonNhat;
      HinhLonNhat.open("RESULT.OUT", std::ios::out | std::ios::app);
      danhSachHinh[index]->inRaFile(HinhLonNhat);
      HinhLonNhat.close();
    }
};