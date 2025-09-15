#include <iostream>
#include <vector>
using namespace std;

class heap{
    int *arr; //
    int size; // total elements in the heap 
    int total_size; //total size of the heap

    //
    public:

    heap(int n)
    {
        arr=new int[n];
        size=0;
        total_size=n;
    }

    // below written two codes are the parts of heapify process
    // heapify contains two parts as step-up or step-down 
    
    void insert (int val)
    {
        //check if heap size is valid or not 
        if(total_size==size)
        {
            cout<<"heap ovrerflow";
            return ;
        }
        arr[size]=val;
        int index=size;
        size ++;

        // swap to maintain the properties of heap 
        while (index>0 && arr[(index-1)/2]<arr[index])
        {
            swap(arr[(index-1)/2],arr[index]);
        }

        cout<<arr[index]<<"element inserted in the heap"<<endl; 
    }

    void print()
    {
        cout<<"the heap is:"<<endl;
        for (int i = 0;i<size;i++)
        {
            cout<< arr[i]<<" ";
        }
    }

    // code to delete a node from the heap. only the root element 
    // is deleted

    void heapify(int index)
    {
        int large=index;
        int left=index*2 +1;
        int right=index*2 +2;

        // the largest of three will get swapped
        if(left<size && arr[index]>arr[large])
        {
            large=left;
        }
        if(right<size && arr[index]>arr[large])
        {
            large=right;
        }

        if (large!=index)
        {
            swap(arr[index],arr[large]);
            heapify(large);

        }


    }

    void deletion()
    {
        if (size==0)
        {
            cout<<"heap undeflow";
            return;
        }

        cout<<arr[0]<<"deleted form the heap";
        arr[0]=arr[size-1];
        size--;

        if (size==0)
        {
            return;
        }
        else{
            heapify(0);
        }


    }


};

int main ()
{
    heap h1(10);
    h1.insert(10);
    h1.insert(20);
    h1.insert(30);
    h1.insert(12);
    h1.insert(15);

    h1.print();





}

