#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point{
    double x,y;
};

void input(struct Point &A){
    cin >> A.x >> A.y;
}

double distance(struct Point A,struct Point B){
    double d = sqrt((B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y));
    return d;    
}

int main(){
    struct Point A,B;
    int t;
    cin >> t;
    while(t--){
        input(A); input(B);
        cout << fixed << setprecision(4) << distance(A,B) << endl;
    }
    return 0;
}