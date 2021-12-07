#include <iostream>
#include <algorithm>

using namespace std;
void input_one_d_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void input_2d_array(int **arr,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
}
void display(int **arr,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    int **arr=new int *[m];
    for(int i=0;i<m;i++)
    {
        arr[i]=new int[n];
    }
    input_2d_array(arr,m,n);
    display(arr,m,n);
    // int n;
    // cin>>n;
    // int arr[n];
    // input_one_d_array(arr,n);
    // cout<<"Before sort: "<<endl;
    // display(arr,n);
    // cout<<"After sort: "<<endl;
    // sort(arr,arr+n);
    // display(arr,n);
    //cout<<"Hello World"<<endl;
}