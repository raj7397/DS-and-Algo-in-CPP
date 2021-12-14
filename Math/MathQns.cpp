#include <iostream>
#include <string>

using namespace std;
void solve_decimal_mult();
int decimal_mult(int ,int);
int decimal_addition(int,int);
int multiply_by_sing_digit(int,int);
void solve_anybase_mult();
int anybase_mult(int ,int ,int);
int mult_by_single_dig_in_anybase(int ,int ,int);
int add_in_anybase(int,int,int);
int anybase_to_dec(int ,int);
void solve_anybase_to_dec();

int main()
{

    //solve_anybase_to_dec();
    solve_anybase_mult();
 //   solve_decimal_mult();
}
void solve_anybase_mult()
{
    int n1,n2,b;
    cin>>n1>>n2>>b;
    int ans=anybase_mult(n1,n2,b);
    cout<<"ans for base: "<<b<<" is"<<ans<<endl;


}
void solve_anybase_to_dec()
{
    int n,b;
    cin>>n>>b;
    int ans=anybase_to_dec(n,b);
    cout<<"ans: "<<ans<<endl;
}
int anybase_to_dec(int n,int b)
{
    int ans=0,power=1;
    while(n!=0)
    {
        int d=n%10;
        n/=10;
        ans=ans+d*power;
        power*=b;
    }
    return ans;
}
int anybase_mult(int n1,int n2,int b)
{
    if(n2>n1)
    {
        int t=n2;
        n2=n1;
        n1=t;
    }
    int ans=0,power=1;
    while(n2!=0)
    {
        int d=n2%10;
        n2/=10;
        int multR=mult_by_single_dig_in_anybase(n1,d,b);
        ans=add_in_anybase(multR*power,ans,b);
        power*=10;
    }
    return ans;
}
int add_in_anybase(int n1,int n2,int b)
{
    int ans=0,power=1,carry=0;
    while(n1!=0 || n2!=0 || carry!=0)
    {
        int d1=n1%10;
        n1/=10;
        int d2=n2%10;
        n2/=10;
        int s=d1+d2+carry;
        int d=s%b;
        carry=d/b;
        ans=ans+d*power;
        power*=10;
    }
    return ans;
}
int mult_by_single_dig_in_anybase(int n1,int x,int b)
{
    int ans=0,power=1,carry=0;
    while(n1!=0 || carry!=0)
    {
        int r=n1%10;
        n1/=10;
        int s=r*x+carry;
        int d=s%b;
        carry=s/b;
        ans=ans+d*power;
        power*=10;
    }
    return ans;
}
void solve_decimal_mult()
{
    int n1,n2;
    cin>>n1>>n2;
    if(n2>n1)
    {
        int t=n2;
        n2=n1;
        n1=n2;
    }
    int ans=decimal_mult(n1,n2);
    cout<<"ans by method: "<<ans<<endl;
    cout<<"by ops: "<<(n1*n2)<<endl;
}
int multiply_by_sing_digit(int n1,int x)
{
    int ans=0,carry=0;
    int power=1;
    while(n1!=0 || carry!=0)
    {
        int r=n1%10;
        n1/=10;
        int t=r*x+carry;
        int d=t%10;
        carry=t/10;
        ans+=d*power;
        power*=10;
    }
    return ans;
}
int decimal_mult(int n1,int n2)
{
    int ans=0,power=1;
    while(n2!=0)
    {
        int d=n2%10;
        n2/=10;
        int multR=multiply_by_sing_digit(n1,d);
        ans=decimal_addition(multR*power,ans);
        power*=10;
    }
    return ans;
}
int decimal_addition(int n1,int n2)
{
    int ans=0,carry=0,power=1;
    while(n1!=0 || n2!=0 || carry!=0)
    {
        int d1=n1%10;
        n1/=10;
        int d2=n2%10;
        n2/=10;
        int sum=d1+d2+carry;
        int d=sum%10;
        carry=sum/10;
        ans=ans+d*power;
        power*=10;
    }
    return ans;
}