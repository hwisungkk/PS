#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    int a, b, c;

    // int t = 0;
    // cin >> t;
    // while(t-->0){
    //     string s;
    //     cin >> s >> m;
    // }
    cin >> a >> b;
    vector <double> d(a);
    for(int i=0;i<a;i++){
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    double total=0;
    for(int i=b;i<a-b;i++){
        total +=d[i];
    }
    cout << fixed;
    cout.precision(2);
    cout << total/(a-2*b) + 0.00000001 << '\n';
    total += b*d[b];
    total += b*d[a-b-1];
    cout << total/a + 0.00000001;
    return 0;
}