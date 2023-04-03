#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*������ � ���������� ������������ ����������� ����������� ������ �� ����� 80 ��������,
��������� �� ����������� ����. ����� � ����������� ���������� ���� �� ����� ��� �������
����� �������� �������. ����������� ������ ���� ������� � ������� ������� getchar().
��������� �������� �����������, ��������� ����� �����������, � ������� ����� �����������
�� ����������� � ������������������ �������*/

class Sentence {
public:
	char* arrchars;//����������� ������
	char** arrwords;//������������� ����� ���� 

	class Sentence() //������� ����������� �����������
	{
		arrchars = (char*)malloc(81 * sizeof(char));
		arrwords = (char**)malloc(40 * sizeof(char*));
		int count;
		puts("����� �����������");
		for (int i = 0; (i < 80 && arrchars[i - 1] != '\n'); i++) {
			arrchars[i] = getchar(); count = i;//������� ����� ������
		}
		arrchars = (char*)realloc(arrchars, count * sizeof(char)); arrchars[count] = '\0';
		char* arrchars = _strdup(this->arrchars);
		arrwords[0] = strtok(arrchars, " ");
		for (int i = 1; (i < 40 && arrwords[i - 1] != NULL); i++) {
			arrwords[i] = strtok(NULL, " "); count = i;//������� ����
		}
		arrwords = (char**)realloc(arrwords, (count + 1) * sizeof(char*));
	}

	class Sentence(char** arrwords) //������� ������ �� ����
	{
		arrchars = new char{ '\0' };
		for (int i = 0; arrwords[i] != NULL; i++) {
			strcat(arrchars, arrwords[i]);
			strcat(arrchars, " ");
		}
	}

	void clear() //������� �����������
	{
		if (arrwords != nullptr) {
			free(arrwords);
		}
		//if (arrchars != NULL && strlen(arrchars) > 0) {
		//	free(arrchars);
		//}
	}

	char** SortByAlfa() { //������������� � ������������������ �������
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

	//���������� ��� strncmp
	//private: int CompearByAlfa(int iL, int iR) //�������� ����� 
	//    {
	//        int k = 0;
	//    start:
	//        if (arrwords[iL][k] < arrwords[iR][k]) { return 0; }//� ������������������
	//        if (arrwords[iL][k] == arrwords[iR][k]) {
	//            if (k < strlen(arrwords[iL])) { k += 1; goto start; }
	//            else if (k == strlen(arrwords[iL]) && k == strlen(arrwords[iR])) { //�� �����������
	//                if (strlen(arrwords[iL]) > strlen(arrwords[iR])) { return 0; }
	//                else { return 1;}
	//            }
	//        }
	//        else { return 1; }
	//    }

	//public: Sentence SortByAlfa() { //������������� � ������������������ �������
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
	std::cout << "������������ �\n";
	Sentence sent;
	std::cout << "\n��������������� �����������:\n";
	Sentence sortsent(sent.SortByAlfa());
	puts(sortsent.arrchars);
	std::cout << "�������� �����������:\n";
	puts(sent.arrchars);
	sortsent.clear();
	sent.clear();
}