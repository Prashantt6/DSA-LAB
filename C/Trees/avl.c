#include <stdio.h>
#include <stdlib.h>

typedef struct AVL {
    int data;
    int height;
    struct AVL *left;
    struct AVL *right;
    struct AVL *parent;
} AVL;

AVL *root = NULL;

int getheight(AVL *n) {
    return n ? n->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVL* createNode(int data) {
    AVL *node = (AVL*)malloc(sizeof(AVL));
    node->data = data;
    node->left = node->right = node->parent = NULL;
    node->height = 1;
    return node;
}

int getBF(AVL *n) {
    if (!n) return 0;
    return getheight(n->left) - getheight(n->right);
}

AVL* rightrotate(AVL *y) {
    AVL *x = y->left;
    AVL *T2 = x->right;

    x->right = y;
    y->left = T2;

    if (T2) T2->parent = y;
    x->parent = y->parent;
    y->parent = x;

    if (x->parent) {
        if (x->parent->left == y) x->parent->left = x;
        else x->parent->right = x;
    } else {
        root = x;
    }

    y->height = 1 + max(getheight(y->left), getheight(y->right));
    x->height = 1 + max(getheight(x->left), getheight(x->right));

    return x;
}

AVL* leftrotate(AVL *x) {
    AVL *y = x->right;
    AVL *T2 = y->left;

    y->left = x;
    x->right = T2;

    if (T2) T2->parent = x;
    y->parent = x->parent;
    x->parent = y;

    if (y->parent) {
        if (y->parent->left == x) y->parent->left = y;
        else y->parent->right = y;
    } else {
        root = y;
    }

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return y;
}

AVL* insert(AVL *node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
        node->left->parent = node;
    } else if (data > node->data) {
        node->right = insert(node->right, data);
        node->right->parent = node;
    } else {
        return node; 
    }

    node->height = 1 + max(getheight(node->left), getheight(node->right));

    int bf = getBF(node);

    if (bf > 1 && data < node->left->data)
        return rightrotate(node);

    if (bf < -1 && data > node->right->data)
        return leftrotate(node);

    if (bf > 1 && data > node->left->data) {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    if (bf < -1 && data < node->right->data) {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

AVL* findMin(AVL *node) {
    while (node && node->left)
        node = node->left;
    return node;
}

AVL* deleteNode(AVL *node, int key) {
    if (node == NULL)
        return node;

    if (key < node->data) {
        node->left = deleteNode(node->left, key);
        if (node->left) node->left->parent = node;
    } else if (key > node->data) {
        node->right = deleteNode(node->right, key);
        if (node->right) node->right->parent = node;
    } else {
        if (node->left == NULL || node->right == NULL) {
            AVL *temp = node->left ? node->left : node->right;
            if (temp) temp->parent = node->parent;
            free(node);
            return temp;
        }
        AVL *temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
        if (node->right) node->right->parent = node;
    }

    node->height = 1 + max(getheight(node->left), getheight(node->right));

    int bf = getBF(node);

    if (bf > 1 && getBF(node->left) >= 0)
        return rightrotate(node);

    if (bf > 1 && getBF(node->left) < 0) {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    if (bf < -1 && getBF(node->right) <= 0)
        return leftrotate(node);

    if (bf < -1 && getBF(node->right) > 0) {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

AVL* search(AVL *node, int key) {
    if (!node || node->data == key)
        return node;
    if (key < node->data)
        return search(node->left, key);
    return search(node->right, key);
}

void inorder(AVL *node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(AVL *node) {
    if (node) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(AVL *node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

void freeTree(AVL *node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    int choice = 0, value;
    AVL *temp;

    while(choice != 7) {
        printf("\n1. INSERT\n2. DELETE\n3. SEARCH\n4. INORDER\n5. PREORDER\n6. POSTORDER\n7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d INSERTED!\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d DELETED!\n", value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                temp = search(root, value);
                if (temp) printf("%d FOUND!\n", value);
                else printf("%d NOT FOUND!\n", value);
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                freeTree(root);
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
