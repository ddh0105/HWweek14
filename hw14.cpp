#include<iostream>
#include<string>
using namespace std;

#define ll long long
#define max 1000
#define NIL -1


//thuoc tinh cho mot node tren cay
struct Node {
	char value;
	Node* left;
	Node* right;
	Node(char val) : value(val), left(nullptr), right(nullptr) {};
};

typedef Node* BinaryTree;

//Ham khoi tao cay
BinaryTree initBT(BinaryTree& T){
	T = nullptr;
}

//Kiem tra rong
bool isEmpty(BinaryTree T) {
	return T == nullptr;
}

//cai dat ham nhap phan tu (bo sung) vao cay tu bieu thuc hau to
BinaryTree buildExpTree(const string& p) {
	BinaryTree nodes[max];
	int index = NIL;

	for (char ch : p) {
		if (isalnum(ch)) {
			nodes[++index] = new Node(ch);
		}
		else {
			Node* node = new Node(ch);
			node->right = nodes[index--];
			node->left = nodes[index--];
			nodes[++index] = node;
		}
	}
	return nodes[index];
}

//3 ham duyet cay

// duyet theo thu tu truoc
void preOrderTraversal(BinaryTree T) {
	if (!isEmpty(T)) {
		cout << T->value << " ";
		preOrderTraversal(T->left);
		preOrderTraversal(T->right);
	}
}

//duyet theo thu tu giua
void inOrderTraversal(BinaryTree T) {
	if (!isEmpty(T)) {
		bool isOperator = !isalnum(T->value);
		if (isOperator && (T->left || T->right)) cout << "( ";//neu nut co con trai
		inOrderTraversal(T->left);//duyet con trai
		cout << T->value << " ";
		inOrderTraversal(T->right);
		if (isOperator && (T->left || T->right)) cout << ") ";
	}
}

//duyet theo cach hau to
void postOrderTraversal(BinaryTree T) {
	if (!isEmpty(T)) {
		postOrderTraversal(T->left);
		postOrderTraversal(T->right);
		cout << T->value << " ";
	}
}


int  main() {
	BinaryTree T;
	initBT(T);

	string bieuthuchauto = "a5*bc6^*d/-hf-e12/^*+";
	T = buildExpTree(bieuthuchauto);

	if (isEmpty(T)) {
		cout << "Cay bieu thuc rong>>" << endl;
		return 0;
	}

	//In bieu thuc theo 3 giai thuat duyet
	cout << "Duyet theo trung to: "; inOrderTraversal(T);cout << endl;
	cout << "Duyet theo tien to: "; preOrderTraversal(T);cout << endl;
	cout << "Duyet theo hau to: "; postOrderTraversal(T);cout << endl;

	return 0;
}
