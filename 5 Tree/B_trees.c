#include <stdio.h>
#include <stdlib.h>

#define T 3 // Minimum degree

typedef struct BTreeNode {
    int keys[2 * T - 1];
    struct BTreeNode* children[2 * T];
    int n;
    int leaf;
} BTreeNode;

// Create a new node
BTreeNode* createNode(int leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i < 2 * T; i++)
        node->children[i] = NULL;
    return node;
}

// Traverse the tree
void traverse(BTreeNode* root) {
    if (root != NULL) {
        for (int i = 0; i < root->n; i++) {
            if (!root->leaf)
                traverse(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            traverse(root->children[root->n]);
    }
}

// Search a key
BTreeNode* search(BTreeNode* root, int key) {
    int i = 0;
    while (i < root->n && key > root->keys[i])
        i++;
    if (i < root->n && root->keys[i] == key)
        return root;
    if (root->leaf)
        return NULL;
    return search(root->children[i], key);
}

// Split child
void splitChild(BTreeNode* parent, int i, BTreeNode* y) {
    BTreeNode* z = createNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T - 1; j++)
        z->keys[j] = y->keys[j + T];
    if (!y->leaf) {
        for (int j = 0; j < T; j++)
            z->children[j] = y->children[j + T];
    }

    y->n = T - 1;

    for (int j = parent->n; j >= i + 1; j--)
        parent->children[j + 1] = parent->children[j];
    parent->children[i + 1] = z;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];
    parent->keys[i] = y->keys[T - 1];
    parent->n++;
}

// Insert non-full
void insertNonFull(BTreeNode* x, int key) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i >= 0 && key < x->keys[i]) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = key;
        x->n++;
    } else {
        while (i >= 0 && key < x->keys[i])
            i--;
        i++;
        if (x->children[i]->n == 2 * T - 1) {
            splitChild(x, i, x->children[i]);
            if (key > x->keys[i])
                i++;
        }
        insertNonFull(x->children[i], key);
    }
}

// Insert operation
void insert(BTreeNode** rootRef, int key) {
    BTreeNode* r = *rootRef;
    if (r == NULL) {
        r = createNode(1);
        r->keys[0] = key;
        r->n = 1;
        *rootRef = r;
        return;
    }

    if (r->n == 2 * T - 1) {
        BTreeNode* s = createNode(0);
        s->children[0] = r;
        splitChild(s, 0, r);
        int i = (key > s->keys[0]) ? 1 : 0;
        insertNonFull(s->children[i], key);
        *rootRef = s;
    } else {
        insertNonFull(r, key);
    }
}

// Menu-driven main
int main() {
    BTreeNode* root = NULL;
    int choice, key;

    while (1) {
        printf("\nB-Tree Menu:\n");
        printf("1. Insert\n2. Search\n3. Traverse (Inorder)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(&root, key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (root == NULL || search(root, key) == NULL)
                printf("Key not found.\n");
            else
                printf("Key found.\n");
            break;

        case 3:
            printf("B-Tree traversal: ");
            traverse(root);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
