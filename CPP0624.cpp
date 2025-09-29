#include <bits/stdc++.h>
using namespace std;

class SinhVien {
    string id, name, lop, email;
public:
    friend istream &operator >> (istream &in, SinhVien &a) {
        getline(in, a.id);
        getline(in, a.name);
        getline(in, a.lop);
        getline(in, a.email);
        return in;
    }
    friend ostream &operator << (ostream &out, const SinhVien &a) {
        out << a.id << " " << a.name << " " << a.lop << " " << a.email << "\n";
        return out;
    }
    string Nganh() const { return id.substr(5, 2); }
    string Lop() const { return lop; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, string> fullName = {
        {"KT", "KE TOAN"},
        {"CN", "CONG NGHE THONG TIN"},
        {"AT", "AN TOAN THONG TIN"},
        {"VT", "VIEN THONG"},
        {"DT", "DIEN TU"}
    };

    int n; cin >> n;
    cin.ignore();
    vector<SinhVien> sv(n);
    for (int i = 0; i < n; i++) cin >> sv[i];

    int t; cin >> t; cin.ignore();
    while (t--) {
        string NGANH;
        getline(cin, NGANH);
        for (auto &x : NGANH) x = toupper(x);
        cout << "DANH SACH SINH VIEN NGANH " << NGANH << ":\n";
        for (auto &x : sv) {
            string ng = x.Nganh();
            if (fullName[ng] == NGANH) {
                if ((ng == "CN" || ng == "AT") && x.Lop()[0] == 'E') continue;
                cout << x;
            }
        }
    }
    return 0;
}
