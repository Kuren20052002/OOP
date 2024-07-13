#include <iostream>
#include <math.h>
#include <vector>
#include <ctime>
using namespace std;

bool isPrime(int n);
void quicksort(vector<int>& v, int start, int end);
int partition(vector<int>& v, int start, int end);

class MangMotChieu{
    private:
        vector<int> v;
    public:
        void sort();
        void fillRan();
        void xuat();
        void countnum();
        void isascend();
        int smolodd();
        int bigprime();
};

void MangMotChieu::fillRan(){
    srand(time(0));
    int size = 1 + rand() % 400;
    for(int i = 0; i < size; i++) this->v.push_back(rand() % 100000000);
}

void MangMotChieu::xuat(){
    cout <<"\nMang co cac phan tu: \n";
    for(int i : this->v) cout << i << " ";
    cout << "\n"; 
}

void MangMotChieu::sort(){
    quicksort(this->v, 0, this->v.size() - 1);
}

void MangMotChieu::countnum(){
    int x = 0, count = 0;
    cout << "\nNhap so can dem: \n";
    cin >> x;
    for(int i : this->v){
        if(i == x) count++;
    }
    cout << "Co " << count << " so " << x << " trong vector.\n";
}

void MangMotChieu::isascend(){
    int size = this->v.size() - 1;
    for(int i = 0; i < size; i++){
        if(v[i] < v[i + 1]){
            cout << "Day so nguyen nay khong theo thu tu tang dan.\n";
            return;
        }
    }
    cout << "Day so nguyen nay theo thu tu tang dan. \n";
}

int MangMotChieu::smolodd(){
    int smol = 999;
    for(int i : v){
        if(i % 2 == 1)
            if(i < smol) smol = i; 
    }
    return smol;
}

int MangMotChieu::bigprime(){
    quicksort(this->v, 0, this->v.size() - 1);
    int end = this->v.size() - 1;
    for(int i = end; i >= 0; i--){
        if(isPrime(v[i])) return v[i];
    }
    return -1;
}

bool isPrime(int n){
    if(n < 2) return false;
    if(n < 4) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i*i < n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int partition(vector<int>& v, int start, int end){
    int pivot = v[end];
    int j = start - 1;

    for(int i = start; i <= end; i++){
        if(v[i] < pivot){
            j++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    j++;
    int temp = v[j];
    v[j] = v[end];
    v[end] = temp;
    return j;
}

void quicksort(vector<int>& v, int start, int end){
    if(end <= start) return;
    int pivot = partition(v, start, end);
    quicksort(v, start, pivot - 1);
    quicksort(v, pivot + 1, end);
}