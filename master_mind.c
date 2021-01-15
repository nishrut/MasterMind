/*
  Name:- Nishrut Vikramkumar patel
  Student ID:- 110028922
*/
/*
  Welcome to the mastermind game, here users have to choose
  how many number of digit's game they want to play, and
  then choose how many trials they want to choose the correct
  guess.Then guess untill the last chance.

  After exiting the game you will get your score about,
  how many game you played and result of those games. 
*/

#include<stdio.h>  // standard input output header file.
#include<math.h>   // math header file (In this program, for POWER function).
#include<stdlib.h> // standard library header file.
#include<time.h>   // time header file for srand(time(0)) function.
int a[10],n[11],cnap,correctnumber,e;  // few globally declared integers,'cnap' is for correct number and location,'correctnumber' is for correctnumber.
                                       // a[10] array is to store random numbers, n[11] is to store entered numbers, and 'e' is for replay or exit.

int uniquerand(int a[10],int size);          // function declaration for generating unique random numbers
int found(int a[10],int size, int value);    // function declaration to check the random numbers and input numbers and updating 'cnap' and 'correctnumber'.
int main()   // initialising the code from main function
{
    int won=0,played=0;   // declaring variable to give score of your game at last when you exit.

    printf("\n\n~~~~~~~~~~~~Welcome to the master mind game~~~~~~~~~~~~\n\n");   // printing welcome message

    do  // 'do-while' loop start
    {
        played++;   // incrementing number of games user plays

        printf("Instructions:-First enter the number of digit you want to guess,\n"); // few instructions to user before statring the game.
        printf("              And then enter the number of chances you want.\n\n");    
        printf("%s","Note:- Every digit will be generated unique.\n");
        printf("       %s","and there will be no 0(zero) in those digits.\n\n");

        int s,num,choice;   // introducing few integers.

        int chance=0;       // initialising chance to 0.
        printf("Enter the number of digit: ");  // asking user to enter number of digits.
        
        while(1)    // while loop starts to make sure that user enter number of digits between 1 and 9.
        {
            scanf("%d",&s);   // scanning number of digit in integer 's'.

            if(s<1 || s>9)   // If entered digit is not between 1 and 9 then following message will print out.
            {
                printf("\n!!!!Invalid number!!!!\n\nPlease re-enter the digit between 1 and 9 only: ");
                continue; // to execute while loop again.
            }
            else  // if player entered number between given range then, it will break, and comes out of while loop.
            break; 
        } // while loop end

        printf("\n\nEnter the number of chances you want: ");  // asking user to enter number of trials.
        while(1) // while loop start to make sure that user enter number of trials between 1 and 100.
        {
            scanf("%d",&choice);  // scanning number of trials in 'choice'
            if(choice<1 || choice>100) // if choice is not in range then following statement will print out.
            {
                printf("\n!!!!Invalid number!!!!\n\nPlease re-enter number between 1 and 100 only: ");
                continue;  // to execute while loop again.
            }
            else  // if player entered number between given range then, it will break, and comes out of loop.
            break;
        } // while loop end

        uniquerand(a,s);  // calling uniqueand function.

        for(chance=1;chance<=choice;chance++)  // for loop start, from here guessing number starts, this loop will execute untill all trials finish or user enter correct guess number
        {
            if (chance==choice)  // if there is user's final guess following message will print out.
            printf("\n!!Final Guess!!");

            printf("\n\n---> Chance no.%d\n",chance); // printing the chance number.

            printf("\nEnter the number: ");  // message to enter the guess number.
            scanf("%d",&num);                // scanning 

            if(num<(int)pow(10,s-1) || num>(int)pow(10,s))  // if player entered number is not equal to digit numbers then following mssg will print out
            {
                printf("\n\n!!!!you entered invalid number, please enter %d digit number!!!!\n\n",s); // message
                chance--;   // decrement variable 'chance'
                continue;   // and then executing 'for' loop again 
            }

            found(a,s,num);  // calling found function

            printf("correct number and location=%d\ncorrect number=%d\n",cnap,correctnumber); // printing out results for entered number.

            if(cnap==s)   // if all entered number matches the guess number with location then following things will happen.
            {
                won++;  // increment variable'won' (It will show at last when user will exit from the game)
                printf("\nExcellent you guess the correct number in %d chance\n",chance);  // message of win
                printf("\n\n\tCongratulations\n\t!!!!You Won!!!!\nyour entered number ");
                for(int i=1; i<=s;i++)
                printf("%d",a[i]);
                
                printf(" is correct\n");
                break;  // to exit from 'for' loop
            }
        }

        if(chance>choice) // if entered chance number become greater than your choice then following things will execute
        {
            printf("\n\n\t!!!Game Over!!!\n   your %d chances are over.\n   correct answer was ",choice); // printing game-over message
            for(int i=1; i<=s; i++) // printing correct answer
            printf("%d",a[i]);
        }

        printf("\n\nEntr 1 to play again else enter any number to exit\n"); // message to play again
        scanf("%d",&e);  // scanning the value in e.

    }while(e==1);  //'do-while' loop end. if 'e' is equal to 1 then whole loop will execute again.

    printf("\n\nthank you for playing"); // thank you message

    printf("\nYou played this game %d time\n",played);    //     printing out score of all played games
    printf("You won %d time and lost %d time\n\n",won,played-won);
}

int uniquerand(int a[10], int size)  // uniquerand function
{
    srand(time(0));  
    while(1)  // loop will execute untill we break it.
    {
        int x;   // declaring integer x.
        for(int i=1;i<=size;i++)   // 'for' loop 
        a[i] = rand() % 9 + 1;      // generating random numbers as per size requirements. 

        for(int i=1;i<=size;i++)  // for loop start
        {
            for(int j=1;j<=size;j++)  // for loop start
            {
                if(i!=j && a[i]==a[j]) // here if any generated numbers are same then x=1.
                {
                    x=1;
                }   
            } //  for loop end
        }//  for loop end
        if(x==1)  // if x=1 then following things will execute
        {
            x=0;  // making x zero
            continue; // and executing whole 'for' loop again and generate random numbers again
        }
        else  // else break with all unique random numbers
        break;
    } // for loop end
    return a[size];
} 


int found(int a[10], int size, int value)  // found function
{
    for(int p=size; p>=1; p--) // for loop start
    {
        n[p] = value % 10;  // here entered number is dividing and storing in array.
        value= value / 10;
    } // for loop end


    correctnumber=0,cnap=0;  // initializing both variables to zero

    for(int i=1; i<=size; i++) // for loop start
    {  int z;
        if(a[i]==n[i]) // if location and number is same then increment the cnap and z becomes 1 and break.
        {   z=1;
            cnap++;
        }
        for(int j=1; j<=size; j++)  // for loop start
        {
            if(z==1) // if z is one (1) then it will break from this 'for' loop.
            {
                z=0;
                break;
            }
            if(i==j && a[i]==n[j])  // if location and the number is same then 
            {                       // variable 'cnap' will increment and then break from 'for' loop
                cnap++;
                break;
            }

            if(i!=j && a[i]==n[j])  // if number is same but location is not same then 
            {                       // variable 'correctnumber' will increment and then break from 'for' loop
                correctnumber++;
                break;
            }
        }  // for loop end

    }  // for loop end
    return cnap,correctnumber;
}
