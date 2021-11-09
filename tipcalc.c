/*
 * NPhilG
 * I/O, calculations, functions
 */

/*
 * General design:
 * app takes input for price of meal, tip percent
 * and calculates total
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void ask(char*);
double getVal();
double calcTotal(double, double, double);
void printTotal(double, double, double);

int main() {

	char buffer[20];
	double price = 0.0;
	double percent = 0.0;
	double tip = 0.0;
	double total = 0.0;

	printf("You are in a restaurant.\n");
	ask("What is the total price of your meal: ");
	price = getVal();

	printf("What percent would you like to tip: ");
	percent = getVal();

	total = calcTotal(price, percent, tip);
	printTotal(price, percent,total);
	return 0;
}

void ask(char* string) {
	printf("%s", string);
}

double getVal() {
	char buffer[20];
	int loop = 1;
	double val = 0;
	while (loop) {
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%lf", &val);
		
		if (val > 0)
			loop--;
		else if(val < 0) 
			printf("Plase give a positive number value: ");
		else 
			printf("Please give a numberic only: ");

	}	
	return val;	
}

double calcTotal(double price, double percent, double tip) {
	tip = price * (percent / 100);
	return (price + tip);

}

void printTotal(double price, double percent, double total) {
	printf("Your meal is: $%0.2lf\n", price);
	printf("Your tip is: %0.2lf%%\n", percent);
	printf("Your total is: $%0.2lf\n", total);
}
