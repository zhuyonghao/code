#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
};


//�����ڵ� 
Node* CreateNode(int key)
{
	Node* newNode = new Node;
	newNode->value = key;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

//�������
Node* insert(Node* root, int key)
{
	//�ݹ���ֹ���� 
	if (root == nullptr)
	{
		return CreateNode(key);
	}		
	//С�ڸ���ֵ 
	if (key < root->value)
		root->left = insert(root->left, key);
	//���ڸ���ֵ 
	else if (key > root->value)
		root->right = insert(root->right, key);
	//������ͬ����֮�䷵�� 
	return root;
} 

Node* search(Node* root, int key)
{
	//���ڵ����ҪѰ�ҵĵ� 
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
	//��ֹ���� 
	if (root == nullptr)
		return root;
	//С�ڸ���ֵ 
	if (key < root->value)
		root->left = deleteNode(root->left, key);
	//���ڸ���ֵ 
	else if (key > root->value)
		root->right = deleteNode(root->right, key);
	//�ҵ��ˣ�����ɾ������ 
	else
	{
		//�ҵ��Ľڵ����Ϊ�� 
		if (root->left == nullptr)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		//�ҵ��Ľڵ��ұ�Ϊ�� 
		else if (root->right == nullptr)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		//����������ҽڵ���ֵ
		//��һ�д��������ҵ���ǰ�ڵ��������е���С�ڵ㡣
//	�ڶ����������У��������е���С�ڵ���Ǳȵ�ǰ�ڵ�����С�ڵ㣬����ǰ�ڵ�ĺ�̽ڵ㡣
		Node* temp = findMin(root->right);
		root->value = temp->value;
		root->right = deleteNode(root->right, temp->value);
	}
	
	return root;
}

//������� 
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


