#include <iostream>
#include <string>

using namespace std;

bool check(string &s){
    int l = s.size(),sum_1 = 0 , sum_2 = 0;
    for(int i=0;i<l;i++){
        if(i%2==0){
            sum_2+=int(s[i] - '0');
        }
        else{
            sum_1+=int(s[i] - '0');
        }
    }
    if((sum_2 - sum_1)%11 != 0) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        cin >> s;
        if(check(s)){
            cout << "1";
        }
        else{
            cout << "0";
        }
        cout << endl;
    }
    return 0;
}