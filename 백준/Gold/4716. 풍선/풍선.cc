#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int max = 10001;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ar[102][102] = {0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        long long a, b, c, total = 0;
        long long block = 0;
        int n, m, k;
        int bal, ad, bd;
        cin >> n >> a >> b;
        if(n+a+b==0)break;
        vector<tuple<int, int, int>> v;
        vector<pair<int, int>> index1;
        vector<pair<int, int>> index2;
        for (int i = 0; i < n; i++)
        {
            cin >> bal >> ad >> bd;
            v.push_back({bal, ad, bd});
            if (ad - bd >= 0)
                index1.push_back({ad - bd, i});
            if (ad - bd < 0)
                index2.push_back({ad - bd, i});
        }

        sort(index1.begin(), index1.end(), greater<>()); // 양수면 큰 순서 //b에 가야함
        sort(index2.begin(), index2.end());              // 음수면 작은 순서 //a에가야함
        int check_a = 0, check_b = 0;
        for (int i = 0; i < index1.size(); i++)
        {
            if (b >= get<0>(v[index1[i].second]))
            {
                b -= get<0>(v[index1[i].second]);
                total += get<0>(v[index1[i].second]) * get<2>(v[index1[i].second]);
                get<0>(v[index1[i].second]) = 0;
            }
            else
            {
                total += get<2>(v[index1[i].second]) * b;
                get<0>(v[index1[i].second]) -= b;
                b = 0;
                check_b = 1;
            }
        }
        for (int i = 0; i < index2.size(); i++)
        {
            if (a >= get<0>(v[index2[i].second]))
            {
                a -= get<0>(v[index2[i].second]);
                total += get<0>(v[index2[i].second]) * get<1>(v[index2[i].second]);
                get<0>(v[index2[i].second]) = 0;
            }
            else
            {
                total += get<1>(v[index2[i].second]) * a;
                get<0>(v[index2[i].second]) -= a;
                a = 0;
                check_a = 1;
            }
        }
        if (check_a)
        { // a가 0이면 b에 다 줘야함.
            for (int i = 0; i < index1.size(); i++)
            {
                total += get<0>(v[index1[i].second]) * get<2>(v[index1[i].second]);
            }
            for (int i = 0; i < index2.size(); i++)
            {
                total += get<0>(v[index2[i].second]) * get<2>(v[index2[i].second]);
            }
        }
        else if (check_b)
        { // b가 0이면 a에 다 줘야함.
            for (int i = 0; i < index1.size(); i++)
            {
                total += get<0>(v[index1[i].second]) * get<1>(v[index1[i].second]);
            }
            for (int i = 0; i < index2.size(); i++)
            {
                total += get<0>(v[index2[i].second]) * get<1>(v[index2[i].second]);
            }
        }
        // 음수면 a쪽
        // 양수면 b쪽
        cout << total << '\n';
    }

    return 0;
}