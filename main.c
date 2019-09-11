#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ifnegative( int x ){
    if ( x<0 )
      return 1;
    else
      return 0;
}
void MODE1(){
    srand ( time(NULL) );
    int guess, counter;
    long number;
    guess = rand()%10 + 1;
    printf("Enter the number you guessed\n");
    scanf("%ld", &number);
    for (counter = 4; counter>0; --counter){
        if ( ifnegative(number)){
            printf("Negative number\nEnter the number again\n");
            scanf("%ld", &number);
            ++counter;
        }

        else if ( guess == number ){
            printf("Well Done! You guessed it right!\n");
            printf("You consumed %d attempts", (5-counter) );
            break;
        }
        else{
            printf("Wrong\n");
            printf("You still have %d attempts.\nEnter the number again\n", counter);
            scanf("%ld", &number);
            if ( counter == 1){
                printf("HARD LUCK\n");
                printf("The number was %d", guess);
            }
        }
    }

}
void MODE2(){
    srand ( time(NULL) );
    int guess;
    long number;
    guess = 1 + rand()%10;
    printf("Enter the number you guessed\n");
    scanf("%ld", &number);
    if ( ifnegative(number)){
        printf("Negative Number.\nEnter the number again\n");
        scanf("%ld", &number);
    }
    if ( guess == number){
        printf("Awesome! You guessed it right!");
    }
    else{
        printf("Wrong! Hard luck..\n");
        printf("The number was %d", guess);
    }
}

int main()
{
    printf("Guess Game !\nIn this game, the computer chooses a number between 0 and 10, and you try to guess it.\nIn mode one, you have 5 attempts. In mode two, you have only one attempt! Good Luck..\n");
    printf("Choose: Mode 1 OR Mode 2?\n");
    int mode;
    scanf("%d", &mode);
    if(mode == 1)
        MODE1();
    else if( mode == 2)
        MODE2();
    else
        printf("You have to enter 1 or 2 !");
    return 0;
}
