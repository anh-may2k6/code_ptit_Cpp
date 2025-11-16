#include <iostream>
#include <vector>
#include <stack>

using namespace std;

inline void nhap(vector<vector<int>> &a , int n , int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
}

int Max_S(vector<int> &h){
    int n = h.size();
    stack<int> st;
    int max_area = 0;

    for(int i=0;i<=n;i++){
        int height = (i == n ? 0 : h[i]);
        while(!st.empty() && height < h[st.top()]){
            int top = st.top();
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area , width * h[top]);
        }
        st.push(i);
    }
    return max_area;
}

void test_case(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> a(n,vector<int> (m));
    nhap(a,n,m);
    
    vector<int> height(m,0);
    int max_rect = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        max_rect = max(max_rect , Max_S(height));         
    }
    cout << max_rect << "\n";
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