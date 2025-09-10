#include <iostream>
#include <vector>

using namespace std;

void test_case(){
    string s;
    cin >> s;
    int n = s.size();

    int i = n-2;
    while(i>=0 && s[i] <= s[i+1]) i--;
    if(i<0){
        cout << "-1" << endl;
        return;
    }

    int j = n-1;
    char a = '0';
    int pos = -1;
    for(int k=n-1;k>i;k--){
        if(s[k] < s[i] && s[k] >= a){
            a = s[k];
            pos = k;
        }
    }
    swap(s[i],s[pos]);
    if(s[0] == '0'){
        cout << "-1" << endl;
        return;
    }
    cout << s << endl;
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