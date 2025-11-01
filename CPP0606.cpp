#include <iostream>
#include <iomanip>

using namespace std;

class NhanVien{
private:
    string name,gender,date,addr,id,time;
public:
    friend istream& operator >> (istream& in,NhanVien &a);
    friend ostream& operator >> (ostream& out,const NhanVien &a);
};

istream& operator >> (istream& in,NhanVien &a){
    getline(in,a.name);
    in >> a.gender;
    in.ignore();
    getline(in,a.date);
    getline(in,a.addr);
    in >> a.id;
    in.ignore();
    getline(in,a.time);
    return in;
}

ostream& operator >> (ostream& out,const NhanVien &a){
    out << setw(5) << setfill('0') << 1 << " " <<
    a.name << " " << a.gender << " " << a.date <<
    " " << a.addr << " " << a.id << " " << a.time;
    return out;
}

int main(){
    NhanVien a;
    cin >> a;
    cout >> a;
    return 0;
}