// C program to demonstrate insert
// operation in binary
// search tree.
#include <iostream>
using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		//printf("%d \n", root->key);
        cout << root->key << endl;
		inorder(root->right);
	}
}
void right(struct node* root)
{
	if (root != NULL) {
		right(root->left);
		//printf("%d \n", root->key);
        cout << root->key << endl;
		right(root->right);
	}
}
int arr[100],k=0;
void customInorder(struct node* root, int inp)
{
    if (root != NULL) {
        customInorder(root->left,inp);
        //printf("%d \n", root->key);
        if(inp>root->key){
            arr[k]=root->key;
            k++;
            //cout << "The next smaller number in the tree is: " << root->key << endl;
        }
        //cout << root->key << endl;
        customInorder(root->right,inp);
    }
    
	
}

/* A utility function to insert
a new node with given key in
* BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

// Driver Code
int main()
{
	/* Let us create following BST
		  
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

    int inp,smallN=99999;
    cout << "Enter number(n): ";
    cin >> inp;
    // smallN = inp;
    // struct node* temp = root;
    // //cout << temp->right->key << endl;
    // while(temp!=NULL){
    //     // if(inp==temp->key){
    //     //     temp = temp->right;
    //     //     //continue;
    //     // }
    //     // if(inp > temp->key){
    //     //     //inp = temp->key;
    //     //     cout << "The next smaller number in the tree is: " << temp->key << endl;
    //     // }
    //     cout << temp->key << endl;
    //     temp = temp->right;
    // }
	//cout << "The next smaller number in the tree is: " << inp << endl;

    customInorder(root,inp);
    int maxi = -99999;
    for(int i=0;i<k;i++){
        if(maxi<arr[i]){
            maxi=arr[i];
        }
    }
    if(maxi!=-99999)
    cout << "The next smaller number in the tree is: " << maxi << endl;
    else{
        cout << "No next smaller number" << endl;
    }

    struct node* temp = root;
    cout << "Right side of the tree: "<< endl;
    temp=temp->right;
    inorder(temp);
	return 0;
}