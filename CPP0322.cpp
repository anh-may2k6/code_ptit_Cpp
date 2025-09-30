#include <iostream>
#include <algorithm>

using namespace std;

string sum(string &a,string &b){
    string x = a , y = b;
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());

    string ans = "";
    int nho = 0;

    int n = max(x.size(),y.size());

    for(int i=0;i<n;i++){
        int num_1 = (i < (int)x.size() ? x[i] - '0' : 0);
        int num_2 = (i < (int)y.size() ? y[i] - '0' : 0);
        int sum = num_1 + num_2 + nho;

        ans.push_back(char('0' + (sum%10)));
        nho = sum/10;
    }
    if(nho){
        ans.push_back(char('0' + nho));
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


void test_case(){
    string a,b;
    cin >> a >> b;
    cout << sum(a,b) << endl;
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