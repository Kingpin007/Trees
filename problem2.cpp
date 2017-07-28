#include <bits/stdc++.h>
#define ll int
#define vcll vector<ll>
using namespace std;
int maxDiameterSum(int nodes, int tree[512]);
bool isLeaf(int n, int nodes);
void recurse(int n,int nodes,int tree[512],int sum);
vector<int> sumOfAllPaths;
int visited[512];
int main()
{
    ll t;
    cin>>t;
    while(t--){

        ll n,x;
        cin>>n;
        ll *tree = new ll[n];
        for(ll i=1;i<=n;i++){
            cin>>tree[i];
        }
        int maxDS = maxDiameterSum(n,tree);
        cout<<maxDS<<endl;
    }

    return 0;
}

int maxDiameterSum(int nodes, int tree[512]){
    vector<int> leafNodes;
    for(int i=1;i<=nodes;i++){
        if(isLeaf(i,nodes)){
            leafNodes.push_back(i);
        }
    }
    for(ll i=0;i<leafNodes.size();i++){
        for(int i=0;i<512;i++)  visited[i]=0;
        recurse(leafNodes[i],nodes,tree,0);
    }
    sort(sumOfAllPaths.begin(),sumOfAllPaths.end());
    for(int i=0;i<sumOfAllPaths.size();i++)
        cout<<sumOfAllPaths[i]<<" ";
    return sumOfAllPaths.back();
}

bool isLeaf(int n,int nodes){
    return n*2>nodes?true:false;
}

void recurse(int n,int nodes,int tree[512],int sum){
    if(isLeaf(n,nodes)){
        visited[n] = 1;
        sumOfAllPaths.push_back(tree[n]+sum);
        if(n!=1 && visited[n/2] == 0){   //not root and never visited parent before
            cout<<"Visiting1: "<<tree[n]<<endl;
            recurse(n/2,nodes,tree,sum);
        }
    }
    else{
        visited[n] = 1;
        sum+=tree[n];
        //recurse left child
        if(n*2 <= nodes && visited[n*2] == 0){
            cout<<"Visiting2: "<<tree[n]<<endl;
            recurse(n*2,nodes,tree,sum);
        }
        //right child
        if(n*2 + 1 <= nodes && visited[n*2+1] == 0){
            cout<<"Visiting3: "<<tree[n]<<endl;
            recurse(n*2+1,nodes,tree,sum);
        }
    }
}

