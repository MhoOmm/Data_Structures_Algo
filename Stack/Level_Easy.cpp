#include <iostream>
#include <stack>
#include<vector>
using namespace std;
//Function which accepts a string and return its reverse
void reversestring(vector<char>s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }
    int i=0;
    while(!st.empty())
    {
        s[i]=st.top();
        i++;
        st.pop();
    }
}

//FUNCTION TO INSERT AT THE BOTTOM 
void insertb(stack<int>s,int x)
{
    vector<int>arr;
    while (!s.empty()){
        arr.push_back(s.top());
        s.pop();
    }
    s.push(x);
    for ( int i =0;i<arr.size();i++)
    {
        s.push(arr[i]);
    }
}

//FUNCTION TO MAKE ARRAY BEAUTIFUL.i.e SAME POLARITY 
vector<int> beauty( vector <int>arr)
{
    stack<int>s;
    for( int i=0;i<arr.size();i++)
    {
        if( s.empty())
        {
            s.push(arr[i]);
        }
        else if( arr[i]<=0)
        {
            if( s.top() <=0)
            {
                s.push(arr[i]);
            }
            else{
                s.pop();
            }
        }
        else
        {
            if( s.top()>=0)
            {
                s.push(arr[i]);
            }
            else{
                s.pop();
            } 
        }
        vector<int>ans(s.size());
        int index=s.size()-1;
        while (!s.empty())
        {
            ans[index]=s.top();
            i--;
            s.pop();
        }
        return ans;
    }
}


//VALID PARANTHESIS

bool valparan(string str)
{
    stack<char>s;
    for(int i=0;i<str.size();i++)
    {
        if ( str[i]=='(')
        {
            s.push(str[i]);
        }
        else{
            if (s.empty())
            {
                return 0;
            }
            else{
                s.pop();
            }
        }
    }
    return (s.empty());
}


//compare bg string compare

void compare( string s)
{
    stack<char>stk;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='#')
        {
            stk.push(s[i]);
        }
        else{
            stk.pop();
        }
    }
}
