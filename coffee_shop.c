#include <stdio.h>
#include <stdlib.h>
#include "register.h"

int main(void){
   
   // initializing varibles 
    int data[50][12]; //creating array 50x12
    int code;
    int val;
    

    
   

    for(int i=0; i<12; i++){  
     
        FILE* f1; 
        switch (i){  //switches to current iteration  
            case 0: // sets each text file to a number case 0-11
            f1 = fopen("Jan_2023_data.txt", "r"); // opens file to read 
            break; 

            case 1:
            f1 = fopen("Feb_2023_data.txt", "r");
            break;

            case 2:
            f1 = fopen("Mar_2023_data.txt", "r");
            break;

            case 3:
            f1 = fopen("Apr_2023_data.txt", "r");
            break;

            case 4:
            f1 = fopen("May_2023_data.txt", "r");
            break;

            case 5:
            f1 = fopen("Jun_2023_data.txt", "r");
            break;

            case 6:
            f1 = fopen("Jul_2023_data.txt", "r");
            break;

            case 7:
            f1 = fopen("Aug_2023_data.txt", "r");
            break;

            case 8:
            f1 = fopen("Sep_2023_data.txt", "r");
            break;

            case 9:
            f1 = fopen("Oct_2023_data.txt", "r");
            break;

            case 10:
            f1 = fopen("Nov_2023_data.txt", "r");
            break;
            
            case 11:
            f1 = fopen("Dec_2023_data.txt", "r");
            break;
        }
      
        

        
        int j=0;
        while(fscanf(f1,"%*d %*s %d", &val)>0){   // scans current file for data storing sales in val
            
            data[j][i] = val; //stores sales value in array at current j(item number) and i(month)
            j++; //increments j to next item 
        }
      

        
    }
    
   
   

    
    //prompting user which program they would like to run
    puts("Which program would you like to run?");
    puts("(1) Output the monthly sales of an item.");
    puts("(2) Calculate overall sales for all items.");
    puts("(3) Find the most popular item.");

    int x;
    scanf("%d", &x);//stores corresponding interger for slected program 

    switch (x) // calls function based on selected program
    {
    case 1:
        print_item(50, 12, data); // gives data and array dimensions to print_item function
        break;
    case 2:
        total_sales(50, 12, data); // gives data and array dimensions to total_sales function
        break;

    case 3: 
        top_overall(50, 12, data); // gives data and array dimensions to top_overall function
        break;
        
    default:
        break;
        }

    return 0;

    
}
