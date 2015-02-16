# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "tree.h"


tree_node_ptr createTreeNode(){
	tree_node_ptr new_node= calloc(sizeof(TreeNode),1);
	new_node->data = NULL;
	new_node->left = NULL;
	new_node->Right = NULL;
	return new_node;
}

BSTree createBSTree(void){
	BSTreePtr new_tree = calloc(sizeof(BSTree),1);
	tree_node_ptr treeNode = createTreeNode();
	new_tree->root = treeNode;
	new_tree->count = 0;
	return *new_tree;
}

int setLeafNode(tree_node_ptr walker, int data,tree_node_ptr node){
	if((walker->data) > (void*)data && walker->left==NULL){
		walker->left = node;
		walker->left->data =(void*) data;return 1;
	}

	if((walker->data) <= (void*)data && walker->Right==NULL){
		walker->Right = node;
		walker->Right->data =(void*) data;return 1;
	}
	return 0;
}

int insert(BSTree * tree, int data){
	tree_node_ptr walker = tree->root;
	tree_node_ptr node = createTreeNode();

	while((walker->data)!=NULL){
		if(setLeafNode(walker,data,node)){ tree->count = tree->count + 1;return 1;}

		walker = ((walker->data) > (void*)data) ?  walker->left : walker->Right;
	}
	
	if((walker->data)==NULL){
		(walker->data) = (void*)data;
		tree->count = tree->count + 1;
	}
		
	return 1;
}

int findNodeInTree(tree_node_ptr walker, int data){
	if((walker->data) == (void*)data) return 1;
	return 0;
}

tree_node_ptr find(BSTree tree, int data){
	tree_node_ptr walker = tree.root;
	tree_node_ptr node;
	while(walker!=NULL){
		if(findNodeInTree(walker,data)) return walker;
		walker = ((walker->data) > (void*)data) ?  walker->left : walker->Right;
	}
	node = createTreeNode();
	return node;
};


void preorder(tree_node_ptr root,void (*print_element)(int  element)) {
   if (root != NULL) {
    	print_element((int) root->data);
   		preorder(root->left,print_element);
      	preorder(root->Right,print_element);
   }
}


void postorder(tree_node_ptr root,void (*print_element)(int  element)) {
   if (root !=NULL) {
      	postorder(root->left,print_element);
      	postorder(root->Right,print_element);
    	print_element((int) root->data);
   }
}

void inorder(tree_node_ptr root,void (*print_element)(int  element)) {
   if (root != NULL) {
    inorder(root->left,print_element);
    print_element((int) root->data);
    inorder(root->Right,print_element);
   }
}

void traverse(BSTree tree, void (*print_element)(int  element)){
	inorder(tree.root,print_element);
	// preorder(tree.root,print_element);
	// postorder(tree.root,print_element);
}

///////////////////////////////////////////////////Delete Node////////////////////////////////////////////////////////

int findLChildAndRChild(tree_node_ptr node){
	if(node->left==NULL && node->Right==NULL) return 0;
	if(node->left==NULL || node->Right==NULL) return 1;
	return 2;
}

int findPreNodeInTree(tree_node_ptr walker, tree_node_ptr nodeToDelete){
	if(walker->left==nodeToDelete || walker->Right==nodeToDelete) return 1;
	return 0;
}


tree_node_ptr findPreviousNode(BSTree *tree, tree_node_ptr nodeToDelete,int data){
	tree_node_ptr walker = tree->root;
	tree_node_ptr node;
	while(walker!=NULL){
		if(findPreNodeInTree(walker,nodeToDelete)) return walker;
		walker = ((walker->data) > (void*)data) ?  walker->left : walker->Right;
	}
	return NULL;
}

tree_node_ptr findMin(tree_node_ptr delNodeRight){
	while (delNodeRight->left != NULL) 
    	delNodeRight = delNodeRight->left;
   	return delNodeRight;
}

void handleOneNode(tree_node_ptr previousNode,tree_node_ptr nodeToDelete,int data){
	if((int)previousNode->data > data && (!nodeToDelete->left)) previousNode->left=nodeToDelete->left ;
	else if((int)previousNode->data > data && nodeToDelete->left) previousNode->left=nodeToDelete->Right;
	else if((int)previousNode->data <= data && (!nodeToDelete->left)) previousNode->Right=nodeToDelete->left ;
	else if((int)previousNode->data <= data && nodeToDelete->left) previousNode->Right=nodeToDelete->Right ;
}

void handleTwoNode(tree_node_ptr previousNode,tree_node_ptr nodeToDelete,BSTree *tree){
	tree_node_ptr minValueNode = findMin(nodeToDelete->Right);
	printf("Find Min----%d\n",(int)minValueNode->data );
	previousNode = findPreviousNode(tree,minValueNode,(int)minValueNode->data);
	printf("Find previousNode----%d\n",(int)previousNode->data );
	if(minValueNode->left) previousNode->left = NULL;
	nodeToDelete->data = minValueNode->data;
}

tree_node_ptr deleteNode(BSTree * tree, int data){
	tree_node_ptr result;tree_node_ptr minValueNode;
	tree_node_ptr nodeToDelete = find(*tree,data);
	tree_node_ptr previousNode = findPreviousNode(tree,nodeToDelete,data);
	int numOfChildNode = findLChildAndRChild(nodeToDelete);

	if(!numOfChildNode){
		if((int)previousNode->data > data) previousNode->left=NULL ;
		else previousNode->Right=NULL;
	}
	if(numOfChildNode==1){
		handleOneNode(previousNode,nodeToDelete,data);
	}
	if(numOfChildNode==2){
		result = createTreeNode();
		result->data = nodeToDelete->data;
		handleTwoNode(previousNode,nodeToDelete,tree);
		return result;
	}
	return nodeToDelete;
};
