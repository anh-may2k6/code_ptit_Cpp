#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class sinhvien{
    string id , name , lop , email;
public :
    friend istream &operator >> (istream &in , sinhvien &a);
    friend ostream &operator << (ostream &out , sinhvien &a);
    string getlop () const {
        return lop;
    }
};

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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,t;
    cin >> n;
    vector<sinhvien> sv;
    for(int i=0;i<n;i++){
        sinhvien x;
        cin >> x;
        sv.push_back(x);
    }
    cin >> t;
    string tmp;
    while(t--){
        cin >> tmp;
        cout << "DANH SACH SINH VIEN LOP " << tmp << ":" << endl;
        for(auto &x : sv){
            if(x.getlop() == tmp){
                cout << x;
            }
        }
    }
    return 0;
}