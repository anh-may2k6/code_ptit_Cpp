#include <iostream>

using namespace std;
using ll = long long;

ll GCD(ll a, ll b){
    if(b==0) return a;
    return GCD(b,a%b);
}

class PhanSo{
private:
    ll tu,mau;
public:
    PhanSo (){
        tu = 0;
        mau = 1;
    }
    PhanSo (ll t,ll m){
        tu = t;
        mau = (m==0 ? 1 : m);
    }
    friend istream& operator >> (istream& in,PhanSo &p);
    friend ostream& operator << (ostream& out,const PhanSo &p);

    PhanSo operator+(const PhanSo &other) const{
        ll t = tu*other.mau + mau*other.tu;
        ll m = mau*other.mau;
        ll s = GCD(t,m);
        t /= s;
        m /= s;
        return PhanSo(t,m);
    }
};

istream& operator >> (istream& in,PhanSo &p){
    in >> p.tu >> p.mau;
    return in;
}

ostream& operator << (ostream& out,const PhanSo &p){
    out << p.tu << "/" << p.mau << endl;
    return out;
}

int main(){
    PhanSo p(1,1),q(1,1);
    cin >> p >> q;
    cout << p + q;
    return 0;
}