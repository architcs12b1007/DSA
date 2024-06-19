#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<limits.h>

using namespace std;

class node{
    public:

    int data;
    node *left;
    node *right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

// Sum of lonest bloodline of a tree  (Sum of nodes on the longest path from root to leaf node)
// if equal path, then return highest sum.

int height=0,sum=0;

void sumPath(node* root,int len,int &maxLen,int sum,int &maxSum){

    if(root==NULL){

        if(len>maxLen){
            maxLen=len;
            maxSum=sum;
        }else if(len==maxLen){
            maxSum=max(sum,maxSum);
        }

        return;
    }

    sum+=root->data;
    
    sumPath(root->left,len+1,maxLen,sum,maxSum);
    sumPath(root->right,len+1,maxLen,sum,maxSum);

    // sum-=root->data; NOT needed bcoz i did not pass it as a reference

    

}

int sumOfLongRootToLeafPath(node* root){

    int len=0;
    
    int maxLen=0;
    
    int sum=0;
    int maxSum=INT_MIN;

    sumPath(root,len,maxLen,sum,maxSum);
    
    return maxLen;

}



// Least Common Ancestor in a Binary Tree (Assume that either noth of them present or none of them present)

node* lca(node* root,int n1,int n2){
    if(root==NULL)
    return NULL;

    if(root->data==n1 || root->data==n2)
    return root;
    
    node* left=lca(root->left,n1,n2);
    node* right=lca(root->right,n1,n2);

    if(left==NULL && right==NULL)
    return NULL;
    else if(left!=NULL && right==NULL)
    return left;
    else if(left==NULL && right!=NULL)
    return right;
    else
    return root;
}

// K Sum Path : Find the number of paths in the tree which have their sum equal to K

// A path may start from any node & end at any node in the downward direction

void KPath(node* root,int k, int sum, int &count){

    if(root==NULL)
    return;

    sum+=root->data;
    KPath(root->left,k,sum,count);
    KPath(root->right,k,sum,count);

    if(root->left==NULL && root->right==NULL && sum==k){
        count++;
    }




}

int KSumPath(node* root,int k){
    int sum=0;
    int count=0;

    KPath(root,k,sum,count);

    return count;

}

int main(){

    return 0;
}