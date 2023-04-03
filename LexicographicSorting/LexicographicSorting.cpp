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
		arrchars = (char*)realloc(arrchars, count * sizeof(char)); arrchars[count] = '\0';
		char* arrchars = _strdup(this->arrchars);
		arrwords[0] = strtok(arrchars, " ");
		for (int i = 1; (i < 40 && arrwords[i - 1] != NULL); i++) {
			arrwords[i] = strtok(NULL, " "); count = i;//подсчет слов
		}
		arrwords = (char**)realloc(arrwords, (count + 1) * sizeof(char*));
	}

	class Sentence(char** arrwords) //создать строку из слов
	{
		arrchars = new char{ '\0' };
		for (int i = 0; arrwords[i] != NULL; i++) {
			strcat(arrchars, arrwords[i]);
			strcat(arrchars, " ");
		}
	}

	void clear() //удалить предложение
	{
		if (arrwords != nullptr) {
			free(arrwords);
		}
		//if (arrchars != NULL && strlen(arrchars) > 0) {
		//	free(arrchars);
		//}
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

	//сортировка без strncmp
	//private: int CompearByAlfa(int iL, int iR) //сранвить слова 
	//    {
	//        int k = 0;
	//    start:
	//        if (arrwords[iL][k] < arrwords[iR][k]) { return 0; }//в лексикографическом
	//        if (arrwords[iL][k] == arrwords[iR][k]) {
	//            if (k < strlen(arrwords[iL])) { k += 1; goto start; }
	//            else if (k == strlen(arrwords[iL]) && k == strlen(arrwords[iR])) { //по возраствнию
	//                if (strlen(arrwords[iL]) > strlen(arrwords[iR])) { return 0; }
	//                else { return 1;}
	//            }
	//        }
	//        else { return 1; }
	//    }

	//public: Sentence SortByAlfa() { //отсортировать в лексикографическом порядке
	//        int lenArrWords = 0; for (int i = 0; arrwords[i] != NULL; i++) { lenArrWords += 1; }
	//        int step = lenArrWords / 2;
	//        while (step > 0) {
	//            for (int i = step; i < lenArrWords; i++)
	//            {
	//                int i_right = i;
	//                int i_left = i_right - step;
	//                while (i_left >= 0 and i_left != i_right and i_right < lenArrWords and CompearByAlfa(i_left, i_right) == 1) {
	//                    char* temp = arrwords[i_left];
	//                    arrwords[i_left] = arrwords[i_right];
	//                    arrwords[i_right] = temp;
	//                    i_right = i_left;
	//                    i_left = i_right - step;
	//                }
	//            }
	//            step /= 2; 
	//        }
	//        /*for (int i = 0; (arrwords[i] != NULL); i++) {
	//            puts(arrwords[i]);
	//        }*/
	//       return Sentence(arrwords);
	//    }

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