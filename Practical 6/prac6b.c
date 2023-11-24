#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a person
struct Person {
    char name[50];
    int id;
};

// Define a node for the binary search tree
struct Node {
    struct Person data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(struct Person person) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = person;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a person into the BST
struct Node* insert(struct Node* root, struct Person person) {
    if (root == NULL) {
        return createNode(person);
    }

    if (person.id < root->data.id) {
        root->left = insert(root->left, person);
    } else if (person.id > root->data.id) {
        root->right = insert(root->right, person);
    }

    return root;
}

// Function for inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s (ID: %d) ", root->data.name, root->data.id);
        inorder(root->right);
    }
}

// Function for postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s (ID: %d) ", root->data.name, root->data.id);
    }
}

// Function for preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%s (ID: %d) ", root->data.name, root->data.id);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to find common members in two BSTs
void findCommonMembers(struct Node* root1, struct Node* root2) {
    if (root1 != NULL && root2 != NULL) {
        findCommonMembers(root1->left, root2);
        findCommonMembers(root1->right, root2);
        
        // Check if the current person in root1 is also present in root2
        struct Node* searchResult = search(root2, root1->data.id);
        if (searchResult != NULL) {
            printf("Common Member: %s (ID: %d)\n", root1->data.name, root1->data.id);
        }
    }
}

// Function to search for a person in the BST
struct Node* search(struct Node* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root;
    }

    if (id < root->data.id) {
        return search(root->left, id);
    }

    return search(root->right, id);
}

int main() {
    // Create and populate the first tree
    struct Node* tree1 = NULL;
    tree1 = insert(tree1, (struct Person){"Rohan", 1});
    tree1 = insert(tree1, (struct Person){"Bob", 2});
    tree1 = insert(tree1, (struct Person){"Charlie", 3});
    tree1 = insert(tree1, (struct Person){"Dane", 4});
    tree1 = insert(tree1, (struct Person){"Myra", 5});
    tree1 = insert(tree1, (struct Person){"Alisa", 6});
    tree1 = insert(tree1, (struct Person){"Ele", 5});

    // Create and populate the second tree
    struct Node* tree2 = NULL;
    tree2 = insert(tree2, (struct Person){"Alice", 1});
    tree2 = insert(tree2, (struct Person){"Eve", 5});
    tree2 = insert(tree2, (struct Person){"Charlie", 3});
    tree2 = insert(tree2, (struct Person){"Frank", 6});

    // Perform inorder, postorder, and preorder traversals on both trees

    // Find common members in both trees
    printf("\nCommon Members in Both Trees:\n");
    findCommonMembers(tree1, tree2);

    return 0;
}
