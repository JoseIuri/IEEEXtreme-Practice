#include<iostream>

using namespace std;

int main()
{
    int i, n, ans, correct;
    
    cin >> n;
    
    bool *Q = new bool[n];
    
    cout << 'Q';
    
    for (i = 0; i < n; i++)
        cout << ' ' << Q[i];
    cout << endl;
    
    cin >> ans;
    
    if (ans == 0)
    {
        cout << 'A';
        for (i = 0; i < n; i++)
            cout << ' ' << !Q[i];
        cout << endl;
    }
    if (ans == n)
    {
        cout << 'A';
        for (i = 0; i < n; i++)
            cout << ' ' << Q[i];
        cout << endl;
    }
    for (int j = 0; j < n; j++)
    {
        Q[j] = !Q[j];
        cout << 'Q';
        for (i = 0; i < n; i++)
            cout << ' ' << Q[i];
        cout << endl;
        
        cin >> correct;
        
        if (correct > ans)
            ans = correct;
        else
            Q[j] = !Q[j];
        
        if (ans == n)
        {
            cout << 'A';
            for (i = 0; i < n; i++)
                cout << ' ' << Q[i];
            cout << endl;
            break;
        }
    }
    return 0;
}