#include <iostream>
#include <string>

using namespace std;
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
int main()
{
    int m,n;
    cin>>m>>n;
    int **arr=new int*[m];
    for(int i=0;i<m;i++)
    {
        arr[i]=new int[n];
    }
    input_2d_array(arr,m,n);
    display(arr,m,n);
}