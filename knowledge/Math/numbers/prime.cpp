#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

}



// Notes:
/*
    1- Wilson's Theorem: (p-1)! ≡ -1 (mod p) iff p is prime.
    2- Fermat's Little Theorem: a^(p-1) ≡ 1 (mod p) iff p is prime and (a % p != 0).

*/