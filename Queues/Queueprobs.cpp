#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


//Function to reverse a queue using stack
queue<int> reverseQ(queue<int> q)
{
    stack<int> st;
    int n=q.size();
    while(n--)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}


// Function to reverse first k elements of a queue
queue<int> reversekQ(queue<int>q,int k )
{
    stack<int>st;
    int rem=q.size()-k;
    while(k--)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    while( rem--)
    {
        q.push(q.front());
        q.pop();
    }
    
}

//Maxm time to buy tickets
 

//Implement queue using stack
// class queue
// {
//     stack <int>s1;
//     stack <int>s2;
//     bool is_empty()
//     {
//         return ( s1.empty() && s2.empty())
//     }
//     void push(int x)
//     {
//         s1.push(x)
//     }
//     int pop()
//     {
//         if (is_empty())
//         {
//             return 0;
//         }
//         if (!s2.empty())
//         {
//             int ele=s2.top();
//             s2.pop();
//             return ele;
//         }
//         else {
//             while (!s1.empty())
//             {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//             int ele=s2.top();
//             s2.pop();
//             return ele;
//         }
//     }
//     int peek()
//     {
//         if (is_empty())
//         {
//             cout<<"queue is full";
//             return 0;
//         }
//         if(!s2.empty())
//         {
//             return s2.top();
//         }
//         else{
//             while(! s1.empty())
//             {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//             return s2.pop()

//         }
//     }
    
// };



int main (){}
