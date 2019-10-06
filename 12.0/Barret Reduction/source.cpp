#include <iostream>
#include <math.h>
#include <stdint.h>

using namespace std;

int main() {
    uint64_t a;
    uint64_t b;
    cin >> a >> b;
    cout << (1<<b) << endl; //s
    cout << int(ceil(double(1<<b)/a));
    return 0;
}