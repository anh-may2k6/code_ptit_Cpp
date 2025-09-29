#include <iostream>

using namespace std;

void test_case(){
    string n;
    cin >> n;
    int l = n.size();
    int sum = 0;
    for(int i=0;i<l;i++){
        sum += (n[i] - '0');
    }
    if(sum == 0){
        cout << "0" << endl;
        return;
    }
    if(sum % 9 == 0){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl;
    }
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