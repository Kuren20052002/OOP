#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhanSu{
    private:
        string hoTen;
        string ngaySinh;
        string ID;
    public:
        NhanSu(string name, string ngaySinh, string ID) 
            : hoTen(name),
              ngaySinh(ngaySinh),
              ID(ID) {}

        virtual ~NhanSu() {}

        virtual double tinhLuong() const = 0;

        virtual void nhapThongTinNhanSu(){
            cout << "Nhap ho va ten: ";
            getline(cin, hoTen);  
            cout << "Nhap ngay sinh (DD/MM/YYYY): ";
            getline(cin, ngaySinh);
            cout << "Nhap ma so nhan su: ";
            getline(cin, ID);
        }

        virtual void xuatThongTinNhanSu() const{
            cout << "Ho va ten: " << hoTen << endl;
            cout << "Ngay sinh: " << ngaySinh << endl;
            cout << "Ma so nhan su: " << ID << endl;
        }

};

class GiangVien : public NhanSu{
    private:
        string hocHam;
        string hocVi;
        int soNamGiangDay;
        vector<string> cacMonGiangDay;
    public:
        GiangVien(string name, string ngaySinh, string ID, string hocHam, string hocVi, 
                  int soNamGiangDay, vector<string> courses)
            : NhanSu(name, ngaySinh, ID),
              hocHam(hocHam),
              hocVi(hocVi),
              soNamGiangDay(soNamGiangDay),
              cacMonGiangDay(courses) {}

        double tinhLuong() const override{
            return (cacMonGiangDay.size() * soNamGiangDay * 0.12) * 20000;
        }

        void nhapThongTinNhanSu() override{
            NhanSu::nhapThongTinNhanSu();
            cout << "Nhap hoc ham: ";
            getline(cin, hocHam);
            cout << "Nhap hoc vi: ";
            getline(cin, hocVi);
            cout << "Nhap so nam giang day: ";
            cin >> soNamGiangDay;
            cout << "Nhap so mon dang giang day: ";
            int soMonGiangDay = 0;
            cin >> soMonGiangDay;
            cin.ignore();
            cout << "Nhap cac mon dang giang day: ";
            for(int i = 0; i < soMonGiangDay; i++){
                string monHoc;
                getline(cin, monHoc);
                cacMonGiangDay.push_back(monHoc);
            }
        }

        void xuatThongTinNhanSu() const override{
            NhanSu::xuatThongTinNhanSu();
            cout << "Hoc ham: " << hocHam << endl;
            cout << "Hoc vi: " << hocVi << endl;
            cout << "So nam giang day: " << soNamGiangDay << endl;
            cout << "Cac mon dang giang day: ";
            for(auto monHoc : cacMonGiangDay) cout << monHoc << ", ";
            cout << endl;
        }
};

class TroGiang : public NhanSu{
    private:
        int soMonTroGiang;
    public:
        TroGiang(string name, string dob, string ID, int soMonTroGiang)
            : NhanSu(name, dob, ID),
              soMonTroGiang(soMonTroGiang) {}
        
        double tinhLuong() const override{
            return (soMonTroGiang * 0.3) * 18000;
        }

        void nhapThongTinNhanSu() override{
            NhanSu::nhapThongTinNhanSu();
            cout << "Nhap so mon dang tro giang: ";
            cin >> soMonTroGiang;
            cin.ignore();
        }

        void xuatThongTinNhanSu() const override{
            NhanSu::xuatThongTinNhanSu();
            cout << "So mon dang tro giang: " << soMonTroGiang << endl;
        }
};

class NghienCuuVien : public NhanSu {
    private:
        vector<string> danhSachMaDuAnHienTai;
        int soNamNghienCuu;
    public:
        NghienCuuVien(string name, string dob, string ID, vector<string> danhSachCacMaDuAnHienTai, int soNamNghienCuu)
            : NhanSu(name, dob, ID),
              danhSachMaDuAnHienTai(danhSachCacMaDuAnHienTai),
              soNamNghienCuu(soNamNghienCuu) {}

        double tinhLuong() const override{
            int countDProject = 0;
            for(string x : danhSachMaDuAnHienTai){
                if(x[0] == 'D') countDProject++;
            }
            return (soNamNghienCuu * 2 + countDProject) * 20000;
        } 

        void nhapThongTinNhanSu() override{
            NhanSu::nhapThongTinNhanSu();
            int soDuAn;
            cout << "Nhap so du an hien tai dang tham gia: ";
            cin >> soDuAn;
            cin.ignore();
            cout << "Nhap ma cua cac du an: ";
            for(int i = 0; i < soDuAn; i++){
                string maDuAn;
                getline(cin, maDuAn);
                danhSachMaDuAnHienTai.push_back(maDuAn);
            }
            cout << "Nhap so nam kinh nghiem nghien cuu: ";
            cin >> soNamNghienCuu;
            cin.ignore(); 
        }

        void xuatThongTinNhanSu() const override{
            NhanSu::xuatThongTinNhanSu();
            cout << "Cac ma du an dang tham gia: ";
            for(string x : danhSachMaDuAnHienTai) cout << x << ", ";
            cout << "\nSo nam kinh nghiem nghien cuu: " << soNamNghienCuu << endl;
        }
};

class ChuyenVien : public NhanSu{
    private:
        vector<string> danhSachMaDuAnHoanThanh;
        int soNamLamViec;
    public:
        ChuyenVien(string name, string dob, string ID, vector<string> danhSachMaDuAnHoanThanh, int soNamLamViec)
            : NhanSu(name, dob, ID),
              danhSachMaDuAnHoanThanh(danhSachMaDuAnHoanThanh),
              soNamLamViec(soNamLamViec) {}
            
        double tinhLuong() const override{
            int countTProject = 0;
            for(string x : danhSachMaDuAnHoanThanh){
                if(x[0] == 'T') countTProject++;
            }
            return (soNamLamViec * 4 + countTProject) * 18000;
        }

        void nhapThongTinNhanSu() override{
            NhanSu::nhapThongTinNhanSu();
            int soDuAn;
            cout << "Nhap so du an giao duc da hoan thanh: ";
            cin >> soDuAn;
            cin.ignore();
            cout << "Nhap ma cua cac du an giao duc da hoan thanh: ";
            for(int i = 0; i < soDuAn; i++){
                string maDuAn;
                getline(cin, maDuAn);
                danhSachMaDuAnHoanThanh.push_back(maDuAn);
            }
            cout << "Nhap so nam kinh nghiem nghien cuu: ";
            cin >> soNamLamViec;
            cin.ignore(); 
        }
        
        void xuatThongTinNhanSu()  const override{
            NhanSu::xuatThongTinNhanSu();
            cout << "Cac ma du an giao duc da hoan thanh: ";
            for(string x : danhSachMaDuAnHoanThanh) cout << x << ", ";
            cout << "\nSo nam kinh nghiem lam viec: " << soNamLamViec << endl;
        }
};