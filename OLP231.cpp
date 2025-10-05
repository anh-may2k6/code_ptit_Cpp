#include <iostream>
#include <vector>

using namespace std;

//tìm các ước số nguyên tố
vector<int> prime(int x){
    vector<int> res;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            res.push_back(i);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res.push_back(x);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> primes;
    vector<bool> used(m+1 , false);
    vector<bool> bad(m+1 , false);

    for(int i=0;i<n;i++){
        vector<int> ps = prime(a[i]);
        for(int x : ps){
            if(!used[x] && x<=m){
                used[x] = true; // xuấ hiện số nt rồi thì ko lặp lại 
                primes.push_back(x);
            }
        }
    }
    for(int x : primes){
        for(int i=x;i<=m;i+=x){
            bad[i] = true;
        }
    }

    vector<int> ans;
    for(int i=1;i<=m;i++){
        if(!bad[i]){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x << " ";
    }
    return 0;
}