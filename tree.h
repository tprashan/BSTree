
typedef struct treeNode TreeNode;
typedef TreeNode * tree_node_ptr;

struct treeNode{
	void* data;
	tree_node_ptr left;
	tree_node_ptr Right;
};

tree_node_ptr createTreeNode();

typedef struct bsTree BSTree;
typedef BSTree * BSTreePtr;

struct bsTree{
	tree_node_ptr root;
	int count;
};

BSTree createBSTree();
int insert(BSTree * tree, int data);
int setLeafNode(tree_node_ptr walker, int data,tree_node_ptr node);

tree_node_ptr find(BSTree tree, int data);
int findNodeInTree(tree_node_ptr walker, int data);

tree_node_ptr deleteNode(BSTree * tree, int data);

void traverse(BSTree tree, void (*print_element)(int  element));