#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

class sinhvien{
    string id , name , lop , email;
public :
    friend istream &operator >> (istream &in , sinhvien &a);
    friend ostream &operator << (ostream &out , sinhvien &a);
    friend bool cmp(const sinhvien &a,const sinhvien &b);
};

vector<sinhvien> sv;

istream &operator >> (istream &in,sinhvien &a){
    in >> a.id;
    in.ignore(numeric_limits<streamsize>::max() , '\n');
    getline(in , a.name);
    in >> a.lop >> a.email;
    return in;
}

ostream &operator << (ostream &out,sinhvien &a){
    out << a.id << " " << a.name << " " << a.lop
    << " " << a.email << endl;
    return out;
}

bool cmp(const sinhvien &a,const sinhvien &b){
    return a.id < b.id;
}

void sap_xep(vector<sinhvien> &a){
    sort(a.begin(),a.end(),cmp);    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sinhvien tmp;
    while(cin >> tmp){
        sv.push_back(tmp);
    }
    sap_xep(sv);
    for(auto x : sv){
        cout << x;
    }
    return 0;
}