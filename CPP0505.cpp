#include <iostream>
#include <sstream>

using namespace std;

struct NhanVien{
    string name;
    string sex;
    string date;
    string addr;
    string code;
    string nkhd;
};

void nhap(struct NhanVien &a){
    getline(cin , a.name);
    getline(cin , a.sex);
    getline(cin, a.date);
    getline(cin, a.addr);
    getline(cin , a.code);
    getline(cin , a.nkhd);
}

void in(struct NhanVien a){
    cout << "00001" << " " << a.name << " " << a.sex
    << " " << a.date << " " << a.addr << " " << a.code
    << " " << a.nkhd;
}

int main(){
    struct NhanVien a;
    nhap(a);
    in(a);
    return 0;
}