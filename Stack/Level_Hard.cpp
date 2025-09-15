#include <iostream>
#include <stack>
#include<vector>
using namespace std;


//FUNCTION TO FIND THE LARGEST AREA OF THE RECTANLGE BY THE GIVEN HEIGHTS.
//AKA LARGEST AREA RECTANGLE 
int LargestAreaRectangle(vector<int>height,int n)
{
    int ans=0,index;
    stack<int>st;
    for( int i=0;i<n;i++)
    {
        while(!st.empty()&& height[st.top()]<height[i])
        {
            index=st.top();
            st.pop();
            if(!st.empty())
            {
                ans=max(ans,height[index]*height[i-st.top()-1]);
            }
            else {
                ans=max(ans,height[index]*i);
            }
        }
        st.push(i);
        while(!st.empty())
        {
            index=st.top();
            st.pop();
            if(!st.empty())
            {
                ans=max(ans,height[index]*(n-st.top()-1));
            }
            else{
                ans=max(ans,height[index]*n);
            }
        }
        return ans;
    }
}


//CELEBRITY PROBLEM 

//WE TAKE EACH OF THE ELEMENTS IN A STACK AND CHECK AGAR USKE 
//NICHE WALE KO WOJANATA HAI YA NHI AND VICE VERSA
//AFTER ALL EK NUMBER REH JAYEGA 
//FIR EK FINAL CHECK KARTE HAIN KI WOH KISI KO NHI JANATA 
//AUR USKO SAB JANTE HAIN 

int celebrity( vector<vector<int>>&m,int n)
{
    stack<int>st;
    for ( int i=0;i>=0;i--)
    {
        st.push(i);
    }
    while(st.size()>1)
    {
        int first=st.top();
        st.pop();
        int sec=st.top();
        st.pop();
        if (m[first][sec] && ! m[sec][first])
        {
            st.push(sec);
        }
        else if (!m[first][sec] && m[sec][first])
        {
            st.push(first);
        }
    }
    int num=st.top();
    st.pop();
    if(st.empty())
    {
        return -1;
    }
    int row=0,col=0;
    for(int i=0;i<n;i++)
    {
        row+=m[num][i];
        col+=m[i][num];
    }
    return row==0 && col==n-1 ? num:-1;
}

