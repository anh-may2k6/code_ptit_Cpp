#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class GiangVien{
    string stt , name , mon , ten;
public:
    friend void nhap(GiangVien a[],int n);
    friend bool cmp(GiangVien &a,GiangVien &b);
    friend void in(GiangVien a[],int n);
};

void nhap(GiangVien a[],int n){
    for(int i=0;i<n;i++){
        a[i].stt = "GV";
        if(i+1 < 10){
            a[i].stt+= '0';
        }
        a[i].stt += to_string(i+1);
        getline(cin , a[i].name);
        getline(cin , a[i].mon);

        stringstream ss_1(a[i].name);
        string tmp;
        while(ss_1 >> tmp){
            a[i].ten = tmp;
        }
    }
}

bool cmp(GiangVien &a,GiangVien &b){
    if(a.ten == b.ten) return a.stt < b.stt;
    return a.ten < b.ten;
}

void sap_xep(GiangVien a[],int n){
    sort(a,a+n,cmp);
}

void in(GiangVien a[],int n){
    for(int i=0;i<n;i++){
        string MON = "",name_MON = a[i].mon;
        for(auto &x : name_MON) x = toupper(x);
        stringstream ss(name_MON);
        string tmp;
        while(ss >> tmp){
            MON += tmp[0];
        }
        cout << a[i].stt << " " << a[i].name << " "
        << MON << endl; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();
    GiangVien *a = new GiangVien[n];
    nhap(a,n);
    sap_xep(a,n);
    in(a,n);
    delete[] a;
    return 0;
}