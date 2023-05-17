#include <iostream>
#include <Windows.h>
#include <locale>
#include <locale>
#include <string>
#include <sstream>
/*
Перетворити масив таким чином, щоб спочатку розташовувалися всі додатні елементи,
 а потім − усі від’ємні (елементи, рівні 0, вважати додатними).
*/
void rearrangeArray(int arr[], int size)
{
    int positiveIndex = 0;
    int negativeIndex = size - 1;

    while (positiveIndex < negativeIndex)
    {
        if (arr[positiveIndex] >= 0)
        {
            positiveIndex++;
        }
        else if (arr[negativeIndex] < 0)
        {
            negativeIndex--;
        }
        else
        {
            std::swap(arr[positiveIndex], arr[negativeIndex]);
            positiveIndex++;
            negativeIndex--;
        }
    }
}
/*
В одновимірному масиві, що складається з цілих елементів,
обчислити: добуток елементів масиву з парними номерами.
Встановлюємо також перевірку чи не складається масив повністю з нульових елементів.
*/
int multiplyEvenElements(int arr[], int size)
{
    bool allZeros = true;
    int product = 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            allZeros = false;

            if (arr[i] % 2 == 0)
            {
                product *= arr[i];
            }
        }
    }

    if (allZeros)
    {
        return 0;
    }

    return product;
}

/*
Обчислити суму елементів масиву, розташованих між першим і останнім нульовим елементами.
*/
int sumElementsBetweenZeros(int arr[], int size)
{
    bool foundFirstZero = false;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            if (foundFirstZero)
            {
                break;
            }
            else
            {
                foundFirstZero = true;
            }
        }
        else if (foundFirstZero)
        {
            sum += arr[i];
        }
    }

    return sum;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, ".1251");

    /*
    Ввід розміру масиву із перевіркою правильності вводу.
    */
    int size;
    std::string sizeInput;
    std::istringstream sizeIss;
    do {
        std::cout << "Введіть розмір масиву: ";
        std::cin >> sizeInput;

        sizeIss.clear();
        sizeIss.str(sizeInput);

        if (!(sizeIss >> size) || size <= 0) {
            std::cout << "Некоректне значення розміру масиву. Будь ласка, спробуйте знову." << std::endl;
        }
    } while (size <= 0);

    int* arr = new int[size];
    /*
    Ввід елементів масиву із перевіркою правильності вводу.
    */
    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; i++) {
        std::string input;
        std::cin >> input;

        int value;
        std::istringstream iss(input);

        if (!(iss >> value)) {
            std::cout << "Некоректне введення. Будь ласка, спробуйте знову: ";
            i--; // Зменшуємо лічильник, щоб зчитати значення знову
            continue;
        }

        arr[i] = value;
    }

    rearrangeArray(arr, size);

    std::cout << "Масив після перетворення: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int result1 = multiplyEvenElements(arr, size);
    std::cout << "Добуток парних елементів (крім нульових): " << result1 << std::endl;

    int result2 = sumElementsBetweenZeros(arr, size);
    std::cout << "Сума елементів між першим і останнім нульовими елементами: " << result2 << std::endl;

    delete[] arr;
}




