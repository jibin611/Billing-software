#include "restaurent_details.h"

typedef struct Restaurant_bill_information  //structure
{
    char item[15];
    int quantity;
    float price;
    float qty_price;

}bill_info;
void print_bill( bill_info *bill, char *name , int limit);

int main()
{
    char name[15];   //customer name array statically allocated
    printf("Enter the customer name: ");
    scanf("%[^\n]", name);

    bill_info *bill;  //array of structure variable
    char choice;
    bill = calloc( 1, sizeof(bill_info) );
    int i = 0, flag = 1;
    do{
	//read values for structure members
	printf("Enter the item name: ");
	scanf("\n%[^\n]", bill[i].item); 
	printf("Enter quantity: ");
	scanf("%d", &bill[i].quantity);
	printf("Enter price: ");
	scanf("%f", &bill[i].price);
	bill[i].qty_price = bill[i].quantity * bill[i].price;

	printf("press ENTER to continue\npress 'q' to stop\n");
	//to exit from loop
	getchar();
	scanf("%c", &choice);
	bill = realloc( bill, ( i + 2 ) * sizeof( bill_info ) );
	i++;
    }while( choice != 'q' );

      print_bill( bill, name, i );

}

void print_bill( bill_info *bill, char *name, int limit )
{
    printf("-----------------------%s----------------------------\n",rest_name);  //rest_name is a macro
    printf("Date          : %s\n",__DATE__);  //print data
    printf("Customer Name : %s\n", name);  //print data
    printf("-----------------------------------------------------------------------\n");
    printf(" Items \t \t Qty \t \t Price \t \t Total\n");
    printf("-----------------------------------------------------------------------\n");

    for ( int i = 0; i < limit; i++ )
	printf(" %-15s %-15d %-15g %-15g\n", bill[i].item, bill[i].quantity, bill[i].price, bill[i].qty_price);

    float total = 0, c_gst = 0, s_gst = 0, dis = 0;
    for ( int i = 0; i < limit; i++ )
	total += bill[i].qty_price;
    printf("-----------------------------------------------------------------------\n");
    printf("Sub Total \t \t \t \t \t %g\n", total);
    dis =  total * ( discount / 100.0 );
    printf("Discount @ %g%%  \t \t \t \t %g\n", discount, dis );
    printf("-----------------------------------------------------------------------\n");
    total -= dis;
    printf("Net Total \t \t \t \t \t %g\n", total);
    c_gst =  total * ( cgst / 100.0 );
    s_gst =  total * ( sgst / 100.0 );
    printf("CGST @%g%% \t \t \t \t \t %g\n", cgst, c_gst);
    printf("SGST @%g%% \t \t \t \t \t %g\n", sgst, s_gst);
    printf("-----------------------------------------------------------------------\n");
    printf("Grand Total \t\t\t \t \t %g\n", total + c_gst + s_gst );
    printf("-----------------------------------------------------------------------\n");
}
