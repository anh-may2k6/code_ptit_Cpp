#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void test_case(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int l = v.size();
    int min_sum = v[0]+v[1];
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            int sum = v[i] + v[j];
            if(abs(sum) < abs(min_sum)){
                min_sum = sum;
            }
        }
    }
    cout << min_sum << endl;
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