#include <iostream>
#include <string>

using namespace std;

string add(string a , string b){
    if(a.length() < b.length()) swap(a,b);
    while(a.length() != b.length()) b = "0" + b;
    string c(a.length(),'0');
    int nho = 0;
    for(int i=a.length()-1;i>=0;i--){
        nho += ((a[i] - '0') + (b[i] - '0'));
        c[i] = (nho % 10) + '0';
        nho /= 10;
    }
    if(nho > 0){
        c = to_string(nho) + c;
    }
    return c;
}

bool TF(string a , string b , string s){
    int x = a.length() + b.length();
    while(x < s.length()){
        string c = add(a,b);
        string d = s.substr(x , c.length());
        if(c == d){
            a = b;
            b = c;
            x += c.length();
        }
        else{
            return false;
        }
    }
    return true;
}

void test_case(){
    string s , a;
    cin >> s;
    for(int i=0;i<=s.length()/2;i++){
        a.push_back(s[i]);
        string b;
        for(int j=i+1;j<=s.length() * 2 / 3 ; j++){
            b.push_back(s[j]);
            if(TF(a,b,s)){
                cout << "Yes" << "\n";
                return;
            }
        }   
    }
    cout << "No" << "\n";
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