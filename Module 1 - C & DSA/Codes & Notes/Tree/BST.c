#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node*left;
    struct Node*right;
};
struct Node*deletion(struct Node*root, int a)
{
    if(root==NULL) return NULL;
    
}
int leaf_nodes(struct Node*root)
{
    if(root->left==NULL && root->right==NULL)
    return 1;

    return leaf_nodes(root->left)+leaf_nodes(root->right);
}
struct Node*insert(struct Node*root,int key)
{
        if(root==NULL)
    {
        struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
        temp->val=key;
        temp->left=temp->right=NULL;
        return temp;
    }
    
    if(root->val==key)
    return root;

    if(key<root->val)
    root->left=insert(root->left,key);

    if(key>root->val)
    root->right=insert(root->right,key);

    return root;
}
struct Node*createnode(struct Node*root,int data)
{
    if(root==NULL)
    {
        struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
        temp->val=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(data<root->val)
    root->left=createnode(root->left,data);

    if(data>root->val)
    root->right=createnode(root->right,data);

    return root;
}
void inorder(struct Node*root)
{
    if(root==NULL) return;

    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    int *ptr=(int*)malloc(n*sizeof(int));
    struct Node*root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    for(int i=0;i<n;i++)
    {
    root=createnode(root,ptr[i]);
    }
    inorder(root);
    //insert(root,40);
    printf("\n");
    //inorder(root);
    printf("Number of leaf nodes=%d\n",leaf_nodes(root));
    deletion(root,40);
    inorder(root);
    return 0;
}