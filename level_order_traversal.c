// Recursive C program for level
// order traversal of Binary Tree
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data,
pointer to left child
and a pointer to right child */
struct node {
	int data;
	struct node *left, *right;
};

/* Function prototypes */
void printCurrentLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);

/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}

/* Print nodes at a current level */
void printCurrentLevel(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(struct node* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Level Order traversal of binary tree is \n");
	printLevelOrder(root);

	return 0;
}




void printLevelOrder(Node* root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<Node*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {

        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();

        // Enqueue left child
        if (node->left != NULL)
            q.push(node->left);

        // Enqueue right child
        if (node->right != NULL)
            q.push(node->right);
    }
}


// Given a binary tree, print its nodes in level order
// using array for implementing queue
void printLevelOrder(struct node* root)
{
    int rear, front;
    struct node** queue = createQueue(&front, &rear);
    struct node* temp_node = root;

    while (temp_node) {
        printf("%d ", temp_node->data);

        // Enqueue left child
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        // Enqueue right child
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        // Dequeue node and make it temp_node
        temp_node = deQueue(queue, &front);
    }
}
