#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include <algorithm>
#include <stdexcept>
#include "tree.h"
#include "list.h"

template<typename T, template<typename> class Container = list>
class red_black_tree: public tree<T, Container> {
  typedef unsigned int size_t;

private:
	enum color { RED, BLACK };

	struct node {
		node(const T& item) :
			_color(BLACK), _parent(0), _left(0), _right(0), _item(item) {
		}

		enum color color() const {
			if (this == 0)
				return BLACK;
			return _color;
		}

		void color(const enum color& color) {
			if (this == 0) {
				if (color == RED)
					throw std::logic_error("Can not paint leaf.");
				return;
			}
			_color = color;
		}

		node* grandparent() const {
			if (this == 0 || _parent == 0)
				return 0;
			return _parent->_parent;
		}

		node* uncle() const {
			node* aux = grandparent();
			if (aux == 0) {
				if (_parent == aux->_left)
					return aux->_right;
				return aux->_left;
			}
			return 0;
		}

		friend void swap(node& a, node& b) {
			using std::swap;

			swap(a._color, b._color);
			swap(a._parent, b._parent);
			swap(a._left, b._left);
			swap(a._right, b._right);
			swap(a._item, b._item);
		}

		enum color _color;
		node* _parent;
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

	void repaint_insertion(node* root) {
		if (root->_parent == 0) {
			root->_color = BLACK;
			return;
		}

		node* aux;
		while (root->_parent->color() == RED) {
			aux = root->grandparent();
			if (root->_parent == aux->_left) {
				if (aux->_right->color() == RED) {
					root->_parent->color(BLACK);
					aux->_right->color(BLACK);

					aux->color(RED);
					root = aux;
				} else {
					if (root == root->_parent->_right) {
						root = root->_parent;
						rotate_left(root);
					}
					root->_parent->color(BLACK);
					
					aux->color(RED);
					rotate_right(aux);
				}
			} else {
				if (aux->_left->color() == RED) {
					root->_parent->color(BLACK);
					aux->_left->color(BLACK);

					aux->color(RED);
					root = aux;
				} else {
					if (root == root->_parent->_left) {
						root = root->_parent;
						rotate_right(root);
					}
					root->_parent->color(BLACK);
					
					aux->color(RED);
					rotate_left(aux);
				}
			}
		}
		root->color(BLACK);

			/*aux = root->uncle();
			if (aux != 0 && aux->_color == RED) {
				root->_parent->_color = BLACK;
				aux->_color = BLACK;
				aux->_parent->_color = RED;
				repaint(aux->_parent);
				return;
			}

			aux = root->grandparent();
			if (root->_parent->_right == root && root->_parent == aux->_left) {
				root->_parent = rotate_left(root->_parent);
				root = root->_left;
				return;
			}
			
			if (root->_parent->_left == root && root->_parent == aux->_right) {
				root->_parent = rotate_right(root->_parent);
				root = root->_right;
				return;
			}

			root->_parent->_color = BLACK;
			aux->_color = RED;
			if (root->_parent->_left == root)
				aux = rotate_right(aux);
			else
				aux = rotate_left(aux);*/
	}

	void repaint_removal(node* root) {
		if (root->_parent == 0) {
			root->color(BLACK);
			return;
		}

		node* aux;
		while (root != _root && root->color() != BLACK) {
			if (root == root->_parent->_left) {
				aux = root->_parent->_right;
				if (aux->color() == RED) {
					aux->color(BLACK);
					root->_parent->color(RED);
					rotate_left(root->_parent);
					aux = root->_parent->_right;
				}

				if (aux->_left->color() == BLACK && aux->_right->color() == BLACK) {
					aux->color(RED);
					root = root->_parent;
				} else {
					if (aux->_right->color() == BLACK) {
						aux->_left->color(BLACK);
						aux->color(RED);
						rotate_right(aux);
						aux = root->_parent->_right;
					}
					aux->color(root->_parent->color());
					root->_parent->color(BLACK);
					aux->_right->color(BLACK);
					rotate_left(root->_parent);
					root = _root;
				}
			} else {
				aux = root->_parent->_left;
				if (aux->color() == RED) {
					aux->color(BLACK);
					root->_parent->color(RED);
					rotate_right(root->_parent);
					aux = root->_parent->_left;
				}

				if (aux->_left->color() == BLACK && aux->_right->color() == BLACK) {
					aux->color(RED);
					root = root->_parent;
				} else {
					if (aux->_left->color() == BLACK) {
						aux->_right->color(BLACK);
						aux->color(RED);
						rotate_left(aux);
						aux = root->_parent->_left;
					}
					aux->color(root->_parent->color());
					root->_parent->color(BLACK);
					aux->_left->color(BLACK);
					rotate_right(root->_parent);
					root = _root;
				}
			}
		}
		root->_color = BLACK;
	}

	node* insert(node* root, const T& item) {
		if (root == 0) {
			root = new node(item);
		}
		else {
			if (root->_item > item) {
				root->_left = insert(root->_left, item);
				root->_left->_parent = root;
				repaint_insertion(root->_left);
			}
			else if (root->_item < item) {
				root->_right = insert(root->_right, item);
				root->_right->_parent = root;
				repaint_insertion(root->_right);
			}
		}
		
		return root;
	}

	node* remove(node* root, const T& item) {
		if (root == 0)
			return 0;

		if (root->_item > item)
			root->_left = remove(root->_left, item);

		else if (root->_item < item)
			root->_right = remove(root->_right, item);

		else {
			if (root->_left == 0 && root->_right == 0) {
				delete root;
				return 0;
			}

			if (root->_right == 0) {
				node* aux = root->_left;
				delete root;
				return aux;
			} 
			
			if (root->_left == 0) {
				node* aux = root->_right;
				delete root;
				return aux;
			}
			
			node* aux = root->_right;
			while (aux->_left != 0) {
				aux = aux->_left;
			}
			std::swap(root->_item, aux->_item);
			root->_right = remove(root->_right, item);
		}

		repaint_removal(root);
		return root;
	}

	node* rotate_left(node* root) {
		node* aux;
		aux = root->_right;
		aux->_parent = root->_parent;
		root->_right = aux->_left;
		root->_right->_parent = root;
		aux->_left = root;
		aux->_left->_parent = aux;

		if (aux->_parent->_left == root)
			aux->_parent->_left = aux;
		else
			aux->_parent->_right = aux;

		return aux;
	}

	node* rotate_right(node* root) {
		node* aux;
		aux = root->_left;
		aux->_parent = root->_parent;
		root->_left = aux->_right;
		root->_left->_parent = root;
		aux->_right = root;
		aux->_right->_parent = aux;

		if (aux->_parent->_left == root)
			aux->_parent->_left = aux;
		else
			aux->_parent->_right = aux;

		return aux;
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
	red_black_tree() :
		_size(0), _root(0) {
	}

	~red_black_tree() {
		recursive_delete(_root);
	}

	bool has(const T& item) const {
		return has(_root, item);
	};

	size_t size() const {
		return _size;
	};

	void insert(const T& item) {
		_root = insert(_root, item);
		++_size;
	};

	void remove(const T& item) {
		_root = remove(_root, item);
		--_size;
	};

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

#endif /* RED_BLACK_TREE_H_ */
