/*
 * RBTree.c
 *
 *  Created on: Nov 22, 2012
 *      Author: arming
 */

#include "RBTree.h"
#include <malloc.h>
/*
 * parameters:
 * is_left: 1 is left_rotate, 0 right_rotate
 */
void tree_rotate(RBTreeNode *root, RBTreeNode x, int is_left)
{
	RBTreeNode y;
	y = (is_left) ? x->right : x->left;
	if (is_left)
	{
		x->right = y->left;
		if (y->left)
			y->left->parent = x;
	}
	else
	{
		x->left = y->right;
		if (y->right)
			y->right->parent = x;
	}

	y->parent = x->parent;
	if (!x->parent)
		*root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	if (is_left)
		y->left = x;
	else
		y->right = x;
	x->parent = y;
}

/*
 void right_rotate(RBTreeNode **root, RBTreeNode *x)
 {
 RBTreeNode *y;
 y = x->left;
 x->left = y->right;
 if (y->right)
 y->right->parent = x;

 y->parent = x->parent;
 if (!x->parent)
 *root = y;
 else if (x == x->parent->right)
 x->parent->right = y;
 else
 x->parent->left = y;

 y->right = x;
 x->parent = y;

 }
 */

void rb_insert(RBTreeNode **root, RBTreeNode *z)
{
	RBTreeNode *y = NULL;
	RBTreeNode *x = *root;
	while (x)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (!y)
	{
		*root = z;
	}
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

	z->left = NULL;
	z->right = NULL;
	z->color = 'R';
	rb_insert_fixup(root, &z);
}
void rb_insert_fixup(RBTreeNode **root, RBTreeNode **x)
{
	RBTreeNode *y = NULL;
	RBTreeNode *z = *x;
	while ((z->parent)->color == 'R')
	{
		if (z->parent == z->parent->parent->left)
		{
			y = z->parent->parent->right;
			if (y->color == 'R')
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
			}
			else if (z == z->parent->right)
			{
				*x = z->parent;
				z = *x; // keep z points to new x
				left_rotate(root, *x);
			}
			z->parent->color = 'B';
			z->parent->parent->color = 'R';
			right_rotate(root, z->parent->parent);

		}
		else
		{
			y = z->parent->parent->left;
			if (y->color == 'R')
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
			}
			else if (z == z->parent->left)
			{
				*x = z->parent;
				z = *x; // keep z points to new x
				right_rotate(root, *x);
			}
			z->parent->color = 'B';
			z->parent->parent->color = 'R';
			left_rotate(root, z->parent->parent);
		}
	}
	*root->color = 'B';
}

RBTreeNode * rb_delete(RBTreeNode *root, RBTreeNode *z)
{
//	RBTreeNode *y;
//	if(z->left == NULL || z->right == NULL)
//		y = z;
//	else
//		y =
}

RBTreeNode *rb_delete_fixup(RBTreeNode *root, RBTreeNode *z)
{

}
