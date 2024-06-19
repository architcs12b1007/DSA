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
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
node* buildTree(node* root){

    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    return NULL;

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}
// do reverseLevelorderTraversal

void levelOrderTraversal(node* root){

    queue<node*> q;

    if(root!=NULL){
        q.push(root);
        q.push(NULL);
    }

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            q.push(temp->left);
            
            if(temp->right!=NULL)
            q.push(temp->right);

        }
        


    }
}

void inorder(node* root){

    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


// pass node by reference

//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

void buildfromLevelOrder(node* &root){

    queue<node*> q;
    cout<<"Enter data for root:"<<endl;
    
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

void inorderLeaves(node* root, int &count){
    if(root==NULL)
    return;

    if(root->left==NULL && root->right==NULL){
        count+=1;
    }

    inorderLeaves(root->left,count);
    inorderLeaves(root->right,count);
}

int countNoofLeaves(node* root){
    int count=0;
    inorderLeaves(root,count);

    return count;


}

int heightOfTree(node* root){
    if(root==NULL)
    return 0;

    int left=heightOfTree(root->left);
    int right=heightOfTree(root->right);

    return 1+max(left,right);
}


int main(){

    node* root=NULL;

    //root=buildTree(root);

    buildfromLevelOrder(root);
    
    levelOrderTraversal(root);
    
    cout<<countNoofLeaves(root)<<endl;

    cout<<heightOfTree(root)<<endl;
    
    return 0;
}