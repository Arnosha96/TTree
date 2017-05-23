#pragma once

typedef unsigned char UC;
typedef int DataType;

struct NODE // ��������� ��� ������������� ����� ������
{
	DataType key;  // ���� ����
	int value;	   // ������
	UC height;     // ������ ���������
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
	UC   height(NODE* p);  // �������� ������
	int  bfactor(NODE* p); // ���������� ������� ����
	void fixheight(NODE* p); // ��������� ���� ������ ����

	NODE* rotateright(NODE* p); // ������ ������� ������ p
	NODE* rotateleft(NODE* q); // ����� ������� ������ q

	NODE* balance(NODE* p);            // ������������ ���� p
	NODE* insert(NODE* p, DataType k, int val); // ������� ����� k � ������� val � ������ � ������ p
	NODE* findmin(NODE* p);            // ����� ���� � ����������� ������ � ������ p 
	NODE* removemin(NODE* p);          // �������� ���� � ����������� ������ �� ������ p
	NODE* remove(NODE* p, DataType k); // �������� ����� k �� ������ p
	NODE *find(NODE*p, DataType k);
	void  print_dfs(NODE *p, int level);
public:
	void PRINT(NODE* n);
	AVLTree() :root(0){};
	void insert(DataType k, int val); // ���������� �������� � �������
	DataType get(DataType key); // ����� ��������
	void del(DataType key); // ������� ������� �� �������
	void print();
private:
	NODE* root;
};
