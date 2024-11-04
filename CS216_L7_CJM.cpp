//Cristian Jacobo Morales
//CS216 Section# 15562

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {}

    Fraction multiply(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    string toString() const {
        return to_string(numerator) + "/" + to_string(denominator);
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Generate a Table\n";
    cout << "2. Quit\n";
    cout << "Select an option: ";
}

int getValidDenominator() {
    int denominator;
    while (true) {
        cout << "Enter the denominator for the fractions: ";
        cin >> denominator;
        if (cin.fail() || denominator <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer.\n";
        } else {
            return denominator;
        }
    }
}

void printTable(Fraction** table, int size) {
    cout << setw(10) << " ";
    for (int col = 1; col <= size; ++col) {
        cout << setw(10) << right << col;
    }
    cout << '\n';

    for (int row = 1; row <= size; ++row) {
        cout << setw(10) << right << row;

        for (int col = 0; col < size; ++col) {
            cout << setw(10) << right << table[row - 1][col].toString();
        }
        cout << '\n';
    }
}

void generateFractionTable(int denominator) {
    Fraction** table = new Fraction*[denominator];
    for (int i = 0; i < denominator; ++i) {
        table[i] = new Fraction[denominator];
        for (int j = 0; j < denominator; ++j) {
            table[i][j] = Fraction(i + 1, denominator).multiply(Fraction(j + 1, denominator));
        }
    }

    printTable(table, denominator);

    for (int i = 0; i < denominator; ++i) {
        delete[] table[i];
    }
    delete[] table;
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            int denominator = getValidDenominator();
            generateFractionTable(denominator);
        } else if (choice != 2) {
            cout << "Invalid choice. Please select again.\n";
        }
    } while (choice != 2);

    cout << "Quitting the program.\n";
    return 0;
}

/*

Menu:
1. Generate a Table
2. Quit
Select an option: 1
Enter the denominator for the fractions: 6
                   1         2         3         4         5         6
         1      1/36      2/36      3/36      4/36      5/36      6/36
         2      2/36      4/36      6/36      8/36     10/36     12/36
         3      3/36      6/36      9/36     12/36     15/36     18/36
         4      4/36      8/36     12/36     16/36     20/36     24/36
         5      5/36     10/36     15/36     20/36     25/36     30/36
         6      6/36     12/36     18/36     24/36     30/36     36/36

Menu:
1. Generate a Table
2. Quit
Select an option: 2
Quitting the program.

*/