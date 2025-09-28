#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

struct SinhVien{
    string id = "B20DCCN" , name , lop ,  date;
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

void sapxep(SinhVien a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j].gpa > a[i].gpa){
                swap(a[i],a[j]);
            }
        }
    }
}

void in(SinhVien a[],int n){
    for(int i=0;i<n;i++){
        for(auto &x : a[i].name){
            x = tolower(x);
        }

        stringstream ss_name(a[i].name);
        string d, m , y , tmp , name = "";
        while(ss_name >> tmp){
            tmp[0] = toupper(tmp[0]);
            name += (tmp+" ");
        }
        
        stringstream ss_date(a[i].date);
        getline(ss_date , d , '/');
        getline(ss_date , m , '/');
        getline(ss_date , y);
        if(d.size() == 1) d = '0' + d;
        if(m.size() == 1) m = '0' + m;

        cout << a[i].id << " " << name << a[i].lop <<
        " " << d << "/" << m << "/" << y << " " <<
        fixed << setprecision(2) << a[i].gpa << endl;
    }
}

int main(){
    struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    sapxep(ds, N);
    in(ds, N);
    return 0;
}