
#include<iostream>
using namespace std;

//recursion +memo
//good memo technique

class Solution {
    public:
    
        int m,n;
        typedef long long ll;
    
        vector<vector<pair<ll,ll>>>t;
    
        pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid)
        {
            if(i == m-1 && j == n-1)
            {
                ll val = grid[i][j];
                return {val, val};
            }
    
            ll maxval=LLONG_MIN;
            ll minval=LLONG_MAX;
    
            if (t[i][j].first != LLONG_MIN || t[i][j].second != LLONG_MAX)
            {
                return t[i][j];
            }
            //down direction
            if (i+1 < m)//bound check
            {
                auto [downmax,downmin]=solve(i+1,j,grid);
                maxval=max({maxval,grid[i][j]*downmax,grid[i][j]*downmin});
                minval=min({minval,grid[i][j]*downmax,grid[i][j]*downmin});
            }
            if(j+1<n)
            {
                auto [rightmax,rightmin]=solve(i,j+1,grid);
                maxval=max({maxval,grid[i][j]*rightmax,grid[i][j]*rightmin});
                minval=min({minval,grid[i][j]*rightmax,grid[i][j]*rightmin});
            }
    
            return t[i][j]={maxval,minval};
           
        }
     
        int maxProductPath(vector<vector<int>>& grid) {
            m = grid.size();        
            n = grid[0].size();
    
            t=vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX}));  
            auto [maxproduct, minproduct] = solve(0, 0, grid);
            const int MOD = 1e9 + 7;
    
            return maxproduct < 0 ? -1 : maxproduct % MOD;
        }
    
    };
//bottom up approach

class Solution {
    public:
    
        int m,n;
        typedef long long ll;
        vector<vector<pair<ll,ll>>>t;
        int maxProductPath(vector<vector<int>>& grid) {
            m = grid.size();        
            n = grid[0].size();
    
            t=vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX})); 
    
            t[0][0]={grid[0][0],grid[0][0]};
    
            for(int j = 1; j < n; j++) {
                t[0][j].first  = t[0][j-1].first  * grid[0][j];
                t[0][j].second = t[0][j-1].second * grid[0][j]; 
            }
            for(int i = 1; i < m; i++) {
                t[i][0].first  = t[i-1][0].first  * grid[i][0];
                t[i][0].second = t[i-1][0].second * grid[i][0]; 
    
            }
    
            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    ll upMax = t[i-1][j].first;
                    ll upMin = t[i-1][j].second;
    
                    ll leftMax = t[i][j-1].first;
                    ll leftMin = t[i][j-1].second;
    
                    t[i][j].first  = max({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
                    t[i][j].second = min({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
                }
            }
            auto [maxproduct, minproduct] = t[m-1][n-1];
            const int MOD = 1e9 + 7;
    
            return maxproduct < 0 ? -1 : maxproduct % MOD;
        }
    
    };