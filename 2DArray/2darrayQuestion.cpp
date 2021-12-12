#include <iostream>
#include <string>
#include <cmath>
#include <climits>

using namespace std;
void wakanda2(int **arr,int n);
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
    for(int r=0;r<m;r++)
    {
        for(int c=0;c<n;c++)
        {
            cout<<arr[r][c]<<"\t";
        }
        cout<<endl;
    }
}
void print_wakanda2()
{
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }
    input_2d_array(arr,n,n);
    wakanda2(arr,n);
}
void wakanda2(int **arr,int n)
{
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0,j=gap;j<n;i++,j++)
        {
            cout<<arr[i][j]<<"\t";
        }
    }
}
void print_saddle_price();
void saddle_price(int **arr,int n);
int find_min(int **arr,int ,int );
bool is_maxi_colmn(int **arr,int ,int ,int );
int main()
{
    print_saddle_price();
   // print_wakanda2();
    //display(arr,m,n);
}
void print_saddle_price()
{
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }
    input_2d_array(arr,n,n);
    saddle_price(arr,n);
}
void saddle_price(int **arr,int n)
{
    for(int r=0;r<n;r++)
    {
        int c=find_min(arr,r,n);
        if(is_maxi_colmn(arr,c,n,arr[r][c])==true)
        {
            cout<<arr[r][c]<<endl;
            break;
        }
    }

}
bool is_maxi_colmn(int **arr,int c,int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i][c]>x)
        {
            return false;
        }
    }
    return true;
}
int find_min(int **arr,int r,int n)
{
    int min_val=INT_MAX;
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[r][i]<min_val)
        {
            min_val=arr[r][i];
            pos=i;
        }
    }
    return pos;
}