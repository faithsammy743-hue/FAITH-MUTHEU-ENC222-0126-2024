#include <iostream>
using namespace std;
#include <cstdlib>  
#include <ctime>     

int main() {
    const int SIZE = 20;
    int numbers[SIZE];
    int odds[SIZE];   
    int evens[SIZE];  
    int oddCount = 0, evenCount = 0;

    srand(static_cast<unsigned>(time(0)));

    cout << "Original array: ";
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 100 + 6; 
        cout << numbers[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] % 2 == 0) {
            evens[evenCount++] = numbers[i];
        } else {
            odds[oddCount++] = numbers[i];
        }
    }

    cout << "Odd values: ";
    for (int i = 0; i < oddCount; i++) {
        cout << odds[i] << " ";
    }
    cout << "\n";

    cout << "Even values: ";
    for (int i = 0; i < evenCount; i++) {
        cout << evens[i] << " ";
    }
    cout << "\n";

    return 0;
}