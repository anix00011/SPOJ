#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[4000040]={0};
ll lazy[400040]={0};

void updateRangeUtil(ll i, ll s, ll e, ll cs,ll ce, ll v) {
        if(lazy[i]!=0){
            a[i]+=(e-s+1)*lazy[i];
            if(s!=e){
                lazy[2*i+1]+=lazy[i];
                lazy[2*i+2]+=lazy[i];
            }
            lazy[i]=0;
        }
    if (s>e||s>ce||e<cs) return;
    if (s>=cs&&e<=ce)
    {
        a[i]+=(e-s+1)*v;
        if (s!=e)
        {
            lazy[2*i+1]+=v;
            lazy[2*i+2]+=v;
        }
        return;
    }
    ll mid=(s+((e-s)>>1));
    updateRangeUtil(2*i+1,s,mid,cs,ce,v);
    updateRangeUtil(2*i+2,mid + 1,e,cs,ce,v);
    a[i]=a[2*i+1]+a[2*i+2];
}

ll getSumUtil(ll s,ll e,ll cs,ll ce,ll i)
{
    if(lazy[i]!=0){
        a[i]+=(e-s+1)*lazy[i];
        if(s!=e){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if (s>e||s>ce||e<cs) return 0;
    if (s>=cs&&e<=ce) return a[i];
    ll mid=(s+((e-s)>>1));
    return getSumUtil(s,mid,cs,ce, 2*i+1)+getSumUtil(mid + 1,e,cs,ce,2*i+2);
}

int main()
{
    ll t,n,q;cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(lazy,0,sizeof(lazy));
        ll ss,qs,qe,v;
        cin>>n>>q;
        while(q--){
        cin>>ss;
        if(ss==0){
            cin>>qs>>qe>>v;
            updateRangeUtil(0,0,n,qs,qe,v);
            }
        else if(ss==1){
            cin>>qs>>qe;
            cout<<getSumUtil(0,n,qs,qe,0)<<endl;
            }
        }
    }
    return 0;
}
