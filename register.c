#include <stdlib.h>
#include <stdio.h>
#include "register.h"



void print_item(int rows, int cols, int data[][cols]){
    

    int print_list[12];     //list to store sales data 
    int item; 

    puts("Which item?");    //prompt user for item 
    scanf("%d", &item); 

    for (int i =0; i<cols; i++){    // loops through months 
        for (int j=0; j< rows; j++ ){       // loops through items in each month 
            if (j == item){     // checks it item is equal to user input
                
                print_list[i]= data[j][i];       // stores value at current month and item number in list 
                break;

            }
        }
    }

    printf("Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");
    for(int k=0; k<12; k++){     // loops through new list with sales of item 
        printf("%d\t", print_list[k]);       //prints sale 
    }
    printf("\n");



}


void total_sales(int rows, int cols, int data[][cols]){
    FILE* f1 = fopen("sales.txt","w");      //opens sales.txt to for output file 
    fprintf(f1,"Item\tSales\n");      // prints to output file 
    
    for (int i =0; i<rows; i++){    //loops through items in list 
        int count=0;    // sets/resets counter to zero
        for (int j=0; j< cols; j++ ){      //loops through months 
            
                count = count + data[i][j];     //adds value at current month and item number
                
              
        }
        fprintf(f1,"%02d\t%4d\n",i,count);   //prints item and total sales to output file 
    }

}


void top_overall(int rows, int cols, int data[][cols]){

    int highest=0;      // keeps track of most popular item
    int highest_sales=0;    // keeps track of highest amount of sales 

    for (int i =0; i<rows; i++){       //loops through items 
        int count=0;        // counts total sales of current item
        for (int j=0; j< cols; j++ ){       //loops through months 

                count = count + data[i][j];      //adds value at current month and item number
        }
        if(count > highest_sales){      // if current item is more then highest so far 
            highest_sales = count;      // item's sales become new highest sales amount
            highest = i;    // current item become highest 
        }
        
    }
    printf("The most popular item is item %d.\n",highest);  //prints item with highest sales to terminal 

}