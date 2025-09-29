#include <iostream>
#include <limits>
#include <vector>
#include <sstream>

using namespace std;

class SinhVien{
    int khoa;
    string id , name , lop , email;
public:
    friend istream &operator >> (istream &in , SinhVien &a);
    friend ostream &operator << (ostream &out , SinhVien &a);

    int Year(){
        return khoa;
    }
};

istream &operator >> (istream &in,SinhVien &a){
    in >> a.id;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in , a.name);
    in >> a.lop >> a.email;
    int year;
    stringstream ss(a.lop.substr(1,2));
    ss >> year;
    a.khoa = 2000 + year;
    return in;
}

ostream &operator << (ostream &out,SinhVien &a){
    out << a.id << " " << a.name << " " << a.lop
    << " " << a.email << endl;
    return out;  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<SinhVien> sv;
    SinhVien tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        sv.push_back(tmp);
    }
    int t;
    cin >> t;
    int year;
    while(t--){
        cin >> year;
        cout << "DANH SACH SINH VIEN KHOA " << year << ":" << endl;
        for(auto &x : sv){
            if(x.Year() == year){
                cout << x;
            }
        }
    }
    return 0;
}