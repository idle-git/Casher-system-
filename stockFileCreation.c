/* Coursework Name: UNNC SU souvenir shop cashing system
 * Student No.6509528
 * Date: Nov 18
 * call function stockFileCreation
 *
 *  FYI: This c file is involved in the project to illustrate the generating process
 *of the database(stock.dat), the program could still run without this function, as
 *long as the file stock.dat is within the source folder of the project.
 *
 *  Plus: The database behaviours could also be achieved by sequential file, but random
 *access file would provoke a magnificant improvement of performance in real industry
 *application.
 *  Plus Plus: Inplementing all struct items into one array wastes memory, thus define a
 *default item and write the file sequentailly
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

//createFile
void stockFileCreation(void){


    //file pointer
    FILE * rfPtr;

    //default record
    struct souvenirItem item;

    //open file
    if( (rfPtr = fopen("Stock.dat","wb+")) == NULL ){//failed
        printf("\n%s\n", "File creation failed!");
    }//end if
    else{

        //write item #Birthday Cards
        //Postercards
        item.itemCategory = "Postercards";
        item.itemDescription = "Birthday Cards";
        item.itemCode = "00310";
        item.itemPrice = 10.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //write item #Christmas Cards
        //
        item.itemCategory = "Postercards";
        item.itemDescription = "Christmas Cards";
        item.itemCode = "00311";
        item.itemPrice = 10.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //write item #NingBo Scenery Cards
        //

        item.itemCategory = "Postercards";
        item.itemDescription = "NingBo Scenery Cards";
        item.itemCode = "00312";
        item.itemPrice = 15.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //write item #Calendar
        //

        item.itemCategory = "Postercards";
        item.itemDescription = "Calendar";
        item.itemCode = "00313";
        item.itemPrice = 20.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);


        //write item #UNNC T Shirt(Pink)
        //clothing
        item.itemCategory = "Clothing";
        item.itemDescription = "UNNC T Shirt(Pink)";
        item.itemCode = "00710";
        item.itemPrice = 38.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //write item #UNNC T Shirt(Navy)
        //
        item.itemCategory = "Clothing";
        item.itemDescription = "UNNC T Shirt(Navy)";
        item.itemCode = "00711";
        item.itemPrice = 38.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //write item #UNNC Jumper(Pink)
        //
        item.itemCategory = "Clothing";
        item.itemDescription = "UNNC Jumper(Pink)";
        item.itemCode = "00712";
        item.itemPrice = 38.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //write item #UNNC Jumper(Pink)
        //
        item.itemCategory = "Clothing";
        item.itemDescription = "UNNC Jumper(Pink)";
        item.itemCode = "00713";
        item.itemPrice = 38.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);



        //write item #Key Ring
        //stationary
        item.itemCategory = "Stationary";
        item.itemDescription = "Key Ring";
        item.itemCode = "00910";
        item.itemPrice = 12.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //write item #Mug
        //
        item.itemCategory = "Stationary";
        item.itemDescription = "Mug";
        item.itemCode = "00911";
        item.itemPrice = 9.50;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //write item #Engraved Pen
        //
        item.itemCategory = "Stationary";
        item.itemDescription = "Engraved Pen";
        item.itemCode = "00912";
        item.itemPrice = 7.50;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //write item #Photo Frame
        //
        item.itemCategory = "Stationary";
        item.itemDescription = "Photo Frame";
        item.itemCode = "00913";
        item.itemPrice = 17.00;
        fwrite(&item,sizeof(struct souvenirItem), 1, rfPtr);

        //close file
        fclose(rfPtr);
    }//end else


}//end creation of file
