class segmentTree{
  #define ll long long
  public:
  vector<ll> seg;
  ll size;
  segmentTree(){
  }
  void build(ll x,ll l ,ll r,vector<ll> &arr)
  {
   
      if(l==r)
      {
          seg[x]=arr[l];return ;
      }
      ll m=l+(r-l)/2;
      build(2*x+1,l,m,arr);
      build(2*x+2,m+1,r,arr);
      seg[x]=seg[2*x+1]+seg[2*x+2];
  }
  
  void update(ll idx,ll val,ll x,ll l,ll r)
  {
     
      if(l==r)
      {
          seg[x]=val;
          return ;
      }
      ll m=l+(r-l)/2;
      if(idx<=m)
      update(idx,val,2*x+1,l,m);
      else
      update(idx,val,2*x+2,m+1,r);
      
      seg[x]=seg[2*x+1]+seg[2*x+2];
      
      
  }
  
  ll getSum(ll lq,ll rq,ll x,ll l,ll r)
  {
      if(lq<=l && rq>=r) return seg[x];
      if(lq>r || rq<l) return 0;
      ll m=l+(r-l)/2;
      ll left = getSum(lq,rq,2*x+1,l,m);
      ll right = getSum(lq,rq,2*x+2,m+1,r);
      return left+right;
  }
  void update(ll idx,ll val) {
      update(idx,val,0,0,size-1);
  }
  ll getSum(ll lq,ll rq)
  {
      return getSum(lq,rq,0,0,size-1);
  }
  void build(vector<ll> &arr)
  {
      size=arr.size();
      seg.resize(4*size,0);
      build(0,0,size-1,arr);
  }
  
  
};
