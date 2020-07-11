#include "BinaryTreeClass.h"
using namespace std;
class BSTclass {
	BinaryTree<int>* root;

	public:

	BSTclass() {
		root = NULL;
	}

	~BSTclass() {
		delete root;
	}

	private:
	bool hasData(int data, BinaryTree<int>* addr) {
		if (addr == NULL) {
			return false;
		}

		if (addr->data == data) {
			return true;
		} else if (data < addr->data) {
			return hasData(data, addr->left);
		} else {
			return hasData(data, addr->right);
		}
	}

	public:
	bool hasData(int data) {
		return hasData(data, root);
	}
};
