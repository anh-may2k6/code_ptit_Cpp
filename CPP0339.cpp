#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int l = s.size();
        vector<int> check(l);
        int dem = l;
        for(int i=0;i<l;i++){
            if(check[i]) continue;
            for(int j=i+1;j<l;j++){
                if(j==i) continue;
                if(s[j] == s[i]){
                    dem++;
                    check[j] == 1;
                }
            }
        }
        cout << dem << endl;
    }
    return 0;
}