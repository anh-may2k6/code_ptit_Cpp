#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

//đề bài ko cho gán i thì mình tạo stt tăng dần từ biến toàn cục
int idx = 0;

class SinhVien{
    string id = "B20DCCN" , name , date , lop;
    float gpa;
public:
    //cho phép truy cập bên trong private
    friend istream &operator >> (istream &in,SinhVien &a);
    friend ostream &operator << (ostream &out,SinhVien &a);
};

//nạp toán tử chồng chất
istream &operator >> (istream &in , SinhVien &a){
    ostringstream tmp;
    tmp << setw(3) << setfill('0') << ++idx;
    string id = tmp.str();
    a.id += id;

    in.ignore();
    getline(in , a.name);
    in >> a.lop >> a.date;
    in >> a.gpa;
    return in;
}

ostream &operator << (ostream &out , SinhVien &a){
    string d,m,y;
    stringstream ss(a.date);
    
    getline(ss , d , '/');
    getline(ss , m , '/');
    getline(ss , y);

    if(d.size() == 1) d = '0' + d;
    if(m.size() == 1) m = '0' + m;

    out << a.id << " " << a.name << " " << a.lop <<
    " " << d << "/" << m << "/" << y << " " <<
    fixed << setprecision(2) << a.gpa << endl;
    return out;
}


int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> ds[i];
    }
    for(int i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}