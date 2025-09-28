#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DoanhNghiep{
    string id , name;
    int so_sv;
public:
    friend istream &operator >> (istream &in , DoanhNghiep &a){
        getline(in , a.id);
        getline(in , a.name);
        in >> a.so_sv;
        in.ignore();
        return in;
    }
    friend ostream &operator << (ostream &out , DoanhNghiep &a){
        out << a.id << " " << a.name << " " << a.so_sv
        << endl;
        return out;
    }
    friend bool cmp(DoanhNghiep &a,DoanhNghiep &b);
};

bool cmp(DoanhNghiep &a, DoanhNghiep &b){
    if(a.so_sv == b.so_sv) return a.id < b.id;
    return a.so_sv > b.so_sv;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();
    vector<DoanhNghiep> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        cout << a[i];
    }
    return 0;
}