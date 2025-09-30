#include <iostream>
#include <algorithm>

using namespace std;

int idx = 0;

struct SinhVien{
    int stt;
    string id , name , lop , email , dn;
};

void nhap(SinhVien a[],int n){
    for(int i=0;i<n;i++){
        a[i].stt = ++idx;
        cin >> a[i].id;
        cin.ignore();
        getline(cin , a[i].name);
        cin >> a[i].lop >> a[i].email >> a[i].dn;
    }
}

bool cmp(SinhVien &a,SinhVien &b){
    return a.name < b.name;
}

void in(SinhVien &a){
    cout << a.stt << " " << a.id << " " << a.name
    << " " << a.lop << " " << a.email << " " <<
    a.dn << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n;
    SinhVien *a = new SinhVien[n];

    nhap(a,n);
    sort(a,a+n,cmp);

    cin >> q;
    string tmp;
    while(q--){
        cin >> tmp;
        for(int i=0;i<n;i++){
            if(a[i].dn == tmp){
                in(a[i]);
            }
        }
    }
    return 0;
}