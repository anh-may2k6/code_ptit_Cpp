#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

struct SinhVien{
    string name,lop,date;
    float gpa;
    void nhap(){
        getline(cin , name);
        getline(cin , lop);
        getline(cin , date);
        cin >> gpa;
        cin.ignore();
    }
    void xuat(){
        string d,m,y;
        stringstream ss(date);
        getline(ss,d,'/');
        getline(ss,m,'/');
        getline(ss,y);
        if(d.size() == 1) d = "0" + d;
        if(m.size() == 1) m = "0" + m;
        cout << "B20DCCN001" << " " << name << " " <<
        lop << " " << d << "/" << m << "/" << y <<
        " " << fixed << setprecision(2) << gpa; 
    }
};


int main(){
    SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}