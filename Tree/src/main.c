/*
 * main.c
 *
 *  Created on: Nov 18, 2012
 *      Author: arming
 */
#include <stdio.h>
#include <malloc.h>
#include "BinaryTree.h"
#define NUM 9
//TreeNode root;
/*void test(TreeNode *a, TreeNode b)
{
	*a = b;
	(*a)->value = 10;

}*/
int main()
{
	TreeNode root = NULL;
	int value = 0;
	int i;
	FILE *file = fopen("tree_test.txt","r");
	for(i = 0; i < NUM; i++)
	{
		fscanf(file,"%d",&value);

		TreeNode newnode = talloc();
		newnode->value = value;
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->parent = NULL;

		tree_insert(&root,newnode);
	}
	fclose(file);

	//delete one node
	TreeNode max = tree_maximum(root);
	printf("max: %d\n",max->value);
	TreeNode min = tree_minimum(root);
	printf("min: %d\n",min->value);

	TreeNode search = tree_search(root,15);
	printf("search %d\n",search->value);

	tree_delete(root, search);
	inorder_tree_walk(root);



/*	TreeNode nn = talloc();
	nn->value = 100;
	test(&root,nn);*/
	return 0;
}
