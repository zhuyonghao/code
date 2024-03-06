#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
};


//创建节点 
Node* CreateNode(int key)
{
	Node* newNode = new Node;
	newNode->value = key;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

//插入操作
Node* insert(Node* root, int key)
{
	//递归终止条件 
	if (root == nullptr)
	{
		return CreateNode(key);
	}		
	//小于根的值 
	if (key < root->value)
		root->left = insert(root->left, key);
	//大于根的值 
	else if (key > root->value)
		root->right = insert(root->right, key);
	//出现相同数字之间返回 
	return root;
} 

Node* search(Node* root, int key)
{
	//根节点就是要寻找的点 
	if (root == nullptr || root->value == key)
		return root;
		
	if (key < root->value)
		return search(root->left, key);
	else if (key > root->value)
		return search(root->right, key);
} 

Node* findMin(Node* root)
{
	if (root == nullptr)
		return nullptr;
	
	while (root->left != nullptr)
	{
		root = root->left;
	}
	
	return root;
}

Node* deleteNode(Node* root, int key)
{
	//终止条件 
	if (root == nullptr)
		return root;
	//小于根的值 
	if (key < root->value)
		root->left = deleteNode(root->left, key);
	//大于根的值 
	else if (key > root->value)
		root->right = deleteNode(root->right, key);
	//找到了，进行删除操作 
	else
	{
		//找到的节点左边为空 
		if (root->left == nullptr)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		//找到的节点右边为空 
		else if (root->right == nullptr)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		//如果根的左右节点有值
		//这一行代码用于找到当前节点右子树中的最小节点。
//	在二叉搜索树中，右子树中的最小节点就是比当前节点大的最小节点，即当前节点的后继节点。
		Node* temp = findMin(root->right);
		root->value = temp->value;
		root->right = deleteNode(root->right, temp->value);
	}
	
	return root;
}

//中序遍历 
void inorderTraversal(Node* root)
{
	if (root == nullptr)
		return;
	
	inorderTraversal(root->left);
	cout << root->value << " ";
	inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 20);

    cout << "Inorder traversal after deleting 20: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}


