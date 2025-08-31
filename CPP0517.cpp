#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct NhanVien{
    string name;
    string sex;
    string date;
    string addr;
    string code;
    string nkhd;
};

void nhap(NhanVien &ds){
    scanf("\n"); // chỉ loại bỏ dấu xuống dòng duy nhất ở cin >> t;
    getline(cin , ds.name);
    getline(cin , ds.sex);
    getline(cin , ds.date);
    getline(cin , ds.addr);
    getline(cin , ds.code);
    getline(cin , ds.nkhd);
}

void inds(NhanVien ds[],int N){
    for(int i=0;i<N;i++){
        cout << setw(5) << setfill('0') << i+1  << " " << // in ra id với 5 chữ số
        ds[i].name << " " << ds[i].sex << " " <<
        ds[i].date << " " << ds[i].addr << " " <<
        ds[i].code << " " << ds[i].nkhd << endl;
    }
}


int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(int i=0; i < N; i++) nhap(ds[i]);
    inds(ds,N);
    return 0;
}