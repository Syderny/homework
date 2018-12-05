#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>

char map[12][12]={"************",        
                  "*          *",        
                  "*          *",
                  "*          *",
                  "*          *",
                  "*          *",
                  "*          *",
                  "*          *",
                  "*          *",
                  "*          *",
                  "*          *",
                  "************"};
struct snake1 {
	int lenth , life;
	int f;
	int x[200] , y[200];
} snake;

struct food1 {
    int n;
    int x , y;
} food;

int putmoney(int x) {
	int i ;
	srand(time(0));
 	food.x = rand()%10+1;
	food.y = rand()%10+1;
	for (i = 1 ; i <= snake.lenth ; i++) {//snake.lenth? =5 
		if (food.x == snake.x[i] && food.y == snake.y[i]) {//在蛇的部位不放 
		  food.x = rand()%10+1;
   		  food.y = rand()%10+1;
		}
	}
	food.n = 1; //?
	return 0;
}
int getmoney(int p) {
    if (snake.x[1] == food.x && snake.y[1] == food.y) {
    	food.n = 0;//? 
    	food.x = -1;//?
    	food.y = -1;//?
    	snake.lenth++;
    	map[food.x][food.y] = ' ';
    }	
    return 0;
}

int snakemove(int x){
	int i;
	map[snake.x[snake.lenth]][snake.y[snake.lenth]] = ' ';//? 
   	for (i = snake.lenth ; i >= 2 ; i--) {
     	snake.x[i] = snake.x[i - 1];
     	snake.y[i] = snake.y[i - 1];
   	}
   	switch (x) {
	   	case 1:snake.x[1] -= 1; break;
	   	case 2:snake.x[1] += 1; break;
	   	case 3:snake.y[1] -= 1; break;
	 	case 4:snake.y[1] += 1; break;
    }
    return 0;
}

int gameover(int x) {
    int i;
	if (snake.x[1] > 9 || snake.x[1] < 1 || snake.y[1] > 9 || snake.y[1] < 1) {//撞墙 
	    	snake.life = 1;
    }
    for(i = 4 ; i <= snake.lenth ; i++){
        if(snake.x[i] == snake.x[1] && snake.y[i] == snake.y[1]){//吃到自己 
          snake.life = 1;
           break;
        }
    }	
    return 0;
}
int output(int x) {
    int i , j;
	map[snake.x[1]][snake.y[1]] = 'H';//蛇头 
    for (i = 2 ; i <= snake.lenth ; i++) {//蛇身 
      	map[snake.x[i]][snake.y[i]] = 'X';
    }
    map[food.x][food.y] = '$';//食物 
    for (i = 0 ; i <= 11 ; i++) {
  	    for (j = 0 ; j <= 11 ; j++) printf("%c" , map[i][j]);
  	    printf("\n");
    }
	return 0;
}
int main() {
	int i , key , j;
	char c;
	snake.lenth = 5;
	snake.life = 0;
	snake.f = 4;//? 
	srand(time(0));
	for (i = 5 ; i > 0 ; i--) {
		snake.x[i] = 1;
		snake.y[i] = 6 - i;
	} 
	while (1) {
      while(!kbhit()) {//当没有键盘输入时执行下列程序 
       	if (food.n == 0) {
       		putmoney(0);
       	}
       	getmoney(0);//? 
        snakemove(snake.f);//?
		gameover(1);//?
		if (snake.life == 1) break;
		Sleep(300);
	    system("cls");
      	output(1);
      }
      if (snake.life == 1) break;
      c = getch();
      if (c == 'w' & snake.f != 2) snake.f = 1;//?
      if (c == 's' & snake.f != 1) snake.f = 2;
      if (c == 'a' & snake.f != 4) snake.f = 3;
      if (c == 'd' & snake.f != 3) snake.f = 4;
	}
	for (i = 1 ; i <= 9 ; i++) {
  	    for (j = 1 ; j <= 9 ; j++) map[i][j] = ' ';
    }
    system("cls");  
	map[5][3] = 'G';	map[5][4] = 'A';	map[5][5] = 'M';	map[5][6] = 'E';//game over
	map[6][3] = 'O';	map[6][4] = 'V';	map[6][5] = 'E';	map[6][6] = 'R';
	for (i = 0 ; i <= 11 ; i++) {
  	    for (j = 0 ; j <= 11 ; j++) printf("%c" , map[i][j]);
  	    printf("\n");
    }
	system("pause");
	return 0; 
}

