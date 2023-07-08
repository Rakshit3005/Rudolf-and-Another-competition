#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
bool comparePairs(const std::pair<int, int>& pair1, const std::pair<int, int>& pair2) {
    if (pair1.first == pair2.first) {
        return pair1.second < pair2.second;
    }
    return pair1.first < pair2.first;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, m, h;
        cin >> n >> m >> h;

        ll t[n][m];
        int solve[n] = {0};

        ll penalty[n] = {0};
       // int pos[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> t[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            sort(t[i], t[i] + m);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j != 0)
                {
                    t[i][j] += t[i][j - 1];
                }
               // cout<<t[i][j]<<" ";
            }
           // cout<<endl;
        }

        for (int i = 0; i < n; i++)
        {
            ll time = 0;
           // pos[i] = i + 1;
            for (int j = 0; j < m; j++)
            {
                time = t[i][j];
                if (time <= h)
                {
                    
                    solve[i]++;
                    penalty[i] += t[i][j];
                }
                else
                {
                    break;
                }
            }
        }
        vector<pair<ll,ll>> v;
        for(int i=0;i<n;i++)
        {
          v.push_back(make_pair(-solve[i],penalty[i]));
        }
        sort(v.begin(),v.end());
       /* for(int i=0;i<n;i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }*/
        //bool f=false;
         for(int i=0;i<n;i++)
        {
            if(v[i].first==-solve[0] && v[i].second==penalty[0])
            {
               
                cout<<i+1<<endl;
                break;
               
            }
        }

        // sort(v.begin(), v.end());
    }

    return 0;
}
