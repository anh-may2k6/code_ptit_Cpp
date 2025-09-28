#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int idx = 0;

class GiangVien{
    string id = "GV" , name , bomon , mon;
public:
    friend istream &operator >> (istream &in , GiangVien &a){
        getline(in , a.name);
        getline(in , a.bomon);


        if(idx + 1 < 10){
            a.id += '0';
        }
        a.id += to_string(++idx);
        stringstream ss(a.bomon);
        string tmp , MON = "";
        
        while(ss >> tmp){
            MON += toupper(tmp[0]);
        }
        a.mon = MON;
        return in; 
    }
    friend ostream &operator << (ostream &out , GiangVien &a){
        out << a.id << " " << a.name << " " <<
        a.mon << endl;
        return out; 
    }
    string MON(){
        return mon;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();
    vector<GiangVien> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int t;
    cin >> t;
    cin.ignore();
    string str;
    while(t--){
        getline(cin , str);
        stringstream ss_str(str);
        string tmp , MON = "";
        while(ss_str >> tmp){
            MON += toupper(tmp[0]);
        }
        cout << "DANH SACH GIANG VIEN BO MON " << MON << ":\n";
        for(auto &x : a){
            if(x.MON() == MON){
                cout << x;
            }
        }
    }
    return 0;
}