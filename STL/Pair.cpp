#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pair<string,int>p1;
    // p1=make_pair("omm",20);

    // pair<int,int>p2;
    // p2.first=30;
    // p2.second=40;

    // cout<<p1.first<<" "<<p1.second;
    // cout<<endl;
    // cout<<p2.first<<" "<<p2.second;

    //method to make multiple pair of many data
    //club two together by making a pair 
    //and make a pair with the the third 

    pair <string , pair <int ,int> >p1;
    p1.first="omm";
    p1.second.first =19;
    p1.second.second =89;

    //alternate way

    pair<string, pair<int ,int>>p2;

    p2=make_pair("xyz",make_pair(20,75));




    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second;
    cout<<endl;
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second;
    return 0;
}