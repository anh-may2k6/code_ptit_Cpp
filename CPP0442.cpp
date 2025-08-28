#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(){
    int n,x;
    cin >> n >> x;
    vector<int> v;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    auto i = find(v.begin(),v.end(),x);
    if(i!=v.end()){
        cout << "1" << endl;
    }
    else{
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