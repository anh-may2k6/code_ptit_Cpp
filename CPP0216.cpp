#include <iostream>
#include <vector>

using namespace std;

bool mountain(vector<int> &v,int l,int r){
    int i = l;
    while(i < r && v[i] <= v[i+1]) i++;
    while(i < r && v[i] >= v[i+1]) i++;
    return (i == r);
}

void test_case(){
    int n,l,r;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> l >> r;
    if(mountain(v,l,r)){
        cout << "Yes";
    }
    else{
        cout << "No";
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