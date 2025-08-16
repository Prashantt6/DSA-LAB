#include<stdio.h>
#include<stdlib.h>
typedef struct BinaryTree {
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
    struct BinaryTree * parent;
}BinaryTree;

BinaryTree *root = NULL;
BinaryTree* createNode(int value) {
    BinaryTree *NewNode;
    NewNode = (BinaryTree*)malloc(sizeof(BinaryTree));
    NewNode->data = value;
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->parent = NULL;
    return NewNode;
}
BinaryTree *insert(BinaryTree* root, int value)
{
    if(root == NULL){
        root = createNode(value);
    }
    if(value < root->data){
        root->left = insert(root->left , value);
        root->left->parent = root;
    }
    if(value >root->data){
        root->right = insert(root->right , value );
        root->right->parent = root;
    }
    return root;

}


BinaryTree* find_min(BinaryTree *root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}


BinaryTree* find_max(BinaryTree *root){
    while(root->right != NULL)
        root = root->right;
    return root;
}
BinaryTree* delete_node(BinaryTree* root, int value){
    if(root==NULL){
        return root;
    }
    if(value<root->data){
        root->left  = delete_node(root->left,value);
        if(root->left){
            root->left->parent = root;
        }
    }
    else if(value > root->data){
        root->right = delete_node(root->right , value);
        if(root->right){
            root->right->parent = root;
        }
    }
    else{
        if(root->left == NULL){
            BinaryTree* temp = root->right;
            if(temp){
                temp->parent = root->parent;

            }
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            BinaryTree* temp = root->left;
            if(temp)
                temp->parent = root->parent;
            free(root);
            return root;
        }
        else {
            BinaryTree* temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right , temp->data);
            if(root->right)
                root->right->parent = root;
        }

    }
    return root;
    

}


BinaryTree* search(BinaryTree *root, int key){
    if((root == NULL) || (key == root->data)) {
        return root;
    }
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}


void preorder(BinaryTree *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(BinaryTree *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(BinaryTree *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
        
    }
}



int main()
{
    int ch = 0;
    int i, element;
    BinaryTree* temp;
    int arr[] = {1,2,3,69,5,10,30,20,40,60};
    while(ch != 10){
        printf("1. Insert\n 2. Delete\n 3. Search\n 4. Inorder \n 5. Postorder\n 6. Preorder \n 7. Find maximum \n 8. Find minimum \n 9. Create\n 10. Exit\n");
        printf("Enter the choice:  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to insert: ");
            scanf("%d", &element);
            root = insert(root, element);
            printf("\n %d was inserted succesfully\n", element);
            break;
        case 2:
            printf("Enter the element to delete: ");
            scanf("%d",&element);
            root = delete_node(root, element);
            printf("%d DELETED SUCCESSFULLY!\n",element);
            break;

        case 3:
            printf("Enter the search key: ");
            scanf("%d",&element);
            temp = search(root, element);
            if(temp == NULL)
                printf("%d NOT FOUND!!\n",element);
            else
                printf("%d FOUND!\n",element);
            break;

        case 4:
            inorder(root);
            printf("\n");
            break;

        case 5:
            preorder(root);
            printf("\n");
            break;

        case 6:
            postorder(root);
            printf("\n");
            break;

        case 7:
            temp = find_max(root);
            if(temp != NULL)
                printf("%d IS THE LARGEST ELEMENT IN THE TREE\n",temp->data);
            break;

        case 8:
            temp = find_min(root);
            if(temp != NULL)
                printf("%d IS THE SMALLEST ELEMENT IN THE TREE\n",temp->data);
            break;

        case 9:
            for(i=0;i<9;i++)
                root = insert(root, arr[i]);
            printf("All elements were inserted sucessfully!\n");
            break;
        
        case 10:
            printf("Bye!\n");
        
        
        
        }
    }
}