#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
using db = double;

struct point{
    int x,y;
};

void test_case(){
    int n;
    cin >> n;
    vector<point> x(n);
    for(int i=0;i<n;i++){
        cin >> x[i].x >> x[i].y;
    }
    db S = 0;
    for(int i=0;i<n;i++){
        int j = (i+1)%n;
        S += (x[i].x*x[j].y) - (x[j].x * x[i].y);
    }
    S = fabs(S) / 2.0;
    cout << fixed << setprecision(3) << S << "\n";
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