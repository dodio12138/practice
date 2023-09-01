#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#define HIGHT 200
#define WIDTH 200

struct cro
{
    int x;
    int y;
};

struct cro loc = {HIGHT / 2, WIDTH / 4};
void gotoxy(int x, int y);
void hide(int k);
int randomChoose();
void loop();
void ini();
int speed = 5;
char c = 'o';
// char* userInput;
// char userc;

int main()
{
    // printf("Enter walk speed(ms)\n");
    // // ʹ�� scanf ��ȡ�û�������ַ�
    // scanf("%s", userInput);

    // speed = atoi(userInput);

    // printf("Enter show char\n");
    // // ʹ�� scanf ��ȡ�û�������ַ�
    // scanf("%s", userc);

    // // ���ַ�����ת��Ϊ����

    // c = userc;

    ini();
    loop();
    return 0;
}

void ini()
{
    system("title Random Walk");
    system("mode con cols=200 lines=100");
    system("reg add \"HKEY_CURRENT_USER\\Console\" /v \"FontSize\" /t REG_DWORD /d 0x00020000 /f");
    system("cls");
    hide(1);
}

void loop()
{
    while (1)
    {
        gotoxy(loc.x, loc.y);
        hide(1);
        printf("%c", c);
        Sleep(speed);
        int dir = randomChoose();
        switch (dir)
        {
        case 0:
            loc.x += 1;
            break;
        case 1:
            loc.x -= 1;
            break;
        case 2:
            loc.y += 1;
            break;
        case 3:
            loc.y -= 1;
            break;

        default:
            break;
        }
        if (loc.x <= 0 || loc.y <= 0)
        {
            loc.x += 2;
            loc.y += 2;
        }
        if (loc.x > 100)
        {
            loc.x -= 2;
        }
        if (loc.y > 50)
        {
            loc.y -= 2;
        }
        gotoxy(loc.x, loc.y);
        hide(0);
    }
}

int randomChoose()
{
    // ���ӳ�ʼ��
    srand(time(NULL) + rand());
    int dir = rand() % 4;
    // printf("%d", dir);

    return dir;
}

void gotoxy(int x, int y) // �ƶ����
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hide(int k) // ���ع��
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = k; // ��1Ϊ��ʾ����0Ϊ����
    SetConsoleCursorInfo(hOut, &cci);
}