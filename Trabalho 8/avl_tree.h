#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include <algorithm>
#include <stdexcept>
#include "tree.h"
#include "list.h"

/* Os comentários estão em inglês porque eu mantenho um repositório no Github:
 * https://github.com/ranisalt/data-structures
 */

template<typename T, template<typename> class Container = list>
class avl_tree: public tree<T, Container> {
  typedef unsigned int size_t;

private:
	struct node {
		node(const T& item) :
				_height(1), _left(0), _right(0), _item(item) {
		}

		size_t _height;
		node* _left;
		node* _right;
		T _item;
	};

	bool has(node* root, const T& item) const {
		if (root == 0)
			return false;
		if (root->_item > item)
			return has(root->_left, item);
		if (root->_item < item)
			return has(root->_right, item);
		return true;
	}

	size_t factor(node* root) const {
		return (root == 0) ? 0 : height(root->_left) - height(root->_right);
	}

	size_t height(node* root) const {
		return (root == 0) ? 0 : root->_height;
	}

	node* insert(node* root, const T& item) {
		// If we find a null root, we found the right spot.
		if (root == 0)
			return root = new node(item);

		// If root's value is greater than inserted value, try to insert to the left.
		else if (root->_item > item) {
			root->_left = insert(root->_left, item);

			// If the factor of root unbalancing is 2, we have a left-left or left-right case.
			if (factor(root) == 2) {

				// If the factor of the left node is -1, we have a left-right case.
				if (factor(root->_left) == -1)
					rotate_left(root->_left);

				// The tree is now guaranteedly a left-left case.
				rotate_right(root);
			}
		}
		
		// If root's value is lesser than inserted value, try to insert to the right.
		else if (root->_item < item) {
			root->_right = insert(root->_right, item);

			// If the factor of root unbalancing is -2, we have a right-left or right-right case.
			if (factor(root) == -2) {

				// If the factor of the right node is 1, we have a right-left case.
				if (factor(root->_right) == 1)
					rotate_right(root->_right);

				// The tree is now guaranteedly a right-right case.
				rotate_left(root);
			}
		}
		
		// Recalculate the node height according to the insertion.
		root->_height = std::max(height(root->_left), height(root->_right)) + 1;
		return root;
	}

	void rotate_left(node*& root) {
		node* aux;
		aux = root->_right;
		root->_right = aux->_left;
		aux->_left = root;
		root = aux;
	}

	void rotate_right(node*& root) {
		node* aux;
		aux = root->_left;
		root->_left = aux->_right;
		aux->_right = root;
		root = aux;
	}

	node* remove(node* root, const T& item) {
		// If we find a 0, the item does not exist in this tree.
		if (root == 0)
			return 0;

		// The same of insertion works here. Find where the item must be, rebalance if needed.
		else if (root->_item > item) {
			root->_left = remove(root->_left, item);
			if (factor(root) == 2) {
				if (factor(root->_left) == -1)
					rotate_left(root->_left);
				rotate_right(root);
			}
		} else if (root->_item < item) {
			root->_right = remove(root->_right, item);
		
			if (factor(root) == -2) {
				if (factor(root->_right) == 1)
					rotate_right(root->_right);
				rotate_left(root);
			}
		}
		
		// If root's value is equal to removed value, we found the node to remove.
		else {

			// Leaf case: just delete the actual node.
			if (root->_left == 0 && root->_right == 0) {
				delete root;
				return 0;
			}

			// If there is only right child, replace the to-be-deleted node and delete it.
			if (root->_left == 0) {
				node* aux = root->_right;
				delete root;
				return aux;
			}

			// If there is only left child, replace the to-be-deleted node and delete it.
			if (root->_right == 0) {
				node* aux = root->_left;
				delete root;
				return aux;
			}

			// If there are both children, find the immediately next value, swap and retry to remove.
			node* aux = root->_right;
			while (aux->_left != 0)
				aux = aux->_left;
			std::swap(root->_item, aux->_item);
			root->_right = remove(root->_right, item);
		}

		// Recalculate the node height according to the removal.
		root->_height = std::max(height(root->_left), height(root->_right)) + 1;
		return root;
	}

	void in_order(node* root, Container<T>& container) const {
		if (root != 0) {
			in_order(root->_left, container);
			container.push_back(root->_item);
			in_order(root->_right, container);
		}
	}

	void pre_order(node* root, Container<T>& container) const {
		if (root != 0) {
			container.push_back(root->_item);
			pre_order(root->_left, container);
			pre_order(root->_right, container);
		}
	}

	void post_order(node* root, Container<T>& container) const {
		if (root != 0) {
			post_order(root->_left, container);
			post_order(root->_right, container);
			container.push_back(root->_item);
		}
	}

	node* recursive_copy(node* other_root) {
		// To recursively copy, create a new node, recursively copy it's left and right child, then return it to be attached.
		node* aux = new node(other_root->_item);
		aux->_left = recursive_copy(other_root->_left);
		aux->_right = recursive_copy(other_root->_right);
		return aux;
	}

	void recursive_delete(node* root) {
		// To recursively delete, recursively delete both children if they exist, then delete.
		if (root != 0) {
			recursive_delete(root->_left);
			recursive_delete(root->_right);
			delete root;
		}
	}

public:
	avl_tree() :
			_size(0), _root(0) {
	}

	avl_tree(const avl_tree<T>& other) {
		_root = recursive_copy(other.root);
	}

	~avl_tree() {
		recursive_delete(_root);
	}

	bool has(const T& item) const {
		return has(_root, item);
	}

	size_t size() const {
		return _size;
	}

	void insert(const T& item) {
		_root = insert(_root, item);
		++_size;
	}

	void remove(const T& item) {
		_root = remove(_root, item);
		--_size;
	}

	Container<T> in_order() const {
		Container<T> container;
		in_order(_root, container);
		return container;
	}

	Container<T> pre_order() const {
		Container<T> container;
		pre_order(_root, container);
		return container;
	}

	Container<T> post_order() const {
		Container<T> container;
		post_order(_root, container);
		return container;
	}

private:
	size_t _size;
	node* _root;
};

#endif
