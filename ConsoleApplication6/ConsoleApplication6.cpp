//3 вар 1лр
//Не используя дополнительный массивов, "сожмите" массив, содержащий нулевые элементы, 
//передвинув нулевые элементы в конец массива.Входные данные : размер массива и массив.Выходные данные : обработанный массив.

#include <iostream>

int input_int(bool is_neg) { // создание функции на проверку int (если буквы, запятые и тд) // is_neg - отриц. ли число true/false
    int inputInt;
    while (!(std::cin >> inputInt)) { // если ввод не равно инт то
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
    std::cout << "Hello. This program will help you get rid of the zeros in your array by moving them to the end. " << std::endl;
    bool flag = false;
    while (flag == false) {     
        int length;
        std::cout << "What length of your array? " << std::endl; //cin,cout потоки выводп/ввода. std группа пространств имен
        length = input_int(false);
        std::cout << "What numbers in your array? " << std::endl;

        int num0 = 0; //для подсчета кол-ва нулей

        int* masiv = new int(length); //Выделение памяти на динамический массив. (пример с мусором в комнате и тазиком)
        for (int i = 0; i < length; i++) { //ввод массива 
            masiv[i] = input_int(true);
            if (masiv[i] == 0)  num0++; // нули нули нули считаем 
        }

        for (int j = 0; j < num0; j++) { //нули. каждый нолик чтобы до конца дошел
            for (int i = 1; i < length; i++) { //поход по массиву с 1 элемента
                if (masiv[i - 1] == 0) { //перебираем, 0? меняем на i и выкидываем 0 на место i
                    masiv[i - 1] = masiv[i];
                    masiv[i] = 0;
                }
            }
        }
        std::cout << "Your array with the zero elements moved to the end of the array: ";

        for (int i = 0; i < length; i++) {
            std::cout << masiv[i] << " ";
        }

        bool flag2 = false;
        while (flag2 == false) {
            std::cout << std::endl << "Do you want to try again? (Y/N): ";
            char answer;
            std::cin >> answer;
            if (answer == 'N') {
                std::cout << "Bye!" << std::endl;
                flag = true;
                flag2 = true;
            }
            else if (answer == 'Y') {
                std::cout << "Here we go!" << std::endl;
                flag2 = true;
            }
            else {
                std::cout << "Uncorrect input. Try again." << std::endl;
            }
        }
    }
}   
