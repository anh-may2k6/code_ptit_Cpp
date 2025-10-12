#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool chia_8(int num){
    return num%8 == 0;
}

void test_case(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    vector<int> a(n+1 , 0);
    for(int i=0;i<n;i++){
        a[i+1] = (a[i] + (s[i] - '0')) % 3;
    }
    for(int i=0;i<n;i++){
        int num = 0;
        for(int j=i;j<n;j++){
            num = num * 10 + (s[j]-'0');
            int sum_3 = (a[j+1] - a[i] + 3) % 3;
            if(chia_8(num) && sum_3 != 0){
                cnt++;
            }
        }
    }
    cout << cnt << endl; 
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