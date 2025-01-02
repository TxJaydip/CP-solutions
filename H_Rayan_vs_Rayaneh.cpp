/**
 *    author:  tourist
 *    created: 30.11.2024 07:47:04
 **/
// #undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

// #ifdef LOCAL
// #include "algo/debug.h"
// #else
// #define debug(...) 42
// #endif

static struct FastInput
{
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t chars_read = 0;
    size_t buf_pos = 0;
    FILE *in = stdin;
    char cur = 0;

    inline char get_char()
    {
        if (buf_pos >= chars_read)
        {
            chars_read = fread(buf, 1, BUF_SIZE, in);
            buf_pos = 0;
            buf[0] = (chars_read == 0 ? -1 : buf[0]);
        }
        return cur = buf[buf_pos++];
    }

    inline void tie(int) {}

    inline explicit operator bool()
    {
        return cur != -1;
    }

    inline static bool is_blank(char c)
    {
        return c <= ' ';
    }

    inline bool skip_blanks()
    {
        while (is_blank(cur) && cur != -1)
        {
            get_char();
        }
        return cur != -1;
    }

    inline FastInput &operator>>(char &c)
    {
        skip_blanks();
        c = cur;
        return *this;
    }

    inline FastInput &operator>>(string &s)
    {
        if (skip_blanks())
        {
            s.clear();
            do
            {
                s += cur;
            } while (!is_blank(get_char()));
        }
        return *this;
    }

    template <typename T>
    inline FastInput &read_integer(T &n)
    {
        // unsafe, doesn't check that characters are actually digits
        n = 0;
        if (skip_blanks())
        {
            int sign = +1;
            if (cur == '-')
            {
                sign = -1;
                get_char();
            }
            do
            {
                n += n + (n << 3) + cur - '0';
            } while (!is_blank(get_char()));
            n *= sign;
        }
        return *this;
    }

    template <typename T>
    inline typename enable_if<is_integral<T>::value, FastInput &>::type operator>>(T &n)
    {
        return read_integer(n);
    }

#if !defined(_WIN32) || defined(_WIN64)
    inline FastInput &operator>>(__int128 &n)
    {
        return read_integer(n);
    }
#endif

    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, FastInput &>::type operator>>(T &n)
    {
        // not sure if really fast, for compatibility only
        n = 0;
        if (skip_blanks())
        {
            string s;
            (*this) >> s;
            sscanf(s.c_str(), "%lf", &n);
        }
        return *this;
    }
} fast_input;

#define cin fast_input

template <typename T>
T inverse(T a, T m)
{
    T u = 0, v = 1;
    while (a != 0)
    {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular
{
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U &x)
    {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U &x)
    {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0)
            v += mod();
        return v;
    }

    const Type &operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular &operator+=(const Modular &other)
    {
        value += other.value;
        value -= (value >= mod()) * mod();
        return *this;
    }
    Modular &operator-=(const Modular &other)
    {
        value -= other.value;
        value += (value < 0) * mod();
        return *this;
    }
    template <typename U>
    Modular &operator+=(const U &other) { return *this += Modular(other); }
    template <typename U>
    Modular &operator-=(const U &other) { return *this -= Modular(other); }
    Modular &operator++() { return *this += 1; }
    Modular &operator--() { return *this -= 1; }
    Modular operator++(int)
    {
        Modular result(*this);
        *this += 1;
        return result;
    }
    Modular operator--(int)
    {
        Modular result(*this);
        *this -= 1;
        return result;
    }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

    friend const Type &abs(const Modular &x) { return x.value; }

    template <typename U>
    friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename U>
    friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename V, typename U>
    friend V &operator>>(V &stream, Modular<U> &number);

private:
    Type value;
};

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b)
{
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0)
    {
        if (p & 1)
            res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T> &number)
{
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T> &number)
{
    return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U &operator<<(U &stream, const Modular<T> &number)
{
    return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U &operator>>(U &stream, Modular<T> &number)
{
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

// using ModType = int;

// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;

constexpr int md = 123;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);

// Mint C(int n, int k) {
//   if (k < 0 || k > n) {
//     return 0;
//   }
//   while ((int) fact.size() < n + 1) {
//     fact.push_back(fact.back() * (int) fact.size());
//     inv_fact.push_back(1 / fact.back());
//   }
//   return fact[n] * inv_fact[k] * inv_fact[n - k];
// }

namespace factorizer
{

    template <typename T>
    struct FactorizerVarMod
    {
        static T value;
    };
    template <typename T>
    T FactorizerVarMod<T>::value;

    template <typename T>
    bool IsPrime(T n, const vector<T> &bases)
    {
        if (n < 2)
        {
            return false;
        }
        vector<T> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (const T &x : small_primes)
        {
            if (n % x == 0)
            {
                return n == x;
            }
        }
        if (n < 31 * 31)
        {
            return true;
        }
        int s = 0;
        T d = n - 1;
        while ((d & 1) == 0)
        {
            d >>= 1;
            s++;
        }
        FactorizerVarMod<T>::value = n;
        for (const T &a : bases)
        {
            if (a % n == 0)
            {
                continue;
            }
            Modular<FactorizerVarMod<T>> cur = a;
            cur = power(cur, d);
            if (cur == 1)
            {
                continue;
            }
            bool witness = true;
            for (int r = 0; r < s; r++)
            {
                if (cur == n - 1)
                {
                    witness = false;
                    break;
                }
                cur *= cur;
            }
            if (witness)
            {
                return false;
            }
        }
        return true;
    }

    bool IsPrime(int64_t n)
    {
        return IsPrime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
    }

    bool IsPrime(int32_t n)
    {
        return IsPrime(n, {2, 7, 61});
    }

    // but if you really need uint64_t version...
    /*
    bool IsPrime(uint64_t n) {
      if (n < 2) {
        return false;
      }
      vector<uint32_t> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
      for (uint32_t x : small_primes) {
        if (n == x) {
          return true;
        }
        if (n % x == 0) {
          return false;
        }
      }
      if (n < 31 * 31) {
        return true;
      }
      uint32_t s = __builtin_ctzll(n - 1);
      uint64_t d = (n - 1) >> s;
      function<bool(uint64_t)> witness = [&n, &s, &d](uint64_t a) {
        uint64_t cur = 1, p = d;
        while (p > 0) {
          if (p & 1) {
            cur = (__uint128_t) cur * a % n;
          }
          a = (__uint128_t) a * a % n;
          p >>= 1;
        }
        if (cur == 1) {
          return false;
        }
        for (uint32_t r = 0; r < s; r++) {
          if (cur == n - 1) {
            return false;
          }
          cur = (__uint128_t) cur * cur % n;
        }
        return true;
      };
      vector<uint64_t> bases_64bit = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
      for (uint64_t a : bases_64bit) {
        if (a % n == 0) {
          return true;
        }
        if (witness(a)) {
          return false;
        }
      }
      return true;
    }
    */

    vector<int> least = {0, 1};
    vector<int> primes;
    int precalculated = 1;

    void RunLinearSieve(int n)
    {
        n = max(n, 1);
        least.assign(n + 1, 0);
        primes.clear();
        for (int i = 2; i <= n; i++)
        {
            if (least[i] == 0)
            {
                least[i] = i;
                primes.push_back(i);
            }
            for (int x : primes)
            {
                if (x > least[i] || i * x > n)
                {
                    break;
                }
                least[i * x] = x;
            }
        }
        precalculated = n;
    }

    void RunSlowSieve(int n)
    {
        n = max(n, 1);
        least.assign(n + 1, 0);
        for (int i = 2; i * i <= n; i++)
        {
            if (least[i] == 0)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    if (least[j] == 0)
                    {
                        least[j] = i;
                    }
                }
            }
        }
        primes.clear();
        for (int i = 2; i <= n; i++)
        {
            if (least[i] == 0)
            {
                least[i] = i;
                primes.push_back(i);
            }
        }
        precalculated = n;
    }

    void RunSieve(int n)
    {
        RunLinearSieve(n);
    }

    template <typename T>
    vector<pair<T, int>> MergeFactors(const vector<pair<T, int>> &a, const vector<pair<T, int>> &b)
    {
        vector<pair<T, int>> c;
        int i = 0;
        int j = 0;
        while (i < (int)a.size() || j < (int)b.size())
        {
            if (i < (int)a.size() && j < (int)b.size() && a[i].first == b[j].first)
            {
                c.emplace_back(a[i].first, a[i].second + b[j].second);
                ++i;
                ++j;
                continue;
            }
            if (j == (int)b.size() || (i < (int)a.size() && a[i].first < b[j].first))
            {
                c.push_back(a[i++]);
            }
            else
            {
                c.push_back(b[j++]);
            }
        }
        return c;
    }

    template <typename T>
    vector<pair<T, int>> RhoC(const T &n, const T &c)
    {
        if (n <= 1)
        {
            return {};
        }
        if ((n & 1) == 0)
        {
            return MergeFactors({{2, 1}}, RhoC(n / 2, c));
        }
        if (IsPrime(n))
        {
            return {{n, 1}};
        }
        FactorizerVarMod<T>::value = n;
        Modular<FactorizerVarMod<T>> x = 2;
        Modular<FactorizerVarMod<T>> saved = 2;
        T power = 1;
        T lam = 1;
        while (true)
        {
            x = x * x + c;
            T g = __gcd((x - saved)(), n);
            if (g != 1)
            {
                return MergeFactors(RhoC(g, c + 1), RhoC(n / g, c + 1));
            }
            if (power == lam)
            {
                saved = x;
                power <<= 1;
                lam = 0;
            }
            lam++;
        }
        return {};
    }

    template <typename T>
    vector<pair<T, int>> Rho(const T &n)
    {
        return RhoC(n, static_cast<T>(1));
    }

    template <typename T>
    vector<pair<T, int>> Factorize(T x)
    {
        if (x <= 1)
        {
            return {};
        }
        if (x <= precalculated)
        {
            vector<pair<T, int>> ret;
            while (x > 1)
            {
                if (!ret.empty() && ret.back().first == least[x])
                {
                    ret.back().second++;
                }
                else
                {
                    ret.emplace_back(least[x], 1);
                }
                x /= least[x];
            }
            return ret;
        }
        if (x <= static_cast<int64_t>(precalculated) * precalculated)
        {
            vector<pair<T, int>> ret;
            if (!IsPrime(x))
            {
                for (T i : primes)
                {
                    T t = x / i;
                    if (i > t)
                    {
                        break;
                    }
                    if (x == t * i)
                    {
                        int cnt = 0;
                        while (x % i == 0)
                        {
                            x /= i;
                            cnt++;
                        }
                        ret.emplace_back(i, cnt);
                        if (IsPrime(x))
                        {
                            break;
                        }
                    }
                }
            }
            if (x > 1)
            {
                ret.emplace_back(x, 1);
            }
            return ret;
        }
        return Rho(x);
    }

    template <typename T>
    vector<T> BuildDivisorsFromFactors(const vector<pair<T, int>> &factors)
    {
        vector<T> divisors = {1};
        for (auto &p : factors)
        {
            int sz = (int)divisors.size();
            for (int i = 0; i < sz; i++)
            {
                T cur = divisors[i];
                for (int j = 0; j < p.second; j++)
                {
                    cur *= p.first;
                    divisors.push_back(cur);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        return divisors;
    }

} // namespace factorizer

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = int(32e6);
    const int M = int(1e5);
    factorizer::RunSieve(N);
    vector<pair<int, int>> all;
    all.reserve(int(1.5e6));
    vector<int> nums;
    for (int i = 2; i < N; i++)
    {
        nums.clear();
        bool fail = false;
        int x = i;
        while (x > 1)
        {
            int p = factorizer::least[x];
            int c = 1;
            while (x % p == 0)
            {
                x /= p;
                c *= p;
            }
            if (i / c > M)
            {
                fail = true;
                break;
            }
            nums.push_back(i / c);
        }
        if (!fail && nums.size() > 2)
        {
            for (int y : nums)
            {
                all.emplace_back(i, y);
            }
        }
    }
    vector<vector<int>> divs(M + 1);
    for (int i = 1; i <= M; i++)
    {
        for (int j = i; j <= M; j += i)
        {
            divs[j].push_back(i);
        }
    }
    // debug(all.size(), clock());
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> cc(M + 1);
        vector<int> cnt(M + 1);
        for (int x : a)
        {
            cc[x] += 1;
            for (int d : divs[x])
            {
                cnt[d] += 1;
            }
        }
        int ans = 0;
        int start = -1;
        int beg = 0;
        while (beg < int(all.size()))
        {
            int end = beg;
            while (end + 1 < int(all.size()) && all[end + 1].first == all[end].first)
            {
                end += 1;
            }
            if (end - beg + 1 > ans)
            {
                int goal = (all[beg].first <= M ? cnt[all[beg].first] : 0);
                bool win = true;
                for (int i = beg; i <= end; i++)
                {
                    if (cnt[all[i].second] == goal)
                    {
                        win = false;
                        break;
                    }
                }
                if (win)
                {
                    ans = end - beg + 1;
                    start = beg;
                }
            }
            beg = end + 1;
        }
        if (ans < 2)
        {
            sort(a.begin(), a.end());
            int x = -1;
            for (int i = 0; i < n - 1; i++)
            {
                if (a[i + 1] % a[i] != 0)
                {
                    x = i;
                    break;
                }
            }
            if (x != -1)
            {
                cout << 2 << '\n';
                cout << a[x] << " " << a[x + 1] << '\n';
                continue;
            }
        }
        if (ans == 0)
        {
            cout << 1 << '\n';
            cout << a[0] << '\n';
            continue;
        }
        cout << ans << '\n';
        for (int i = 0; i < ans; i++)
        {
            auto [x, y] = all[start + i];
            int v = y;
            while (v <= M && (cc[v] == 0 || v % x == 0))
            {
                v += y;
            }
            assert(v <= M);
            cout << v << " \n"[i == ans - 1];
        }
    }
    // debug(clock());
    return 0;
}
