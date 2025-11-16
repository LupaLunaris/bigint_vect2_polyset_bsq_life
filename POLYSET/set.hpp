#pragma once

#include "searchable_bag.hpp"

class set {
	private:
		searchable_bag* _bag;
	
	public :
		set(searchable_bag* _bag);
		set(searchable_bag& bag);
		set(const set& source);
		set& operator=(const set& source);
		~set();

		void insert (int value);
		void insert (int *array, int size);
		bool has(int value) const;
		void print() const;
		void clear();

		searchable_bag& get_bag();
} ;