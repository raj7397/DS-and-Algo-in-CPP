#include <iostream>
#include <string>

using namespace std;
void driver_of_all_substr();
void all_substr(string str);
void driver_for_all_palin_substr();
void all_palin_substr(string str);
bool is_palindrome(string );
int main()
{
   // driver_of_all_substr();
    driver_for_all_palin_substr();
}
void driver_for_all_palin_substr()
{
    string str;
    cin>>str;
    all_palin_substr(str);
}
bool is_palindrome(string str)
{
    int start=0,end=str.length()-1;
    while(start<=end)
    {
        if(str[start]!=str[end])
            return false;
        start++;
        end--;
    }
    return true;
}
void all_palin_substr(string str)
{
    int n=str.length();
    for(int start=0;start<n;start++)
    {
        for(int end=start;end<n;end++)
        {
            string subS=str.substr(start,end-start+1);
            if(is_palindrome(subS))
                cout<<subS<<endl;
        }
    }
}
void driver_of_all_substr()
{
    string str;
    cin>>str;
    all_substr(str);
}
void all_substr(string str)
{
    int n=str.length();
    for(int start=0;start<n;start++)
    {
        for(int end=start;end<n;end++)
        {
            for(int i=start;i<=end;i++)
            {
                cout<<str[i];
            }
            cout<<endl;
        }
    }   
}