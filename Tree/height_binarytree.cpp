#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>

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


// no of nodes on the longest path between rootnode and leafnode
int heightOfTree(node* root){
    if(root==NULL)
    return 0;

    int left=heightOfTree(root->left);
    int right=heightOfTree(root->right);

    return 1+max(left,right);
}

// diameter of a tree (width) is the number of nodes on the longest path b/w two end nodes
// o(n2) time complexity
int diameterOfTree(node* root){
    if(root==NULL)
    return 0;

    int left_subtree=diameterOfTree(root->left);
    int right_subtree=diameterOfTree(root->right);
    int both_subtree=heightOfTree(root->left)+heightOfTree(root->right)+1;

    return max(both_subtree,max(left_subtree,right_subtree));
}

//o(n) time complexity
// returns height,diameter
pair<int,int> FastDiameterOfTree(node *root){
    if(root==NULL){
        return make_pair(0,0);

    }

    pair<int,int> left =FastDiameterOfTree(root);
    pair<int,int> right=FastDiameterOfTree(root);

    int diameter=1+left.second+right.second;
    int height=1+max(left.second,right.second);

    return make_pair(max(diameter,max(left.first,right.first)),height);
}

// check for balanced tree

// A tree is height balanced if difference between heights of left and right subtrees
// is not more than 1 for all nodes of tree.

// Abs(height(leftsubtree)-height(rightsubtree) <=1) ;  o(n2) time complexity

// do it with pair<bool,int> ---> TC: O(n2)

bool isBalanced(node* root){

    if(root==NULL)
    return true;

    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    bool temp=abs(heightOfTree(root->left)-heightOfTree(root->right))<=1;
    return left && right && temp;
}

// Determine if 2 trees are identical or NOT

bool isIdentical(node* r1,node* r2){
    if(r1==NULL && r2==NULL)
    return true;
    if(r1!=NULL && r2==NULL)
    return false;
    if(r1==NULL && r2!=NULL)
    return false;

    bool left=isIdentical(r1->left,r2->left);
    bool right=isIdentical(r1->right,r2->right);
    bool temp=r1->data==r2->data;

    return left && right && temp;
}

// Sum Tree:Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

pair<bool,int> isSumTreeFast(node* root){

    if(root==NULL){
        return make_pair(true,0);
    }

    if(root->left==NULL && root->right==NULL){
        return make_pair(true,root->data);
    }

    pair<bool,int> left=isSumTreeFast(root->left);
    pair<bool,int> right=isSumTreeFast(root->right);
    int sum=left.second+right.second;
    bool temp=(sum==root->data);

    return make_pair(left.first && right.first && temp,sum+root->data);
}

bool isSumTree(node* root){
    return isSumTreeFast(root).first;
}

int main(){

    return 0;
}