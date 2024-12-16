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
int k, n;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    cin >> n;
    //0->6, 1->2, 2->5, 3->5, 4->4, 5->5, 6->6, 7->3, 8->7, 9->6
    //최대들 2:1, 5:5, 3:7, 6:9, 4:4, 7:8
    //가성비 순 7->2.33개, 6->1,5개 7->1.11, 4, 5->1개
    int total=0;
    while(n>=5){
        total+=7;
        n-=3;
    }
    if(n==4)total+=4;
    if(n==3)total+=7;
    if(n==2)total+=1;

    cout<<total;
    return 0;
}
//8 2 9 1 4 6 7 10
