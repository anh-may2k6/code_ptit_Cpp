#include <iostream>
#include <vector>

using namespace std;

void test_case(){
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int l = 0 , r = n-1 , dem = 0;
    while(l<r){
        if(v[l] == v[r]){
            l++;r--;
        }
        else if(v[l] < v[r]){
            v[l+1] += v[l];
            l++;
            dem++;
        }
        else{
            v[r-1] += v[r];
            r--;
            dem++;
        }
    }
    cout << dem << endl;
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