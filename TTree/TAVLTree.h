#pragma once

typedef unsigned char UC;
typedef int DataType;

struct NODE // структура для представления узлов дерева
{
	DataType key;  // ключ узла
	int value;	   // данные
	UC height;     // высота поддерева
	NODE* left;
	NODE* right;
	NODE(DataType k, int val)
	{ 
		key = k; 
		value = val; 
		left = right = 0; 
		height = 1; 
	}
};

class AVLTree
{	
private:
	UC   height(NODE* p);  // селектор высоты
	int  bfactor(NODE* p); // вычисление баланса узла
	void fixheight(NODE* p); // установка поля высоты узла

	NODE* rotateright(NODE* p); // правый поворот вокруг p
	NODE* rotateleft(NODE* q); // левый поворот вокруг q

	NODE* balance(NODE* p);            // балансировка узла p
	NODE* insert(NODE* p, DataType k, int val); // вставка ключа k с данными val в дерево с корнем p
	NODE* findmin(NODE* p);            // поиск узла с минимальным ключом в дереве p 
	NODE* removemin(NODE* p);          // удаление узла с минимальным ключом из дерева p
	NODE* remove(NODE* p, DataType k); // удаление ключа k из дерева p
	NODE *find(NODE*p, DataType k);
	void  print_dfs(NODE *p, int level);
public:
	void PRINT(NODE* n);
	AVLTree() :root(0){};
	void insert(DataType k, int val); // добавление элемента в таблицу
	DataType get(DataType key); // поиск элемента
	void del(DataType key); // удалить элемент из таблицы
	void print();
private:
	NODE* root;
};
