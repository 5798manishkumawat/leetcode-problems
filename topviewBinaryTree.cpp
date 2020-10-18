#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
   map<Node *,int>m1;
   map<int,int>m2;
   void helper(Node* root,int n)
   {
    if(root->left!=nullptr)
    {
        m1[root->left]=n-1;
        helper(root->left,n-1);
    }
    if(root->right!=nullptr)
    {
        m1[root->right]=n+1;
        helper(root->right,n+1);
    }
   }
    void topView(Node * root) {
        if(root==nullptr)
        return;
     m1[root]=0;
     m2[0]=root->data;
     helper(root,0);
     queue<Node *>q;
     q.push(root);
     while(!q.empty())
     {
         Node* ptr=q.front();
         q.pop();
         if(ptr->left!=nullptr)
         {
         int k=m1[ptr->left];
         if(m2.count(k)==0)
         m2[k]=ptr->left->data;
         q.push(ptr->left);
         }
         if(ptr->right!=nullptr)
         {
         int k=m1[ptr->right];
         if(m2.count(k)==0)
         m2[k]=ptr->right->data;
         q.push(ptr->right);
         }
     }
     for(auto it:m2)
     cout<<it.second<<" ";
     

    }

}; 
