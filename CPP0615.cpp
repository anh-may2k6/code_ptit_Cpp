#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <algorithm>

using namespace std;

int idx = 0;

class NhanVien{
    string id , name , gender , date , addr , code , day;
public:
    friend istream &operator >> (istream &in , NhanVien &a);
    friend ostream &operator << (ostream &out , NhanVien &a);   
    friend void sapxep(NhanVien a[],const int n);
    friend bool cmp(const NhanVien &a,const NhanVien &b);
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

bool cmp(const NhanVien &a,const NhanVien &b){
    int da,ma,ya,db,mb,yb;
    char sep;
    stringstream ss_a(a.date);
    ss_a >> ma >> sep >> da >> sep >> ya;

    stringstream ss_b(b.date);
    ss_b >> mb >> sep >> db >> sep >> yb;

    if(ya != yb) return ya < yb;
    if(ma != mb) return ma < mb;
    return da < db;
}

void sapxep(NhanVien a[],int n){
    sort(a,a+n,cmp);
}

int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> ds[i];
    sapxep(ds, N);
    for(i=0;i<N;i++) cout << ds[i];
    return 0;
}