/*
	Muhammad Hameed Tariq
	BCSF20A027
*/
#include "AVL.h"

template<typename T>
 AVL<T>::AVL()
{
	root = nullptr;
}

template<typename T>
 AVL<T>::~AVL()
{
	if (!root) return;
	queue<AVLNode<T>*> nodes;
	nodes.push(root);
	while (!nodes.empty()) {
		if (nodes.front()->left) nodes.push(nodes.front()->left);
		if (nodes.front()->right) nodes.push(nodes.front()->right);
		delete nodes.front();
		nodes.pop();
	}
	root = nullptr;
}

template<typename T>
 AVL<T>::AVL(const AVL<T>& rhs)
{
	queue<AVLNode<T>*> nodes;
	nodes.push(rhs.root);
	while (!nodes.empty()) {
		if (nodes.front()->left) nodes.push(nodes.front()->left);
		if (nodes.front()->right) nodes.push(nodes.front()->right);
		insert(nodes.front()->data);
		nodes.pop();
	}
}

template<typename T>
 void AVL<T>::insert(T val)
{
	if (!root) root = new AVLNode<T>(val);
	else
	{
		stack<AVLNode<T>*> nodes;
		nodes.push(root);
		while (!nodes.empty()) {
			if (nodes.top()->data > val) {
				if (!nodes.top()->left) {
					nodes.top()->left = new AVLNode<T>(val);
					break;
				}
				else
					nodes.push(nodes.top()->left);
			}
			else
			{
				if (!nodes.top()->right) {
					nodes.top()->right = new AVLNode<T>(val);
					break;
				}
				else
					nodes.push(nodes.top()->right);
			}
		}
		// recalculate height and check for rotations
		while (!nodes.empty()) {
			AVLNode<T>* p = nodes.top(); nodes.pop();
			p->height = calHeight(p);

			if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1) {
				if (nodes.empty()) {
					root = LLRotation(p);
				}
				else if (nodes.top()->left == p) {
					nodes.top()->left = LLRotation(p);
				}
				else if (nodes.top()->right == p) {
					nodes.top()->right = LLRotation(p);
				}
			}
			else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1) {
				if (nodes.empty()) {
					root = LRRotation(p);
				}
				else if (nodes.top()->left == p) {
					nodes.top()->left = LRRotation(p);
				}
				else if (nodes.top()->right == p) {
					nodes.top()->right = LRRotation(p);
				}
			}
			else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1) {
				if (nodes.empty()) {
					root = RRRotation(p);
				}
				else if (nodes.top()->left == p) {
					nodes.top()->left = RRRotation(p);
				}
				else if (nodes.top()->right == p) {
					nodes.top()->right = RRRotation(p);
				}
			}
			else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1) {
				if (nodes.empty()) {
					root = RLRotation(p);
				}
				else if (nodes.top()->left == p) {
					nodes.top()->left = RLRotation(p);
				}
				else if (nodes.top()->right == p) {
					nodes.top()->right = RLRotation(p);
				}
			}
		}

	}
}

template<typename T>
 int AVL<T>::calHeight(AVLNode<T>* node)
{
	if (!node) return -1;
	int rightH = node->right ? node->right->height : -1;
	int leftH = node->left ? node->left->height : -1;
	return rightH > leftH ? rightH + 1 : leftH + 1;
}

template<typename T>
 int AVL<T>::balanceFactor(AVLNode<T>* node)
{
	int rightH = node->right ? node->right->height : -1;
	int leftH = node->left ? node->left->height : -1;
	return leftH - rightH;
}

template<typename T>
 AVLNode<T>* AVL<T>::LLRotation(AVLNode<T>* p)
{
	AVLNode<T>* pl = p->left;

	p->left = pl->right;
	pl->right = p;

	p->height = calHeight(p);
	pl->height = calHeight(pl);
	return pl;
}

template<typename T>
 AVLNode<T>* AVL<T>::RRRotation(AVLNode<T>* p)
{
	AVLNode<T>* pr = p->right;

	p->right = pr->left;
	pr->left = p;

	p->height = calHeight(p);
	pr->height = calHeight(pr);


	return pr;
}

template<typename T>
 AVLNode<T>* AVL<T>::LRRotation(AVLNode<T>* p)
{
	AVLNode<T>* pl = p->left;
	AVLNode<T>* plr = pl->right;

	p->left = plr->right;
	pl->right = pl->left;
	plr->left = pl;
	plr->right = p;

	return plr;

}

template<typename T>
 AVLNode<T>* AVL<T>::RLRotation(AVLNode<T>* p)
{
	AVLNode<T>* pr = p->right;
	AVLNode<T>* prl = pr->left;
	p->right = prl->left;
	pr->left = prl->right;
	prl->left = p;
	prl->right = pr;

	return prl;
}

template<typename T>
 void AVL<T>::deleteNode(AVLNode<T>* p)
{
	stack<AVLNode<T>*> nodes;
	nodes.push(root);
	while (!nodes.empty()) {
		if (!p) return;
		else if (nodes.top() == p) {
			if (!nodes.top()->left && !nodes.top()->right) {
				AVLNode<T>* temp = nodes.top(); nodes.pop();

				if (!nodes.empty()) {
					if (nodes.top()->left == temp) {
						nodes.top()->left = nullptr;
					}
					else {
						nodes.top()->right = nullptr;
					}
				}
				else {
					root = nullptr;
				}
				delete temp;

				break;
			}
			else
			{
				if (calHeight(nodes.top()->left) > calHeight(nodes.top()->right)) {
					AVLNode<T>* pred = inOrderPredecessor(nodes.top());
					nodes.top()->data = pred->data;
					p = pred;
					nodes.push(nodes.top()->left);
				}
				else
				{
					AVLNode<T>* succ = inOrderSuccessor(nodes.top());
					nodes.top()->data = succ->data;
					p = succ;
					nodes.push(nodes.top()->right);
				}
			}
		}
		else if (nodes.top()->data > p->data) {
			nodes.push(nodes.top()->left);
		}
		else {
			nodes.push(nodes.top()->right);
		}
	}

	while (!nodes.empty()) {
		AVLNode<T>* p = nodes.top(); nodes.pop();
		p->height = calHeight(p);

		if (balanceFactor(p) == 2 && (balanceFactor(p->left) == 1 || balanceFactor(p->left) == 0)) {
			if (nodes.empty()) {
				root = LLRotation(p);
			}
			else if (nodes.top()->left == p) {
				nodes.top()->left = LLRotation(p);
			}
			else if (nodes.top()->right == p) {
				nodes.top()->right = LLRotation(p);
			}
		}
		else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1) {
			if (nodes.empty()) {
				root = LRRotation(p);
			}
			else if (nodes.top()->left == p) {
				nodes.top()->left = LRRotation(p);
			}
			else if (nodes.top()->right == p) {
				nodes.top()->right = LRRotation(p);
			}
		}
		else if (balanceFactor(p) == -2 && (balanceFactor(p->right) == -1 || balanceFactor(p->right) == 0)) {
			if (nodes.empty()) {
				root = RRRotation(p);
			}
			else if (nodes.top()->left == p) {
				nodes.top()->left = RRRotation(p);
			}
			else if (nodes.top()->right == p) {
				nodes.top()->right = RRRotation(p);
			}
		}
		else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1) {
			if (nodes.empty()) {
				root = RLRotation(p);
			}
			else if (nodes.top()->left == p) {
				nodes.top()->left = RLRotation(p);
			}
			else if (nodes.top()->right == p) {
				nodes.top()->right = RLRotation(p);
			}
		}
	}


}

template<typename T>
 AVLNode<T>* AVL<T>::search(T key)
{
	AVLNode<T>* temp = root;

	while (temp != nullptr) {
		if (temp->data > key) {
			temp = temp->left;
		}
		else if (temp->data < key) {
			temp = temp->right;
		}
		else {
			break;
		}
	}

	return temp;
}

template<typename T>
 AVLNode<T>* AVL<T>::inOrderPredecessor(AVLNode<T>* p)
{
	p = p->left;
	while (p->right != nullptr) {
		p = p->right;
	}
	return p;
}

template<typename T>
 AVLNode<T>* AVL<T>::inOrderSuccessor(AVLNode<T>* p)
{
	p = p->right;
	while (p->left != nullptr) {
		p = p->left;
	}
	return p;
}

template<typename T>
 AVLNode<T>* AVL<T>::getParent(AVLNode<T>* p)
{
	AVLNode<T>* parent = nullptr, * child = root;
	while (child && child != p) {
		parent = child;
		if (child->data > p->data) {
			child = child->left;
		}
		else {
			child = child->right;
		}
	}
	if (child) return parent;
	else return nullptr;
}

template<typename T>
 void AVL<T>::printNodes()
{
	queue<AVLNode<T>*> nodes;
	nodes.push(root);
	while (!nodes.empty()) {
		if (nodes.front()->left) nodes.push(nodes.front()->left);
		if (nodes.front()->right) nodes.push(nodes.front()->right);
		cout << nodes.front()->data << " ";
		nodes.pop();
	}
	cout << endl;
}

template<typename T>
 void AVL<T>::printTree()
{
	queue<AVLNode<T>*> nodes;
	nodes.push(root);
	int level = 0, breaker = 1, i = 0;
	while (!nodes.empty()) {
		if (level == breaker || i == 1) {
			level = 0;
			breaker *= 2;
			cout << endl;
		}
		if (nodes.front()) {
			if (nodes.front()->left) nodes.push(nodes.front()->left);
			else nodes.push(nullptr);
			if (nodes.front()->right) nodes.push(nodes.front()->right);
			else nodes.push(nullptr);
			cout << nodes.front()->data << " ";
			nodes.pop();
		}
		else {
			cout << "  ";
			nodes.pop();
		}
		i++; level++;
	}

}
