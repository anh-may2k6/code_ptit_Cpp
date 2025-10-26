#include <iostream>
#include <string>

using namespace std;

string modBig(string a , string b);

int cmp(string a , string b){
    if(a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    if(a==b) return 0;
    return a < b ? -1 : 1;
}


string substract(string a ,string b){
    //hàm trừ 2 số từ phải qua trái
    string res = "";
    int carry = 0;
    while(a.size() > b.size()) b = "0" + b;
    for(int i=a.size()-1;i>=0;i--){
        int x = (a[i] - '0') - (b[i]-'0') - carry;
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

string modBig(string a ,string b){
    string cur = "";
    for(char c:a){
        cur += c;
        //nếu 0 có j or 0 ở đầu thì mình xóa 0
        while(cur.size() > 1 && cur[0] == '0') cur.erase(0,1);
        //phép chia là phép trừ nhiều lần 
        while(cmp(cur , b) >=0){ //nếu mà cur mà lớn hơn b thì trừ đi
            cur = substract(cur , b);
        }
    }
    if(cur == "") cur = "0";
    return cur;
}

string gcdBig(string a , string b){
    if(b=="0") return a;
    // modBig(a,b) == a%b
    return gcdBig(b,modBig(a,b));
}

void test_case(){
    string a,b;
    cin >> a >> b;
    cout << gcdBig(a,b) << endl;
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