#include<iostream>
using namespace std;




int arr[1000001];



bool binarySearch(int i, int j, int m)
{
    if(i>j)
    {
        return false;
    }
    
    int mid = (i+j)/2;
    if(arr[mid] == m)
        return true;
    if(m < arr[mid])
        return binarySearch(i, mid-1, m);
    if(m > arr[mid])    
        return binarySearch(mid+1, j, m);
    
}


int main()
{
    int T, n, m;
    cin>>T;
    
    for(int t=0; t<T; t++)
    {
        cin>>n>>m;
        for(int i =0; i<n; i++)
        {
            cin>>arr[i];
        }
        
        if(binarySearch(0,n-1,m) == true)
            cout<<1;
        else 
            cout<<-1;
            
        cout<<endl;
    }
}
