---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps_count_subset_sum.test.cpp
    title: verify/fps_count_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps_exp.test.cpp
    title: verify/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps_inv.test.cpp
    title: verify/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps_log.test.cpp
    title: verify/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps_pow.test.cpp
    title: verify/fps_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Fps/fps.hpp\"\nusing mint = atcoder::modint998244353;\n\
    using vm = vector<mint>;\nstruct fps : vm {\n#define d (*this)\n#define s int(vm::size())\n\
    \    fps() {}\n    fps(vector<mint> a) : vm(a.begin(), a.end()) {}\n    void rsz(int\
    \ n, mint val = 0) {\n        if (s < n) resize(n, val);\n    }\n    fps &low_(int\
    \ n) {\n        resize(n);\n        return d;\n    }\n    fps low(int n) const\
    \ { return fps(d).low_(n); }\n    fps &shrink_(int n) {\n        if (s > n) resize(n);\n\
    \        return d;\n    }\n    fps shrink(int n) const { return fps(d).shrink_(n);\
    \ }\n    mint &operator[](int i) {\n        rsz(i + 1);\n        return vm::operator[](i);\n\
    \    }\n    mint operator[](int i) const { return i < s ? vm::operator[](i) :\
    \ 0; }\n    mint operator()(mint x) const {\n        mint r;\n        for (int\
    \ i = s - 1; i >= 0; --i) r = r * x + d[i];\n        return r;\n    }\n    fps\
    \ operator>>(int sz) const {\n        if (s <= sz) return {};\n        fps r =\
    \ d;\n        r.erase(r.begin(), r.begin() + sz);\n        return r;\n    }\n\
    \    fps operator<<(int sz) const {\n        fps r = d;\n        r.insert(r.begin(),\
    \ sz, mint(0));\n        return r;\n    }\n    fps operator-() const {\n     \
    \   fps r(d);\n        for (int i = 0; i < s; i++) r[i] = -r[i];\n        return\
    \ r;\n    }\n    fps &operator+=(const fps &a) {\n        rsz(a.size());\n   \
    \     for (int i = 0; i < int(a.size()); i++) d[i] += a[i];\n        return d;\n\
    \    }\n    fps &operator+=(const mint &a) {\n        d[0] += a;\n        return\
    \ d;\n    }\n    fps &operator-=(const fps &a) {\n        rsz(a.size());\n   \
    \     for (int i = 0; i < int(a.size()); i++) d[i] -= a[i];\n        return d;\n\
    \    }\n    fps &operator-=(const mint &a) {\n        d[0] -= a;\n        return\
    \ d;\n    }\n    fps &operator*=(const fps &a) { return d = atcoder::convolution(d,\
    \ a); }\n    fps &operator*=(mint a) {\n        for (int i = 0; i < s; i++) d[i]\
    \ *= a;\n        return d;\n    }\n    fps &operator/=(mint a) {\n        mint\
    \ a_inv = 1 / a;\n        for (int i = 0; i < s; i++) d[i] *= a_inv;\n       \
    \ return d;\n    }\n    fps operator+(const fps &a) const { return fps(d) += a;\
    \ }\n    fps operator-(const fps &a) const { return fps(d) -= a; }\n    fps operator+(const\
    \ mint &a) const { return fps(d) += a; }\n    fps operator-(const mint &a) const\
    \ { return fps(d) -= a; }\n    fps operator*(const fps &a) const { return fps(d)\
    \ *= a; }\n    fps operator*(mint a) const { return fps(d) *= a; }\n    fps operator/(mint\
    \ a) const { return fps(d) /= a; }\n    fps inv(int n = -1) const {\n        if\
    \ (n == -1) n = s;\n        assert(d[0] != mint(0));\n\n        fps r({d[0].inv()});\n\
    \        for (int i = 1; i < n; i <<= 1)\n            r = r * mint(2) - (r * r\
    \ * low(i << 1)).low_(i << 1);\n        return r.low_(n);\n    }\n    fps &operator/=(const\
    \ fps &a) {\n        assert(a[0] != mint(0));\n        int w = s + a.size();\n\
    \n        d *= a.inv(w);\n        return d;\n    }\n    fps operator/(const fps\
    \ &a) const { return fps(d) /= a; }\n    fps integral(int n = -1) const {\n  \
    \      fps r;\n        if (n == -1) n = s;\n        r.rsz(n, 1);\n        rep(i,\
    \ 2, n) r[i] = r[i - 1] * i;\n        mint v = mint(1) / r.back();\n        rrep(i,\
    \ 0, n - 1) {\n            r[i + 1] = d[i] * r[i] * v;\n            v *= (i +\
    \ 1);\n        }\n        r[0] = 0;\n        return r;\n    }\n    fps diff(int\
    \ n = -1) const {\n        fps r;\n        if (n == -1) n = s;\n        rep(i,\
    \ 0, n - 1) r[i] = d[i + 1] * (i + 1);\n        return r;\n    }\n\n    fps log(int\
    \ n = -1) const {\n        assert(d[0] == mint(1));\n        if (n == -1) n =\
    \ s;\n        return (diff(n) * inv(n)).low_(n).integral(n).low_(n);\n    }\n\n\
    \    fps exp(int n = -1) const {\n        assert(d[0] == mint(0));\n        if\
    \ (n == -1) n = s;\n        fps r({1});\n        for (int i = 1; i < n; i <<=\
    \ 1) {\n            r = (r * (-(r.log(i << 1)) + mint(1) + low(i << 1))).low(i\
    \ << 1);\n        }\n        return r.low_(n);\n    }\n\n    fps pow(ll y, int\
    \ n = -1) const {\n        if (n == -1) {\n            if (s == 0) {\n       \
    \         n = 0;\n            } else {\n                n = (s - 1) * y + 1;\n\
    \            }\n            if (y == 0) n = 1;\n        }\n        if (!y) return\
    \ fps({1}).low_(n);\n\n        fps r;\n\n        int l = 0;\n        while (l\
    \ < n && d[l].val() == 0) ++l;\n        if (l > (s - 1) / y || l == n) {\n   \
    \         r.resize(n);\n            return r;\n        }\n\n        mint a = d[l];\n\
    \        r = (d >> l) / a;\n        r = (r.log(n - l * y) * mint(y)).exp();\n\
    \        r *= a.pow(y);\n        r = r << (l * y);\n        return r.low_(n);\n\
    \    }\n#undef s\n#undef d\n};\nostream &operator<<(ostream &o, const fps &a)\
    \ {\n    rep(i, 0, a.size()) o << (i ? \" \" : \"\") << a[i].val();\n    return\
    \ o;\n}\n"
  code: "using mint = atcoder::modint998244353;\nusing vm = vector<mint>;\nstruct\
    \ fps : vm {\n#define d (*this)\n#define s int(vm::size())\n    fps() {}\n   \
    \ fps(vector<mint> a) : vm(a.begin(), a.end()) {}\n    void rsz(int n, mint val\
    \ = 0) {\n        if (s < n) resize(n, val);\n    }\n    fps &low_(int n) {\n\
    \        resize(n);\n        return d;\n    }\n    fps low(int n) const { return\
    \ fps(d).low_(n); }\n    fps &shrink_(int n) {\n        if (s > n) resize(n);\n\
    \        return d;\n    }\n    fps shrink(int n) const { return fps(d).shrink_(n);\
    \ }\n    mint &operator[](int i) {\n        rsz(i + 1);\n        return vm::operator[](i);\n\
    \    }\n    mint operator[](int i) const { return i < s ? vm::operator[](i) :\
    \ 0; }\n    mint operator()(mint x) const {\n        mint r;\n        for (int\
    \ i = s - 1; i >= 0; --i) r = r * x + d[i];\n        return r;\n    }\n    fps\
    \ operator>>(int sz) const {\n        if (s <= sz) return {};\n        fps r =\
    \ d;\n        r.erase(r.begin(), r.begin() + sz);\n        return r;\n    }\n\
    \    fps operator<<(int sz) const {\n        fps r = d;\n        r.insert(r.begin(),\
    \ sz, mint(0));\n        return r;\n    }\n    fps operator-() const {\n     \
    \   fps r(d);\n        for (int i = 0; i < s; i++) r[i] = -r[i];\n        return\
    \ r;\n    }\n    fps &operator+=(const fps &a) {\n        rsz(a.size());\n   \
    \     for (int i = 0; i < int(a.size()); i++) d[i] += a[i];\n        return d;\n\
    \    }\n    fps &operator+=(const mint &a) {\n        d[0] += a;\n        return\
    \ d;\n    }\n    fps &operator-=(const fps &a) {\n        rsz(a.size());\n   \
    \     for (int i = 0; i < int(a.size()); i++) d[i] -= a[i];\n        return d;\n\
    \    }\n    fps &operator-=(const mint &a) {\n        d[0] -= a;\n        return\
    \ d;\n    }\n    fps &operator*=(const fps &a) { return d = atcoder::convolution(d,\
    \ a); }\n    fps &operator*=(mint a) {\n        for (int i = 0; i < s; i++) d[i]\
    \ *= a;\n        return d;\n    }\n    fps &operator/=(mint a) {\n        mint\
    \ a_inv = 1 / a;\n        for (int i = 0; i < s; i++) d[i] *= a_inv;\n       \
    \ return d;\n    }\n    fps operator+(const fps &a) const { return fps(d) += a;\
    \ }\n    fps operator-(const fps &a) const { return fps(d) -= a; }\n    fps operator+(const\
    \ mint &a) const { return fps(d) += a; }\n    fps operator-(const mint &a) const\
    \ { return fps(d) -= a; }\n    fps operator*(const fps &a) const { return fps(d)\
    \ *= a; }\n    fps operator*(mint a) const { return fps(d) *= a; }\n    fps operator/(mint\
    \ a) const { return fps(d) /= a; }\n    fps inv(int n = -1) const {\n        if\
    \ (n == -1) n = s;\n        assert(d[0] != mint(0));\n\n        fps r({d[0].inv()});\n\
    \        for (int i = 1; i < n; i <<= 1)\n            r = r * mint(2) - (r * r\
    \ * low(i << 1)).low_(i << 1);\n        return r.low_(n);\n    }\n    fps &operator/=(const\
    \ fps &a) {\n        assert(a[0] != mint(0));\n        int w = s + a.size();\n\
    \n        d *= a.inv(w);\n        return d;\n    }\n    fps operator/(const fps\
    \ &a) const { return fps(d) /= a; }\n    fps integral(int n = -1) const {\n  \
    \      fps r;\n        if (n == -1) n = s;\n        r.rsz(n, 1);\n        rep(i,\
    \ 2, n) r[i] = r[i - 1] * i;\n        mint v = mint(1) / r.back();\n        rrep(i,\
    \ 0, n - 1) {\n            r[i + 1] = d[i] * r[i] * v;\n            v *= (i +\
    \ 1);\n        }\n        r[0] = 0;\n        return r;\n    }\n    fps diff(int\
    \ n = -1) const {\n        fps r;\n        if (n == -1) n = s;\n        rep(i,\
    \ 0, n - 1) r[i] = d[i + 1] * (i + 1);\n        return r;\n    }\n\n    fps log(int\
    \ n = -1) const {\n        assert(d[0] == mint(1));\n        if (n == -1) n =\
    \ s;\n        return (diff(n) * inv(n)).low_(n).integral(n).low_(n);\n    }\n\n\
    \    fps exp(int n = -1) const {\n        assert(d[0] == mint(0));\n        if\
    \ (n == -1) n = s;\n        fps r({1});\n        for (int i = 1; i < n; i <<=\
    \ 1) {\n            r = (r * (-(r.log(i << 1)) + mint(1) + low(i << 1))).low(i\
    \ << 1);\n        }\n        return r.low_(n);\n    }\n\n    fps pow(ll y, int\
    \ n = -1) const {\n        if (n == -1) {\n            if (s == 0) {\n       \
    \         n = 0;\n            } else {\n                n = (s - 1) * y + 1;\n\
    \            }\n            if (y == 0) n = 1;\n        }\n        if (!y) return\
    \ fps({1}).low_(n);\n\n        fps r;\n\n        int l = 0;\n        while (l\
    \ < n && d[l].val() == 0) ++l;\n        if (l > (s - 1) / y || l == n) {\n   \
    \         r.resize(n);\n            return r;\n        }\n\n        mint a = d[l];\n\
    \        r = (d >> l) / a;\n        r = (r.log(n - l * y) * mint(y)).exp();\n\
    \        r *= a.pow(y);\n        r = r << (l * y);\n        return r.low_(n);\n\
    \    }\n#undef s\n#undef d\n};\nostream &operator<<(ostream &o, const fps &a)\
    \ {\n    rep(i, 0, a.size()) o << (i ? \" \" : \"\") << a[i].val();\n    return\
    \ o;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Fps/fps.hpp
  requiredBy: []
  timestamp: '2025-01-16 07:24:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps_count_subset_sum.test.cpp
  - verify/fps_pow.test.cpp
  - verify/fps_inv.test.cpp
  - verify/fps_exp.test.cpp
  - verify/fps_log.test.cpp
documentation_of: Fps/fps.hpp
layout: document
redirect_from:
- /library/Fps/fps.hpp
- /library/Fps/fps.hpp.html
title: Fps/fps.hpp
---
