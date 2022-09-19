class CoffeeMachine {
private:
	unsigned short coffee;
	unsigned short water;
	unsigned short suger;
public:
	CoffeeMachine(int coffee, int water, int suger); // »ý¼ºÀÚ
	void drinkEspresso();
	void show();
	void drinkAmericano();
	void drinkSugarCoffee();
	void fill();
};