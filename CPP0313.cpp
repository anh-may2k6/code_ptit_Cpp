#include <iostream>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,x;
    getline(cin ,s);
    cin >> x;
    stringstream ss(s);
    string temp;
    while(ss >> temp){
        if(temp == x){
            continue;
        }
        cout << temp << " ";
    }
    return 0;
}