#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &arr)
{
    vector<int> st;
    int n=arr.size();

    for(int i=0;i<n;i++)
    {
        if(arr[i]>0) st.push_back(arr[i]);
        else{
            while(!st.empty() && st.back()<abs(arr[i]) && st.back()>0)
            {
                st.pop_back();
            }
            if(!st.empty() && st.back()==abs(arr[i]))
            {
                st.pop_back();
            }
            else if(st.empty() || st.back()<0)
            {
                st.push_back(arr[i]);
            }
        }
    }
    return st;
}
void print(vector<int> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    vector<int> arr={4,7,1,1,2,-3,-7,17,15,-16};
    vector<int> ans=asteroidCollision(arr);
    print(ans);
}

//WRITTEN BY SUBRAT:)