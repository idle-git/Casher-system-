/* Coursework Name: UNNC SU souvenir shop cashing system
 * Student No.6509528
 * Date: Nov 18
 * main function
 *
 *  findings:
 *      [1].Fixed layout: do{
 *                           ;
 *                        }while(call function);
 *      always set return value as integer 0 to continue execution,
 *leave the do{} part void thus reduce execution time
 *
 */

#include <stdio.h>
#include <stdlib.h>

//header
#include <stockFileCreation.h>
#include <displayWelcome.h>
#include <purchaseAndPrint.h>


//prototypes
//void stockFileCreation(void);
//void displayWelcome(void);
//int purchasePrintChange(void);


//main
int main(void)
{
    //stock random access file creation
    stockFileCreation();

    //display welcome header & stock list
    displayWelcome();

    //customer action
    //purchase and print
    do{
        ;
    }while( purchasePrintChange()==0);//end while

    //end of program
    printf("\n\n\t************* END ****************");

    return 0;
}//end main
