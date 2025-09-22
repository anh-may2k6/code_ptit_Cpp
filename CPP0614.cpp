#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;

int idx = 0;

class NhanVien{
    string id , name , gender , date , addr , code , day;
public:
    friend istream &operator >> (istream &in , NhanVien &a);
    friend ostream &operator << (ostream &out , NhanVien &a);   
};

istream &operator >> (istream &in , NhanVien &a){
    ostringstream tmp;
    tmp << setw(5) << setfill('0') << ++idx;
    a.id = tmp.str();
    //loại bỏ tất cả dấu xuống dòng trc khi getline
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in , a.name);
    in >> a.gender >> a.date;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in , a.addr);
    in >> a.code >> a.day;
    return in;
}   

ostream &operator << (ostream &out , NhanVien &a){
    out << a.id << " " << a.name << " " << a.gender
    << " " << a.date << " " << a.addr << " " <<
    a.code << " " << a.day << endl;
    return out;
}

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}