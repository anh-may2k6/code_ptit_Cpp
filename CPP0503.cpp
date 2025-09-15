#include <iostream>

using namespace std;
using ll = long long;

struct PhanSo{
    ll tu,mau;
};

ll GCD(ll a,ll b){
    if(b==0) return a;
    return GCD(b,a%b);
}

void nhap(struct PhanSo &p){
    cin >> p.tu >> p.mau;
}

void rutgon(struct PhanSo &p){
    ll s = GCD(p.tu,p.mau);
    p.tu /= s;
    p.mau /= s;
}

void in(struct PhanSo p){
    cout << p.tu << "/" << p.mau << endl;
}


int main(){
    struct PhanSo p;
    nhap(p);
    rutgon(p);
    in(p);
    return 0;
}