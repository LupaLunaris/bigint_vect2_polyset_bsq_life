#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {

}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& source) : tree_bag(source) {

}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag& source) {
	if (this == &source)
		return *this;
	tree_bag::operator=(source);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag() {

}

bool searchable_tree_bag::search_node(node *current, int value) const {
	if (current == nullptr)
		return false;
	if (current->value == value)
		return true;
	return search_node(current->r, value) || search_node(current->l, value);
}

bool searchable_tree_bag::has(int value) const {
	return search_node(tree, value);
}
