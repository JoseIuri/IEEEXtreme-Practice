#include <bits/stdc++.h> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n, q, g, res;
    
    cin >> n;
    int p[n];
    int i;
    
    for (i = 0; i < n; i++){
        cin >> p[i];
    }
    
    cin >> q;
    
    for (i = 0; i < q; i++){
        cin >> g;
        
        res = 0;
        for (const auto &value : p){
            if ((value | g) == g){
                res |= value;
            }
        }
        if(res == g){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}