#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*Ввести с клавиатуры произвольное абстрактное предложение длиной не более 80 символов,
состоящее из абстрактных слов. Слова в предложении отделяются друг от друга как минимум
одним символом «пробел». Предложение должно быть введено с помощью функции getchar().
Используя введённое предложение, построить новое предложение, в котором слова упорядочены
по возрастанию в лексикографическом порядке*/

class Sentence {
public:
    char* arrchars;//сивмвольная строка
    char** arrwords;//упорядоченный набор слов 

    class Sentence() //создать абстрактное предложение
    {
        arrchars = (char*)malloc(81 * sizeof(char));
        arrwords = (char**)malloc(40 * sizeof(char*));
        int count;
        puts("Введи предложение");
        for (int i = 0; (i < 80 && arrchars[i - 1] != '\n'); i++) {
            arrchars[i] = getchar(); count = i;//подсчет длины строки
        }
        count++;
        arrchars = (char*)realloc(arrchars, count * sizeof(char));
        arrchars[count - 1] = '\0';
        char* arrchars = _strdup(this->arrchars);
        arrwords[0] = strtok(arrchars, " ");
        for (int i = 1; (i < 40 && arrwords[i - 1] != NULL); i++) {
            arrwords[i] = strtok(NULL, " "); count = i;//подсчет слов
        }
        arrwords = (char**)realloc(arrwords, (count + 1) * sizeof(char*));
    }

    class Sentence(char** arrwords) //создать строку из слов
    {
        int len = 0;
        for (int i = 0; arrwords[i] != NULL; i++)
            len += strlen(arrwords[i]) + 1;
        arrchars = (char*)malloc((len + 1) * sizeof(char));
        arrchars[0] = '\0';
        strcat(arrchars, arrwords[0]);
        for (int i = 1; arrwords[i] != NULL; i++) {
            strcat(arrchars, " ");
            strcat(arrchars, arrwords[i]);
        }
    }

    void clear() //удалить предложение
    {
        if (arrwords != nullptr) {
            free(arrwords);
        }
        if (arrchars != NULL && strlen(arrchars) > 0) {
            free(arrchars);
            arrchars = nullptr;
        }
    }

    char** SortByAlfa() { //отсортировать в лексикографическом порядке
        int lenArrWords = 0; for (int i = 0; arrwords[i] != NULL; i++) { lenArrWords += 1; }
        int step = lenArrWords / 2;
        while (step > 0) {
            for (int i = step; i < lenArrWords; i++)
            {
                int i_right = i;
                int i_left = i_right - step;
                while (i_left >= 0) {
                    for (size_t j = 0; j <= strlen(arrwords[i_left]); j++) {
                        if (strncmp(arrwords[i_left], arrwords[i_right], j) > 0) {
                            char* temp = arrwords[i_left];
                            arrwords[i_left] = arrwords[i_right];
                            arrwords[i_right] = temp;
                            break;
                        }
                    }

                    i_right = i_left;
                    i_left = i_right - step;
                }
            }
            step /= 2;
        }
        for (int i = 0; (arrwords[i] != NULL); i++) {
            puts(arrwords[i]);
        }
        return arrwords;
    }

};


void main()
{
    system("chcp 1251");
    std::cout << "Лабораторная №\n";
    Sentence sent;
    std::cout << "\nОтсортированное предложение:\n";
    Sentence sortsent(sent.SortByAlfa());
    puts(sortsent.arrchars);
    std::cout << "Исходное предложение:\n";
    puts(sent.arrchars);
    sortsent.clear();
    sent.clear();
}
