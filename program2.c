//*
// Program: <Program2>
// Author: <Curtis Teitleman>
// Date: <04/16/2015>
// Time spent: <6 hours>
// Purpose: My program asks the user through a series of questions if they would like to convert either
//  weights or lengths from either US measurements to metric measurements or metric measurements to US
// measurements.
//

#include <stdio.h>
#include <stdlib.h>

void convert_weights(void);
void convert_lengths(void);
void clear_keyboard_buffer(void);
void length_to_us(void);
void length_to_metric(void);
void weight_to_us(void);
void input_weight_to_us(int* kg_ptr, double* g_ptr);
void convert_weight_to_us(int* kg_ptr, double* g_ptr);
void print_weight_to_us(int* kg_ptr, double* g_ptr);
void weight_to_metric(void);
void input_weight_to_metric(int* lbs_ptr, double* oz_ptr);
void convert_weight_to_metric(int* lbs_ptr, double* oz_ptr);
void print_weight_to_metric(int* lbs_ptr, double* oz_ptr);
void input_length_metric (int* feet_ptr, double* inch_ptr);
void convert_length_to_metric(int* feet_ptr, double* inch_ptr);
void print_length_to_metric(int* feet_ptr, double* inch_ptr);
void input_length_to_us(int* meters_ptr, double* centimeters_ptr);
void convert_length_to_us(int* meters_ptr, double* centimeters_ptr);
void print_length_to_us (int* meters_ptr, double* centimeters_ptr);

const double wtm_conversion_factor=2.2046;

int main(int argc, char* argv[])
{
    int lw=0;
    
 do{
    printf("Would you like to convert either lengths(1) or weights(2)?");
    scanf("%d", &lw);
    clear_keyboard_buffer();
    while(lw!=1&&lw!=2&&lw!=0)
    {
        printf("Please enter 1 to convert lengths, 2 to convert weights and "
                "0 to terminate the program");
        scanf("%d", &lw);
        clear_keyboard_buffer();
    }
    
    
    if (lw==1)
    {
        convert_lengths();
    }
    if (lw==2)
    {
        convert_weights();
    }
  }while(lw!=0);
    return 0;
}

void convert_lengths(void)
{
    int cl=0;
    
    printf("You have chosen to convert lengths\n");
    printf("Would you like to: convert lengths to feet/inches (1) or convert lengths"
    "to metric measurements (2)");
    scanf("%d", &cl);
    
    if(cl==1)
    {
        length_to_us();
    }
    if(cl==2)
    {
        length_to_metric();
    }
    while(cl!=1&&cl!=2&&cl!=0)
    {
        printf("Please enter 1 to convert lengths to feat and inches,"
      " 2 to convert lengths to metric units and 0 to stop returning weights.");
    }
}

void convert_weights(void)
{
    int cw=0;
    
    printf("You have chosen to convert weights\n");
    printf("Would you like to convert pounds/ounces to kilograms/grams(1),"
            " or from kilograms/grams to pounds/ounces (2). To return to the main menu"
            "press 0 \n");
    scanf("%d", &cw);
    if (cw==1)
    {
        weight_to_metric();
    }
    if (cw==2)
    {
        weight_to_us();
    }
}

void length_to_us(void)
{
    int meters;
    double centimeters;
    int* meters_ptr;
    double* centimeters_ptr;
    meters_ptr=&meters;
    centimeters_ptr=&centimeters;
    
    *meters_ptr=-3;
    *centimeters_ptr=-4;
    
    printf("You have chosen to convert lengths to feet and inches. \n");
    
    input_length_to_us(meters_ptr, centimeters_ptr); 
    convert_length_to_us(meters_ptr, centimeters_ptr);
    print_length_to_us(meters_ptr, centimeters_ptr);
}

void input_length_to_us(int* meters_ptr, double* centimeters_ptr)
{
   
    *centimeters_ptr = -98;
    * meters_ptr = -6;
    
    printf("Input length in meters: \n");
    scanf("%lf", meters_ptr);
    clear_keyboard_buffer();
   
    while(*meters_ptr<0)
    {
        printf("Please input a positive value for meters: ");
        scanf("%lf", meters_ptr);
        clear_keyboard_buffer();
    }
    printf("Input length in centimeters: \n");
    scanf("%d", centimeters_ptr);
    clear_keyboard_buffer();
    
    while(*meters_ptr<0)
    {
        printf("Please input a positive value for centimeters: \n");
        scanf("%d", centimeters_ptr);
        clear_keyboard_buffer();
    }
    
}

void convert_length_to_us(int* meters_ptr, double* centimeters_ptr)
{
    *centimeters_ptr=*meters_ptr*100+*centimeters_ptr;
    
    *centimeters_ptr=(*centimeters_ptr/30.48)*12;
    
    *meters_ptr=(int)*centimeters_ptr/12;
    
    *centimeters_ptr=*centimeters_ptr-*meters_ptr*12;
    
}

void print_length_to_us(int* meters_ptr, double* centimeters_ptr)
{
    
    printf("The amount you have converted is %d feet and %f inches", *meters_ptr, *centimeters_ptr);

}

void length_to_metric(void)
{
    int* feet_ptr;
    double* inch_ptr;
    int feet=-3;
    double inches=-4;
    feet_ptr=&feet;
    inch_ptr=&inches;
    
    printf("You have chosen to convert lengths to metric units. \n");
  
    
        input_length_metric(feet_ptr, inch_ptr);
        convert_length_to_metric(feet_ptr, inch_ptr);
        print_length_to_metric(feet_ptr, inch_ptr);
    
}
void input_length_metric (int* feet_ptr, double* inch_ptr)
{
   *inch_ptr = -98;
   *feet_ptr = -6;
    
    printf("Input length in feet: \n");
    scanf("%lf", feet_ptr);
    clear_keyboard_buffer();
   
    while(*feet_ptr<0)
    {
        printf("Please input a positive value for feet");
        scanf("%lf", feet_ptr);
        clear_keyboard_buffer();
    }
    printf("Input length in inches: \n");
    scanf("%d", inch_ptr);
    clear_keyboard_buffer();
    
    while(*inch_ptr<0)
    {
        printf("Please input a positive value for feet \n");
        scanf("%d", feet_ptr);
        clear_keyboard_buffer();
    }
    
}

void convert_length_to_metric (int* feet_ptr, double* inch_ptr)
{   
    
  *inch_ptr=*feet_ptr*12+*inch_ptr;
  
  *inch_ptr=(*inch_ptr*.3048)/12;
  
  *feet_ptr=(int)*inch_ptr;
  
  *inch_ptr=*inch_ptr-*feet_ptr;
  
}

void print_length_to_metric(int* feet_ptr, double* inch_ptr)
{
    printf("Your length converts to %d meters and %f centimeters.",*feet_ptr,*inch_ptr);
}

void weight_to_us(void)
{
    int* kg_ptr;
    double* g_ptr;
    int kg=-3;
    double g=-4;
    kg_ptr=&kg;
    g_ptr=&g;
    
    printf("You have chosen to convert weight to pounds and ounces \n");
    
    input_weight_to_us(kg_ptr, g_ptr);
    convert_weight_to_us(kg_ptr, g_ptr);
    print_weight_to_us(kg_ptr, g_ptr);
}

void input_weight_to_us(int *kg_ptr, double *g_ptr)
{
   *kg_ptr=-3;
   *g_ptr=-4;
    
    printf("Input weight in kilograms: \n");
    scanf("%d", kg_ptr);
    clear_keyboard_buffer();
   
    while(*kg_ptr<0)
    {
        printf("Please input a weight value for kilograms: \n");
        scanf("%d", kg_ptr);
        clear_keyboard_buffer();
    }
    printf("Input weight in grams: \n");
    scanf("%lf", g_ptr);
    clear_keyboard_buffer();
    
    while(*g_ptr<0)
    {
        printf("Please input a positive value for grams: \n");
        scanf("%lf", g_ptr);
        clear_keyboard_buffer();
    }
}

void convert_weight_to_us(int *kg_ptr, double *g_ptr)
{
    *g_ptr=*kg_ptr*1000+*g_ptr;
    
    *g_ptr=((16*2.2046)/1000)**g_ptr;
    
    *kg_ptr=(int)*g_ptr/16;
    
    *g_ptr=*g_ptr-*kg_ptr*16;
    
}

void print_weight_to_us(int* kg_ptr, double *g_ptr)
{
    printf("The weight you have converted is %d pounds and %f ounces \n", *kg_ptr, *g_ptr);
}
void weight_to_metric(void)
{
    int* lbs_ptr;
    double* oz_ptr;
    int lbs;
    double oz;
    lbs_ptr=&lbs;
    oz_ptr=&oz;
    
    printf("You have chosen to convert weight to kilograms and grams. \n");
    
    input_weight_to_metric(lbs_ptr, oz_ptr);
    convert_weight_to_metric(lbs_ptr, oz_ptr);
    print_weight_to_metric(lbs_ptr, oz_ptr);
    
}

void input_weight_to_metric(int* lbs_ptr, double* oz_ptr)
{
    
    
   int lbs;
   double oz;
    
   
   lbs_ptr=&lbs;
   oz_ptr=&oz;
   
   printf("Input a value in pounds: \n");
   scanf("%d", lbs_ptr);
   
   while(lbs_ptr<0)
   {
       printf("please input a positive value in pounds: \n");
       scanf("%d", lbs_ptr);
   }
   
   printf("Input a weight in ounces: \n");
   scanf("%lf", oz_ptr);
   
    while(oz_ptr<0)
    {
        printf("Please input a positive value in ounces: \n");
        scanf("%lf", oz_ptr);
    }
}

void convert_weight_to_metric(int* lbs_ptr, double* oz_ptr)
{
    *oz_ptr=(*lbs_ptr*16)+*oz_ptr;
    
    *oz_ptr=(*oz_ptr*wtm_conversion_factor)/16;
    
    *lbs_ptr=((int)*oz_ptr)/16;
    
    *oz_ptr=*oz_ptr-*lbs_ptr;
}

void print_weight_to_metric(int* lbs_ptr, double* oz_ptr)
{
     printf("The weight you have converted is %d kilograms and %f grams", *lbs_ptr, *oz_ptr);
    
}
void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c", &c);
    while(c!='\n')
    {
        scanf("%c", &c);
    }
    
}
