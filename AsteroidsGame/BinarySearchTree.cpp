#include <iostream>
using namespace std;


class BinarySearchTree {
private :
	class Node {
	public:
		long data;
		Node* right;
		Node* left;
		Node(long value) {
			data = value;
			right = left = 0;
		}
	};
	Node* root;
public:
	BinarySearchTree() {
		root = nullptr;
	}
	BinarySearchTree(long value) {
		root = new Node(value);
	}

	void insert(long item) {
		if (root == nullptr) {
			root = new Node(item);
			return;
		}

		Node* ptr = root;
		Node* pred = 0;
		while (ptr) {
			pred = ptr;

			if (item == ptr->data) {
				return;
			}
			if (item > ptr->data) {
				ptr = ptr->right;
				continue;
			}
			if (item < ptr->data) {
				ptr = ptr->left;
				continue;
			}
		}
		ptr = new Node(item);
		if (pred->data < item) {
			pred->right = ptr;
			return;
		}
		else {
			pred->left = ptr;
		}
	}
	long getMax() {
		Node* ptr = root;
		while (ptr->right) {
			ptr = ptr->right;
		}
		return ptr->data;
	}
	void displayReq(string order) {
		if(order == "in order") display1(root);
		else if (order == "pre order") display2(root);
		else if (order == "post order") display3(root);
		
	}
	void erase(long item) {
		Node* ptr = root;
		Node* parent = 0;
		bool found = false;

		//searching for intended node
		while (ptr) {
			
			if (ptr->data == item) {
				found = true;
				break;
			}
			if (ptr->data > item) {
				parent = ptr;
				ptr = ptr->left;
				continue;
			}
			if (ptr->data < item) {
				parent = ptr;
				ptr = ptr->right;
				continue;
			}
		}
		if (!found) {
			cerr << "item not found"<<endl;
			return;
		}
		
		//2 children
		if ((ptr->left) && (ptr->right)) {
			//getting right leftmost
			Node* rightleftmost = ptr->right;
			while ((rightleftmost->left) != 0) {
				parent = rightleftmost;
				rightleftmost = rightleftmost->left;
			}
			ptr->data = rightleftmost->data;
			ptr = rightleftmost;
		}
		
		
		// 0 or 1 children
		Node* subtree = ptr->left;
		if (subtree == 0) {
			subtree = ptr->right;
		}
		if (parent == 0) {
			root = subtree;
			return;
		}
		if (parent->left == ptr) {
			parent->left = subtree;
			return;
		}
		if (parent->right == ptr) {
			parent->right = subtree;
			return;
		}
	}

private:
	void display1(Node* ptr) {

		if (ptr == 0) return;
		display1(ptr->left);
		cout << ptr->data<<" ";
		display1(ptr->right);
	}
	void display2(Node* ptr) {

		if (ptr == 0) return;
		cout << ptr->data << " ";
		display2(ptr->left);
		display2(ptr->right);
	}
	void display3(Node* ptr) {

		if (ptr == 0) return;
		display3(ptr->left);
		display3(ptr->right);
		cout << ptr->data << " ";
	}
};

class hashmap {
private:
	int arr[97] = { -1 };
	int size;

public:
	hashmap() {
		size = 0;
		for (int i = 0; i < 97;i++) {
			arr[i] = -1;
		}
	}
	void insert(int val) {
		if (val < 0) {
			cerr << "only postive values";
			return;
		}

		int i = hash(val);

		while (true) {
			if ((arr[i] == -1) || (arr[i] == -2) ) break;
			i = (i+1) % 97;
		}

		arr[i] = val;
		size++;

	}
	void erase(int val) {
		if (val < 0) {
			cerr << "only postive values";
			return;
		}

		int i = hash(val);

		while (true) {
			if (arr[i] == -1) {
				cout << "item not found";
				return;
			}
			if (arr[i] == val) {
				arr[i] = -2;
				return;
			}
			i = (i+1) % 97;
		}
	}
	bool ispresent(int val) {
		int i = hash(val);
		while (true) {
			if (arr[i] == val) return true;
			if (arr[i] == -1) return false;
			i = (i+1) % 97;
		}
	}
	int hash(int val) {
		return (val % 97);
	}
	int rsize() {
		return size;
	}

};
/*int main() {
	BinarySearchTree<int> bst;
	bst.insert(50);
	bst.insert(40);
	bst.insert(30);
	bst.insert(45);
	bst.insert(42);
	bst.insert(60);
	bst.insert(55);
	bst.insert(70);
	bst.insert(75);
	bst.insert(65);
	bst.insert(62);
	bst.insert(64);
	bst.erase(50);

	hashmap m;
	m.insert(100);
	m.insert(82);
	m.insert(86);
	m.insert(6);
	m.erase(82);
	cout << m.ispresent(82);


	
	return 0;
}*/