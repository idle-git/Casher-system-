/* Coursework Name: UNNC SU souvenir shop cashing system
 * Student No.6509528
 * Date: Nov 18
 * call function purchasePrintChange
 *
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 12

//header
#include <buy.h>
#include <printRecept.h>
#include <change.h>
#include <nextCustomer.h>

//prototypes
//int buy(unsigned int * const sumPtr);
//double print(unsigned int * const sumPtr);
//void change(double cashNeed);
//int nextCustomer(void);


//static local variable
static unsigned int customerNo = 0;//customer number

//purchasePrintChange
int purchasePrintChange(void){

    char status;//variable used to determine next customer
    unsigned int purchase[SIZE] = {0};//purchase data;
    double sum;//total cost

    //costumer number invkoing static local variable
    customerNo++;
    printf("\n\n\n\t%s%2u%s\n\n\n","**************Customer No.", customerNo,"*******************");

    //prompt the casher to enter
    puts("Please enter the purchased item code: (5 digits, 'F' to finish):");

    //do...while loop purchase
    do{
        ;
    }while( 0 == buy(purchase));

    //print result
    sum = print(purchase);

    //change
    change(sum);

    //next customer?
    if(nextCustomer()==0){
        return  0;
    }//end if
    else{
        return 1;
    }//end else

}//end purchasePrintChange


