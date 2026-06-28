#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};


int max(int a, int b){
    return (a > b) ? a : b;
}

// to get height
int height(struct Node *node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

struct Node *createnode(int key){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

//right rotation
struct Node *rightrotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(
        height(y->left),
        height(y->right)
    ) + 1;

    x->height = max(
        height(x->left),
        height(x->right)
    ) + 1;

    return x;
}

//left rotation
struct Node *leftrotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(
        height(x->left),
        height(x->right)
    ) + 1;
    
    y->height = max(
        height(y->left),
        height(y->right)
    ) + 1;

    return y;
}

int getbalance(struct Node *node){
    if(node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct Node *insert(struct Node *node, int key){
    if(node == NULL){
        return createnode(key);
    }
    if(key < node->key){
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
    }
    else{
        return node;
    }

    //Update Height
    node->height = 1 + max(
        height(node->left), 
        height(node->right)
    );

    //Get balance Factor
    int balance = getbalance(node);

    //LL case
    if(balance > 1 && key < node->left->key){
        return rightrotate(node);
    }

    //RR case
    if(balance < -1 && key > node->right->key){
        return leftrotate(node);
    }

    //LR case
    if(balance > 1 && key > node->left->key){
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    //RL case
    if(balance < -1 && key < node->right->key){
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;

}

void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void main(){
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root , 5);
    root = insert(root, 25);

    printf("Inorder Traversal: \n");
    inorder(root);
}
