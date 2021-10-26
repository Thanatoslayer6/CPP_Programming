#include "iostream"

using namespace std;

int main(){
	int number, holder = 1, init = 1;
	char op;
	cin >> op >> number;
	
	while(init <= number){
		if (op == 'F'){
			holder *= init;
			if (init == number)
				cout << "THE FACTORIAL OF " << number << " IS: " << holder << endl;
		} else if (op == 'C'){
			cout << "THE CUBE OF " << init << " IS: " << (init*init*init) << endl;
		} else if (op == 'S'){
			cout << "THE SQUARE OF " << init << " IS: " << (init*init) << endl;
		}
		init++;
	}
}
