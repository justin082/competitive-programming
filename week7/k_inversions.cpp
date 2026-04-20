#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(std::vector<cd> &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j |= bit;
        if (i < j)
            std::swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));

        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd &x : a)
            x /= n;
    }
}

std::vector<long long> multiply(std::vector<double> &a, std::vector<double> &b) {
    std::vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    int n = 1;
    while (n < (int)a.size() + (int)b.size())
        n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];

    fft(fa, true);

    std::vector<long long> result(n);
    for (int i = 0; i < n; i++)
        result[i] = (long long)(fa[i].real() + 0.5);

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string s;
    while (std::cin >> s) {
        int n = s.size();
    
        std::vector<double> A(n), B(n);
    
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') A[i] = 1;
            else B[i] = 1;
        }
    
        std::reverse(B.begin(), B.end());
    
        std::vector<long long> conv = multiply(A, B);
    
        for (int k = 1; k < n; k++) {
            std::cout << conv[n - 1 + k] << '\n';
        }
    }
    return 0;
}