#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

class Student;

class Class{
    private:
        vector<Student> Students;
    public:
        void addStudentToClass();
        void removeStudentFromClass();
        void outputClassMembers();
        void outputGoodStudents();
        void addStudentFromFile();
        void sortMembersByName();
};

void Class::addStudentToClass(){
    Student newStudent;
    cout << "Nhap du lieu cua hoc sinh them vao lop: \n";
    newStudent.inputStudentData();
    Students.push_back(newStudent);
}

void Class::removeStudentFromClass(){
    cout << "Nhap ten hoc sinh can bi xoa: ";
    string gone;
    getline(cin, gone);

    for(int i = 0; i < Students.size(); i++){
        if(Students[i].getName() == gone){
            Students.erase(Students.begin() + i);
            cout << "\nHoc sinh " << gone <<" da bi kick.\n";
            return;
        }
    }
    cout << "Khong co hoc sinh " << gone << " trong lop: \n";
}

void Class::outputClassMembers(){
    cout << "Lop co " << Students.size() << " hoc sinh: \n";
    for(auto i : Students) i.outputStudentData();
}

void Class::outputGoodStudents(){
    cout << "Cac sinh vien co diem trung binh hon 8 la: \n";
    for(auto i : Students){
        if(i.getAvgGrade() > 8) i.outputStudentData();
    }
}

void Class::addStudentFromFile(){
    ifstream inputClassFile("LopHoc.txt");

    if(inputClassFile.is_open()){
        int n = 0;
        inputClassFile >> n;
        cout << endl << "n = " << n << endl;
        inputClassFile.ignore();

        for(int i = 0; i < n; i++){
            Student A;
            string tempName;
            float tempGrade;

            getline(inputClassFile, tempName);
            A.setName(tempName);

            tempName.clear();
            inputClassFile >> tempName;
            A.setID(tempName);

            tempName.clear();
            inputClassFile >> tempName;
            A.setPhoneNumber(tempName);

            inputClassFile >> tempGrade;
            A.setAvgGrade(tempGrade);
            inputClassFile.ignore();

            Students.push_back(A);
        }  
    }
    else cout << "\nMo file khong thanh cong.\n";
}

void Class::sortMembersByName(){
    
}