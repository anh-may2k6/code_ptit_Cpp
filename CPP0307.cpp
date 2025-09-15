#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    string s1,s2;
    while(t--){
        getline(cin , s1);
        getline(cin , s2);

        stringstream ss1(s1);
        stringstream ss2(s2);
        // dùng set để lưu các giá trị không trùng và được sắp xếp theo thứ tự từ điển
        set<string> v1,v2;
        
        string temp2;
        while(ss2 >> temp2){
            v2.insert(temp2);
        }
        
        string temp1;
        while(ss1 >> temp1){
            bool check = false;
            for(auto x : v2){
                if(temp1 == x){
                    check = true;
                    break;
                }
            }
            if(!check){
                v1.insert(temp1);
            }
        }
        for(auto x : v1){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}