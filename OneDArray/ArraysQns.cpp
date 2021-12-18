#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;
void solve_all_subset();
void input(int *arr,int n);
void all_subset(int *arr,int n);
void display(int *arr,int n);
void solve_equilibrium_point();
int equilibrium_point_On2(int * arr, int n);
int equilibrium_point_On(int * , int );
void solve_max_freq_in_range();
int max_freq_in_range(int *, int *,int );
int max_freq_in_limited_range(int *,int *,int n);
void solve_max_sum_in_subarray_sizeK();
int max_sum_in_subarray_sizeK_On2(int *,int ,int k);
int max_sum_in_subarray_sizeK_On(int *,int n,int k);
int main()
{
    solve_max_sum_in_subarray_sizeK();
    //solve_max_freq_in_range();
    //solve_equilibrium_point();
 //   int *arr=new int[0];
    //int arr[1];
   // cout<<"Hi"<<endl;
   // arr[0]=1901;
    //cout<<arr[0]<<endl;
  /*  int n=3;
    int t=(int)pow(10,3);
    cout<<"t: "<<t<<endl;*/
    //solve_all_subset();
}
int max_sum_in_subarray_sizeK_On(int * arr,int n,int k)
{
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    int max_sum=sum;
    for(int i=k;i<n;i++)
    {
        sum=sum-arr[i-k]+arr[i];
        max_sum=max(max_sum,sum);
    }
    return max_sum;
}
void solve_max_sum_in_subarray_sizeK()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    input(arr,n);
    int k;
    cin>>k;
    int ans=max_sum_in_subarray_sizeK_On2(arr,n,k);
    cout<<"O(n2): "<<ans<<endl;
    ans=max_sum_in_subarray_sizeK_On(arr,n,k);
    cout<<"O(n): "<<ans<<endl;
}
int max_sum_in_subarray_sizeK_On2(int *arr,int n,int k)
{
    int max_sum=INT_MIN;
    for(int i=0;i<n-k+1;i++)
    {
        int curr_sum=0;
        for(int j=0;j<k;j++)
        {
            curr_sum+=arr[i+j];
        }
        if(curr_sum>max_sum)
        {
            max_sum=curr_sum;
        }
    }
    return max_sum;
}
void solve_max_freq_in_range()
{
    int n;
    cin>>n;
    int *L=new int[n];
    int *R=new int[n];
    cout<<"first range"<<endl;
    input(L,n);
    input(R,n);
    int ans=max_freq_in_range(L,R,n);
    cout<<"ans1: "<<ans<<endl;
    ans=max_freq_in_limited_range(L,R,n);
    cout<<"ans2: "<<ans<<endl;
    
}
int max_freq_in_range(int *L,int *R,int n)
{
    unordered_map<int,int>freq;
    for(int i=0;i<n;i++)
    {
        int start=L[i];
        int end=R[i];
        for(int k = start ; k <= end; k++)
        {
            freq[k]++;
        }
    }
    int ans=-1;
    int max_freq=INT_MIN;
    for(auto x:freq)
    {
        cout<<"Key: "<<(x.first)<<" value: "<<(x.second)<<endl;
        if(x.second>max_freq)
        {
            max_freq=x.second;
            ans=x.first;
        }
    }
    return ans;
}
int max_freq_in_limited_range(int *L, int *R,int n)
{
    int limit=R[n-1];
    vector<int>freq(limit+1,0);
    for(int i=0;i<n;i++)
    {
        freq[L[i]]++;
        freq[R[i]+1]--;
    }
//    int pre_sum=0;
    int max_freq=INT_MIN,ans=-1;
    for(int i=1;i<=limit;i++)
    {
        freq[i]+=freq[i-1];
        if(freq[i]>max_freq)
        {
            max_freq=freq[i];
            ans=i;
            //+-
        }
    }
    return ans;
}
void solve_equilibrium_point()
{
    int n;
    cin>>n;
    int *arr=new int [n];
    input(arr , n );
    int ans=equilibrium_point_On2(arr,n);
    cout<<"O(n2): "<<ans<<endl;
    ans=equilibrium_point_On(arr , n);
    cout<<"O(n): "<<ans<<endl;
}
int equilibrium_point_On2(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int lsum=0;
        for(int j = 0;j < i ; j++)
        {
            lsum+=arr[j];
        }
        int rsum=0;
        for(int j = i+1 ;j < n ; j++)
        {
            rsum+=arr[j];
        }
        if(lsum==rsum)
            return i;
    }
    return -1;
}
int equilibrium_point_On(int * arr , int n)
{
    int sum=0;
    for(int i = 0;i < n; i++)
    {
        sum+=arr[i];
    }
    int left_sum=0;
    for(int i = 0; i < n ; i++)
    {
        if(left_sum == sum-arr[i])
        {
            return i;
        }
        left_sum+=arr[i];
        sum = sum - arr[i];
    }
    return -1;

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