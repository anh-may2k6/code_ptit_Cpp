#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

struct SinhVien{
    string ma_sv,name,lop,date;
    float gpa;
};

void nhapThongTinSV(SinhVien &a){
    a.ma_sv = "N20DCCN001";
    getline(cin , a.name);
    cin >> a.lop >> a.date >> a.gpa;
}

void inThongTinSV(const SinhVien &a){
    string d,m,y;
    stringstream ss(a.date);
    getline(ss , d , '/');
    getline(ss, m , '/');
    getline(ss , y);
    if(d.size() == 1) d = "0" + d;
    if(m.size() == 1) m = "0" + m;
    cout << a.ma_sv << " " << a.name << " " <<
    a.lop << " " << d << "/" << m << "/" << y << " " << 
    fixed << setprecision(2) << a.gpa;
}


int main(){
    struct SinhVien a;
    nhapThongTinSV(a);
    inThongTinSV(a);
    return 0;
}