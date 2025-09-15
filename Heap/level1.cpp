#include<iostream>
using namespace std;
#include<queue>
#include<math.h>


//height of heap

int heightheap(int arr[], int n ){

    if (n==1){
        return 1;
    }

    else{
        int co=0;
        while(n>1)
        {
            co++;
            n=n/2;
        }
        return co;

    }
}

//minimum cost of ropes

int mincost(int arr[],int n)
{
    priority_queue<int, vector<int>, greater<int>>p;
    for (int i=0;i<n;i++)
    {
        p.push(arr[i]);
    }
    int cost=0;
    while(p.size()>1)
    {
        int rope= p.top();
        p.pop();
        rope+=p.top();
        p.pop();
        cost+=rope;
        p.push(rope);
    }
    return cost;
}


// magician and chocolates
long long solution(int a , vector<int>b)
{
    priority_queue<int>p;
    for(int i=0; i<b.size();i++)
    {
        p.push(b[i]);
    }
    long long max_choc=0;
    while(a && !(p.empty()))
    {
        max_choc += p.top();
        if(p.top()/2)
        {
            p.push(p.top()/2);
        }
        p.pop();
        a--;
    }
    return max_choc % 1000000007 ; 
}


//weight of stones

int weight(vector<int>stones)
{
    priority_queue<int>p;
    for(int i =0; i<stones.size();i++)
    {
        p.push(stones[i]);
    }
    int dest=0;

    while(p.size()>1)
    {
        dest=p.top();
        p.pop();
        dest-=p.top();
        p.pop();

        if(dest)
        {
            p.push(dest);
        }

    }
    return p.empty() ? 0: p.top();

}

//profit maximisation
long long solution(int b, vector<int>a)
{
    priority_queue<int>p;
    for(int i=0; i<a.size();i++)
    {
        p.push(a[i]);
    }
    long long sum=0;
    while(b && !(p.empty()))
    {
        sum+= p.top();
        if(p.top()-1)
        {
            p.push(p.top()-1);
        }
        p.pop();
        b--;
    }
    return sum; 
}

//richest pile
int solution(vector<int>gifts,int k )
{
    priority_queue<int>p;
    for(int i=0; i<gifts.size();i++)
    {
        p.push(gifts[i]);
    }
    int sum=0;
    int temp=0;
    while(k)
    {
        temp=p.top();
        p.pop();
        if(temp-sqrt(temp))
        {
            p.push(temp);
        }
        k--;
    }
    for(int i=0;i<p.size();i++)
    {
        sum+=p.top();
        p.pop();
    }
    return sum;  
}








int main()
{
    
    return 0;
}