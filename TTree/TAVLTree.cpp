#include "TAVLTree.h"
#include <iostream>
using namespace std;

UC AVLTree::height(NODE* p)
{
	return p ? p->height : 0;
}

int AVLTree::bfactor(NODE* p)
{
	return height(p->right) - height(p->left);
}

void AVLTree::fixheight(NODE* p)
{
	UC hl = height(p->left);
	UC hr = height(p->right);
	p->height = (hl>hr ? hl : hr) + 1;
}

NODE* AVLTree::rotateright(NODE* p)
{
	NODE* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}
NODE* AVLTree::rotateleft(NODE* q)
{
	NODE* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}
NODE* AVLTree::balance(NODE* p)
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}
NODE* AVLTree::insert(NODE* p, DataType k, int val)
{
	if (!p) return new NODE(k,val);
	if (k<p->key)
		p->left = insert(p->left, k,val);
	else
		p->right = insert(p->right, k,val);
	return balance(p);
}
NODE* AVLTree::findmin(NODE* p)
{
	return p->left ? findmin(p->left) : p;
}
NODE* AVLTree::removemin(NODE* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}
NODE* AVLTree::remove(NODE* p, DataType k)
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else 
	{
		NODE* q = p->left;
		NODE* r = p->right;
		delete p;
		if (!r) return q;
		NODE* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}
void AVLTree::insert(DataType k, int val)
{
	root = insert(root, k,val);
}
void AVLTree::print_dfs(NODE *p, int level)
{
	if (p->left)
		print_dfs(p->left, level + 1);
	cout<<"Key:"<<p->key<<"; Value:"<<p->value<<endl;
	if(p->right)
		print_dfs(p->right, level + 1);
	
}


void AVLTree::print()
{
	cout<<"Root:("<<root->key<<";"<<root->value<<");"<<endl;
	print_dfs(root, 0);
}

NODE* AVLTree::find(NODE*p,DataType k)
{
	if (!p)
		return NULL;
	else if (k == p->key)
		return p;
	else if (k<p->key)
		p->left = find(p->left, k);
	else if (k > p->key)
		p->right = find(p->right, k);
}

DataType AVLTree::get(DataType key) 
{
	NODE* found = find(root, key);
	return found ? found->value :NULL;
}

void AVLTree::del(DataType key) 
{
	if (key!=root->key) 
	remove(root, key);
	else cout << "¬ершину удалить нельз€!";

}