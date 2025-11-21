#include <iostream>
#include <string>

using namespace std;
//sum 2 số lớn
string add(string a , string b){
    if(a.size() < b.size()) swap(a,b);
    while(a.size() != b.size()) b = "0" + b;
    
    int n = a.size();
    int carry = 0;
    string res(n,'0');
    for(int i=n-1;i>=0;i--){
        carry += ((a[i] - '0') + (b[i] - '0'));
        res[i] = (carry % 10) + '0';
        carry /= 10;
    }
    if(carry > 0){
        res = to_string(carry) + res;
    }
    return res;
}

string test(string s , int n){
    //dùng quy hoạch động để tạo 1 mảng 2 chiều chứa các mod và chỉ số số chia hết
    string a[1000][1000];
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            a[i][j] = "0";
        }
    }
    a[0][(s[0] - '0')%n] = add(a[0][(s[0] - '0')%n] , "1");
    for(int i=1;i<s.size();i++){
        a[i][(s[i] - '0')%n] = add(a[i][(s[i] - '0')%n] , "1");
        for(int j=0;j<n;j++){
            a[i][j] = add(a[i][j] , a[i-1][j]);
            a[i][(j*10 + (s[i] - '0')) % n] = add(a[i][(j*10 + (s[i] - '0')) % n] , a[i-1][j]);
        }
    }
    //trả về tất cả các số chia dư cho n = 0
    return a[s.size()-1][0];
}

void test_case(){
    int x,n;
    cin >> x >> n;
    string s;
    cin >> s;
    cout << test(s,n) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}