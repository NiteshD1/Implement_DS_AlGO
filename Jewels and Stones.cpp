#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--)
{

    int c=0,flag=0;
    string j,s;
    cin>>j>>s;


    for(int i=0;i<(int)s.size();i++){

        for(int k=0;k<(int)j.size();k++){
            if(s[i]==j[k]){
                c++;
                break;
            }
        }
    }

    cout<<c<<endl;




}

return 0;
}
