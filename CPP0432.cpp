#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparetor(const string &a,const string &b){
    return a+b > b+a;
}

void test_case(){
    int n;
    cin >> n;
    vector<string> a;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(to_string(x));
    }
    sort(a.begin(),a.end(),comparetor);
    for(auto x : a){
        cout << x;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}