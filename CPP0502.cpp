#include <iostream>
#include <iomanip>

using namespace std;

struct ThiSinh{
    string name;
    string date;
    float a,b,c;
};

float tong(float a,float b,float c){
    return a+b+c;
}

void nhap(struct ThiSinh &A){
    getline(cin , A.name);
    getline(cin, A.date);
    cin >> A.a >> A.b >> A.c;
}

void in(struct ThiSinh A){
    cout << A.name << " " << A.date << " " << fixed << setprecision(1) << tong(A.a,A.b,A.c) << endl;
}

int main(){
    struct ThiSinh A;
    nhap(A);
    in(A);    
    return 0;
}