#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int unit, num1, userUnit1, convertUnit;
    cout << "Select the Property to Convert : " << endl;
    cout << "1. Weight\n2. Distance\n";
    cin >> unit;

    switch (unit)
    {
    case 1:
        cout << "Enter Number : ";
        cin >> num1;

        cout << "\nSelect unit of your Number : \n1. Kg\n2. g\n3. mg\n";
        cin >> userUnit1;

        cout << "\nSelect unit to convert in : \n1. Kg\n2. g\n3. mg\n\n";
        cin >> convertUnit;

        switch (userUnit1)
        {
        case 1:
            if (convertUnit == 1)
            {
                cout << num1 << " kg" << endl;
            }
            else if (convertUnit == 2)
            {
                cout << 1000 * num1 << " g" << endl;
            }
            else if (convertUnit == 3)
            {
                cout << 1000000 * num1 << " mg" << endl;
            }
            else
            {
                cout << "Choose Valid conversion Unit" << endl;
            }
            break;

        case 2:
            if (convertUnit == 1)
            {
                cout << num1 * 0.001 << " kg" << endl;
            }
            else if (convertUnit == 2)
            {
                cout << num1 << " g" << endl;
            }
            else if (convertUnit == 3)
            {
                cout << 1000 * num1 << " mg" << endl;
            }
            else
            {
                cout << "Choose Valid conversion Unit" << endl;
            }
            break;

        case 3:
            if (convertUnit == 1)
            {
                cout << .000001 * num1 << " kg" << endl;
            }
            else if (convertUnit == 2)
            {
                cout << 0.001 * num1 << " g" << endl;
            }
            else if (convertUnit == 3)
            {
                cout << num1 << " mg" << endl;
            }
            else
            {
                cout << "Choose Valid conversion Unit" << endl;
            }
            break;

        default:
            cout << "chosse valid unit of your Number" << endl;
            break;
        }
        break;

    case 2:
        cout << "Enter Number : ";
        cin >> num1;

        cout << "\nSelect unit of your Number : \n1. Km\n2. m\n3. mm\n";
        cin >> userUnit1;

        cout << "\nSelect unit to convert in : \n1. Km\n2. m\n3. mm\n\n";
        cin >> convertUnit;

        switch (userUnit1)
        {
        case 1:
            if (convertUnit == 1)
            {
                cout << num1 << " km" << endl;
            }
            else if (convertUnit == 2)
            {
                cout << 1000 * num1 << " m" << endl;
            }
            else if (convertUnit == 3)
            {
                cout << 1000000 * num1 << " mm" << endl;
            }
            else
            {
                cout << "Choose Valid conversion Unit" << endl;
            }
            break;

        case 2:
            if (convertUnit == 1)
            {
                cout << num1 * 0.001 << " km" << endl;
            }
            else if (convertUnit == 2)
            {
                cout << num1 << " m" << endl;
            }
            else if (convertUnit == 3)
            {
                cout << 1000 * num1 << " mm" << endl;
            }
            else
            {
                cout << "Choose Valid conversion Unit" << endl;
            }
            break;

        case 3:
            if (convertUnit == 1)
            {
                cout << .000001 * num1 << " km" << endl;
            }
            else if (convertUnit == 2)
            {
                cout << 0.001 * num1 << " m" << endl;
            }
            else if (convertUnit == 3)
            {
                cout << num1 << " mm" << endl;
            }
            else
            {
                cout << "Choose Valid conversion Unit" << endl;
            }
            break;

        default:
            cout << "chosse valid unit of your Number" << endl;
            break;
        }
        break;

    default:
        cout<<"Choose valid Property"<<endl;
        break;
    }
    return 0;
}