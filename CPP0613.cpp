#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <limits>

using namespace std;

int idx = 0;

class SinhVien{
    string id , name , lop , date;
    float gpa;
public:
    friend istream &operator >> (istream &in , SinhVien &a);
    friend ostream &operator << (ostream &out , SinhVien &a);

    friend bool cmp(SinhVien &a,SinhVien &b);
};

istream &operator >> (istream &in ,SinhVien &a){
    ostringstream tmp;
    tmp << "B20DCCN" << setw(3) << setfill('0') << ++idx;
    a.id = tmp.str();
    //Bỏ ký tự xuống dòng còn lại trước khi getline(để không đọc rỗng)
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in , a.name);
    in >> a.lop >> a.date;
    in >> a.gpa;
    return in;
}

ostream &operator << (ostream &out , SinhVien &a){
    string name = a.name;
    for(auto &x : name) x = tolower(x);

    stringstream ss_name(name);
    string tmp , Name = "";
    while(ss_name >> tmp){
        tmp[0] = toupper(tmp[0]);
        Name += (tmp + " ");
    }
    Name.pop_back(); // Bỏ khoảng trắng cuối

    string d,m,y;
    stringstream ss_date(a.date);
    getline(ss_date , d , '/');
    getline(ss_date , m , '/');
    getline(ss_date , y);

    if(d.size() == 1) d = '0' + d;
    if(m.size() == 1) m = '0' + m;

    out << a.id << " " << Name << " " << a.lop << " " <<
    d << "/" << m << "/" << y << " " << fixed <<
    setprecision(2) << a.gpa << endl;
    return out;
}

bool cmp(SinhVien &a,SinhVien &b){
    return a.gpa > b.gpa;
}

void sapxep(SinhVien a[] ,int n){
    sort(a,a+n,cmp);
}

int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    sapxep(ds, N);
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}