/*
 * RBTree.h
 *
 *  Created on: Nov 22, 2012
 *      Author: arming
 */

#ifndef RBTREE_H_
#define RBTREE_H_

typedef struct RBtnode
{
	int key;
	char color;
	struct RBtnode *parent;
	struct RBtnode *left;
	struct RBtnode *right;
}*RBTreeNode, RBNode;

#define  RED 'R'
#define  BLACK 'B'

/*create new node*/
RBTreeNode rb_new_node();


/* Rotates a node around the given root. */
void tree_rotate(RBTreeNode *root, RBTreeNode node, int is_left);

/*
 void left_rotate(RBTreeNode **root, RBTreeNode *x);

 void right_rotate(RBTreeNode **root, RBTreeNode *x);
 */

void rb_insert(RBTreeNode *root, RBTreeNode z);

void rb_insert_fixup(RBTreeNode *root, RBTreeNode z);

RBTreeNode rb_delete(RBTreeNode *root, RBTreeNode z);

void rb_delete_fixup(RBTreeNode *root, RBTreeNode z);

#endif /* RBTREE_H_ */
