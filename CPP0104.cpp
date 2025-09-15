#include <iostream>
    
    using namespace std;
    using ll = long long;
    
    ll sum(int n){
        ll sum = 0;
        ll t = 1;
        for(int i=1;i<=n;i++){
            t*=i;
            sum+=t;
        }
        return sum;
    }
    
    int main(){
        int n;
        cin >> n;
        cout << sum(n) << endl;
        return 0;
    }
