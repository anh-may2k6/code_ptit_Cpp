#include <iostream>
#include <algorithm>

using namespace std;

struct TIME{
    int gio , phut , giay;
};

void nhap(TIME &a){
    cin >> a.gio >> a.phut >> a.giay;
}

bool cmp(TIME &a,TIME &b){
    if(a.gio != b.gio) return a.gio < b.gio;
    if(a.phut != b.phut) return a.phut < b.phut;
    return a.giay < b.giay;
}

void in(TIME a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i].gio << " " << a[i].phut <<
        " " << a[i].giay << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    TIME *t = new TIME[n];

    for(int i=0;i<n;i++){
        nhap(t[i]);
    }
    sort(t,t+n,cmp);
    in(t,n);
    return 0;
}