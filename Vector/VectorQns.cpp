#include <iostream>
#include <string>
#include <vector>

using namespace std;
void vector_demo();
void oneD_vector_demo();
int main()
{
    oneD_vector_demo();
    //vector_demo();
}
void oneD_vector_demo()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void vector_demo()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));// default inintialize to 0
    cout<<"Displaying default vector: "<<endl;
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<m;c++)
        {
            cout<<arr[r][c]<<" ";
        }
        cout<<endl;
    }
}
