#include <iostream>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        int dem = 0;
        string s;
        getline(cin , s);
        stringstream ss(s);
        string temp;
        while(ss >> temp){
            dem++;
        }
        cout << dem << endl;
    }   
    return 0;
}