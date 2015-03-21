//  CSC 125 - Online
//  nwilliams_week4lab.cpp
//  Author: Nick Williams on 3/1/15.
//  Description:
//         This Program creates a dynamic array with a user defined size, initializes
//          all array elements to zero, and places user numbers into calculated key
//          array positions using the modulo operator.

#include <iostream>

void initialize_array(int, int *); //Initializes all array values to 0
int get_value(); //Asks user for number
int find_key(int, int); //Calculates the index to place user number
void place_key(int, int, int *); //Places user number in calculated index
void print_array(int, int *); //Displays all array values

using namespace std;

int main(int argc, const char * argv[]) {
    
    int *array_pointer;
    int array_size, key, user_number = 0;
   
    cout << "Please Enter the Number of Elements you would like in your Array: ";
    cin >> array_size;
    
    array_pointer = new int[array_size];
    
    initialize_array(array_size, array_pointer);
    
    while (user_number != -1)
    {
        user_number = get_value();
        
        if (user_number != -1)
        {
            key = find_key(user_number, array_size);
            
            place_key(user_number, key, array_pointer);
            
            print_array(array_size, array_pointer);
        }
    };
    
    delete[] array_pointer;
    
    return 0;
}

//Initializes all array values to 0 by iterating
//through all elements up to the array size
void initialize_array(int array_size, int *array_pointer)
{
    for (int i = 0; i < array_size; i++)
    {
        array_pointer[i] = 0;
    }
}

//Asks user to input any positive integer
int get_value()
{
    int value;
    
    cout << "Enter any Positive Integer: ";
    cin >> value;
    
    return value;
}

//Calculates key location in array for user number placement
int find_key(int user_number, int array_size)
{
    int key = user_number % array_size;
    
    return key;
}

//Places user number in calculated array location
void place_key(int user_number, int key, int *array_pointer)
{
    array_pointer[key] = user_number;
}

//Displays all values in the array
void print_array(int array_size, int *array_pointer)
{
    for (int i = 0; i < array_size; i++)
    {
        cout << array_pointer[i] << endl;;
    }
}
