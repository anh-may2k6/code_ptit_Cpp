#include <iostream>

using namespace std;
using ll = long long;

ll GCD(ll a,ll b){
    if(b==0) return a;
    return GCD(b,a%b);
}

struct PhanSo{
    ll tu,mau;
};

void rutgon(PhanSo &a){
    ll t = GCD(a.tu,a.mau);
    a.tu /= t;
    a.mau /= t;
}

void nhap(PhanSo &a){
    cin >> a.tu >> a.mau;
}

PhanSo tong(PhanSo a,PhanSo b){
    PhanSo t;
    t.tu = a.tu*b.mau + b.tu*a.mau;
    t.mau = a.mau*b.mau;
    rutgon(t);
    return t;
}

void in(PhanSo a){
    cout << a.tu << "/" << a.mau;
}

int main(){
    struct PhanSo p,q;
    nhap(p); nhap(q);
    PhanSo t = tong(p,q);
    in(t);
    return 0;
}