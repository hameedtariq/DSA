#include "BST.h"
using namespace std;


int main() {
	BST<int> tree;

	tree.insert(50);
	tree.insert(10);
	tree.insert(60);
	tree.insert(9);
	tree.insert(20);
	tree.insert(55);
	tree.insert(56);
	tree.insert(65);

	//cout << tree.search(9);

	//tree.levelOrderPrint();

	//cout << tree.getHeight();

	tree.remove(50);


	tree.inOrderPrint();


}




