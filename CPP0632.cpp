#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;
using ll = long long;

int idx_kh = 0 , idx_mh = 0 , idx_hd = 0;

class KhachHang{
    string id , name , gender , date , addr;
public:
    static KhachHang ds[25];
    static int n;
    friend istream &operator >> (istream &in , KhachHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_kh;
        a.id = "KH" + tmp.str();

        if(in.peek() == '\n') in.ignore();
        getline(in , a.name);
        getline(in , a.gender);
        getline(in , a.date);
        getline(in , a.addr);

        ds[n++] = a;
        return in;
    }
    string get_id(){return id;}
    string get_name(){return name;}
    string get_addr(){return addr;}
    friend class HoaDon;
};
KhachHang KhachHang::ds[25];
int KhachHang::n=0;

class MatHang{
    string id , name , dvt;
    int buy , pass;
public:
    static MatHang ds[45];
    static int n;
    friend istream &operator >> (istream &in , MatHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_mh;
        a.id = "MH" + tmp.str();

        if(in.peek() == '\n') in.ignore();
        getline(in , a.name);
        getline(in , a.dvt);
        in >> a.buy >> a.pass;
        in.ignore();

        ds[n++] = a;
        return in;
    }
    string get_id(){return id;}
    string get_name(){return name;}
    string get_dvt(){return dvt;}
    int get_buy(){return buy;}
    int get_pass(){return pass;}
    friend class HoaDon;
};
MatHang MatHang::ds[45];
int MatHang::n=0;

class HoaDon{
    string id_hd , id_kh , id_mh;
    int sl;
public:
    string name_mh;
    ll loi_nhuan;
    friend istream &operator >> (istream &in , HoaDon &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_hd;
        a.id_hd = "HD" + tmp.str();
        in >> a.id_kh >> a.id_mh >> a.sl;

        for(int i=0;i<MatHang::n;i++){
            if(a.id_mh == MatHang::ds[i].get_id()){
                a.loi_nhuan = 1LL * a.sl *
                    (MatHang::ds[i].get_pass() - MatHang::ds[i].get_buy());
                break;
            }
        }
        return in;
    }
    friend ostream &operator << (ostream &out , HoaDon &a){
        KhachHang kh;
        MatHang mh;
        for(int i=0;i<KhachHang::n;i++){
            if(a.id_kh == KhachHang::ds[i].get_id()) kh = KhachHang::ds[i];
        }
        for(int i=0;i<MatHang::n;i++){
            if(a.id_mh == MatHang::ds[i].get_id()) mh = MatHang::ds[i];
        }
        ll sum = 1LL*a.sl*mh.get_pass();
        out << a.id_hd << " " << kh.get_name() << " " << kh.get_addr()
            << " " << mh.get_name() << " " << a.sl << " "
            << sum << " " << a.loi_nhuan << '\n';
        return out;
    }
    friend bool operator < (HoaDon &a,HoaDon &b){
        if(a.loi_nhuan != b.loi_nhuan) return a.loi_nhuan > b.loi_nhuan;
        for(int i=0;i<MatHang::n;i++){
            if(a.id_mh == MatHang::ds[i].get_id()) a.name_mh = MatHang::ds[i].get_name();
        }
        for(int i=0;i<MatHang::n;i++){
            if(b.id_mh == MatHang::ds[i].get_id()) b.name_mh = MatHang::ds[i].get_name();
        }
        return a.name_mh > b.name_mh;
    }
};

void sapxep(HoaDon dshd[] , int K){
    sort(dshd , dshd + K);
}

int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];

    sapxep(dshd, K);
    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}
