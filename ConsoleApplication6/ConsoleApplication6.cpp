
#include <iostream>

int main()
{
    int length;
    std::cout << "what length of your array? " << std::endl;
    std::cin >> length;
    std::cout << "what numbers in your array? ";

    int num0 = 0;

    int *masiv = new int(length); //Выделение памяти на динамический массив. (пример с мусором в комнате и тазиком)
    for (int i = 0; i < length; i++) {
        std::cin >> masiv[i];
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

    std::cout << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << masiv[i] << " ";
    }    
}   
