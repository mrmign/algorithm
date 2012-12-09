/*
 * BinaryTree.h
 *
 *  Created on: Oct 28, 2012
 *      Author: arming
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

typedef struct tnode
{
	int value;
	struct tnode *parent;
	struct tnode *left;
	struct tnode *right;
}*TreeNode, TNode;


//create a new tnode
TreeNode talloc(void);

//print the tree
void inorder_tree_walk(TreeNode);

//search the node
TreeNode tree_search(TreeNode, int);

//the successor of the node x
TreeNode tree_successor(TreeNode);

// insert node
void tree_insert(TreeNode *, TreeNode);

// delete node from tree
TreeNode tree_delete(TreeNode, TreeNode);

//return the minimum node
TreeNode tree_minimum(TreeNode);

// return the maximum node
TreeNode tree_maximum(TreeNode);

#endif /* BINARYTREE_H_ */
