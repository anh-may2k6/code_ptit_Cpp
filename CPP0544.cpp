#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
using db = double;

#define PI 3.141592653589793238

struct toado{
    db x,y;
};

bool check(db a,db b,db c){
    if(a + b <= c || a + c <= b || b + c <= a) return false;
    return true;
}

db S_dtron(db a,db b,db c){
    db S = sqrt((a+b+c) * (a+b-c) * (b+c-a) * (c+a-b))/4;
    db R = (a * b * c)/(4*S);
    return PI*R*R;
}

void test_case(){
    toado a,b,c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    db x = sqrt(pow((b.x - a.x) , 2) + pow((b.y - a.y),2));
    db y = sqrt(pow((c.x - b.x) , 2) + pow((c.y - b.y),2));
    db z = sqrt(pow((c.x - a.x) , 2) + pow((c.y - a.y),2));
    
    if(check(x,y,z)){
        cout << fixed << setprecision(3) << S_dtron(x,y,z) << endl;         
    }
    else{
        cout << "INVALID" << endl;
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