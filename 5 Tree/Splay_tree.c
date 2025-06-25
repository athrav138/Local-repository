#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Right rotation
Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation
Node* splay(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    // Key in left subtree
    if (key < root->key) {
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key in right subtree
    else {
        if (root->right == NULL)
            return root;

        // Zig-Zig (Right Right)
        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        // Zig-Zag (Right Left)
        else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Insert a key
Node* insert(Node* root, int key) {
    if (root == NULL) return newNode(key);
    root = splay(root, key);

    if (root->key == key) return root;

    Node* node = newNode(key);
    if (key < root->key) {
        node->right = root;
        node->left = root->left;
        root->left = NULL;
    } else {
        node->left = root;
        node->right = root->right;
        root->right = NULL;
    }
    return node;
}

Node* deleteKey(Node* root, int key) {
    if (root == NULL)
        return NULL;

    root = splay(root, key);

    if (root->key != key) {
        printf("Key not found.\n");
        return root;
    }

    Node* temp;
    if (root->left == NULL) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = splay(root->left, key); // bring the max of left subtree to root
        root->right = temp->right;
    }

    free(temp);
    return root;
}

// Search a key
Node* search(Node* root, int key) {
    return splay(root, key);
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Menu-driven main
int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nSplay Tree Menu:\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Preorder\n5. Inorder\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            root = search(root, key);
            if (root && root->key == key)
                printf("Key found and splayed to root.\n");
            else
                printf("Key not found.\n");
            break;

        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteKey(root, key);
            break;

        case 4:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 5:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    
return 0;
}