#include <iostream>
#include <vector>

using namespace std;

void test_case(){
    string a,b;
    cin >> a >> b;
    int n = a.length() , m = b.length();
    if(n == 0 || m == 0){
        cout << "0" << endl;
        return;
    }
    vector<int> res(n+m,0);    
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int mul = (a[i]-'0') * (b[j]-'0');
            int sum = res[i+j+1] + mul;
            res[i+j+1] = sum%10;
            res[i+j] += sum/10;
        }
    }
    //chuyển vector sang string
    string ans = "";
    int i = 0;
    while(i<res.size() && res[i] == 0){
        i++;
    }
    for(;i<res.size();i++){
        ans += (res[i] +'0');
    }
    cout << ans << endl;
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