#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>   

const int ROWS = 4;
const int COLS = 5;

void fillMatrix(int matrix[ROWS][COLS]) {
   
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 90 + 10; 
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
  
    int rowSum[ROWS] = {0};
    int colSum[COLS] = {0};
    int totalSum = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
            totalSum += matrix[i][j];
        }
        std::cout << "| " << rowSum[i] << std::endl;
    }

   
    for (int j = 0; j < COLS; ++j) {
        std::cout << "----";
    }
    std::cout << "|\n";

   
    for (int j = 0; j < COLS; ++j) {
        std::cout << std::setw(3) << colSum[j] << " ";
    }
    std::cout << "| " << totalSum << std::endl;
}

void findMinMaxValueAndPosition(int matrix[ROWS][COLS], int& minValue, int& minRow, int& minCol,
                                int& maxValue, int& maxRow, int& maxCol) {
   
    minValue = matrix[0][0];
    minRow = 0;
    minCol = 0;
    maxValue = matrix[0][0];
    maxRow = 0;
    maxCol = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
                minRow = i;
                minCol = j;
            }
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
}

int main() {
   
    srand(time(0));

    int matrix[ROWS][COLS];

   
    fillMatrix(matrix);

   
    std::cout << "Matrix:\n";
    printMatrix(matrix);
    std::cout << std::endl;

    
    int minValue, minRow, minCol;
    int maxValue, maxRow, maxCol;
    findMinMaxValueAndPosition(matrix, minValue, minRow, minCol, maxValue, maxRow, maxCol);

    
    std::cout << "Наименьшее значение " << minValue << " строка " << minRow + 1 << " столбец " << minCol + 1 << std::endl;
    std::cout << "Наибольшее значение " << maxValue << " строка " << maxRow + 1 << " столбец " << maxCol + 1 << std::endl;

    return 0;
}
