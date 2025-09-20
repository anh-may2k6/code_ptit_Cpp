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

PhanSo sum(PhanSo &A, PhanSo &B){
    PhanSo C;
    ll x = A.tu * B.mau + B.tu * A.mau;
    ll y = A.mau * B.mau;
    ll USCLN = GCD(x,y);
    ll a = x/USCLN;
    ll b = y/USCLN;
    C.tu = a*a;
    C.mau = b*b;
    return C;
}

void process(PhanSo &A , PhanSo &B){
    PhanSo C = sum(A,B);
    ll x = A.tu * B.tu * C.tu;
    ll y = A.mau * B.mau * C.mau;
    ll USCLN = GCD(x,y);
    cout << C.tu << "/" << C.mau << " " << x/USCLN
    << "/" << y/USCLN << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        PhanSo A;
        PhanSo B;
        cin >> A.tu >> A.mau >> B.tu >> B.mau;
        process(A, B);
    }
}