#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double distance(double a,double b,double c, double d){
    double x = (c-a) * (c-a);
    double y = (d-b) * (d-b);
    return sqrt(x+y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        double a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << fixed << setprecision(4) << distance(a,b,c,d) << endl;
    }
    return 0;
}