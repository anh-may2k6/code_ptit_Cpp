#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int idx = 0;

struct NhanVien{
    string id = "" , name , gender , date , addr , code , date_of;
};

bool cmp(NhanVien &a,NhanVien &b){
    int da , ma, ya , db , mb , yb;
    char sep;
    
    stringstream ss_a(a.date);
    ss_a >> ma >> sep >> da >> sep >> ya;

    stringstream ss_b(b.date);
    ss_b >> mb >> sep >> db >> sep >> yb;

    if(ya != yb) return ya < yb;
    if(ma != mb) return ma < mb;
    return da < db;
}

void nhap(NhanVien &a){
    ostringstream tmp;
    tmp << setw(5) << setfill('0') << ++idx; // phải dùng biến toàn cục , vì đề bài yêu cầu ko đc dùng biến cục bộ để làm id
    a.id += tmp.str();

    cin.ignore();
    getline(cin , a.name);
    cin >> a.gender >> a.date;
    cin.ignore();

    getline(cin , a.addr);
    cin >> a.code >> a.date_of;      
}

void sapxep(NhanVien a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(!cmp(a[i],a[j])){
                swap(a[i],a[j]);
            }
        }
    }
}

void inds(NhanVien a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i].id << " " << a[i].name << " "
        << a[i].gender << " " << a[i].date << " "
        << a[i].addr << " " << a[i].code << " "
        << a[i].date_of << endl;
    }
}

int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    sapxep(ds, N);
    inds(ds, N);
    return 0;
}