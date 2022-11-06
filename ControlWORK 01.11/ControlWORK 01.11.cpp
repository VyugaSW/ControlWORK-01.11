
#include <Windows.h>
#include <iostream>
#include <io.h>

using namespace std;

void Task1() {
    const int size = 6;
    int arr[6] = {1, 2, 3, 4, 5, 6};
    for (int i = size-1; i != 0; i++) {
        cout << arr[i] << " ";
    }
}
void Task2() {
    int size = 5;
    int perimeter = 0;
    int* arr = new int[size];
    for (int i = 0; i < size;i++) {
        system("cls");
        cout << "Enter a side number " << i+1 << " :\n";
        cin >> arr[i];
        perimeter += arr[i];
    }
    system("cls");
    cout << "The Perimeter of pentagon = " << perimeter;
}

int Task3_Arif(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += i;
    }
    return sum / size;
}
void Task3() {
    int size = 9;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        system("cls");
        cout << "Enter the element " << i + 1 << " :\n";
        cin >> arr[i];
    }
    system("cls");
    if (Task3_Arif(arr, size) == 0) {
        int tempSize = (size / 3) * 2;
        int temp;
        //Соритурем 2/3
        for (int i = 0; i < tempSize; i++) {
            for (int j = tempSize - 1; j > i; j--) {
                if (arr[j - 1] > arr[j]) {
                    temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    else {
        int tempSize = size / 3;
        //Сортируем 1/3
        int temp;
        for (int i = 0; i < tempSize; i++) {
            for (int j = tempSize - 1; j > i; j--) {
                if (arr[j - 1] > arr[j]) {
                    temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        //Обратный порядок иной части массива
        for (int i = tempSize; i < size; i++) {
            for (int j = size - 1; j > i; j--) {
                  temp = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

}

void Task4() {
    const int size = 10;
    int arr[size] = { 1,2,3,4,5,6,7,8,9,10 };
    int* a = arr;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(a + i);
    }
    cout << sum;
}

//Размер (по условиям задачи) общий у трех массивов
void Task5(int* A, int* B, int* C, int size) {
    for (int i = 0; i < size; i++) {
        C[i] = A[i] + B[i];
        cout << C[i] << " ";
    }
}

//--- Task6
int mystrlen(const char* str) {
    return strlen(str);
}
char* mystrcpy(char* str1, const char* str2) {
    strcpy_s(str1,strlen(str1)+strlen(str2), str2);
    return str1;
}
char* mystrcat(char* str1, const char* str2) {
    strcat_s(str1, strlen(str1) + strlen(str2), str2);
    return str1;
}
char* mystrchr(char* str, char s) {
    char* newStr = new char[strlen(str)];
    newStr = strchr(str, s);
    return newStr;
}
char* mystrstr(char* str1, char* str2) {
    char* newStr = new char[strlen(str1)];
    newStr = strstr(str1, str2);
    return newStr;
}
//---


void Task7() {
    FILE* out;
    char path[200]; //Основной путь до папки
    char mask[20]; //Расширения файла
    char fullPath[220]; //path+mask
    char nameFile[220]; //Полный путь к конкретному файлу
    char* word = new char[45];//Искомое слово
    char* buff = new char[255]; //Буфер для поиска
    char* buffTwo = new char[255]; //Второй буфер для поиска
    cout << "Enter a full path (for example, \"C:\\Test\\ \")\n";
    cin >> path;
    cout << "Enter mask (for exmaple, \"*.txt\")\n";
    cin >> mask;

    strcpy_s(fullPath, path);
    strcat_s(fullPath, mask);

    cout << "Please enter the searching word:\n";
    cin >> word;
    int counter = 0; //Кол-во совпадений
    struct _finddata_t fileinfo;
    intptr_t done = _findfirst(fullPath, &fileinfo);
    system("cls");
    cout << "Matches files:\n";
    //Я не смог разрешить проблему, но на втором файле он не может считать буфер, мол, чтение памяти невозможно
    do {
        strcpy_s(nameFile, path);
        strcat_s(nameFile, fileinfo.name);
        if (!fopen_s(&out, nameFile, "r")) {
            while (!feof(out)) {
                buffTwo = fgets(buff, 255, out);
                while (buffTwo = strstr(buffTwo, word)) {
                    buffTwo++;
                    counter++;
                }
            }
            cout << nameFile << endl;
            fclose(out);
        }
    } while (_findnext(done, &fileinfo) != -1);
    if (counter == 0)
        cout << "Matches weren't founded\n";
    else
        cout << "Amount of matches - " << counter << endl;

}

int main()
{
    int size = 5;
    int* A = new int[size] {1, 2, 3, 4, 5};
    int* B = new int[size] {1, 2, 3, 4, 5};
    int* C = new int[size];
    //Task5(A, B, C, size);
    Task7();


}


