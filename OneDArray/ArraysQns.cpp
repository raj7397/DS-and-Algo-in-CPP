#include <iostream>
#include <string>
#include <cmath>

using namespace std;
void solve_all_subset();
void input(int *arr,int n);
void all_subset(int *arr,int n);
void display(int *arr,int n);
int main()
{
    int *arr=new int[0];
    //int arr[1];
    cout<<"Hi"<<endl;
    arr[0]=1901;
    cout<<arr[0]<<endl;
  /*  int n=3;
    int t=(int)pow(10,3);
    cout<<"t: "<<t<<endl;*/
    //solve_all_subset();
}
void solve_all_subset()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    input(arr,n);
    all_subset(arr,n);
   // display(arr,n);
}
void all_subset(int *arr,int n)
{

    int ts=(int)(pow(2,n)+0.5);
    cout<<"ts: "<<ts<<endl;
    for(int i=0;i<ts;i++)
    {
        int temp=i;
        for(int j=n-1;j>=0;j--)
        {
            if((temp &(1<<j))!=0)
            {
                cout<<arr[n-j-1]<<"\t";
            }
            else{
                cout<<"-\t";
            }
        }
        cout<<endl;
    }
}
void input(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cin>>arr[i];
}
void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}