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
}