
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];
map<int,string> mpp;
map<string,int> mp;

struct Connection{
    string firstTown,secondTown;
    int cost;
};

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

vector<Connection> kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    vector<Connection> res;
    Connection temp;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        temp.cost=cost;
        temp.firstTown=mpp[x];
        temp.secondTown=mpp[y];
        if(root(x) != root(y))
        {
            
            minimumCost += cost;
            union1(x, y);
            res.push_back(temp);
        }    
    }
    return res;
}


vector<Connection> minimumCost(int num, vector<Connection> con)
{
    int cc=0;
    int i=0;
    edges=num;
    initialize();
    for(auto c:con)
    {
        if(mp.find(c.firstTown)==mp.end())
        {
            mpp[cc]=c.firstTown;
            mp[c.firstTown]=cc;
            cc++;
        }
        
        
        if(mp.find(c.secondTown)==mp.end())
        {
            mpp[cc]=c.secondTown;
            mp[c.secondTown]=cc;
            cc++;
        }
        
        p[i]={c.cost,{mp[c.firstTown],mp[c.secondTown]}};
        i++;
    }
    sort(p, p + con.size());
   return  kruskal(p);
    
}

int main()
{
    int num;
    cin>>num;
    
    
    vector<Connection> con(num);
    for(int i=0;i<num;i++)
    {
        cin>>con[i].firstTown>>con[i].secondTown>>con[i].cost;
    }
    
    vector<Connection> res = minimumCost(num,con);
    
    for(auto c:res)
    cout<<c.firstTown<<" "<<c.secondTown<<" "<<c.cost<<"\n";
    
    return 0;
    
}




