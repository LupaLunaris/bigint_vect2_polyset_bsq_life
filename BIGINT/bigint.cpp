

#include "bigint.hpp"
#include <sstream>

// Constructeurs
bigint::bigint() : str("0") {}

bigint::bigint(unsigned int num) {
    std::ostringstream oss;
    oss << num;
    str = oss.str();
}

bigint::bigint(const bigint& other) : str(other.str) {}

// Opérateur d'affectation
bigint& bigint::operator=(const bigint& other) {
    if (this != &other) {
        str = other.str;
    }
    return *this;
}

// Addition
bigint bigint::operator+(const bigint& other) const {
    bigint result;
    result.str = "";
    
    int carry = 0;
    int i = str.length() - 1;
    int j = other.str.length() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += str[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += other.str[j] - '0';
            j--;
        }
        result.str = char('0' + sum % 10) + result.str;
        carry = sum / 10;
    }
    return result;
}

bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

// Incrémentation
bigint& bigint::operator++() {
    bigint one(1);
    *this += one;
    return *this;
}

bigint bigint::operator++(int) {
    bigint temp(*this);
    ++(*this);
    return temp;
}

unsigned int bigint::sToUint(std::string str) const
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}
// Shifts
bigint bigint::operator<<(unsigned int n) const {
    bigint result(*this);
    for (unsigned int i = 0; i < n; i++) {
        result.str += '0';
    }
    return result;
}

bigint& bigint::operator<<=(unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        str += '0';
    }
    return *this;
}

bigint bigint::operator>>(unsigned int n) const {
    bigint result(*this);
    if (n >= result.str.length()) {
        result.str = "0";
    } else {
        result.str.erase(result.str.length() - n, n);
    }
    return result;
}

bigint& bigint::operator>>=(unsigned int n) {
    if (n >= str.length()) {
        str = "0";
    } else {
        str.erase(str.length() - n, n);
    }
    return *this;
}

// Tous tes opérateurs bigint → unsigned int
bigint& bigint::operator>>=(const bigint& other) {
    return *this >>= sToUint(other.str);
}

// bigint& bigint::operator<<=(const bigint& other) {
//     return *this <<= sToUint(other.str);
// }

// bigint bigint::operator>>(const bigint& other) const {
//     return *this >> sToUint(other.str);
// }

// bigint bigint::operator<<(const bigint& other) const {
//     return *this << sToUint(other.str);
// }

// Comparaisons
bool bigint::operator<(const bigint& other) const {
    if (str.length() != other.str.length()) {
        return str.length() < other.str.length();
    }
    return str < other.str;
}

bool bigint::operator>(const bigint& other) const {
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
    return !(other < *this);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

bool bigint::operator==(const bigint& other) const {
    return str == other.str;
}

bool bigint::operator!=(const bigint& other) const {
    return !(*this == other);
}

// Affichage
std::ostream& operator<<(std::ostream& os, const bigint& bi) {
    os << bi.str;
    return os;
}

