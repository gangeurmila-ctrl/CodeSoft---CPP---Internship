#include <iostream>
using namespace std;

int main() {
    int choice;
    double num1, num2;
    char again;

    do {
        cout << "\n***************************************" << endl;
        cout << "\t Simple Calculator ";
        cout << "\n***************************************"<<endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        

        switch(choice) {
            case 1:
                cout << "Result = " << num1 + num2 << endl;
                break;

            case 2:
                cout << "Result = " << num1 - num2 << endl;
                break;

            case 3:
                cout << "Result = " << num1 * num2 << endl;
                break;

            case 4:
                if(num2 != 0)
                    cout << "Result = " << num1 / num2 << endl;
                else
                    cout << "Error! Division by zero not allowed." << endl;
                break;

            default:
                cout << "Invalid Choice! Please try again." << endl;
        }

    } 
    else 
    {
          cout<< "Invalid choice!"<<endl;
    }
       cout <<"\n Do you want to calculate more ? (y/n):";
       cin >> again;
}
  while (again  == 'y' || again =='Y');
  cout << " Thank you for using Calculator !"<< endl;


    return 0;
}