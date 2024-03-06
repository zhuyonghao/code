#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//结构 
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//先序遍历    根左右 递归的方式进行 
//从根结点开始从左往右进行 
//遍历都是按照从左到右开始的 
void preOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;
	cout << root->val << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
	//开始归 
}

//中序遍历      左根右    
//从最左边的值开始 
void inOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;
	inOrderTraversal(root->left);
	cout << root->val << " ";
	inOrderTraversal(root->right);
	//开始归 
} 

//后序遍历 
//从最左边的值开始，最后一位是根结点 
void postOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->val << " ";	
} 

//广度遍历    层序遍历
void levelOrderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;
	//新建一个队列用来存放树节点 
	queue<TreeNode*> q;
	q.push(root);
	
	while (!q.empty()) 
	{
		//将对头结点取出 
		TreeNode* node = q.front();
		//对头出队 
		q.pop();
		cout << node->val << " ";
		//左右结点入队 
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
		
} 

//最大深度   根节点到叶子节点的最大层数 
//第一层为根节点 
int maxDepth(TreeNode* root) 
{
	if (root == nullptr)
		return 0;
	//如果为叶子节点   leftDepth = rightDepth = 0
	//归的时候   对于叶子节点的上一层      leftDepth = 1 
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	
	return max(leftDepth, rightDepth) + 1;  
}


//最小层数   根节点到叶子节点的最小层数
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

