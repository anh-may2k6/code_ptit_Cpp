#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();
    map<string,int> a;
    while(n--){
        string s;
        getline(cin , s);
        a[s]++;
    }
    cout << a.size() << endl;
    return 0;
}