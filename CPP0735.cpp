#include <iostream>
#include <vector>
#include <stack>

using namespace std;

inline void nhap(vector<vector<int>> &a, int n , int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
}

int level_matrix(vector<int> &h){
    stack<int> st;
    int max_lv = 0;
    int n = h.size();

    for(int i=0;i<=n;i++){
        int height = (i == n ? 0 : h[i]);
        while(!st.empty() && height < h[st.top()]){
            int top = st.top();
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;
            int size = min(h[top] , width);
            max_lv = max(max_lv , size);
        }
        st.push(i);
    }
    return max_lv;
}

void test_case(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int> (m));
    nhap(a,n,m);

    vector<int> height(m);
    int max_lv = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        max_lv = max(max_lv , level_matrix(height));
    }
    cout << max_lv << "\n";
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