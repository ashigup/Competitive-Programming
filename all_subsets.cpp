//To find all non-empty subsets of a given set using bitmasking
//author--ashigup11


#include<iostream>
#include<bitset>
#include<vector>
#include<math.h>
#define ll long long int
using namespace std;
int main()
{  ll n,i,j,k,m;                
    cin>>n;            //n : number of elements
    vector<ll> a(n);     //a[] : array of given elements
    for(i=0;i<n;i++)
      cin>>a[i];
  ll y=pow(2,n);   
  bitset<32> s[y];
  for(i=1;i<y;i++)
  {
      bitset<32> x(i);
      s[i]=x;
  }
      
 for(k=1;k<=n;k++)
 {
      for(i=1;i<y;i++)
      {
      vector<ll> v;
      if(s[i].count()==k)
      {
          for(j=0;j<n;j++)
          {
              if(s[i][j]==1)
               v.push_back(a[j]);
          }
         for(m=0;m<k;m++)
           cout<<v[m]<<" ";
         cout<<"\n";  
      }
      }
cout<<"-------------------------------------------------------------------\n";      
 }
    return 0;
}