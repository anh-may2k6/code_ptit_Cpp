#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

struct SinhVien{
    string name,lop,date;
    float gpa;
};

istream& operator >> (istream& in,SinhVien &a){
    getline(in,a.name);
    getline(in,a.lop);
    getline(in,a.date);
    in >> a.gpa;
    in.ignore();
    return in;
}

ostream& operator << (ostream& out,SinhVien &a){
    string d,m,y;
    stringstream ss(a.date);
    getline(ss , d , '/');
    getline(ss , m , '/');
    getline(ss , y);
    if(d.size() == 1) d = "0" + d;
    if(m.size() == 1) m = "0" + m;
    out << "B20DCCN001" << " " << a.name << " " << 
    a.lop << " " << d << "/" << m << "/" << y <<
    " " << fixed << setprecision(2) << a.gpa << endl;
    return out;
}

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}