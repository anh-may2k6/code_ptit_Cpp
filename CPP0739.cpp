#include <iostream>
#include <stack>

using namespace std;

void test_case(){
    string a;
    cin >> a;
    int n = a.size();

    stack<int> st;
    for(int i=0;i<=n;i++){
        st.push(i+1); //lưu các số từ 1-9
        // nếu băng I or nếu i == n thì in ra luôn 
        if(a[i] == 'I' || i == n){
            while(!st.empty()){
                cout << st.top(); // in từ đỉnh
                st.pop(); // xóa từ đỉnh 
            }
        }
    }
    cout << endl;
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