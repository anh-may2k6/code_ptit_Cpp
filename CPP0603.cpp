#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

struct SinhVien{
    string name,lop,date;
    float gpa;
};

istream& operator >> (istream &in , SinhVien &a){
    getline(in,a.name);
    getline(in,a.lop);
    getline(in,a.date);
    in >> a.gpa;
    in.ignore();
    return in;
}

ostream& operator << (ostream &out,SinhVien &a){
    string d,m,y;
    stringstream ss_1(a.date);
    getline(ss_1,d,'/');
    getline(ss_1,m,'/');
    getline(ss_1,y);
    if(d.size() == 1) d = "0" + d;
    if(m.size() == 1) m = "0" + m;

    for(auto &x : a.name){
        x = tolower(x);
    }
    stringstream ss_2(a.name);
    string temp,name ="";
    while(ss_2 >> temp){
        temp[0] = toupper(temp[0]);
        name += temp;
        name += " ";
    }
    out << "B20DCCN001" << " " << name << a.lop
    << " " << d << "/" << m << "/" << y << " " <<
    fixed << setprecision(2) << a.gpa << endl;
    return out;
}

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}