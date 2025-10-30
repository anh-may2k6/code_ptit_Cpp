//tham khảo nguồn thì phải thêm nhập xuất trên file mới AC đc 
#include <iostream>
#include <fstream>

using namespace std;

#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

inline void test_case() {
    string s; cin >> s;
    string res;
    for (char c : s) {
        res.push_back(c);
        if (res.size() >= 3 && res.substr(res.size() - 3) == "100") {
            res.erase(res.end() - 3, res.end());
        }
    }
    cout << s.size() - res.size() << '\n';
}

int main() {
    faster();
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int t; cin >> t;
    while (t--) test_case();
    return 0;
}