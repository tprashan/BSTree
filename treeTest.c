# include <stdio.h>
# include <stdlib.h>
# include "tree.h"
#include "expr_assert.h"

void test_1_create_tree_node_ptr_that_gives_left_right_and_data_0(){
	tree_node_ptr node ;
	node = createTreeNode();
	assertEqual((int)node->data,0);
	assertEqual((int)node->left,0);
	assertEqual((int)node->Right,0);
};

void test_2_create_tree_structure_that_gives_root_as_tree_node_ptr_and_count_0(){
	BSTree tree ;
	tree = createBSTree();
	assertEqual((int)((tree.root)->data),0);
	assertEqual((int)(tree.count),0);
};

void test_3_create_tree_structure_that_gives_root_as_tree_node_ptr_and_root_has_data_left_Right(){
	BSTree tree ;
	tree = createBSTree();
	assertEqual((int)((tree.root)->left),0);
	assertEqual((int)((tree.root)->Right),0);
	assertEqual((int)(tree.count),0);
};

void test_4_inserts_the_given_element_into_the_search_tree(){
	BSTree tree ;
	int data = 5,result;
	tree = createBSTree();
	result = insert(&tree,data);

	assertEqual((int)((tree.root)->data),5);
	assertEqual((int)(tree.count),1);
};

void test_5_inserts_the_given_element_into_the_search_tree(){
	BSTree tree ;
	int data = 200,result;
	tree = createBSTree();
	result = insert(&tree,data);
	assertEqual((int)((tree.root)->data),200);
	assertEqual((tree.count),1);
};

void test_6_inserts_the_given_elements_into_the_search_tree_return_count_5(){
	BSTree tree ;
	int data[5] = {13,11,12,10,9},result,i;
	tree = createBSTree();
	for(i=0;i<5;i++){
		result = insert(&tree,data[i]);
	}
	assertEqual((int)((tree.root)->data),13);
	assertEqual((int)((tree.root->left)->data),11);
	assertEqual((int)((tree.root->left)->Right->data),12);
	assertEqual((int)(tree.count),5);
};

void test_7_inserts_the_given_elements_into_the_search_tree_return_count_10(){
	BSTree tree ;
	int data[10] = {13,11,12,10,9,8,14,20,14,22},result,i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		result = insert(&tree,data[i]);
	}
	assertEqual((int)(tree.root->Right->data),14);
	assertEqual((int)(tree.root->left->left->data),10);
	assertEqual((int)(tree.root->Right->Right->data),20);
	assertEqual((int)(tree.root->Right->Right->left->data),14);
	assertEqual((int)(tree.count),10);
};

void test_8_inserts_the_given_elements_into_the_search_tree_return_count_10(){
	BSTree tree ;
	float data[10] = {13,11.2,12,10.4,9,8.3,14.5,20,14.7,22};
	int result,i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		result = insert(&tree,data[i]);
	}
	assert((int)(tree.root->Right->data)==14);
	assert((int)(tree.root->left->left->data)==10);
	assert((int)(tree.root->Right->Right->data)==20);
	assert((int)(tree.root->Right->Right->left->data)==14);
	assertEqual((int)(tree.count),10);
};

void test_9_Given_a_key_find_a_node_with_that_key_is_present_in_the_tree(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {13,11,12,10,9,8,14,20,14,22},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = find(tree,10);
	assertEqual((int)(result->data),10);
};

void test_10_Given_a_key_find_a_node_with_that_key_is_present_in_the_tree_return_22(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {13,11,12,10,9,8,14,20,14,22},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = find(tree,22);
	assertEqual((int)result->data,22);
};

void test_11_Given_a_key_find_a_node_with_that_key_is_present_in_the_tree_return_null_if_not_found(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {13,11,12,10,9,8,14,20,14,22},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = find(tree,25);
	assertEqual((int)result->data,(int)NULL);
};

void test_12_Given_a_key_find_a_node_with_that_key_is_present_in_the_tree_return_null_if_not_found(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {14,12,15,13,17,16,13,18,10,0},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = find(tree,20);
	assertEqual((int)result->data,(int)NULL);
};

void test_13_Given_a_key_find_a_node_with_that_key_is_present_in_the_tree(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {14,12,15,13,17,16,13,18,10,0},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = find(tree,16);
	assertEqual((int)result->data,16);
};

void test_14_Given_a_key_find_a_node_with_that_key_is_present_in_the_tree(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {14,12,15,13,17,16,13,18,10,0},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = find(tree,13);
	assertEqual((int)result->data,13);
};

void print_element(int element) { 
	printf("%d\n", element);
};

void test_15_Given_a_key_find_that_node_and_delete_that_key_if_present_in_the_tree_when_key_node_has_no_child(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {14,12,15,13,17,16,13,18,10,7},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = deleteNode(&tree,7);
	assertEqual((int)result->data,7);
};

void test_16_Given_a_key_find_that_node_and_delete_that_key_when_key_node_has_one_child(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {14,12,15,13,17,16,13,18,10,7},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = deleteNode(&tree,10);
	assertEqual((int)result->data,10);
};

void test_17_Given_a_key_find_that_node_and_delete_that_key_when_key_node_has_two_child(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {14,12,15,13,17,16,13,14,10,7},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = deleteNode(&tree,15);
	assertEqual((int)result->data,15);
};

void test_18_Given_a_key_find_that_node_and_delete_that_key_when_key_node_has_two_child(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {14,12,15,13,17,16,13,14,10,7},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	result = deleteNode(&tree,12);
	traverse(tree, &print_element);
	assertEqual((int)result->data,12);
};

void test_20_Given_a_key_find_a_node_with_that_key_is_present_in_the_tree(){
	BSTree tree ;
	tree_node_ptr result;
	int data[10] = {14,12,15,13,17,16,13,14,10,7},i;
	tree = createBSTree();
	for(i=0;i<10;i++){
		insert(&tree,data[i]);
	}
	traverse(tree, &print_element);
};