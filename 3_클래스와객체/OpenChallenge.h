class Exp {
private:
	unsigned long base;
	unsigned long exp;
public:
	Exp(int base, int exp);
	Exp(int base);
	Exp();

	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);
};