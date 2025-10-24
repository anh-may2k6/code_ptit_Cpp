#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
using ll = long long;

int idx_1 = 0;
int idx_2 = 0;
int idx_3 = 0;

class KhachHang {
    string id = "KH", name, gender, date, addr;
public:
    static KhachHang ds[25];
    static int n;

    friend istream &operator>>(istream &in, KhachHang &a) {
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_1;
        a.id += tmp.str();
        in.ignore();
        getline(in, a.name);
        in >> a.gender >> a.date;
        in.ignore();
        getline(in, a.addr);
        ds[n++] = a;
        return in;
    }

    friend class HoaDon;
};

KhachHang KhachHang::ds[25];
int KhachHang::n = 0;

class MatHang {
    string id = "MH", name, dvt;
    int buy, pass;
public:
    static MatHang ds[45];
    static int n;

    friend istream &operator>>(istream &in, MatHang &a) {
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_2;
        a.id += tmp.str();
        in.ignore();
        getline(in, a.name);
        in >> a.dvt >> a.buy >> a.pass;
        ds[n++] = a;
        return in;
    }

    friend class HoaDon;
};

MatHang MatHang::ds[45];
int MatHang::n = 0;

class HoaDon {
    string id_hd = "HD", id_kh, id_mh;
    int sl;
public:
    friend istream &operator>>(istream &in, HoaDon &a) {
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_3;
        a.id_hd += tmp.str();
        in >> a.id_kh >> a.id_mh >> a.sl;
        return in;
    }

    friend ostream &operator<<(ostream &out, HoaDon &a) {
        KhachHang kh;
        MatHang mh;

        for (int i = 0; i < KhachHang::n; i++) {
            if (a.id_kh == KhachHang::ds[i].id)
                kh = KhachHang::ds[i];
        }
        for (int i = 0; i < MatHang::n; i++) {
            if (a.id_mh == MatHang::ds[i].id)
                mh = MatHang::ds[i];
        }

        ll total = 1LL * a.sl * mh.pass;
        out << a.id_hd << " " << kh.name << " " << kh.addr << " "
            << mh.name << " " << mh.dvt << " "
            << mh.buy << " " << mh.pass << " "
            << a.sl << " " << total << "\n";
        return out;
    }
};

int main() {
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N, M, K, i;
    cin >> N;
    for (i = 0; i < N; i++) cin >> dskh[i];
    cin >> M;
    for (i = 0; i < M; i++) cin >> dsmh[i];
    cin >> K;
    for (i = 0; i < K; i++) cin >> dshd[i];

    for (i = 0; i < K; i++) cout << dshd[i];
    return 0;
}
