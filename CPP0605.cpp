#include <iostream>

using namespace std;
using ll = long long;

ll GCD(ll a,ll b){
    if(b==0) return a;
    return GCD(b,a%b);
}

class PhanSo{
private:
    ll tu,mau;
public:
    PhanSo(){
        tu = 0;
        mau = 1;
    }

    PhanSo(ll t, ll m){
        tu = t;
        mau = (m==0 ? 1: m);
    }
    friend istream& operator >> (istream &in,PhanSo &a);
    friend ostream& operator << (ostream &out,const PhanSo &a);

    void rutgon(){
        ll hehe = GCD(tu,mau);
        tu /= hehe;
        mau /= hehe;
    }
};

istream& operator >> (istream& in,PhanSo &a){
    in >> a.tu >> a.mau;
    return in;
}

ostream& operator << (ostream& out,const PhanSo &a){
    out << a.tu << "/" << a.mau << endl;
    return out;
}

int main(){
    PhanSo p(1,1);
    cin >> p;
    p.rutgon();
    cout << p;
    return 0;
}