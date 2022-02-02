#include "restaurent_details.h"

typedef struct Restaurant_bill_information  //structure
{
    char item[15];
    int quantity;
    float price;
    float qty_price;

}bill_info;

int main()
{
    char name[15];   //customer name array statically allocated
    printf("Enter the customer name: ");
    scanf("%[^\n]", name);

    bill_info bill[10];  //array of structure variable
    char choice, flag;
    for ( int i = 0; i < 10 ; i++ )  //iterate over 10 
    {
	//read values for structure members
	printf("Enter the item name: ");
	scanf("\n%[^\n]", bill[i].item); 
	printf("Enter quantity: ");
	scanf("%d", &bill[i].quantity);
	printf("Enter price: ");
	scanf("%f", &bill[i].price);
	bill[i].qty_price = bill[i].quantity * bill[i].price;
	printf("press 'q' to stop entering\n");
	getchar();
	//to exit from loop
	scanf("%c", &choice);
	while( choice == 'q' )
	    flag == 1;
	if ( flag  )
	    break;

    }


}

/*
void print_bill.c()
{

    printf("-------------------------%s--------------------------\n",rest_name);  //rest_name is a macro
    printf("Date : %s\n",__DATE__);  //print data
}

*/
