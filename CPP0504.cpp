#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

struct SinhVien{
    string name;
    string lop;
    string date;
    float gpa;
};

void nhap(struct SinhVien &a){
    getline(cin , a.name);
    getline(cin, a.lop);
    getline(cin , a.date);
    cin >> a.gpa;
}

void in(struct SinhVien a){
    string d,m,y;
    stringstream ss(a.date);
    getline(ss , d ,'/');
    getline(ss, m ,'/');
    getline(ss, y);
    if(d.size() == 1) d = "0" + d;
    if(m.size() == 1) m = "0" + m;
    cout << "B20DCCN001" << " " << a.name << " " <<
    a.lop << " " << d << "/" << m << "/" << y << " "
    << fixed << setprecision(2) << a.gpa << endl;    
}

int main(){
    struct SinhVien a;
    nhap(a);
    in(a);
    return 0;
}