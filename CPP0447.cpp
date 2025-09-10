#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<k;i++){
        cout << v[i] << " ";
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