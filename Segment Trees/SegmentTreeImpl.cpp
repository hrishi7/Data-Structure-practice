#include<iostream>

using namespace std;

void buildTree(int *arr, int *tree, int s, int e, int cI){

    //base case
    if(s == e){
        tree[cI] = arr[s];
        return;
    }

    int mid = (s+e)/2;

    buildTree(arr,tree,s,mid,2*cI);
    buildTree(arr, tree, mid + 1,e,2*cI+1);

    tree[cI] = tree[2*cI] + tree[2*cI + 1];
}

int main(){

    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int * tree = new int[2 * n];
    buildTree(arr, tree, 0,n - 1,1);

    for(int i = 1; i<2*n; i++){
        cout<<i<<" - "<<tree[i]<<endl;
    }

}
