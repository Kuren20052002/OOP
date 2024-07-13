#include "NhanSu.h"

int main(){
    vector<NhanSu*> danhSachNhanSu;

    int soLuongNhanSu = 0;
    cout << "Nhap so luong nhan su trong doi ngu: ";
    cin >> soLuongNhanSu;
    cin.ignore();

    for(int i = 0; i < soLuongNhanSu; i++){
        cout << "Nhap thong tin cho nhan su thu " << i + 1 << ": \n";
        cout << "Chon loai nhan su (1: Giang vien, 2: Tro giang, 3: Nghien cuu vien, 4: Chuyen vien): ";
        int loai = 0;
        cin >> loai;
        cin.ignore();

        GiangVien* gv;
        TroGiang* tv;
        NghienCuuVien* ncv;
        ChuyenVien* cv;

        switch (loai) {
            case 1: 
                gv = new GiangVien("", "", "", "", "", 0, {});
                gv->nhapThongTinNhanSu();
                danhSachNhanSu.push_back(gv);
                break;
            case 2:
                tv = new TroGiang("", "", "", 0);
                tv->nhapThongTinNhanSu();
                danhSachNhanSu.push_back(tv);
                break;
            case 3:
                ncv = new NghienCuuVien("", "", "", {}, 0);
                ncv->nhapThongTinNhanSu();
                danhSachNhanSu.push_back(ncv);
                break;
            case 4:
                cv = new ChuyenVien("", "", "", {}, 0);
                cv->nhapThongTinNhanSu();
                danhSachNhanSu.push_back(cv);
                break;
            default:
                cout << "Loai nhan su khong hop le, xin thu lai.\n";
                i--;
                break;
        }
    }

    double tongLuong = 0;
    for(auto nhanSu : danhSachNhanSu){
        tongLuong += nhanSu->tinhLuong();
    }
    cout << "Tong luong cac nhan su truong dai hoc phai tra: " << tongLuong << endl;

    for(auto nhanSu : danhSachNhanSu){
        delete nhanSu;
    }

    return 0;
}