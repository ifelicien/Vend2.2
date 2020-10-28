#include <iostream>
using namespace std;

int turnPowerOn();
bool powerSwitch();
double menu();
double payment(double);
double coin_Return(double, double);
void payment_Verification(double, double);

bool power = false;

int main() {
	turnPowerOn();
	double price =  menu();
	double pmt = payment(price);
	payment_Verification(price, pmt);
	coin_Return(price, pmt);
}

int turnPowerOn() {
	!power ? powerSwitch() : power;
	return 0;
}

bool powerSwitch() {
	cout << "Turning the power on. \n" << endl;
	power = !power;
	return 0;
}

double menu() {
	int selection;
	double price;

start:

	cout << "Please Select an Item: " << endl;
	cout << "1. Coke \t 0.95\n2. Doritos \t 0.75\n3. Snickers \t 0.55 \n4. Chex Mix \t 0.60 \n5. Pepsi \t 0.90" << endl;
	cin >> selection;

	switch (selection) {
	case 1: 
		cout << "Coke" << endl;
		price = 0.95;
		break;
	case 2:
		cout << "Doritos" << endl;
		price = 0.75;
		break;
	case 3:
		cout << "Snickers" << endl;
		price = 0.55;
		break;
	case 4:
		cout << "Chex Mix" << endl;
		price = 0.60;
		break;
	case 5:
		cout << "Pepsi" << endl;
		price = 0.90;
		break;
	default:
		cout << "Invalid Selection" << endl;
		goto start;
	}
	return price;
}

double payment(double price){
	double paid = 0.0;
	int pennies, nickles, dimes, quarters, one_Dollar, five_Dollar;

	cout << "Please enter payment " << endl;

	cout << "Pennies: ";
	cin >> pennies;
	paid += pennies * 0.01;

	cout << "Nickles:";
	cin >> nickles;
	paid += nickles * 0.05;

	cout << "Dimes:";
	cin >> dimes;
	paid += dimes * 0.10;

	cout << "Quarters:";
	cin >> quarters;
	paid += quarters * 0.25;

	cout << "One Dollar:";
	cin >> one_Dollar;
	paid += one_Dollar * 1.00;

	cout << "Five Dollar:";
	cin >> five_Dollar;
	paid += five_Dollar * 5.00;

	string dispense = (paid >= price) ? "dispensing item " : "Insert correct amount";
	return paid;
	}

void payment_Verification(double itemCost, double userPayment) {
	double refund = itemCost - userPayment;

	if (userPayment >= itemCost) {
		cout << "Your item is dispensing" << endl;
	}
	else {
		cout << "Please add " << refund << " cents" << endl;
	}
}

double coin_Return(double itemCost, double userPayment) {
	double refund = itemCost - userPayment;
	return refund;
}
//TODO: complete coin return in pennies, nickles, dimes,  quarters, etc...