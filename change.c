/* Coursework Name: UNNC SU souvenir shop cashing system
 * Student No.6509528
 * Date: Nov 18
 * call function change
 *
 *  findings: when a char or a string is entered where a float-point
 *number supposed to be entered, the char or string would remain in
 *the standard_inout_stream all the time, thus give the user no chance
 *to alter the input whatsoever, and enter an infinite loop, in this case,
 *invoke function fflush(...) to clear the standard_input_stream!!!
 *
 */

#include <stdlib.h>
#include <stdio.h>

//change
void change(double cashNeed){

    double cashPaid = 0;//cashPaid
    unsigned int back;

    //loop enter until enough cash paid
    while( cashNeed > 0){

        //prompt the cutomer to enter the cash
        do{
            printf("\nCash Paid? (Yuan)\n");
            back = scanf("%lf", &cashPaid);

            //enter negative?
            if( cashPaid <= 0 && back == 1){
                printf("\nVoid input! Cash received should NOT be negative!!!");
            }//end if

            //enter character?
            if( back == 0){
                printf("\nVoid input,Please enter a number!!!\n");
                fflush(stdin);
            }//end if

        }while(cashPaid <= 0 || back == 0);

        //more cash needed?
        if( (cashNeed -= cashPaid) > 0){
            printf("\n%s%5.2f%s\n","Still need: ", cashNeed, " Yuan");
        }//end if
    }//end while

    //print out change
    if( cashNeed != 0){
        printf("\n%s%5.2f%s\n","CashBack:", -cashNeed," Yuan");
    }//end if
    else{
        ;
    }//end else

    //thx
    printf("\n\t%s\n\t%s\t\n",
           "*** Please take care of your personal belongings ***",
           "      ********* THANK YOU AGAIN! **************");

}//end change
