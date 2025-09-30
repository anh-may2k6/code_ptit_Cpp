#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin >> t;
    while(t--){
        map<int,int> a;
        int x,dem = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x;
            a[x]++;
        }
        for(auto y : a){
            if(y.second == 1) continue;
            dem+=y.second;
        }
        cout << dem << endl;
    }
    return 0;
}