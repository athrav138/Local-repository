#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

Node* root = NULL;

// Create a new red node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Left rotate
void rotateLeft(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Right rotate
void rotateRight(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

// Fix violations after insertion
void fixInsert(Node **root, Node *z) {
    while (z->parent && z->parent->color == RED) {
        Node *gp = z->parent->parent;
        if (z->parent == gp->left) {
            Node *y = gp->right;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                gp->color = RED;
                z = gp;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(root, z);
                }
                z->parent->color = BLACK;
                gp->color = RED;
                rotateRight(root, gp);
            }
        } else {
            Node *y = gp->left;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                gp->color = RED;
                z = gp;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(root, z);
                }
                z->parent->color = BLACK;
                gp->color = RED;
                rotateLeft(root, gp);
            }
        }
    }
    (*root)->color = BLACK;
}

// Insert a node
void insert(int data) {
    Node *z = createNode(data);
    Node *y = NULL;
    Node *x = root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else if (z->data > x->data)
            x = x->right;
        else {
            free(z); // no duplicates
            return;
        }
    }

    z->parent = y;
    if (y == NULL)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(&root, z);
}

// Inorder traversal
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Search for a key
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Transplant for delete
void transplant(Node **root, Node *u, Node *v) {
    if (u->parent == NULL)
        *root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v)
        v->parent = u->parent;
}

// Get minimum node
Node* minimum(Node* x) {
    while (x->left != NULL)
        x = x->left;
    return x;
}

// Fix deletion
void fixDelete(Node **root, Node *x) {
    while (x != *root && (!x || x->color == BLACK)) {
        if (x == x->parent->left) {
            Node *w = x->parent->right;
            if (w && w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(root, x->parent);
                w = x->parent->right;
            }
            if ((!w->left || w->left->color == BLACK) &&
                (!w->right || w->right->color == BLACK)) {
                if (w)
                    w->color = RED;
                x = x->parent;
            } else {
                if (!w->right || w->right->color == BLACK) {
                    if (w->left)
                        w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->right)
                    w->right->color = BLACK;
                rotateLeft(root, x->parent);
                x = *root;
            }
        } else {
            Node *w = x->parent->left;
            if (w && w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(root, x->parent);
                w = x->parent->left;
            }
            if ((!w->left || w->left->color == BLACK) &&
                (!w->right || w->right->color == BLACK)) {
                if (w)
                    w->color = RED;
                x = x->parent;
            } else {
                if (!w->left || w->left->color == BLACK) {
                    if (w->right)
                        w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->left)
                    w->left->color = BLACK;
                rotateRight(root, x->parent);
                x = *root;
            }
        }
    }
    if (x)
        x->color = BLACK;
}

// Delete node
void deleteNode(int data) {
    Node *z = search(root, data);
    if (z == NULL) {
        printf("Key not found.\n");
        return;
    }

    Node *y = z, *x;
    Color originalColor = y->color;

    if (z->left == NULL) {
        x = z->right;
        transplant(&root, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        transplant(&root, z, z->left);
    } else {
        y = minimum(z->right);
        originalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            if (x)
                x->parent = y;
        } else {
            transplant(&root, y, y->right);
            y->right = z->right;
            if (y->right)
                y->right->parent = y;
        }
        transplant(&root, z, y);
        y->left = z->left;
        if (y->left)
            y->left->parent = y;
        y->color = z->color;
    }

    free(z);
    if (originalColor == BLACK && x)
        fixDelete(&root, x);
}

// Menu-driven program
int main() {
    int choice, data;

    while (1) {
        printf("\nRed-Black Tree Menu:\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Preorder\n5. Inorder\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &data);
            insert(data);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &data);
            if (search(root, data))
                printf("Key found.\n");
            else
                printf("Key not found.\n");
            break;

        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &data);
            deleteNode(data);
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
