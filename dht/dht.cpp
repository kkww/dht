#include <iostream>
#include <stdlib.h>
#include <conio.h>

#define ROWS 5
#define COLS 5

using namespace std;

void Print_map();
bool KeyMove(char key);

int map[ROWS][COLS]
= {2,1,1,1,1,
   0,0,0,0,0,
   1,0,1,0,1,
   1,0,0,0,1,
   1,1,1,0,3,};

int map2[ROWS][COLS]
= {1,1,1,1,1,
   2,0,0,0,0,
   1,0,1,0,1,
   1,0,0,0,1,
   1,1,1,0,3,};

class user {
private:
	int x;
	int y;

	int fx;
	int fy;

public:
	// '옷' 처음 위치 저장
	user () {
		for (int i=0; i< ROWS; i++) { // 행
			for (int j=0; j<COLS; j++) { // 열
				if (map[i][j] == 2) { // '옷' == 2 이고, x, y 변수에 '옷'의 현재 위치 저장
					x = j;
					y = i;
					break;
				} else if (map[i][j] == 3) { // finish 위치 저장
					fx = j;
					fy = i;
				}
			}
		}
	}
	
	void Up() {
		if(map[y-1][x] != 1) {
			if((0<y && y<ROWS) && (0<=x && x<COLS)) {
				y--;
				map[y][x] = 2;
				map[y+1][x] = 0;
			}
		}
	}
	void Down() {
		if(map[y+1][x] != 1) {
			if((0<=y && y<ROWS-1) && (0<=x && x<COLS)) {
				y++;
				map[y][x] = 2;
				map[y-1][x] = 0;
			}
		}
	}
	void Left() {
		if(map[y][x-1] != 1) {
			if((0<=y && y<ROWS) && (0<x && x<COLS)) {
				x--;
				map[y][x] = 2;
				map[y][x+1] = 0;
			}
		}
	}
	void Right() {
		if(map[y][x+1] != 1) {
			if((0<=y && y<ROWS) && (0<=x && x<COLS-1)) { 
				x++; 
				map[y][x] = 2;
				map[y][x-1] = 0;
			}
		}
	}
	
	int rocation() {
		return map[y][x];
	}

	int fin_rocation() {
		return map[fy][fx];
	}
};

user user1;

int main() {
	Print_map();

	while(user1.rocation() != user1.fin_rocation()) {
		KeyMove(getch());
		//cout << user1.rocation() << endl;
	}

	cout << "\n<<end>>\n";
	getch();
	
	return 0;
}

void Print_map() {
	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS; j++) {
			if (map[i][j] == 2) {
				cout<<"옷"<<" ";
			} else if (map[i][j] == 1) {
				cout<<"■"<<" ";
			} else if (map[i][j] == 3) {
				cout<<"♡"<<" ";
			} else if (map[i][j] == 0) {
				cout<<"  "<<" ";
			}
		}
		cout<<endl;
	}
}

bool KeyMove(char key) {
key = getch();
	switch(key) {
	case 75: // <-
		user1.Left();
		system("cls");
		Print_map();
		break;
	case 77: // ->
		user1.Right();
		system("cls");
		Print_map();
		break;
	case 72: // ↑
		user1.Up();
		system("cls");
		Print_map();
		break;
	case 80: // ↓
		user1.Down();
		system("cls");
		Print_map();
		break;
	default :
		cout << "error" << endl;
		break;
	}
	return 1;
}