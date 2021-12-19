#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
void input(int *,int n);
void solve_distinct_ele_counts();
int distinct_ele_counts_On2(int *,int n);
int distinct_ele_counts_On(int *,int n);
void solve_freq_of_array_ele();
void freq_of_array_ele_On2(int *arr,int n);
void freq_of_array_ele_On(int *,int );
void solve_intersection_of_two_array();
int intersection_of_two_array_On2(int *,int *,int ,int);
int intersection_of_two_array_On(int *,int *,int ,int );
void solve_union_of_two_array();
int union_of_two_array_On2(int *,int *,int ,int);
int count_distinct_ele(int *,int ,vector<int>&);
int union_of_two_array_On(int *,int *,int m,int n);
void solve_pair_with_given_sum();
bool pair_with_given_sum_On2(int *,int n,int sum);
bool pair_with_given_sum_On(int *,int ,int );
void solve_is_0sum_subarray();
bool is_0sum_subarray_On2(int *arr,int n);
bool is_0sum_subarray_On(int *,int n);
void solve_subarray_with_given_sum();
bool subarray_with_given_sum_On(int *,int ,int);
bool subarray_with_given_sum_On2(int *,int,int);
void solve_longest_subarray_with_given_sum();
int longest_subarray_with_given_sum_On2(int *,int n,int sum);
int longest_subarray_with_given_sum_On(int *,int n,int sum);
void solve_longest_subarray_with_eq01();
int longest_subarray_with_eq01_On2(int *,int );
int longest_subarray_with_eq01_On(int *,int);
void solve_longest_subarray_with_same_sum_in_two_bin_array();
int longest_subarray_with_same_sum_in_two_bin_array_On2(int *,int *,int);
int longest_subarray_with_same_sum_in_two_bin_array_On(int *,int *,int);
void solve_longest_consecutive_subseq();
int longest_consecutive_subseq_Onlogn(int *,int );
int longest_consecutive_subseq_On(int *,int n);
void solve_dist_ele_windowK();
void dist_ele_windowK_Onk2(int *,int n,int k);
int dist_ele(int *arr,int s,int e);
void dist_ele_windowK_On(int *,int ,int);
int main()
{
    solve_dist_ele_windowK();
 //   solve_longest_consecutive_subseq();
    //solve_longest_subarray_with_same_sum_in_two_bin_array();
 //   solve_longest_subarray_with_eq01();
    //solve_longest_subarray_with_given_sum();
    //solve_subarray_with_given_sum();
//    solve_is_0sum_subarray();
//    solve_pair_with_given_sum();
 //   solve_union_of_two_array();
    //solve_intersection_of_two_array();
    //solve_distinct_ele_coudnts();
    //solve_freq_of_array_ele();
}
void dist_ele_windowK_On(int *arr,int n,int k)
{
    unordered_map<int,int>freq;
    for(int i=0;i<k;i++)
    {
        freq[arr[i]]++;
    }
    cout<<freq.size()<<" ";
    for(int i=k;i<n;i++)
    {
        freq[arr[i]]++;
        freq[arr[i-k]]--;
        if(freq[arr[i-k]]==0)
        {
             freq.erase(arr[i-k]);
        }
        cout<<freq.size()<<" ";
    }
    cout<<endl;
}
void solve_dist_ele_windowK()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    input(arr,n);
    int k;
    cin>>k;
    dist_ele_windowK_Onk2(arr,n,k);
    cout<<"O(n): "<<endl;
    dist_ele_windowK_On(arr,n,k);

}
int dist_ele(int *arr,int start,int end)
{
    int count=0;
    for(int i=start;i<=end;i++)
    {
        bool found=false;
        for(int j=i-1;j>=start;j--)
        {
            if(arr[i]==arr[j])
            {
                found=true;
                break;
            }
        }
        if(!found)
            count++;
    }
    return count;
}
 void dist_ele_windowK_Onk2(int *arr,int n,int k)
{
    for(int i=0;i<n-k+1;i++)
    {
        cout<<dist_ele(arr,i,i+k-1)<<" ";
    }
}
void solve_longest_consecutive_subseq()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    input(arr,n);
    int ans=longest_consecutive_subseq_Onlogn(arr,n);
    cout<<"O(nlogn): "<<ans<<endl;
    ans=longest_consecutive_subseq_On(arr,n);
    cout<<"O(n): "<<ans<<endl;
    

}
int longest_consecutive_subseq_On(int *arr,int n)
{
    int ans=0;
    unordered_set<int>s(arr,arr+n);
    for(auto x:s)
    {
        if(s.find(x-1)==s.end())
        {
            int count=1;
            while(s.find(x+count)!=s.end())
            {
                count++;
            }
            ans=max(ans,count);
        }
    } 
    return ans;
}
int longest_consecutive_subseq_Onlogn(int *arr,int n)
{
    sort(arr,arr+n);
    int ans=1,count=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1]+1)
        {
            count++;
        }
        else{
            ans=max(ans,count);
            count=1;
        }
    }
    return ans;
}
void solve_longest_subarray_with_same_sum_in_two_bin_array()
{
    int n;
    cin>>n;
    int *A=new int[n];
    int *B=new int[n];
    input(A,n);
    input(B,n);
    int ans=longest_subarray_with_same_sum_in_two_bin_array_On2(A,B,n);
    cout<<"O(n2): "<<ans<<endl;
    ans=longest_subarray_with_same_sum_in_two_bin_array_On(A,B,n);
    cout<<"O(n): "<<ans<<endl;
}
int longest_subarray_with_same_sum_in_two_bin_array_On(int *A,int *B,int n)
{
    for(int i=0;i<n;i++)
    {
        A[i]=A[i]-B[i];
    }
    return longest_subarray_with_given_sum_On(A,n,0);
}
int longest_subarray_with_same_sum_in_two_bin_array_On2(int *A,int *B,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int curr_sum1=0,curr_sum2=0;
        for(int j=i;j<n;j++)
        {
            curr_sum1+=A[j];
            curr_sum2+=B[j];
            if(curr_sum1==curr_sum2)
            {
                ans=max(ans,j-i+1);
            }
        }
    }
    return ans;
}
void solve_longest_subarray_with_eq01()
{
    int n;
    cin>>n;
    int *A=new int[n];
    //int *B=new int[n];
    input(A,n);
    //input(B,n);
    int ans=longest_subarray_with_eq01_On2(A,n);
    cout<<"O(n2): "<<ans<<endl;
    ans=longest_subarray_with_eq01_On(A,n);
    cout<<"O(n): "<<ans<<endl;
}
int longest_subarray_with_eq01_On(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)
            A[i]=-1;
    }
    unordered_map<int,int>m;
    int pre_sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        pre_sum+=A[i];
        if(pre_sum==0)
        {
            ans=max(ans,i+1);
        }
        if(m.find(pre_sum)==m.end())
        {
            m[pre_sum]=i;
        }
        if(m.find(pre_sum)!=m.end())
        {
            ans=max(ans,i-m[pre_sum]);
        }
    }
    return ans;

}
int longest_subarray_with_eq01_On2(int *A,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int c0=0,c1=0;
        for(int j=i;j<n;j++)
        {
            if(A[j]==0)
            {
                c0++;
            }
            else{
                c1++;
            }
            if(c0==c1)
            {
                ans=max(ans,c0+c1);
            }
        }

    }
    return ans;
}
void solve_longest_subarray_with_given_sum()
{
    int n;
    cin>>n;
    int *arr= new int[n];
    input(arr,n);
    int sum;
    cin>>sum;
    int ans=longest_subarray_with_given_sum_On2(arr,n,sum);
    cout<<"O(n2): "<<ans<<endl;
    ans=longest_subarray_with_given_sum_On(arr,n,sum);
    cout<<"O(n): "<<ans<<endl;
}
int longest_subarray_with_given_sum_On(int *arr,int n,int sum)
{
    unordered_map<int,int>m;
    int ans=0;
    int pre_sum=0;
    for(int i=0;i<n;i++)
    {
        pre_sum+=arr[i];
        if(pre_sum==sum)
        {
            ans=max(i+1,ans);
        }
        if(m.find(pre_sum)==m.end())
        {
            m[pre_sum]=i;
        }
        if(m.find(pre_sum-sum)!=m.end())
        {
            ans=max(ans,i-m[pre_sum-sum]);
        }
    }
    return ans;

}
int longest_subarray_with_given_sum_On2(int *arr,int n,int sum)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int curr_sum=0;
        for(int j=i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==sum)
            {
                ans=max(ans,j-i+1);
            }
        }
    }
    return ans;
}
bool subarray_with_given_sum_On(int * arr,int n,int sum)
{
    unordered_set<int>s;
    int pre_sum=0;
    for(int i=0;i<n;i++)
    {
        if(pre_sum==sum)
            return true;
        if(s.find(pre_sum-sum)!=s.end())
            return true;
        s.insert(pre_sum);
    }
    return false;
}
void solve_subarray_with_given_sum()
{
    int n;
    cin>>n;
    int *arr =new int[n];
    input(arr,n);
    int sum;
    cin>>sum;
    bool pres=subarray_with_given_sum_On2(arr,n,sum);
    if(pres)
        cout<<"found in O(n2)"<<endl;
    else{
        cout<<"not found in O(n2)"<<endl;
    }
    bool pres1=subarray_with_given_sum_On(arr,n,sum);
    if(pres1)
    {
        cout<<"found in O(n)";
    }
    else{
        cout<<"Not found in O(n)";
    }
}
bool subarray_with_given_sum_On2(int * arr,int n,int sum)
{
    for(int i=0;i<n;i++)
    {
        int curr_sum=0;
        for(int j=i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==sum)
                return true;
        }
    }
    return false;
}
void solve_is_0sum_subarray()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    input(arr,n);
    bool isPres=is_0sum_subarray_On2(arr,n);
    if(isPres)
        cout<<"found "<<endl;
    else{
        cout<<"not found"<<endl;
    }
    bool isPres1=is_0sum_subarray_On(arr,n);
    if(isPres1)
        cout<<"found in O(n)"<<endl;
    else{
            cout<<"not found in O(n)"<<endl;
        }
    //isPres1?(cout<<"found in O(n)"); : cout<<"not found in O(n)"
}
bool is_0sum_subarray_On(int * arr,int n)
{
    unordered_set<int>s;
    int pre_sum=0;
    for(int i=0;i<n;i++)
    {
        pre_sum+=arr[i];
        if(pre_sum==0)
            return true;
        if(s.find(pre_sum)!=s.end())
            return true;
        s.insert(pre_sum);
        
    }
    return false;
}
bool is_0sum_subarray_On2(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int curr_sum=0;
        for(int j=i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==0)
                return true;
        }
    }
    return false;
}
bool pair_with_given_sum_On(int *arr,int n,int sum)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        if(s.find(sum-arr[i])!=s.end())
        {
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}
void solve_pair_with_given_sum()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    input(arr,n);
    int sum;
    cin>>sum;
    bool present=pair_with_given_sum_On2(arr,n,sum);
    if(present)
    {
        cout<<"found in O(n2)"<<endl;
    }
    else {
        cout<<"not found in O(n2)"<<endl;
    }
    bool pres=pair_with_given_sum_On(arr,n,sum);
    if(pres)
    {
        cout<<"found in O(n)"<<endl;
    }
    else{
        cout<<"not found in O(n)"<<endl;
    }
}
bool pair_with_given_sum_On2(int *arr,int n,int sum)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==sum)
                return true;
        }
    }
    return false;
}
void solve_union_of_two_array()
{
    int m;
    cin>>m;
    int *A=new int[m];
    input(A,m);
    int n;
    cin>>n;
    int *B=new int[n];
    input(B,n);
    int ans=union_of_two_array_On2(A,B,m,n);
    cout<<"O(n2): "<<ans<<endl;
    ans=union_of_two_array_On(A,B,m,n);
    cout<<"O(n): "<<ans<<endl;
}
int union_of_two_array_On(int *A,int *B,int m,int n)
{
    unordered_set<int>s;
    for(int i=0;i<m;i++)
    {
        s.insert(A[i]);
    }
    for(int i=0;i<n;i++)
    {
        s.insert(B[i]);
    }
    return s.size();
}
int  count_distinct_ele(int * arr,int m,vector<int>&distele)
{
    int ans=0;
   for(int i=0;i<m;i++)
    {
        bool found=false;
        for(int j=0;j<distele.size();j++)
        {
            if(arr[i]==distele[j])
            {
                found=true;
                break;
            }
        }
        if(!found)
        {
            distele.push_back(arr[i]);
            ans++;
        }
    }
    return ans;
}
int union_of_two_array_On2(int *A,int *B,int m,int n)
{
    int ans=0;
    vector<int>distele;
    int ans1=count_distinct_ele(A,m,distele);
    int ans2=count_distinct_ele(B,n,distele);
    return ans1+ans2;

}
void solve_intersection_of_two_array()
{
    int m,n;
    cin>>m;
    int *A=new int[m];
    input(A,m);
    cin>>n;
    int *B=new int[n];
    input(B,n);
    int ans=intersection_of_two_array_On2(A,B,m,n);
    cout<<"O(n2): "<<ans<<endl;
    ans=intersection_of_two_array_On(A,B,m,n);
    cout<<"O(n): "<<ans<<endl;
}
int intersection_of_two_array_On2(int *A,int *B,int m,int n)
{
    int ans=0;
    for(int i=0;i<m;i++)
    {
        bool found=false;
        for(int j=i-1;j>=0;j--)
        {
            if(A[i]==A[j])
            {
                found=true;
                break;
            }
        }
        if(!found)
        {
            for(int k=0;k<n;k++)
            {
                if(A[i]==B[k])
                {
                    ans++;
                    break;
                }
            }
        }
    }
    return ans;
}
int intersection_of_two_array_On(int *A,int *B,int m,int n)
{
    unordered_set<int>s;
    for(int i=0;i<m;i++)
    {
        s.insert(A[i]);
    }
    int ans=0;
    for(int j=0;j<n;j++)
    {
        if(s.find(B[j])!=s.end())
        {
            ans++;
            s.erase(B[j]);
        }
    }
    return ans;
}
void solve_freq_of_array_ele()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    input(arr,n);
    cout<<"O(n2):"<<endl;
    freq_of_array_ele_On2(arr,n);
    cout<<"O(n): "<<endl;
    freq_of_array_ele_On(arr,n);

}
void freq_of_array_ele_On2(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        bool found=false;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]==arr[i])
            {
                found=true;
                break;
            }
        }
        if(found==false)
        {
            int count=1;
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                }
            }
            cout<<arr[i]<<"-->"<<count<<endl;
        }
    }
}
void freq_of_array_ele_On(int *arr,int n)
{
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(auto x:freq)
    {
        cout<<(x.first)<<"-->"<<(x.second)<<endl;
    }
}    
void solve_distinct_ele_counts()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    input(arr,n);
    int ans=distinct_ele_counts_On2(arr,n);
    cout<<"O(n2): "<<ans<<endl;
    ans=distinct_ele_counts_On(arr,n);
    cout<<"O(n): "<<ans<<endl;
}
int distinct_ele_counts_On(int *arr,int n)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }    
    return s.size();
}
void input(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
int distinct_ele_counts_On2(int *arr,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        bool found = false;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]==arr[j])
            {
                found = true;
                break;
            }
        }
        if(found == false)
            ans++;
    }
    return ans;
}
