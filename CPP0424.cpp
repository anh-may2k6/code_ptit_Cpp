#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,k;
    cin >> t;
    while(t--){
        cin >> k >> n;
        vector<int> v;
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                int x;
                cin >> x;
                v.push_back(x);
            }
        }
        sort(v.begin(),v.end());
        int l = v.size();
        for(int i=0;i<l;i++){
            cout << v[i];
            if(i == l-1){
                break;
            }
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}