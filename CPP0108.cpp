#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}


int n,ans;

void so_tang(int last , string s){
    if((int)s.size() == n){
        if(s[0] != '0'){
            int num = stoi(s);
            if(prime(num)) ans++;
        }
        return;
    }
    for(int d = last + 1;d < 10; d++){
        so_tang(d,s + char('0' + d));
    }
}

void so_giam(int last,string s){
    if((int)s.size() == n){
        if(s[0] != '0'){
            int num = stoi(s);
            if(prime(num)) ans++;
        }
        return;
    }
    for(int d = last - 1; d >= 0 ; d--){
        so_giam(d,s + char('0' + d));
    }
}

void test_case(){
    cin >> n;
    ans = 0;
    so_tang(0,"");
    so_giam(10,"");
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