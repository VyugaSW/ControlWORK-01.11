
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
    strchr(str, s);
    return newStr;
}
char* mystrstr(char* str1, char* str2) {
    char* newStr = new char[strlen(str1)];
    newStr = strstr(str1, str2);
}
//---


void Task7() {
    FILE* in;
    char path[200];
    char mask[20];
    cout << "Enter a full path (for example, \"D:\\\")\n";
    cin >> path;
    cout << "Enter mask (for exmaple, \"*.txt\")\n";
    cin >> mask;

    strcat_s(path, mask);

    struct _finddata_t fileinfo;
    char str[200] = "C:\\Test\\*.txt";

    intptr_t done = _findfirst(path, &fileinfo);
    do {
        cout << fileinfo.name << " " << fileinfo.size << endl;
    } while (_findnext(done, &fileinfo) != -1);




}

int main()
{
    int size = 5;
    int* A = new int[size] {1, 2, 3, 4, 5};
    int* B = new int[size] {1, 2, 3, 4, 5};
    int* C = new int[size];
    //Task5(A, B, C, size);



}


