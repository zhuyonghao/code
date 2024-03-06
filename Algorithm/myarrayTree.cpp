#include <iostream>
#include <queue>

#define MAX_SIZE 100

using namespace std;

//初始化操作 
struct Node
{
	int data;
};

//初始化
void initTree(Node* tree[], int n)
{
	for (int i = 0; i < n; i++)
		tree[i] = nullptr;
} 

//插入节点
void insertNode(Node* tree[], int data, int idx)
{
	if (tree[idx] == nullptr)
	{
		tree[idx] = new Node;
		tree[idx]->data = data;
	}	
} 

void preorderTraversal(Node* tree[], int idx)
{
	if (tree[idx] == nullptr)
		return;
	cout << tree[idx]->data << " ";
	preorderTraversal(tree, idx * 2 + 1);
	preorderTraversal(tree, idx * 2 + 2);
}

void inorderTraversal(Node* tree[], int idx)
{
	if (tree[idx] == nullptr)
		return;
	inorderTraversal(tree, idx * 2 + 1);
	cout << tree[idx]->data << " ";
	inorderTraversal(tree, idx * 2 + 2);
}

void postorderTraversal(Node* tree[], int idx)
{
	if (tree[idx] == nullptr)
		return;
	postorderTraversal(tree, idx * 2 + 1);
	postorderTraversal(tree, idx * 2 + 2);
	cout << tree[idx]->data << " ";
}

void levelOrderTraversal(Node* tree[],int n)
{
	if (tree[0] == nullptr)
		return;
	for (int i = 0; i < n; i++)
		cout << tree[i]->data << " ";
	cout << endl;
}

int main() {
    Node* tree[MAX_SIZE];
    initTree(tree, MAX_SIZE);

    insertNode(tree, 1, 0);
    insertNode(tree, 2, 1);
    insertNode(tree, 3, 2);
    insertNode(tree, 4, 3);
    insertNode(tree, 5, 4);

    cout << "Preorder Traversal: ";
    preorderTraversal(tree, 0);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(tree, 0);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(tree, 0);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrderTraversal(tree, 5);
    cout << endl;

    return 0;
}
