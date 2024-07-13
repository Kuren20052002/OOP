#include <iostream>
#include <string>
#include <vector>
#include <ctime>

long randomNumber(int min, int max){
    srand(time(0));
    return (rand() % (max + 1 - min)) + min;
}

int randomNumber(){
    srand(time(0));
    return rand() % 51;
}

class GiaSuc{
    protected:
        int soCon;
        long soLitSua;
    public:
        GiaSuc() : soCon(0), soLitSua(0) {}

        virtual void thongKe() const{};

        void sinhCon(){
            int limit = soCon;
            for(int i = 0; i < limit; i++){
                soCon += randomNumber(1, 2);
            }
        }
        virtual void choSua(){
            for(int i = 0; i < soCon; i++){
                soLitSua += randomNumber();
            }
        }
        virtual void tiengKeu() const {
            for(int i = 1; i <= soCon; i++){
                std::cout << "Meow\n";
            }
        }
        virtual void nhapGiaSuc(){
            std::cout << "Nhap so luong gia suc: ";
            std::cin >> soCon;
        }
};

class Bo : public GiaSuc{
    public:
        Bo() : GiaSuc() {} 

        void thongKe() const override{
            std::cout << "So con bo trong trang trai la: " << soCon << std::endl;
            std::cout << "So sua bo da cho ra la: " << soLitSua << std::endl;
        }

        void choSua() override{
            for(int i = 0; i < soCon; i++){
                soLitSua += randomNumber(0, 20);
            }
        }

        void tiengKeu() const override{
            for(int i = 1; i <= soCon; i++){
                std::cout << "Boooooooooo\n";
            }
        }

        void nhapGiaSuc() override{
            std::cout << "Nhap so luong bo: ";
            std::cin >> soCon;
        }
};

class Cuu : public GiaSuc{
    public:
        Cuu() : GiaSuc() {} 

        void thongKe() const override{
            std::cout << "So con cuu trong trang trai la: " << soCon << std::endl;
            std::cout << "So sua cuu da cho ra la: " << soLitSua << std::endl;
        }

        void choSua() override{
            for(int i = 0; i < soCon; i++){
                soLitSua += randomNumber(0, 5);
            }
        }

        void tiengKeu() const override{
            for(int i = 1; i <= soCon; i++){
                std::cout << "Cuuuuuuuuuu\n";
            }
        }

        void nhapGiaSuc() override{
            std::cout << "Nhap so luong cuu: ";
            std::cin >> soCon;
        }
};

class De : public GiaSuc{
    public:
        De() : GiaSuc() {} 

        void thongKe() const override{
            std::cout << "So con de trong trang trai la: " << soCon << std::endl;
            std::cout << "So sua de da cho ra la: " << soLitSua << std::endl;
        }

        void choSua() override{
            for(int i = 0; i < soCon; i++){
                soLitSua += randomNumber(0, 10);
            }
        }

        void tiengKeu() const override{
            for(int i = 1; i <= soCon; i++){
                std::cout << "Deeeeeeeeee\n";
            }
        }

        void nhapGiaSuc() override{
            std::cout << "Nhap so luong de: ";
            std::cin >> soCon;
        }

};