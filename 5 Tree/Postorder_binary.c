#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *createnode(int data);
struct tree *insert(struct tree *root, int n);
void Postorder(struct tree *root);

int main() {
    struct tree *root = NULL;
    int choice, n;

    while (1) {
        printf("\n---- Menu ----\n");
        printf("1. Insert element\n");
        printf("2. Postorder traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element you want to insert: ");
                scanf("%d", &n);
                root = insert(root, n);
                break;

            case 2:
                printf("Postorder traversal: ");
                Postorder(root);
                printf("\n");
                break;

            case 3:
                printf("Exiting...!\n");
                return 0;

            default:
                printf("Enter correct choice\n");
        }
    }

    return 0;
}

struct tree *createnode(int data) {
    struct tree *new = (struct tree *)malloc(sizeof(struct tree));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct tree *insert(struct tree *root, int n) {
    if (root == NULL) {
        root = createnode(n);
    } else if (n <= root->data) {
        root->left = insert(root->left, n);
    } else {
        root->right = insert(root->right, n);
    }
    return root;
}

void Postorder(struct tree *root) {
  if(root==NULL){
    return;
  }
  else{
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);


  }
    
}
