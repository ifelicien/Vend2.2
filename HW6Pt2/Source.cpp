#include <iostream>
#include <iomanip>
using namespace std;

int turnPowerOn();
bool powerSwitch();
float menu();
float payment(float);
float coin_Return(float, float);
float compute_Overhead(float);
float compute_LaborCost(float);
float item_Profit(float);
void payment_Verification(float, float);
void display(float, float);

bool power = false;

int main() {
	turnPowerOn();
	float price =  menu();
	float pmt = payment(price);
	payment_Verification(price, pmt);
	float userRefund = coin_Return(price, pmt);
	//float overH = compute_Overhead(price);
	//float laborCost = compute_LaborCost(price);
	//float itemProfit = item_Profit(price);
	display(price, userRefund);
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

float menu() {
	int selection;
	float price;

start:

	cout << "Please Select an Item: " << endl;
	cout << "1. Coke \t 0.95\n2. Doritos \t 0.75\n3. Snickers \t 0.55 \n4. Chex Mix \t 0.60 \n5. Pepsi \t 0.90" << endl;
	cin >> selection;

	switch (selection) {
	case 1: 
		cout << "\nCoke" << endl;
		price = 0.95;
		break;
	case 2:
		cout << "\nDoritos" << endl;
		price = 0.75;
		break;
	case 3:
		cout << "\nSnickers" << endl;
		price = 0.55;
		break;
	case 4:
		cout << "\nChex Mix" << endl;
		price = 0.60;
		break;
	case 5:
		cout << "\nPepsi" << endl;
		price = 0.90;
		break;
	default:
		cout << "\nInvalid Selection" << endl;
		goto start;
	}
	return price;
}

float payment(float price){
	float paid = 0.0;
	int pennies, nickles, dimes, quarters, one_Dollar, five_Dollar;
	bool foreignCoin;

start2:

	cout << "\nPlease enter payment\n" << endl;
	cout << "is this a foreign coin? type 1 for yes and 0 for no" << endl;
	cin >> foreignCoin;

	if (foreignCoin == false) {

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
	else {
		cout << "This is NOT a valid coin\n Please try again!\n" << endl;
		goto start2;
	}
}

void payment_Verification(float itemCost, float userPayment) {
	float refund = itemCost - userPayment;

	if (userPayment >= itemCost) {
		cout << "Your item is dispensing" << endl;
	}
	else {
		cout << "Please add " << refund << " cents" << endl;
	}
}

float coin_Return(float itemCost, float userPayment) {
	float refund = itemCost - userPayment;
	float absol_Refund = refund - (refund * 2);

	return absol_Refund;
}

float compute_Overhead(float itemCost) {
	float overhead = itemCost * 0.05;
	return overhead;
}

float compute_LaborCost(float itemCost) {
	float laborCost = itemCost * 0.25;
	return laborCost;
}

float item_Profit(float itemCost) {
	float itemProfit = itemCost * (0.05 + 0.35 + 0.25);
	return itemProfit;
}

void display(float price, float refund) {
	cout << "\n\nYour selection: " << endl;
	cout << "Item price is: " << setprecision(2) << price << endl;
	cout << "Your refunded amount is: " << setprecision(2) << refund << endl;
	cout << "The labor cost is: " << compute_LaborCost(price) << endl;
	cout << "The item overhead is: " << compute_Overhead(price) << endl;
	cout << "Your total profit is: " << item_Profit(price) << endl;
}
//TODO: complete coin return in pennies, nickles, dimes,  quarters, etc...