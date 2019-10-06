#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    
    cout << int((s*ceil(log2(n))) + ((n-1)*m));
    
    return 0;
}

