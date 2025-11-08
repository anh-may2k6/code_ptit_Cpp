#include <iostream>
#include <string>

using namespace std;

int cmp(string a,string b){
    if(a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    if(a == b) return 0;
    return a < b ? -1 : 1;
}

string substract(string a , string b){
    string res = "";
    int carry = 0;
    while(a.size() > b.size()) b = "0" + b;
    for(int i=a.size()-1;i>=0;i--){
        int x = (a[i]-'0') - (b[i]-'0') - carry;
        if(x<0){
            x += 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        res = char(x+'0') + res;
    }
    while(res.size() > 1 && res[0] == '0') res.erase(0,1);
    return res;
}

string div(string a, string b){
    if(a == "0") return "0";
    if(cmp(a,b) < 0) return "0";

    string cur = "" , res = "";
    for(char c:a){
        int num = 0;
        cur += c;
        while(cur.size() > 1 && cur[0] == '0') cur.erase(0,1);
        while(cmp(cur , b) >= 0){
            cur = substract(cur , b);
            num++;
        }
        res += to_string(num);
    }
    while(res.size() > 1 && res[0] == '0') res.erase(0,1);
    return res;
}

void test_case(){
    string x,y;
    cin >> x >> y;
    cout << div(x,y) << "\n";
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