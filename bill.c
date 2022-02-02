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

    char (*filename)[15], choice2;
    int option, j = 0;
    filename = malloc( (j + 1) * sizeof(char*) );
    do{
	printf("1. Enter customer bill\n2. Print all bill\n3. print bill by name search\n4. exit\nselect an option: ");
	scanf("%d", &option);
	switch ( option )
	{
	    case 1:
		{
		    char name[15];
		    printf("Enter the customer name: ");
		    scanf("\n%[^\n]", name);

		    bill_info *bill;  //structure pointer declared
		    bill = calloc( 1, sizeof(bill_info) );  //allocate memmory for one structure variable
		    char choice;
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
			getchar();
			scanf("%c", &choice);
			bill = realloc( bill, ( i + 2 ) * sizeof( bill_info ) );  //memory incresed to store next item details
			i++;
		    }while( choice != 'q' );  //using do while, if condition is true repeat the process

		    print_bill( bill, name, i );  //call function

		    char choice1;
		    printf("Do you want to save? [y/n]\n");
		    getchar();
		    scanf("%c", &choice1);
		    if ( choice1 == 'y' )
		    {
			printf("Enter the filename to save bill: ");
			scanf("\n%s", filename[j]);
			strcat(filename[j], ".txt");
			freopen( filename[j], "w", stdout );  //save data to file
			print_bill( bill, name, i );  //call function
			freopen( "/dev/tty", "w",stdout );  //goto stdout from file
			filename = realloc( filename, (++j + 1) * sizeof(char*) );
			printf("saved successfully\n");
		    }
		    break;
		}
	    case 3:
		{
		    int option1;
		    for ( int i = 0; i < j; i++ )
			printf("%d. %s\n", i + 1, filename[i]);
		    printf("select one filename :");
		    scanf("%d", &option1);
		    FILE *fptr = fopen( filename[ option1 - 1 ], "w" );
		    char ch = fgetc( fptr );
		    while( ch != EOF )
			fputc( ch, stdout );
		    break;
		}
	    case 4:
		return 0;
	}
	printf("Do you want to continue? [y/n]: ");
	scanf("\n%c", &choice2);
    }while( choice2 == 'Y' || choice2 == 'y' );

}



//function for printing bill
void print_bill( bill_info *bill, char *name, int limit ) 
{

    printf("-----------------------%s----------------------------\n",rest_name);  //rest_name is a macro
    printf(" Date          : %s\n",__DATE__);  //print data
    printf(" Customer Name : %s\n", name);  //print data
    printf("-----------------------------------------------------------------------\n");
    printf(" Items \t \t Qty \t \t Price \t \t Total\n");
    printf("-----------------------------------------------------------------------\n");

    for ( int i = 0; i < limit; i++ )
	printf(" %-15s %-15d %-15g %-15g\n", bill[i].item, bill[i].quantity, bill[i].price, bill[i].qty_price);

    float total = 0, c_gst = 0, s_gst = 0, dis = 0;
    for ( int i = 0; i < limit; i++ )
	total += bill[i].qty_price;
    printf("-----------------------------------------------------------------------\n");
    printf(" Sub Total \t \t \t \t \t%g\n", total);
    dis =  total * ( discount / 100.0 );
    printf(" Discount @ %g%%  \t \t \t \t%g\n", discount, dis );
    printf("-----------------------------------------------------------------------\n");
    total -= dis;
    printf(" Net Total \t \t \t \t \t%g\n", total);
    c_gst =  total * ( cgst / 100.0 );
    s_gst =  total * ( sgst / 100.0 );
    printf(" CGST @%g%% \t \t \t \t \t%g\n", cgst, c_gst);
    printf(" SGST @%g%% \t \t \t \t \t%g\n", sgst, s_gst);
    printf("-----------------------------------------------------------------------\n");
    printf(" Grand Total \t\t\t \t \t%g\n", total + c_gst + s_gst );
    printf("-----------------------------------------------------------------------\n");
}

