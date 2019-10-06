#include <iostream>
#include <math.h>
#include <stdint.h>

using namespace std;

int main() {
    uint64_t a;
    uint64_t b;
    uint64_t d;
    cin >> a >> b;
    d = (uint64_t(1)<<b);
    cout << int(ceil(double(d)/a));
    return 0;
}