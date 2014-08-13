/* Coursework Name: UNNC SU souvenir shop cashing system
 * Student No.6509528
 * Date: Nov 18
    * call function displayWelcome
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>


//structure souvenirItem defintition
struct souvenirItem {
    char *itemCategory;
    char *itemDescription;
    char *itemCode;
    double itemPrice;
};//end struct


//display
void displayWelcome(void){

    FILE * rfPtr;//file pointer
    struct souvenirItem item; //default item

    //display welcome
    printf("\n\n\n\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\n\n",
           "********************************************************",
           "*        UNNC STUDENT UNION SOUVENIR SHOP TILL         *",
           "*   Scan the item code or manually type the code ID    *",
           "*                 Type F to finish                     *",
           "********************************************************");

    //display commodity list
    //open file
    if( (rfPtr = fopen("stock.dat","rb+"))==NULL ){
        printf("\nDatabase access denied!\n");
    }//end if
    else{

        //header of the chart
        printf("\n\t\t\t%s\n\n\n\t%11s%25s\t%6s\t%10s\n\n",
               "*** TODAY's HOT CHOICES!!! ***",
               "Category","Item Descripton",
               "Code","Price");

        //loop read and print
        while( !feof(rfPtr)){
            fread(&item,sizeof(struct souvenirItem), 1, rfPtr);
            printf("\t%11s%25s\t%6s\t%10.2f\n",item.itemCategory,
                   item.itemDescription,item.itemCode,
                   item.itemPrice);
        }//end while

        //close file
        fclose(rfPtr);

    }//end else
}//end display


