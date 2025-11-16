#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>

class bigint {
	private:
		std::string str;
		unsigned int sToUint(std::string str) const;

	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& other);
		
		bigint& operator=(const bigint &other);

		bigint& operator++();
		bigint operator++(int);

		bigint operator+(const bigint &other) const;
		bigint& operator+=(const bigint &other);

		// bigint operator<<(const bigint& other) const;
		bigint operator<<(unsigned int n) const;
		// bigint& operator<<=(const bigint& other);
		bigint& operator<<=(unsigned int n);
		// bigint operator>>(const bigint& other) const;
		bigint operator>>(unsigned int n) const;
		bigint& operator>>=(const bigint& other);
		bigint& operator>>=(unsigned int n);

		bool operator<(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;

	friend std::ostream& operator<<(std::ostream& out, const bigint& bi);

};

#endif
















































// #ifndef BIGINT_HPP
// #define BIGINT_HPP

// #include <iostream>
// #include <string>

// class bigint {
// private:
//     std::string str;
// 	unsigned int sToUint(std::string str) const;
// public:
//     // Constructeurs
//     bigint();
//     bigint(unsigned int num);
//     bigint(const bigint& other);

//     // Opérateur d'affectation
//     bigint& operator=(const bigint& other);

//     // Addition
//     bigint operator+(const bigint& other) const;
//     bigint& operator+=(const bigint& other);

//     // Incrémentation
//     bigint& operator++();
//     bigint operator++(int);

//     // Shifts
//     bigint operator<<(unsigned int n) const;
//     bigint& operator<<=(unsigned int n);
//     bigint operator>>(unsigned int n) const;
//     bigint& operator>>=(unsigned int n);
// 	bigint& operator>>=(const bigint& other);
// 	bigint& operator<<=(const bigint& other);
// 	bigint operator>>(const bigint& other) const;
// 	bigint operator<<(const bigint& other) const;

//     // Comparaisons
//     bool operator<(const bigint& other) const;
//     bool operator>(const bigint& other) const;
//     bool operator<=(const bigint& other) const;
//     bool operator>=(const bigint& other) const;
//     bool operator==(const bigint& other) const;
//     bool operator!=(const bigint& other) const;

//     // Affichage
//     friend std::ostream& operator<<(std::ostream& os, const bigint& bi);
// };

// #endif
