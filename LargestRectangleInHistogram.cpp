#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE 
vector<int> findNSE(vector<int> &arr)
{
    stack<int> st;
    int n=arr.size();
    vector<int> nse(n);
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        nse[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int> &arr)
{
    stack<int> st;
    int n=arr.size();
    vector<int> pse(n);
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        pse[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pse;
}

int LargestRectInHistogram(vector<int> &arr)
{
    int n=arr.size();
    int maxArea=0;
    vector<int> nse=findNSE(arr);
    vector<int> pse=findPSE(arr);

    for(int i=0;i<n;i++)
    {
        maxArea=max(maxArea,arr[i]*(nse[i]-pse[i]-1));
    }
    return maxArea;

}

//BETTER APPROACH
int LargestRectInHistogramBetter(vector<int> &arr)
{
    stack<int> st;
    int maxArea=0;
    for(int i=0;i<arr.size();i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            int element=st.top();
            st.pop();
            int nse=i;
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,arr[element]*(nse-pse-1));
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int nse=arr.size();
        int element=st.top();
        st.pop();
        int pse=st.empty()?-1:st.top();
        maxArea=max(maxArea,arr[element]*(nse-pse-1));
    }
    return maxArea;

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
    vector<int> arr={2,1,5,6,2,3};
    cout<<LargestRectInHistogramBetter(arr);
}

//WRITTEN BY SUBRAT:)