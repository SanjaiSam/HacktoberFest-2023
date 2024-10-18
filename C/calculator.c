#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define MAX_LENGTH 500
#define MAX_FOOD 30

struct coordinate {
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate head, food;
int length = 5;
int life = 3;
int bend_no = 0;
coordinate bend[MAX_LENGTH];
coordinate body[MAX_LENGTH];

void Delay(long double k);
void Move();
void Food();
void Print();
void Boarder();
void ExitGame();
void gotoxy(int x, int y);
void record();
void load();

int main() {
    Print();
    system("cls");
    load();

    head.x = 25;
    head.y = 20;
    head.direction = RIGHT;

    Boarder();
    Food();
    bend[0] = head;

    Move();
    return 0;
}

void Move() {
    while (1) {
        Boarder();
        Food();

        if (_kbhit()) {
            char key = _getch();
            if (key == 27) exit(0); // Exit on ESC
            if ((key == RIGHT && head.direction != LEFT) ||
                (key == LEFT && head.direction != RIGHT) ||
                (key == UP && head.direction != DOWN) ||
                (key == DOWN && head.direction != UP)) {
                bend[bend_no++] = head;
                head.direction = key;

                switch (head.direction) {
                    case UP: head.y--; break;
                    case DOWN: head.y++; break;
                    case LEFT: head.x--; break;
                    case RIGHT: head.x++; break;
                }
                // Call the function to check for collisions and other game logic
                ExitGame();
            } else {
                printf("\a"); // Beep for invalid direction
            }
        }
 
