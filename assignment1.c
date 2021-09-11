// Problem Statement : Program to find the cheapest walnuts in Raghunath Bazaar of Jammu.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
struct Shop
{
	int shopNumber;		//Data of the Shop Number
    int price;			//Data of the Walnut Price
    float quality;		//Data of the Walnut Quality
	struct Shop *walShopNumber;		//Address of the next node for Shop Number
    struct Shop *walPrice;			//Address of the next node for Walnut Price
    struct Shop *walQuality;			//Address of the next node for Walnut Quality
}*headShop = NULL, *headPrice = NULL, *headQuality = NULL;
// creating insertionByShop function to insert shops in the sorted order
void insertionByShop(struct Shop* newShop, int shopNumber)
{
    struct Shop  *current;
    /* Special case for the head end */
    if (headShop == NULL || (headShop)->shopNumber >= newShop->shopNumber)
	{
	/* if any of the given condition is true,
	address of the shop number will point towards headShop and headShop becomes the new shop */
        newShop->walShopNumber = headShop;
        headShop = newShop;
    }
    else {
        /* Locate the node before the point of insertion */
        current = headShop;
        while (current->walShopNumber != NULL
               && current->walShopNumber->shopNumber < newShop->shopNumber) {
            current = current->walShopNumber;
        }
        newShop->walShopNumber = current->walShopNumber;
        current->walShopNumber = newShop;
    }
}
// creating insertionByPrice function to insert walnut prices
void insertionByPrice(struct Shop *newShop, int price)
{
    struct Shop *shop = headPrice;
    struct Shop *index = NULL;
    if (headPrice == NULL)
    {
        headPrice = newShop;
		newShop->walPrice = NULL;
	}
	else
    {
        while (shop != NULL && shop->price <= price)
        {
            index = shop;
            shop = shop->walPrice;
        }
        if (shop == NULL)
        {
            index->walPrice = newShop;
            newShop->walPrice = NULL;
        }
        else
        {
            newShop->walPrice = headPrice;
            headPrice = newShop;
        }
    }
}
// creating insertionByQuality function to insert walnut qualities
void insertionByQuality(struct Shop *newShop, float quality)
{
    struct Shop *shop = headQuality;
    struct Shop *index = NULL;
    if (headQuality == NULL)
    {
        headQuality = newShop;
        newShop->walQuality = NULL;
    }
    else
    {
        while (shop != NULL && shop->quality <= quality)
        {
            index = shop;
            shop = shop->walQuality;
        }
        if (shop == NULL)
        {
		index->walQuality = newShop;
        newShop->walQuality = NULL;
		}
        else
        {
            newShop->walQuality = headQuality;
            headQuality = newShop;
        }
    }
}
// creating printSNumber function to display all the registered shops in Raghunath Bazaar
void printSNumber() {
    //Shop shop will point to headShop  
    struct Shop *shop = headShop;  
	int shopNumber, newShop;
    if(headShop == NULL) {  
        printf("\nShops are not registered, try again after sometime\n");
    }
	printf("\n");
	while(shop != NULL) {  
        //Prints each Shop by incrementing pointer  
        printf("%d ", shop->shopNumber);  
        shop = shop->walShopNumber;  
    }
	printf("\n\n");
}
// creating printWPrice function to display the price of cheapest walnut along with its Shop Number and Quality
void printWPrice()
{
	int shopNumber;
    int price = INT_MAX;		//keeping the highest price of walnuts as INT_MAX
    float quality;
	struct Shop *shop = headPrice;
	if (shop == NULL)
	{
		printf("\nShops are not registered, try again after sometime\n");
    }
    else
    {
        while(shop != NULL)
        {
            if(((shop->price) <= price))		// loop will run until the walnuts having cheapest price are found
            {
				/* when the cheapest walnuts are found it will make shop number as that particular shop number,
				quality as quality of cheapest walnuts and price as price of cheapest walnuts found */
				shopNumber = shop->shopNumber;
                quality = shop->quality;
                price = shop->price;
            }
            shop = shop->walPrice;
        }
	// printing the cheapest walnuts with their shop number and quality
        printf("\n\nShop with the cheapest Walnuts: (Shop Number : %d)\t(Price : %d)\t(Quality : %.2f)\n\n", shopNumber, price, quality);
    }
	printf("\n");
}
// creating printWPrice function to display the price of cheapest walnut along with its Shop Number and Quality
void printWQuality()
{
	int shopNumber;
	int price;
	float quality = FLT_MIN;		//keeping the highest quality of walnuts as FLT_MAX
	struct Shop *shop = headQuality;
	if (shop == NULL)
	{
		printf("\nShops are not registered, try again after sometime\n");
    }
    else
    {
        while(shop != NULL)
        {
            if(((shop->quality) >= quality))            // loop will run until the walnuts having cheapest price are found
            {
                /* when the cheapest walnuts are found it will make shop number as that particular shop number,
                quality as quality of cheapest walnuts and price as price of cheapest walnuts found */
                shopNumber = shop->shopNumber;
                quality = shop->quality;
                price = shop->price;
       		}
            shop = shop->walQuality;
        }
        // printing the cheapest walnuts with their shop number and quality
        printf("\n\nShop with the cheapest Walnuts: (Shop Number : %d)\t(Price : %d)\t(Quality : %.2f)\n\n", shopNumber, price, quality);
    }
        printf("\n");
}
// creating printAll function to display all the registered shops with Shop Number, Price and Quality of Raghunath Bazaar
void printAll()
{
	int shopNumber;
	int price = INT_MAX;		//keeping the highest price of walnuts as INT_MAX
	float quality;
	struct Shop *shop = headPrice;
	if (shop == NULL)
	{
		printf("\nShops are not registered, try again after sometime\n");
    }
    else
    {
		printf("\n\n\t\t\t~~ WALNUTS SHOPS IN RAGUNATH BAZAAR JAMMU ~~\n\n");
        printf("\tSHOP NUMBER \t PRICE (INR) \t QUALITY");
        while(shop != NULL)
        {
			if((shop->price) < INT_MAX)		// loop will run until the highest price node is reached
            {
				/* traversing each node and making shop number as that particular shop number,
                quality as quality of walnuts of the shop and price as price of walnuts of the shop being traversed */
				price = shop->price;
				shopNumber = shop->shopNumber;
                quality = shop->quality;
                printf("\n\n\t%d\t\t%d\t\t%.2f", shop->shopNumber, shop->price, shop->quality);
            }
            shop = shop->walPrice;
        }
    }
    printf("\n\n");
}
//creating insertShop function for the insertion of each  Shop Number, Price and Quality of walnuts as a whole single node
void insertShop(int shopNumber, int price, float quality)
{
	struct Shop *newShop = (struct Shop *)malloc(sizeof(struct Shop));
	newShop->shopNumber = shopNumber;
    newShop->price = price;
    newShop->quality = quality;
    insertionByShop(newShop, shopNumber);
    insertionByPrice(newShop, price);
    insertionByQuality(newShop, quality);
}
int main()
{
	int operation1, operation2, price, shopNumber;
	float quality;
	printf("\n\t\t\t\t\tNAMASTE\n\n");
	printf("\n\t\t\t\tWelcome to the Raghunath Bazar\n");
	printf("\nChoose any option to continue\n");
	do
    {
        printf("\n1.Press 1 if you are a Seller\n");
		printf("\n2.Press 2 if you are a Buyer\n");
		printf("\n3.Exit\n");
        scanf("%d", &operation1);
		switch(operation1)
        {
        // case 1 is for the shopkeepers to register their shops
			case 1:
				printf("\n\n\t Register Your Shop \n");
				printf("\nEnter the Shop Number\n");
				scanf("%d", &shopNumber);
				printf("\nEnter the Walnut Price\n");
		        scanf("%d", &price);
				printf("\nRate the Walnut Quality from '0' to '10'\n");
                scanf("%f", &quality);
				/* checking whether the entered inputs are valid or not,
				if the inputs are valid it will reflect into the insertShop function and
				if any of the inputs are invalid it will directly come out of the program */
				if((shopNumber < 0 || price < 0 || quality < 0 || quality > 10))
				{
					printf("\nPlease enter the valid inputs only\n");
					return -1;
				}
				else{
                    insertShop(shopNumber, price, quality);		//calling insertShop function
                    printf("\nYou have successfully registered your shop.\n\n");
				}
				break;
			// case 2 is for the buyers 
			case 2:
				printf("\n\nChoose any option to continue\n");
				do
				{
				/* press 1 to see all the registered shops with us from Raghunath Bazaar Jammu, 
				press 2 to see the cheapest walnuts price along with the shop number and quality,
				press 3 to see all the shops with Shop Number, Price and Quality of walnuts
				press 4 to exit */
					printf("\n1.Display Shop Numbers of Registered Shops of Raghunath Bazaar\n");
					printf("\n2.Display all shops with Shop Number, Price and Quality\n");
					printf("\n3.Shop with cheapest walnut\n");
		        	printf("\n4.Shop with best quality walnuts\n");
					printf("\n5.Exit\n");
					printf("\n0.Back\n");
		        	scanf("%d", &operation2);
		        	switch(operation2)
					{
						case 1:
							printSNumber();		//calling printSNumber function
							break;
						case 2:
							printAll();		//calling printWPrice function
							break;
						case 3:
							printWPrice();		//calling printAll function
							break;
						case 4:
							printWQuality();
							break;
						case 5:
							printf("\nPress any key to exit\n");
				            		exit(0);
							break;
		            	default:
							if(operation2 != false){
				        		printf("\nWrong operation\n");
							break;
							}
		    		}
				}
	    		while (operation2 != false);
				break;
			case 3:
                printf("\nPress any key to exit\n");
                exit(0);
                break;
            default:
                printf("\nWrong operation\n");
                break;
		}
	}
	while(1);
    return 0;
}
