#include <iostream>
#include <algorithm>

using namespace std;

string hieu(string &a,string &b){
    if(a.size() > b.size() || (a.size() == b.size() && a > b)){
        swap(a,b);
    }
    // đảo ngược 2 chuỗi dể ta trừ dần từ đầu xuống cho dễ
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int nho = 0;
    string ans = "";
    for(int i=0;i<(int)b.size();i++){
        // nếu i mà vượt quá size của a thì đưa về giá trị là 0
        int x = (i<(int)a.size() ? a[i] - '0' : 0);
        int y = (b[i] - '0') - nho;
        if(x > y){
            nho = 1;
            y += 10;
        }
        else{
            nho = 0;
        }
        ans.push_back(char('0' +(y-x)));
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void test_case(){
    string a,b;
    cin >> a >> b;
    cout << hieu(a,b) << endl;
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