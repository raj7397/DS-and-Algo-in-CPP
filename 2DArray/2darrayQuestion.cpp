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
void driver_for_spiral();
void spiral(int **arr,int n,int m);
void check_arr2d_return();
int ** arr2d_return(int n,int m);
void driver_for_exit_point();
int ** create_2d_array(int &,int &);
void exit_point(int **arr,int n,int m);
void driver_for_ring_rotate();
void ring_rotate(int **,int ,int ,int,int);
int * from2d_to_oneD(int **,int,int ,int);
void rotate(int *arr,int,int,int ,int);
void reverse(int *arr,int i,int j);
void fill_2d_array(int **arr,int ,int m,int s,int *);
void driver_for_state_of_wakanda2();
void driver_for_sow2();
void state_of_wakanda2(int **arr,int n,int m);
int main()
{
    //driver_for_ring_rotate();
    //driver_for_exit_point();
  //  check_arr2d_return();
    //driver_for_spiral();
    //print_saddle_price();
   // print_wakanda2();
    //display(arr,m,n);
  //  driver_for_state_of_wakanda2();
  driver_for_sow2();
}

void state_of_wakanda2(int **arr,int n,int m)
{

    for(int gap=0;gap<m;gap++)
    {
        for(int i=0,j=gap;j<m;i++,j++)

        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int * from2d_to_oneD(int **arr,int n,int m,int s)
{
    int minr=s-1;
    int minc=s-1;
    int maxr=n-s;
    int maxc=m-s;
    int total=(maxr-minr+1)*2+(maxc-minc+1)*2-4;
    cout<<"total: "<<total<<endl;
    int idx=0;
    int *oneD=new int[total];
    for(int i=minr;i<=maxr;i++)
    {
        oneD[idx]=arr[i][minc];
        idx++;
    }
    minc++;
    for(int i=minc;i<=maxc;i++)
    {
        oneD[idx]=arr[maxr][i];
        idx++;
    }
    maxr--;
    for(int i=maxr;i>=minr;i--)
    {
        oneD[idx]=arr[i][maxc];
        idx++;    
    }
    maxc--;
    for(int i=maxc;i>=minc;i--)
    {
        oneD[idx]=arr[minr][i];
        idx++;
    }
    minr--;
    cout<<"Printing oneD array: "<<endl;
    for(int i =0;i<total;i++)
    {
        cout<<oneD[i]<<" ";
    }
    cout<<endl;
    return oneD;
}
void driver_for_ring_rotate()
{
    int n,m,s,r;
    int **arr=create_2d_array(n,m);
    cin>>s>>r;
    ring_rotate(arr,n,m,s,r);
}
void ring_rotate(int **arr,int n,int m,int s,int r)
{
   // display(arr,n,m);
   // cout<<"s: "<<s<<" r: "<<r<<endl;
    int * oneDArra=from2d_to_oneD(arr,n,m,s);
    rotate(oneDArra,n,m,s,r);
    int minr=s-1;
    int minc=s-1;
    int maxr=n-s;
    int maxc=m-s;
    int t=(maxr-minr+1)*2+(maxc-minc+1)*2-4;
    cout<<"After oneD array rotate: "<<endl;
    for(int i=0;i<t;i++)
        cout<<oneDArra[i]<<" ";
    cout<<"\n-------------"<<endl;
    //cout<<"Before fill 2d array: "<<endl;
    //display(arr,n,m);
    fill_2d_array(arr,n,m,s,oneDArra);
    cout<<"After fill 2d array: "<<endl;

    display(arr,n,m);
}
void rotate(int *arr,int n,int m,int s,int r)
{
    int minr=s-1;
    int minc=s-1;
    int maxr=n-s;
    int maxc=m-s;
    int t=(maxr-minr+1)*2+(maxc-minc+1)*2-4;
    r=(r%t+t)%t;
    reverse(arr,0,t-r-1);
    reverse(arr,t-r,t-1);
    reverse(arr,0,t-1);
}
void fill_2d_array(int **arr,int n,int m,int s,int *oneD)
{
    int minr=s-1;
    int minc=s-1;
    int maxr=n-s;
    int maxc=m-s;
 //   int t=(maxr-minr+1)*2+(maxc-minc+1)*2-4;
    int idx=0;
    for(int i=minr;i<=maxr;i++)
    {
        arr[i][minc]=oneD[idx++];
    }
    minc++;
    for(int i=minc;i<=maxc;i++)
    {
        arr[maxr][i]=oneD[idx++];
    }
    maxr--;
    for(int i=maxr;i>=minr;i--)
    {
        arr[i][maxc]=oneD[idx++];
    }
    maxc--;
    for(int i=maxc;i>=minc;i--)
    {
        arr[minr][i]=oneD[idx++];
    }
    minr++;
}
void reverse(int *arr,int i,int j)
{
    while(i<=j)
    {
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
        i++;
        j--;
    }
}
void exit_point(int **arr,int n,int m)
{
    int dir=0;
    int i=0,j=0;
    while(true)
    {
        dir=dir+arr[i][j];
        dir%=4;
        if(dir==0)
        {
            j++;
        }
        else if(dir==1)
        {
            i++;
        }
        else if(dir==2)
        {
            j--;
        }
        else {
            i--;
        }
        if(i<0 || i>=n || j<0 || j>=m)
            break;
    }
    if(i<0)
    {
        i++;
    }
    if(j<0)
    {
        j++;
    }
    if(i>=n)
    {
        i--;
    }
    if(j>=m)
    {
        j--;
    }
    cout<<i<<endl;
    cout<<j<<endl;
}
void driver_for_exit_point()
{
    int n,m;
    int **arr=create_2d_array(n,m);
    exit_point(arr,n,m);
}
int ** create_2d_array(int &n,int &m)
{
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[m];
    }
    input_2d_array(arr,n,m);
    return arr;

}
int **arr2d_return(int n,int m)
{
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[m];
    }
    input_2d_array(arr,n,m);
    cout<<"Display before return: "<<endl;
    display(arr,n,m);
    return arr;
}
void check_arr2d_return()
{
    int n,m;
    cin>>n>>m;
    int **arr=arr2d_return(n,m);
    cout<<"Display from check_arr2d_return: "<<endl;
    display(arr,n,m);
}
void driver_for_spiral()
{
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
        arr[i]=new int[m];
    cout<<"Enter n*m elements: "<<endl;
    input_2d_array(arr,n,m);
    display(arr,n,m);
    spiral(arr,n,m);

}
void spiral(int **arr,int n,int m)
{
    int minr=0;
    int maxr=n-1;
    int minc=0;
    int maxc=m-1;
    int count=0;
    int total=n*m;
    while(count<total)
    {
        for(int i=minr;i<=maxr && count<total;i++)
        {
            cout<<arr[i][minc];
            count++;
        }
        minc++;
        for(int i=minc;i<=maxc && count<total;i++)
        {
            cout<<arr[maxr][i]<<" ";
            count++;
        }
        maxr--;
        for(int i=maxr;i>=minr && count<total;i--)
        {
            cout<<arr[i][maxc]<<" ";
            count++;
        }
        maxc--;
        for(int i=maxc;i>=minc && count<total;i--)
        {
            cout<<arr[minr][i]<<" ";
            count++;
        }
        minr++;
    }

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
void driver_for_sow2()
{

    int n,m;
    int **arr=create_2d_array(n,m);
 //   input_2d_array(arr,n,m);
    state_of_wakanda2(arr,n,m);

}
void driver_for_state_wakanda2()
{
    int n,m;
    int **arr=create_2d_array(n,m);
    input_2d_array(arr,n,m);
    state_of_wakanda2(arr,n,m);
}