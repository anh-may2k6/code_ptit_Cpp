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
    string NAME(){
        return name;
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
        string tmp_str = "";
        getline(cin , str);
        cout << "DANH SACH GIANG VIEN THEO TU KHOA " << str << ":\n";
        for(auto &x : str) tmp_str += tolower(x);
        for(auto &x : a){
            string tmp_name = "";
            for(auto &y : x.NAME()) tmp_name += tolower(y);
            // đưa hết về chữ in thường rồi sau đó dùng find để tìm xem trong tên có từ khóa ko
            if(tmp_name.find(tmp_str) != string::npos){
                // nếu có thì in , ko thì pass 
                cout << x;
            }
        }
    }
    return 0;
}