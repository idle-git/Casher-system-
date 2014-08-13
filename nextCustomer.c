/* Coursework Name: UNNC SU souvenir shop cashing system
 * Student No.6509528
 * Date: Nov 18
 * call function nextCustomer
 *
 *  findings:
 *          [1].To prevent '\n' being read, use scanf("\n%s",...);
 *          [2].To prevent '\n' being read, use scanf("*%c%s",...);
 *
 */


#include <stdlib.h>
#include <stdio.h>

//nextCustomer
int nextCustomer(void){

    char status;

    //error detection
    while( status != 'y'&&status != 'Y'&& status != 'n'&&status != 'N'){

            printf("\nNext Customer?(Y/N)");
            scanf("\n%c",&status);
    }//end while

    //return value
    if( status == 'y' || status == 'Y'){
        return 0;
    }//end if

}//end nextCustomer
