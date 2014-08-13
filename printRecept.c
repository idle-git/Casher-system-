/* Coursework Name: UNNC SU souvenir shop cashing system
 * Student No.6509528
 * Date: Nov 18
 * call function printReceipt
 *
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#define SIZE 12

//structure souvenirItem defintition
struct souvenirItem {
    char *itemCategory;
    char *itemDescription;
    char *itemCode;
    double itemPrice;
};//end struct

//printReceipt
double print(unsigned int * const sumPtr){

    FILE * rfPtr;//file pointer
    size_t count;//counter
    struct souvenirItem item;//default item
    double sum = 0;//total price
    unsigned int total = 0;//total purchases

    //void purchase?
    for( count = 0; count <  SIZE; ++count){
        total += *(sumPtr+count);
    }//end for

    //open file binary read mode
    //falis
    if( (rfPtr = fopen("stock.dat","rb+"))==NULL){
        printf("\nDatabase reading failure!\n");
    }//end if
    else{//data read


        //print out receipt
        //header
        printf("\n\n\n\t%s\n\t%s\n\t%s\n",
               "----------------------------------------------",
               "            THANK YOU FOR VISITING US!        ",
               "----------------------------------------------");

        //purchased?
        if( total > 0){
            //items
            //attributes

            printf("\t%s\n\n\n%22s%8s%8s%8s\n",
                   "                    Here is your receipt:",
                   "Item","Code","Num","Price");

            //print out info for each item
            for( count = 0; count < SIZE; ++count){

                //determine if item is purchased
                if( sumPtr[count] == 0){//item not purchased
                    continue;
                }//end if
                else{//item purchased

                    //locate and read the data from the file
                    fseek(rfPtr,count*sizeof(struct souvenirItem),SEEK_SET);
                    fread(&item,sizeof(struct souvenirItem), 1, rfPtr);

                    //print
                    printf("%22s%8s%8u%8.2f\n",item.itemDescription,
                           item.itemCode,sumPtr[count],item.itemPrice*sumPtr[count]);

                    //add to sum
                    sum += item.itemPrice*sumPtr[count];

                }//end else
            }//end for

            //print the receipt end
            printf("\t%s\n\t%s%5.2f\n\n",
                   "----------------------------------------------",
                   "                           Total cost:",sum);
        }//end if
        else{//not purchased
            ;
        }//end else
    //close file
    fclose(rfPtr);
    }//end else

    return sum;
}//end printRecept
