#include <iostream>
#include <map>

using namespace std;

void test_case(){
    int n,x;
    cin >> n >> x;
    map<int,int> s;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        s[k]++;
    }
    bool check = false;
    for(auto i : s){
        if(i.first == x){
            check = true;
            cout << i.second << endl;
            break;
        }
    }
    if(!check){
        cout << "-1" << endl;
    }
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