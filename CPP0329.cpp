#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//đổi string về vector nó sẽ tối ưu hơn
vector<int> to_vector(string &a){
    vector<int> res;
    for(char c : a){
        res.push_back(c - '0');
    }
    return res;
}
//so sánh 2 vector
bool cmp(vector<int> &a , vector<int> &b){
    if(a.size() != b.size()) return a.size() > b.size();
    for(size_t i=0;i<a.size();i++){
        if(a[i] != b[i]){
            return a[i] > b[i];
        }
    }
    return true;
}
//trừ 2 vector
vector<int> substract(vector<int> a , vector<int> &b){
    int carry = 0;
    int n = a.size();
    int m = b.size();

    for(int i=0;i<n;i++){
        //duyệt từ cuối lên đầu
        int idxA = n - 1 - i;
        int idxB = m - 1 - i;

        int digitB = (idxB >= 0) ? b[idxB] : 0;
        a[idxA] -=digitB + carry;

        if(a[idxA] < 0){
            a[idxA] += 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
    }

    while(a.size() > 1 && a[0] == 0){
        a.erase(a.begin());
    }
    return a; 
}
//X\Y
string div(string a, string b){
    if(a == "0") return "0";
    
    vector<int> num = to_vector(a);
    vector<int> demon = to_vector(b);

    string result;
    vector<int> cur;

    for(int digit : num){
        cur.push_back(digit);
        //xóa 0 ở đầu
        while(cur.size() > 1 && cur[0] == 0){
            cur.erase(cur.begin());
        }
        //đếm số lần trừ
        int count = 0;
        while(cmp(cur,demon)){
            cur = substract(cur,demon);
            count++;
        }
        result += to_string(count);
    }
    size_t pos = result.find_first_not_of('0');
    return (pos != string::npos) ? result.substr(pos) : "0";
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