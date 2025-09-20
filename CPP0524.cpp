#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct SinhVien{
    string id , name , lop;
    float x,y,z;
};

void nhap(SinhVien &a){
    cin >> a.id;
    cin.ignore();
    getline(cin , a.name);
    cin >> a.lop >> a.x >> a.y >> a.z;
}

bool cmp(SinhVien &a,SinhVien &b){
    return a.id < b.id;
}

void sap_xep(SinhVien a[] ,int n){
    sort(a,a+n,cmp);
}

void in_ds(SinhVien a[],int n){
    for(int i=0;i<n;i++){
        cout << i+1 << " " << a[i].id << " " <<
        a[i].name << " " << a[i].lop << " " << 
        fixed << setprecision(1) << a[i].x << " " <<
        a[i].y << " " << a[i].z << endl; 
    }
}



int main(){
    int n;
    cin >> n;
    struct SinhVien *ds = new SinhVien[n];
    for(int i = 0; i < n; i++) {
    	nhap(ds[i]);
	}
	sap_xep(ds, n);
    in_ds(ds,n);
    return 0;
}
