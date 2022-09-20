#include <string>
class Integer {
	int n;
public:
	inline Integer(int n) { this->n = n; }
	inline Integer(std::string n) {
		this->n = stoi(n);
	}

	inline void set(int n) { this->n = n; }
	inline int get() { return this->n; }
	inline bool isEven() {
		if (this->n % 2 == 0) return 1;
		else return 0;
	}
};