#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char Stack_1[3], Stack_2[3], Stack_3[3], Stack_4[3];

int Stack_1_Top = -1;
int Stack_2_Top = -1;
int Stack_3_Top = -1;
int Stack_4_Top = -1;

//PUSH FUNCTION FOR STACKS
void push(char Stack[], int *Top, char e){
	
	if(*Top == 2){
		printf("\nStack OverFlow!");
	}
	else{
		*Top = *Top + 1;
		Stack[*Top] = e;
	}
}

//POP FUNCTION FOR STACKS
char pop(char Stack[], int *Top){
	
	if(*Top == -1){
		printf("\nStack Underflow!");
	}
	else{
		char Ball = Stack[*Top];
		*Top = *Top - 1;
		return Ball;
	}
}

// FUNCTION TO GENERATE AND STORE RANDOM RED, GREEN, BLUE BALLS 
void BallGenerator(){
	
    srand(time(NULL)); 
	int RandomNums[9], i;
	char Ball;
	
    for (i = 0; i < 9; i++){
        RandomNums[i] = i + 1;
    }
    
    for (i = 8; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = RandomNums[i];
        RandomNums[i] = RandomNums[j];
        RandomNums[j] = temp;
    }
    
    for (i = 0; i < 9; i++){
    	
    	if(RandomNums[i] >= 1 && RandomNums[i] <= 3)
    		Ball = 'R';
    	else if(RandomNums[i] >= 4 && RandomNums[i] <= 6)
    		Ball = 'B';
    	else 
    		Ball = 'G';
    	
    	
        if(Stack_1_Top < 2)
        	push(Stack_1, &Stack_1_Top, Ball);	
		else if(Stack_2_Top < 2)
        	push(Stack_2, &Stack_2_Top, Ball);	
		else
        	push(Stack_3, &Stack_3_Top, Ball);	
    }
}

//FUNCTION TO VIEW THE ROWS, SWAPPER AND BALLS
void GameViewer(){
	
	int i;
	
	printf("\n\n\n\n\n\t\t\t\t\t\t*-*-*-*-*-*-*-*-*--*-*-*-*-*\n");
	printf("\t\t\t\t\t\t     !_BALL SORT GAME_!\n\t\t\t\t\t\t*-*-*-*-*-*-*-*-*--*-*-*-*-*\n");
	
	printf("\n\t\t\t\t\t\tTube 1:");
	for(i = 0; i<Stack_1_Top+1 ; i++){
		printf("\t%c", Stack_1[i]);
	}
	
	printf("\n\t\t\t\t\t\tTube 2:");
	for(i = 0; i<Stack_2_Top+1 ; i++){
		printf("\t%c", Stack_2[i]);
	}
	
	printf("\n\t\t\t\t\t\tTube 3:");
	for(i = 0; i<Stack_3_Top+1 ; i++){
		printf("\t%c", Stack_3[i]);
	}
	
	printf("\n\n\t\t\t\t\t\tSwapper(4):");
	for(i = 0; i<Stack_4_Top+1 ; i++){
		printf("\t%c", Stack_4[i]);
	} 
	printf("\n\t\t\t\t\t\t*-*-*-*-*-*-*-*-*--*-*-*-*-*\n");
}

//FUNCTION TO CHECK WIN STATUS
int WinCheck(){
	
	if( (Stack_1[0] == Stack_1[1] && Stack_1[1] == Stack_1[2]) && 
		(Stack_2[0] == Stack_2[1] && Stack_2[1] == Stack_2[2]) && 
		(Stack_3[0] == Stack_3[1] && Stack_3[1] == Stack_3[2]) )
		return 1;
	else
		return 0;
}

//FUNCTION TO REMOVE A BALL FROM A SPECIFIC ROW
char Remove(int Row){

	char Ball;
	switch(Row){
		case 1: if(Stack_1_Top != -1){
					Ball = pop(Stack_1, &Stack_1_Top);
					return Ball;
				}
				else{
					printf("\n\t\t\t\t\t\tCan't Remove Ball from Empty Row! Try Again!");
					return 'E';
				}
				break;
		case 2:	if(Stack_2_Top != -1){
					Ball = pop(Stack_2, &Stack_2_Top);
					return Ball;
				}
				else{
					printf("\n\t\t\t\t\t\tCan't Remove Ball from Empty Row! Try Again!");
					return 'E';
				}
				break;
		case 3: if(Stack_3_Top != -1){
					Ball = pop(Stack_3, &Stack_3_Top);
					return Ball;
				}
				else{
					printf("\n\t\t\t\t\t\tCan't Remove Ball from Empty Row! Try Again!");
					return 'E';
				}
				break;
		case 4: if(Stack_4_Top != -1){
					Ball = pop(Stack_4, &Stack_4_Top);
					return Ball;
				}
				else{
					printf("\n\t\t\t\t\t\tCan't Remove Ball from Empty Row! Try Again!");
					return 'E';
				}
				break;
		default:printf("\n\t\t\t\t\t\tWrong Choice! Try Again!");
				return 'W';
				break;
	}
}

//FUNCTION TO ADD A BALL TO A SPECIFIC ROW
int Add(int Start_Row, int Dest_Row, char Ball){

	switch(Dest_Row){
		case 1: if(Stack_1_Top < 2){
					push(Stack_1, &Stack_1_Top, Ball);
					return 1;
				}	
				else{
					printf("\n\t\t\t\t\t\tCan't Add Ball into Full Row! Try Again!");
					Add(0, Start_Row, Ball);
					return 0;
				}
				break;
		case 2:	if(Stack_2_Top < 2){
					push(Stack_2, &Stack_2_Top, Ball);
					return 1;
				}	
				else{
					printf("\n\t\t\t\t\t\tCan't Add Ball into Full Row! Try Again!");
					Add(0, Start_Row, Ball);
					return 0;
				}
				break;
		case 3: if(Stack_3_Top < 2){
					push(Stack_3, &Stack_3_Top, Ball);
					return 1;
				}	
				else{
					printf("\n\t\t\t\t\t\tCan't Add Ball into Full Row! Try Again!");
					Add(0, Start_Row, Ball);
					return 0;
				}
				break;
		case 4: if(Stack_4_Top < 2){
					push(Stack_4, &Stack_4_Top, Ball);
					return 1;
				}	
				else{
					printf("\n\t\t\t\t\t\tCan't Add Ball into Full Row! Try Again!");
					Add(0, Start_Row, Ball);
					return 0;
				}
				break;
		default:printf("\n\t\t\t\t\t\tWrong Choice! Try Again!");
				return 0;
				break;
				
	}
}

void BallSortGame(){
	
	int Start_Row, Dest_Row, Success, Tries = 0;
	char Ball;
	
	printf("\n\nArrange Similar Coloured Balls (R-RED, G-GREEN, B-BLUE) in any of the three Tubes (1, 2, 3). You got 10 tries");
	printf("\n*Note: You can use Swapper to store 3 Balls.");
	GameViewer();

	while(WinCheck() == 0 && Tries<=10){

		printf("\n\n\t\t\t\t\t\tTRIES TAKEN: %d", Tries);
		printf("\n\n\t\t\t\t\t\tChoose Starting Tube(1-4): ");
		scanf("%d",&Start_Row);
		
		printf("\n\t\t\t\t\t\tChoose Destination Tube(1-4): ");
		scanf("%d",&Dest_Row);
		
		Ball = Remove(Start_Row);
		if(Ball == 'E' || Ball == 'W'){
			continue;
		}	
		else{
			if(Add(Start_Row, Dest_Row, Ball) == 0){
				continue;	
			}
		}
		Tries++;
		system("cls");
		GameViewer();
		
		if(Tries >= 10){
			printf("\n\n\n\t\t\t\t\t\tGAME OVER! YOU LOST!");
			exit(0);
		}
	}
	
	printf("\n\n\t\t\t\t\t\t****************************");
	printf("\n\t\t\t\t\t\tConratulations!! YOU WON !!");
	printf("\n\t\t\t\t\t\t     You took %d tries!", Tries);
	printf("\n\t\t\t\t\t\t****************************\n");	
	
}

int main() {
	
	BallGenerator();
	BallSortGame();
    return 0;
}
