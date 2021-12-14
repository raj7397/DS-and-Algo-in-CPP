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
void solve_find_pivot();
int find_pivot(int *arr,int n);
int main()
{
 solve_find_pivot(); 
}
void solve_find_pivot()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    input_one_d_array(arr,n);
    int ans=find_pivot(arr,n);  
    cout<<"pivot: "<<ans<<endl;  
}
int find_pivot(int *arr,int n)
{
    int li=0,ri=n-1;
    while(li<=ri)
    {
        int mid=li+(ri-li)/2;
        if(mid<ri && arr[mid]>arr[mid+1])
            return mid;
        if(mid>li && arr[mid-1]>arr[mid])
            return mid-1;
        if(arr[li]<=arr[mid])
            li=mid+1;
        else{
            ri=mid-1;
        }
    }
    return -1;
}