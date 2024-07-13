#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Student{
    private:
        string name;
        string id;
        string phoneNumber;
        float avgGrade;
    public:
        void setName(string &n);
        void setID(string &s);
        void setPhoneNumber(string &pn);
        void setAvgGrade(float &g);
        void inputStudentData();
        void outputStudentData();
};

void Student::setName(string &n){
    for(int i = 0; i < n.length(); i++){
        if(!isalpha(n[i]) && n[i] != ' '){
            cout << "Ten khong hop le, vui long nhap lai: \n";
            n.clear();
            getline(cin, n);
            i = -1;
        } 
    }
    name = n;
}

void Student::setID(string &s){
    for(int i = 0; i < 8; i++){
        if(!isdigit(s[i]) || (s.length() != 8)){
            cout << "Ma so khong hop le, vui long nhap lai: \n";
            cin >> s;   
            i = 0;
        } 
    }
    id = s;
}

void Student::setPhoneNumber(string &pn){
    for(int i = 0; i < 8; i++){
        if((!isdigit(pn[i])) || (pn.length() < 9 || pn.length() > 11)){
            cout << "So dien thoai khong hop le, vui long nhap lai: \n";
            cin >> pn;   
            i = 0;
        }
    }
    phoneNumber = pn;
}

void Student::setAvgGrade(float &g){
    while(g < 0 || g > 10){
        cout << "So diem khong hop le, vui long nhap lai: \n"; 
        cin >> g;
    }
    avgGrade = g;
}

void Student::inputStudentData(){
    string temp;

    cout << "Nhap ten hoc sinh: \n";
    getline(cin, temp);
    setName(temp);

    cout << "Nhap ma so hoc sinh: \n";
    temp.clear();
    cin >> temp;
    setID(temp);

    cout << "Nhap so dien thoai lien lac: \n";
    temp.clear();
    cin >> temp;
    setPhoneNumber(temp);

    float grade = 0;
    cout << "Nhap diem trung binh: \n";
    cin >> grade;
    setAvgGrade(grade);
    cin.ignore();
}

void Student::outputStudentData(){
    cout << "\nTen hoc sinh: " << name << '\n';

    cout << "Ma so hoc sinh: " << id << '\n';

    cout << "So dien thoai lien lac: " << phoneNumber << '\n';

    cout << "Diem trung binh: " << avgGrade << "\n\n";
}