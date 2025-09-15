#include <iostream>
#include <climits>

using namespace std;

void test_case(){
    string s;
    cin >> s;
    
    int num = 0 , ans = INT_MIN , l = s.size();
    bool check = false;
    for(int i=0;i<l;i++){
        if(!check){
            ans = max(ans,num);
            num = 0;
        }
        if(isdigit(s[i])){
            num = (num*10 + (s[i] - '0'));
            check = true;
        }
        else{
            check = false;
        }
    }
    ans = max(ans,num);
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