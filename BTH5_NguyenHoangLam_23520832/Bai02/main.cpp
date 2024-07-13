#include "GiaSuc.h"

void thongKe(const std::vector<GiaSuc*> nongTrai){
    for(auto gs : nongTrai){
        gs->thongKe();
    }
}

int main(){
    std::vector<GiaSuc*> nongTrai = {new Bo, new Cuu, new De};
    for(auto gs : nongTrai){
        gs->nhapGiaSuc();
        gs->choSua();
    }

    std::cout << "\nSau mot ngay di vang, cac tieng keu: \n";
    for(auto gs : nongTrai) gs->tiengKeu();

    std::cout << "\nSau mot luoc sinh con va cho sua: \n";
    for(auto gs : nongTrai){
        gs->sinhCon();
        gs->thongKe();
    }
    
}