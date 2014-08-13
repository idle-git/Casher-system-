/* Coursework Name: UNNC SU souvenir shop cashing system
 * Student No.6509528
 * Date: Nov 18
 * call function buy
 *
 *  findings:  go review CHAPTER 8->STRINGS you oik!!!!!
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 12


//structure souvenirItem defintition
struct souvenirItem {
    char *itemCategory;
    char *itemDescription;
    char *itemCode;
    double itemPrice;
};//end struct

//buy
int buy(unsigned int * const sumPtr){

    FILE * rfPtr;//file pointer
    char codeEntered[10];//codeEntered
    char *F = "F";//sentinal value
    char *f = "f";//sentinal value
    struct souvenirItem item;//default file
    size_t count;//counter
    unsigned int found = 0;//variable used to determine the vaildity of the code

    //open file binary read mode
    if( (rfPtr = fopen("stock.dat","rb+")) == NULL){
        printf("\nDatabase access failed!\n");
    }//end if
    else{

        //entercode
        scanf("%s", codeEntered);

        //read file for match
        for( count = 0; count < SIZE; ++count){

            //locate and read the item record
            fseek(rfPtr,count*sizeof(struct souvenirItem),SEEK_SET);
            fread(&item,sizeof(struct souvenirItem), 1, rfPtr);

            //if the item matches to the code?
            if( 0 == strcmp(item.itemCode,codeEntered)){
                ++sumPtr[count];
                ++found;
                break;
            }//end if
        }//end for

        //close file
        fclose(rfPtr);

    }//end else

    //invalid code entered
    if( strcmp(f,codeEntered) == 0 || strcmp(F,codeEntered) == 0){
        return 1;
    }//end if
    else if(found == 0){
        printf("\nInvaild code entered!\n");
        return 0;
    }//end else if
    else{
        return 0;
    }//end else


}//end buy
