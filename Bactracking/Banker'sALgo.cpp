#include<iostream>
#define MAX 10;
using namespace std;

class Bankers{
    private:
        int al[MAX][MAX],m[MAX][MAX],n[MAX][MAX],avail[MAX];
        int nop,nor,k,result[MAX],pnum,work[MAX],finish[MAX];

    public:
        Bankers()
        {
            k=0;
            for(int i=0;i<MAX;i++)
            {
                for(int j=0;j<MAX;j++)
                {
                    al[i][j]=0;
                    m[i][j]=0;
                    n[i][j]=0;
                }
                avail[i]=0;
                result[i]=0;
                finish[i]=0;
            }
        }
        void input(){
            int i,j;
            int nop,nor;
            cout<<"Enter the number of processes: ";
            cin>>nop;
            cout<<"enter the number of resources:";
            cin>>nor;
            cout<<"enter the allocation matrix:";

            cout <<"enter the no of resources per instance:";
            for (int i = 0;i<nor;i++)
            {
                cin>>avail[i];
            }


            for (int i = 0;i<nop;i++)
            {
                for (int j=0;i<nor,j++)
                {
                    cin>>al[i][j];
                }
            }
            cout<<"enter the max matrix:";
            for (int i = 0;i<nop;i++)
            {
                for (int j=0;i<nor,j++)
                {
                    cin>>m[i][j];
                }
            }

            cout<<"enter the available vector"
            for (int i = 0;i<nor;i++)
            {
                cin>>avail[i];
            }
            
        }
        
        void minus()
        {
            for (int i = 0;i<nop;i++)
            {
                for (int j=0;i<nor,j++)
                {
                    n[i][j]=m[i][j]-al[i][j];
                }
            }
        }
        void show()
        {
            cout<<"Allocation matrix is:";
            for (int i = 0;i<nop;i++)
            {
                for (int j=0;i<nor,j++)
                {
                    cout<<al[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"Max matrix is:";
            for (int i = 0;i<nop;i++)
            {
                for (int j=0;i<nor,j++)
                {
                    cout<<m[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"Need matrix is:";
            for (int i = 0;i<nop;i++)
            {
                for (int j=0;i<nor,j++)
                {
                    cout<<n[i][j]<<" ";
                }
                cout<<endl;
            }
        }
       
};

int main()
{
    Bankers b;
    b.input();
    b.minus();
    b.show();
    return 0;
}