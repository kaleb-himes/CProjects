#include <iostream>
#include <string>
using namespace std;
int main()
{
	//input declarations as doubles for total and counter
	double total = 0, counter = 0;
	//input declarations sign and Q as chars
	char sign, Q = 0;
	//input declaration value as double
	double value;
		//A do..while will loop forever (or until we hit the break statement)
		do
		{
			//The current value is 0
			cout << "Current value is " << total << endl;

			//Please enter an operation
			cout << "Please enter an operation +, -, *, / ('Q' to quit) ";
			cin >> sign;
			//If the operation is Q, will end the program
			if (sign != 'Q')
			{
				//If the operation is not Q, please enter a number.
				cout << "Please enter a number: ";
				cin >> value;
				cin.ignore();
				/* If the value input is <=0, you are an idiot b/c you can't divide
				   anything by zero. */
				if (value <= 0)
				{
					cout << "ERROR! DIVIDE BY ZERO!! ";
					cout << endl;
				}
				//Otherwise procede with the calulator program
				else
				{
				//If the operation is equal to '+', then the total is added.
				if (sign == '+')
				{
					total += value;
				}
				/* If the operation is equal to '-', then the value is subtracted from
				   the previous number input. */
				else
				{
					if (sign == '-')
					{
						total -= value;
					}
					/* If the operation is equal to '*', then the value is multiplied to
					   the previous number input. */
					else
					{
						if (sign == '*')
						{
							total *= value;
						}
						/* If the operation is equal to '/', then the value is divided by
						   the previous number input. */
						else
						{
							if ((sign == '/') && (value != 0))
							{
								total /= value;
							}

						}
					}
				}
				}

		}
	}
		//While the operation is not equal to 'Q', the program will run.
		//Otherwise, if the operation is equal to Q, the program will end.
		while (sign != 'Q');

		//Each time the program runs, reset the current value to zero.
		return (0);


}
