#include "TAVLTree.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	AVLTree tree;

	tree.insert(10, 39);
	tree.insert(20, 12);
	tree.insert(30, 2320);
	tree.insert(40, 322);
	tree.insert(50, 22);
	tree.insert(25, 21);
	
	cout << "Печать дерева:" << endl;
	tree.print();
	
	cout << "Удаление элемента:" << endl;
	tree.del(40);

	tree.print();

	cout << "Поиск элемента по ключу:" << endl;
	cout << tree.get(30)<<endl;

	_getch();
	return 0;
}