#include<iostream>
#include<queue>
using namespace std;


// kth smallest element in a sorted matrix 

int kthsallest(int mat[MAX_PATH][MAX_PATH],int n, int k)
{
    //data(value),row,col
    vector<pair<int,pair<int,int>>>temp;

    for( int i=0;i<n;i++)
    {
        temp.push_back(make_pair(mat[i][0],make_pair(i,0)));
    }
    //create a min heap
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>p(temp.begin(),temp.end());
    int ans;
    pair<int,pair<int,int>>element;
    int i, j;
    while (k--)
    {
        element = p.top();
        p.pop();
        ans=element.first;//data
        i=element.second.first;//row number
        j=element.second.second;//column number

        if(j+1<n)
        {
            p.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
        }
    }
    return ans;

}

// MERGE K SORTED LINKED LIST

class node{ 

    public:
    int data ;
    node* next;

    node( int value)
    {
        data=value;
        next=NULL;
    }
};

class compare
{
    public:
    bool operator()(node* a , node* b)
    {
        return a->data > b->data;

    }
    
};

node* mergeksortedlists(node* arr[], int k)
{
    priority_queue<node*, vector<node*>, compare>p(arr,arr+k);
    //the priority queue conatains node pointer value with custoomised 
    //priority as the data will be given priority not the address value


    //dummy node 
    node* root= new node(0);
    node* tail= root;
    node* temp;

    while(!p.empty())
    {
        temp=p.top();
        p.pop();
        tail->next= temp;
        tail=tail->next;
        if( temp->next)
        {
            p.push(temp->next);
        }

    }
    return root->next ; 
}


//merge k sorted arrays

vector<int> mergeksorted(vector<vector<int>>arr, int k)
{
    vector<pair<int,pair<int,int>>>temp;

    for(int i=0;i<k;i++)
    {
        temp.push_back(make_pair(arr[i][0],make_pair(i,0)));
    }

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>p(arr.begin(), arr.end());

    vector<int>ans;
    pair<int,pair<int,int>>element;
    int i,j;
    while(!p.empty())
    {
        element=p.top();
        p.pop();

        ans.push_back(element.first);
        i=element.second.first;
        j=element.second.second;

        if(j+1<k)
        {
            p.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
        }
    }
    return ans;
}


// gaand phad solution
//merge sort upto k 

// mid = start + portion/2* 1

void merge(vector<int>&arr,int start,int mid,int end)
{
    vector<int>temp((end-start)+1);
    int left=start;
    int right=mid+1;
    int index=0;
    while (left<=mid && right<=end)
    {
        if(arr[left]<=arr[right])
        {
            temp[index]=arr[left];
            index++;
            left++;
        }
        else{
            temp[index]=arr[right];
            index++;
            right++;
        }

    }
    while(left<=mid)
    {
        temp[index]=arr[left];
        index++;
        left++;
    }
    while(right<=end)
    {
        temp[index]=arr[right];
        index++;
        right++;
    }
    index=0;
    while (start<=end)
    {
        arr[start]=temp[index];
        start++;
        index++;
    }
}

void mergesort(vector<int>&arr,int start,int end,int portion, int k)
{
    if (portion<2)
    {
        return;
    }
    int mid=start+(portion/2)*k-1;
    mergesort(arr,start,mid,portion/2,k);
    mergesort(arr,mid+1,end,portion-portion/2,k);
    merge(arr,start,mid,end);
}
vector<int> mergeksorted(vector<vector<int>>arr, int k)
{
    vector<int>ans;
    for(int i =0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            ans.push_back(arr[i][j]);
        }
    }

    mergesort(ans,0,ans.size()-1,k,k);

}

int main()
{
    
    return 0;
}