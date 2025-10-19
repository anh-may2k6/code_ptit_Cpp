#include <iostream>

using namespace std;
using ll = long long;

ll det(int a1 , int b1 , int c1 , int a2 , int b2 , 
        int c2 , int a3 , int b3 , int c3){
    ll ans = (ll)(a1 * (b2*c3 - b3*c2)
                - a2 * (b1*c3 - b3*c1)
                + a3 * (b1*c2 - b2*c1));
    return ans;
}

void test_case(){
    int x1 , y1 , z1 , x2 , y2 , z2 , x3 , y3 , z3 ,
    x4 , y4 , z4;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >>
    y3 >> z3 >> x4 >> y4 >> z4;
    //ta có 3 vector là AB AC AD 
    ll ans = det(x2-x1 , y2-y1 , z2-z1 , x3-x1 , 
           y3-y1 , z3-z1 , x4-x1 , y4-y1 , z4-z1);
    if(ans == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
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