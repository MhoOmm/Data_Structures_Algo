#include <iostream>
#include <vector>
using namespace  std;

// array implementation
// class deque{
//     public:
//     int *arr;
//     int front,rear,size;
//     deque(int x)
//     {
//         size=x;
//         front=rear=-1;
//         arr=new int[x];
//     }
//     bool is_empty(){
//         return front==-1;
//     }
//     bool is_full(){
//         return (rear+1)%size==front;
//     }
//     void push_front(int x)
//     {
//         if(front==-1)
//         {
//             rear=front=0;
//             arr[0]=x;
//             return ;
//         }
//         else if(is_full())
//         {
//             cout<<"overflow";
//             return;
//         }
//         else{
//             front=(front-1+size)%size;
//             arr[front]=x;
//             return;
//         }
//     }
//     void pop_front(int x)
//     {
//         if(front==-1)
//         {
//             rear=front=0;
//             arr[0]=x;
//             return ;
//         }
//         else if(is_full())
//         {
//             cout<<"overflow";
//             return;
//         }
//         else{
//             rear=(rear+1)%size;
//             arr[rear]=x;
//             return;
//         }
//     }
//     void pop_front()
//     {
//         if(is_empty())
//         {
//             cout<<"underflow";
//             return;
//         }
//         else{
//             if (front==rear)
//             {
//                 front=rear=-1;
//             }
//             else{
//                 front=(front+1)%size;
//             }
//         }
//     void pop_back()
//     {
//         if(is_empty())
//         {
//             cout<<"underflow";
//         }
//         else{
//             if (front==rear)
//             {
//                 front=rear=-1;
//             }
//             else{
//                 rear=(rear-1+size)%size;
//             }
//         }
//     }
// };

// int main()
// {
//     return 0;
// }