/*
 * BinaryTree.c
 *
 *  Created on: Oct 28, 2012
 *      Author: arming
 */

#include <stddef.h>
#include <malloc.h>
#include "BinaryTree.h"

TreeNode talloc()
{
	return (TreeNode) malloc(sizeof(struct tnode));
}

void inorder_tree_walk(TreeNode root)
{
	TreeNode p = root;
	if (p)
	{
		inorder_tree_walk(p->left);
		printf("%d\n", p->value);
		inorder_tree_walk(p->right);
	}
}

TreeNode tree_search(TreeNode root, int key)
{
	TreeNode p = root;
	while (p && p->value != key)
		if (key < p->value)
			p = p->left;
		else
			p = p->right;

	return p;
}
TreeNode tree_minimum(TreeNode node)
{
	while (node->left)
		node = node->left;

	return node;
}

TreeNode tree_maximum(TreeNode node)
{
	while (node->right)
		node = node->right;
	return node;
}

TreeNode tree_successor(TreeNode node)
{
	if (node->right)
		return tree_minimum(node->right);
	TreeNode y = node->parent;
	TreeNode x = node;
	while(y && (x == y->right))
	{
		x = y;
		y = y->parent;
	}

	return y;

}

void tree_insert(TNode **root, TreeNode z)
{
	TreeNode x, y;
	y = NULL;
	x = *root;
	while (x)
	{
		y = x;
		if((z->value ) < (x->value))
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if(!y)
		*root = z;
	else 
		if(z->value < y->value)
			y->left = z;
		else
			y->right = z;

}

TreeNode tree_delete(TreeNode root, TreeNode node)
{
	TreeNode y = NULL;
	TreeNode x = NULL;
	if(node->left == NULL || node->right == NULL)
		y = node;
	else
		y = tree_successor(node);

	if(y->left)
		x = y->left;
	else
		x = y->right;

	if(x)
		x->parent = y->parent;

	if(y->parent == NULL)
		root = x;
	else 
		if(y == ((y->parent)->left))
			(y->parent)->left = x;
		else
			(y->parent)->right = x;

	if(y != node)
		node->value = y->value;
	
	return y;


}
