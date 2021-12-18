#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

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
void solve_median_in_sorted_array();
double median_in_sorted_array(int *,int *,int,int);
int main()
{
    solve_median_in_sorted_array();
// solve_find_pivot(); 
}

void solve_median_in_sorted_array()
{
    int n1,n2;
    cin>>n1;
    int *A=new int[n1];
    input_one_d_array(A,n1);
    cin>>n2;
    int *B=new int[n2];
    input_one_d_array(B,n2);
    double ans=median_in_sorted_array(A,B,n1,n2);
    cout<<"ans: "<<ans<<endl;
}
double median_in_sorted_array(int *A,int *B,int n1,int n2)
{
    if(n1>n2)
    {
        int *t=A;
        A=B;
        B=t;
    }
    int li=0,ri=n1;
    while(li<=ri)
    {
        int i1=(li+ri)/2;
        int i2=(n1+n2+1)/2-i1;
        int max1=(i1==0) ? INT_MIN :A[i1-1];
        int max2=(i2==0) ? INT_MIN : B[i2-1];
        int min1=(i1==n1) ? INT_MAX : A[i1];
        int min2= (i2==n2) ? INT_MAX: B[i2];
        if(max1<=min2 && max2<=min1)
        {
            if((n1+n2)%2==0)
            {
                double ans=((double)(max(max1,max2)+min(min1,min2))/2);
                return ans;
            }
            else{
                double ans=(double)max(max1,max2);
                return ans;
            }
        }
        else if(max1>min2){
            ri=i1-1;
        }
        else{
            li=i1+1;
        }
    }
    return -1;
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