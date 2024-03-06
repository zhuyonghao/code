#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//�ṹ 
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//�������    ������ �ݹ�ķ�ʽ���� 
//�Ӹ���㿪ʼ�������ҽ��� 
//�������ǰ��մ����ҿ�ʼ�� 
void preOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;
	cout << root->val << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
	//��ʼ�� 
}

//�������      �����    
//������ߵ�ֵ��ʼ 
void inOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;
	inOrderTraversal(root->left);
	cout << root->val << " ";
	inOrderTraversal(root->right);
	//��ʼ�� 
} 

//������� 
//������ߵ�ֵ��ʼ�����һλ�Ǹ���� 
void postOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->val << " ";	
} 

//��ȱ���    �������
void levelOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;
	//�½�һ����������������ڵ� 
	queue<TreeNode*> q;
	q.push(root);
	
	while (!q.empty()) 
	{
		//����ͷ���ȡ�� 
		TreeNode* node = q.front();
		//��ͷ���� 
		q.pop();
		cout << node->val << " ";
		//���ҽ����� 
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
		
} 

//������   ���ڵ㵽Ҷ�ӽڵ�������� 
//��һ��Ϊ���ڵ� 
int maxDepth(TreeNode* root) 
{
	if (root == nullptr)
		return 0;
	//���ΪҶ�ӽڵ�   leftDepth = rightDepth = 0
	//���ʱ��   ����Ҷ�ӽڵ����һ��      leftDepth = 1 
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	
	return max(leftDepth, rightDepth) + 1;  
}


//��С����   ���ڵ㵽Ҷ�ӽڵ����С����
int minDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr)
		return minDepth(root->right) + 1;
	if (root->right == nullptr)
		return minDepth(root->left) + 1;
	
	int leftDepth = minDepth(root->left);
	int rightDepth = maxDepth(root->right);
	
	return min(leftDepth, rightDepth) + 1; 
} 

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Preorder Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    
    cout << "Inorder Traversal: ";
    inOrderTraversal(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    postOrderTraversal(root);
    cout << endl;
    
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;
    
    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;
    
    return 0;
}

