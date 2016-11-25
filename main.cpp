#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void printGrid(int grid[42][102], int x, int y);
void start(int grid[42][102]);
void life(int grid[42][102]);
void copy(int array1[42][102], int array2[42][102]);
bool compare(int array1[42][102], int array2[42][102]);

int main(){
	int grid[42][102] = {{0}};
	int prev[42][102] = {{0}};
	int counter = 0;
	int a;
	start(grid);
	copy(grid, prev);
	do{
		printGrid(grid, -1, -1);
	 	system("sleep 0.1");
	 	copy(grid, prev);
	 	life(grid);
	 	if(counter % 100 == 0 && counter != 0) cin>>a;
	 	counter++;
	}while(!compare(grid, prev));
	cin>>a;
	return 0;
}

void printGrid(int grid[42][102], int x, int y){
	system("cls");
	char dead = (char)176, alive = (char)254, user = (char)219;
	for(int i = 0 ; i < 40 ; i ++){
		for(int j = 0 ; j < 100 ; j ++){
			if(x == i && y == j)
				cout<< user;
			else if(grid[i][j] == 0)
				cout<< dead;
			else 
				cout<< alive;
		}
		cout<<"\n";
	}
}

void start(int grid[42][102]){
	char dir = (char)0;
	int x = 20, y = 50;	
	while(dir != 32){
		printGrid(grid, x, y);
		dir = getch();
		if(dir == -32)
			dir = getch();
		if(dir == 72 && x > 0) x--;
		if(dir == 75 && y > 0) y--;
		if(dir == 80 && x < 40) x++;
		if(dir == 77 && y < 100) y++; 
		if(dir == 13) grid[x][y] = 1;	
	}
}

void copy(int array1[42][102], int array2[42][102]){
	for(int i = 0 ; i < 40 ; i ++)
		for(int j = 0 ; j < 100 ; j ++)
			array2[i][j] = array1[i][j];
}

void life(int grid[42][102]){
	int tmp [42][102] = {{0}};
	copy(grid, tmp);
	for(int i = 0 ; i < 40 ; i ++){
		for(int j = 0 ; j < 100 ; j ++){
			int count = grid[i + 1][j] + grid[i - 1][j]
						+ grid[i][j + 1] + grid[i][j - 1]
						+ grid[i - 1][j + 1] + grid[i - 1][j - 1]
						+ grid[i + 1][j + 1] + grid[i + 1][j - 1];

			if(count < 2 || count > 3) 		
				tmp[i][j] = 0;
			if(count == 3)
				tmp[i][j] = grid[i][j];
			if(count == 2)
				tmp[i][j] = 1;
		}
	}
	copy(tmp, grid);
}

bool compare(int array1[42][102], int array2[42][102]){
	for(int i = 0 ; i < 40 ; i ++)
		for(int j = 0 ; j < 100 ; j ++)
			if(array2[i][j] != array1[i][j]) 
				return false;
	return true;
}