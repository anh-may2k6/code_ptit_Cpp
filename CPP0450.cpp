#include <iostream>
#include <unordered_set>

using namespace std;

void test_case(){
    int n, num=-1;
    cin >> n;
    unordered_set<int> s;    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(num == -1){
            if(s.count(x)){
                num = x;
            }
            else{
                s.insert(x);
            }
        }
    }
    cout << num << endl;
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