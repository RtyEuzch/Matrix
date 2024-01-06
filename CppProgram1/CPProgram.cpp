#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <ios>

using namespace std;

/** This program creates a visual matrix in the terminal containing r rows
 *  and c columns. The user must specify the r and c, and is able to 
 *  initialize the numbers themself, or just create a matrix of 0s. 
 *  They are able to set values of the matrix to certain
 *  numbers, or get the sum of all the numbers in the matrix or in certain
 *  rows or columns. 
 *  @author Charles Doan
 *  Date Completed:
 */

class Matrix {
    private:
        vector<vector<int>> matrix;
        int numRows;
        int numCols;
        int numDigits;
    public:
        const int defaultValue = 0; 
        const int defaultNumDigits = 1;   
        Matrix() { 
            cout << "Please specify:\n";
            cout << "\t" << setw(38) << "the number of rows for the matrix: ";
            cin >> numRows;
            cout << "\t" << setw(38) << "the number of columns: ";
            cin >> numCols;
            matrix = 
                vector<vector<int>>(numRows, 
                                    vector<int>(numCols, Matrix::defaultValue));
            numDigits = defaultNumDigits;                       
            printMatrix();    
        }

        int countDigits(int num) {
            int count = 0;
            int test = num;
            do {
                count++;
                test /= 10;
            } while (test > 0);
            return count;
        }

        void changeNumDigits() {
            for (int row = 0; row < matrix.size(); row++) {
                for (int col = 0; col < matrix.at(row).size(); col++) {
                    if (countDigits(matrix.at(row).at(col)) > numDigits) {
                        numDigits = countDigits(matrix.at(row).at(col));
                    }
                }
            }
        }

        int getRows() const { 
            return numRows;
        }

        void setRow(int row) {
            for (int col = 0; col < getCols(); col++) {
                int newNum;
                cout << "Set index " << col << " as: ";
                cin >> newNum;
                matrix.at(row).at(col) = newNum;
            }
            changeNumDigits();
        }

        int sumRow(int row) {
            int sum = 0;
            for (int col = 0; col < getCols(); col++) {
                sum += matrix.at(row).at(col);
            }
            return sum;
        }

        int getCols() const {
            return numCols;
        }

        void setCol(int col) {
            for (int row = 0; row < getRows(); row++) {
                int newNum;
                cout << "Set index " << row << " as: ";
                cin >> newNum;
                matrix.at(row).at(col) = newNum;
            }
            changeNumDigits();
        }

        int sumCol(int col) {
            int sum = 0;
            for (int row = 0; row < getRows(); row++) {
                sum += matrix.at(row).at(col);
            }
            return sum;
        }

        void setCell(int row, int col, int newNum) {
            matrix.at(row).at(col) = newNum;
            changeNumDigits();
        }

        vector<vector<int>> getMatrix() {
            return matrix;
        }

        void printMatrix() {
            //Printing sequence: three spaces, numDigits spaces, 
            //then setw(numDigits + 1)

            cout << "   " << setw(numDigits) << " ";
            for (int num = 0; num < matrix.at(0).size(); num++) 
                cout << left << setw(numDigits + 1) << num;
            cout << endl;

            cout << "   " << setw(numDigits) << " ";
            for (int num = 0; num < matrix.at(0).size(); num++) {
                cout << setw(numDigits + 1) << "-";
            }
            cout << endl;

            for (int row = 0; row < matrix.size(); row++) {
                cout << row << " |" << setw(numDigits) << " ";
                for (int col = 0; col < matrix.at(row).size(); col++) {
                    cout << left << setw(numDigits + 1)
                         << matrix.at(row).at(col);
                }
                cout << "|\n";
                
            }

            cout << "   " << setw(numDigits) << " ";
            for (int num = 0; num < matrix.at(0).size(); num++) {
                cout << setw(numDigits + 1) << "-";
            }
            cout << endl;
        }
 

};

int main() {
    
    Matrix m1;
    bool done = false;
    while (!done) { 
        cout << "OPTIONS:\n";
        cout << "-----------------------------\n";
        cout << "1. Change an entire row\n";
        cout << "2. Change an entire column\n";
        cout << "3. Change a specific number\n";
        cout << "4. Get sum of a row\n";
        cout << "5. Get sum of a column\n";
        cout << "-----------------------------\n";

        int selection;
        cout << "What would you like to do? (-1 to exit):: ";
        cin >> selection;
        if (selection == 1) {
            int row;
            cout << "Which row would you like to manipulate? (-1 to exit):: ";
            cin >> row;
            if (row >= 0) {
                m1.setRow(row);
            } else {
                cout << "Invalid index: " << row << endl;
            } 
            m1.printMatrix(); 
        } else if (selection == 2) {
            int col;
            cout << "Which column would you like to manipulate? (-1 to exit):: ";
            cin >> col;
            if (col >= 0) {
                m1.setCol(col);
            } else {
                cout << "Invalid index: " << col << endl;
            }
            m1.printMatrix();
        } else if (selection == 3) {
            int row;
            cout << "Enter the row of the number you want to change: ";
            cin >> row;
            int col;
            cout << "Enter the column of the number you want to change: ";
            cin >> col;
            int newNum;
            if (col >= 0 && row >= 0) {
                cout << "Enter the new number you want to replace the index with: ";
                cin >> newNum;
                m1.setCell(row, col, newNum);
            } else {
                cout << "Invalid index: ";
                if (row < 0)
                    cout << "row = " << row << endl;
                else
                    cout << "column = " << col << endl;
            }
            m1.printMatrix();
        } else if (selection == 4) {
            int row;
            cout << "Which row would you like to sum up? :: ";
            cin >> row; 
            if (row >= 0) {
                cout << "The sum of row " << row
                     << " is " << m1.sumRow(row) << "." << endl;
            } else {
                cout << "Invalid index: " << row << endl;
            }
            m1.printMatrix();
        } else if (selection == 5) {
            int col;
            cout << "Which column would you like to sum up? :: ";
            cin >> col; 
            if (col >= 0) {
                cout << "The sum of column " << col
                     << " is " << m1.sumCol(col) << "." << endl;
            } else {
                cout << "Invalid index: " << col << endl;
            }
            m1.printMatrix();          
        } else {
            break;
        }

    }


}