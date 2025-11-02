//bài này vì sai số quá lớn nên ta phải dùng ull or i128
//Chú ý ép kiểu
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int SCALE = 10000;

//biến đổi chuỗi thành số nguyên lớn
//example : 12345,6789 -> 123456789
ll parse_scaled(const string &s) {
    bool neg = false;
    int pos = 0;
    if (s[pos] == '+' || s[pos] == '-') { if (s[pos] == '-') neg = true; pos++; }
    ll intpart = 0;
    while (pos < (int)s.size() && s[pos] != '.') {
        intpart = intpart * 10 + (s[pos] - '0');
        pos++;
    }
    //giá trị sau dấu . 4 đơn vị
    ll frac = 0;
    int digits = 0;
    if (pos < (int)s.size() && s[pos] == '.') {
        pos++;
        while (pos < (int)s.size() && digits < 4) {
            frac = frac * 10 + (s[pos] - '0');
            pos++; digits++;
        }
    }
    //nếu đầu vào mà ch đến 4 chữ số thì ta thêm 0 vào cuối
    while (digits < 4) { frac *= 10; digits++; }
    ll scaled = intpart * (ll)SCALE + frac;
    if (neg) scaled = -scaled;
    return scaled;
}

//làm tròn xuống
ll div_floor_ll(ll a, ll b) {
    ll q = a / b;
    // Nếu a và b khác dấu và có dư, thì phép chia của C++ sẽ làm lệch sàn, nên cần --q để lấy floor
    if ((a ^ b) < 0 && a % b) --q;
    return q;
}
//làm tròn lên
ll div_ceil_ll(ll a, ll b) {
    ll q = a / b;
    //cùng dấu thì + 1
    if ((a ^ b) >= 0 && a % b) ++q;
    return q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sx, sy, sr;
    if (!(cin >> sx >> sy >> sr)) return 0;

    ll X = parse_scaled(sx);
    ll Y = parse_scaled(sy);
    ll R = parse_scaled(sr);

    ll xmin = div_ceil_ll(X - R, SCALE);
    ll xmax = div_floor_ll(X + R, SCALE);

    //khả năng sai số khá cao nên ta đặt luôn ull cho r^2
    ull R2 = (ull)R * (ull)R;

    ull cnt = 0;

    for (ll xi = xmin; xi <= xmax; ++xi) {
        //tính (x-x0)
        ll dx_scaled = xi * (ll)SCALE - X;

        ull tmp = (ull)(dx_scaled) * (ull)(dx_scaled);
        ull dx2 = tmp;
        //ta kiểm tra luôn để cho R^2 >= (x-x0)^2 còn nếu để rem thì khả năng -0,000000 nó sẽ cho là continue
        if (dx2 > R2) continue;
        //R^2 - (x-x0)^2
        ull rem = R2 - dx2; // >= 0

        long double rem_ld = (long double) rem;
        ull t = (ull) floor(sqrtl(rem_ld));

        //với mỗi x ta sẽ có khoảng cách y lớn nhất và y nhỏ nhất 
        ll ymin = div_ceil_ll( (ll)(Y - (ll)t), SCALE );
        ll ymax = div_floor_ll( (ll)(Y + (ll)t), SCALE );

        if (ymax >= ymin) cnt += (ull)(ymax - ymin + 1);
    }

    cout << cnt << '\n';
    return 0;
}