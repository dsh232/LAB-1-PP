
#include <iostream>

int input_int(bool is_neg) { // создание функции на проверку int (если буквы, запятые и тд) // is_neg - отриц. ли число true/false
    int inputInt;
    while (!(std::cin >> inputInt)) { // не инт проверка
        std::cout << "Can you please put CORRECT value? Try again. " << std::endl;
        std::cin.clear(); // чистим поток. пример с гречкой и зубом и стоматологом (clear)
        std::cin.ignore(9999, '\n'); //игнорим 9999 символов до перевода строки.
    }

    if (!is_neg && inputInt < 0)  // для проверки при чтении размера массива. (отриц. числа мимо)
    {
        std::cout << "Try numbers that > or = 0. " << std::endl;
        return input_int(false);
    } 

    return inputInt;
}

int main()
{
    int length;
    std::cout << "what length of your array? " << std::endl; //cin,cout потоки выводп/ввода. std группа пространств имен
    length = input_int(false);
    std::cout << "what numbers in your array? " << std::endl;

    int num0 = 0;

    int *masiv = new int(length); //Выделение памяти на динамический массив. (пример с мусором в комнате и тазиком)
    for (int i = 0; i < length; i++) {
        masiv[i] = input_int(true);
        if (masiv[i] == 0)  num0++;
    }

    for (int j = 0; j < num0; j++) {
        for (int i = 1; i < length; i++) {
            if (masiv[i - 1] == 0) {

                masiv[i - 1] = masiv[i];
                masiv[i] = 0;
            }
        }
    }

    std::cout << "Your array with the zero elements moved to the end of the array: ";

    for (int i = 0; i < length; i++) {
        std::cout << masiv[i] << " ";
    }    
}   
