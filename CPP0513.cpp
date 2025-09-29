#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

struct SinhVien{
    string id = "B20DCCN";
    string name , lop , date;
    float gpa;
};

void nhap(SinhVien a[],int n){
    for(int i=0;i<n;i++){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << i+1;
        a[i].id += tmp.str();
        cin.ignore();
        getline(cin , a[i].name);
        cin >> a[i].lop >> a[i].date >> a[i].gpa;
    }
}

void in(SinhVien a[],int n){
    for(int i=0;i<n;i++){
        string d,m,y;
        stringstream ss(a[i].date);
        getline(ss , d , '/');
        getline(ss , m , '/');
        getline(ss , y);
        if(d.size() == 1) d = '0' + d;
        if(m.size() == 1) m = '0' + m;
        
        cout << a[i].id << " " << a[i].name << " "
        << a[i].lop << " " << d << "/" << m << "/"
        << y << " " << fixed << setprecision(2) <<
        a[i].gpa << endl;
    }
}

int main(){
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds , N);
    in(ds , N);
    return 0;
}