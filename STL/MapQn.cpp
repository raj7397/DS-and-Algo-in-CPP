#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int,int> myMap;
    map<int,int>:: iterator itr;

    myMap.insert({2,20});
    myMap[1]=30;
    myMap.insert(make_pair(30,49));
    for(auto x:myMap)
    {
        cout<<"key: "<<(x.first)<<" value: "<<(x.second)<<endl;
    }
    myMap.erase(1);
    cout<<"After erase 1"<<endl;
    for(itr=myMap.begin();itr!=myMap.end();itr++)
    {
        cout<<"key: "<<(itr->first)<<" value: "<<itr->second<<endl;
    }
    itr=myMap.find(2);
    cout<<"found key: "<<(itr->first)<<" value: "<<(itr->second)<<endl;
    //pair<int,int>:: iterator  p=myMap.find(2);
    int t=myMap[2];
    cout<<"t: "<<t<<endl;
    cout<<"diff: "<<myMap[333]<<endl;
}