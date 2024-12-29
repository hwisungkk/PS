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
    int a, b, c, n, m, k;
    int t;

    cin >> n;
    
    vector <int> va(n);
    vector <int> vb(n);
    vector <int> vc(n);
    vector <int> vd(n);

    for(int i=0;i<n;i++){
        cin >> va[i] >> vb[i] >> vc[i] >> vd[i];
    }

    vector <int> sum_1(n*n);
    vector <int> sum_2(n*n);
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum_1[index] = va[i]+vb[j];
            index++;
        }
    }
    index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum_2[index] = vc[i]+vd[j];
            index++;
        }
    }
    sort(sum_1.begin(), sum_1.end());
    sort(sum_2.rbegin(), sum_2.rend());
    long long count = 0;
    int i_1=0, i_2=0;

    while((i_1<=(n*n-1) && i_2 <= (n*n-1))){
        if(sum_1[i_1]+sum_2[i_2]==0){
            if(i_1<n*n-1 || i_2<n*n-1){
                long long multi_a=1;
                long long multi_b=1;
                while(sum_1[i_1+1]-sum_1[i_1] == 0 && i_1<(n*n-1)){
                    i_1++;
                    multi_a++;
                }
                while(sum_2[i_2+1]-sum_2[i_2] == 0 && i_2 <(n*n-1)){
                    i_2++;
                    multi_b++;
                }
                count+= multi_a*multi_b;
                if(sum_1[i_1+1]-sum_1[i_1] <= sum_2[i_2]-sum_2[i_2+1])i_1++;
                else i_2++;
            }
        }
        else if(sum_1[i_1]+sum_2[i_2]>0){
            i_2++;
        }
        else if(sum_1[i_1]+sum_2[i_2]<0){
            i_1++;
        }
    }
    // for(int i=0;i<n*n;i++){
    //     cout << sum_1[i] << ' ';
    // }cout << '\n';
    // for(int i=0;i<n*n;i++){
    //     cout << sum_2[i] << ' ';
    // }cout << '\n';
    cout << count;
    return 0;
}
