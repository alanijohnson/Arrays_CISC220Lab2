/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alani Johnson
 * TA: Taghreed Bagies
 * 2/23/17
 *
 * This file contains functons for lab 2.
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <math.h> 
using namespace std;


bool order1(int *a, int *b);
bool order2(int &a, int &b);
void fillArray(int array[], int arrayLength);
void arrayPrint(int array[], int arraySize);
void smallest(int array[], int size, int &int1, int &int2);
int smallest_recursive(int array[], int size, int &value, int &index);
int sumArray(int array[], int x);
int lowSequence(int array[], int size);
void arrayOrder(int array[], int size);
bool arrayPalindrome(int array[], int index);
bool arrayPalindrome_Recursive(int array[], int index);
bool arrayPalindromeTestAll(int array[], int size, int palSize, int &index);
bool arrayLargestPalindrome(int array[], int size, int &palSize, int &index);
int* fillArray2(int**num, int*size);
int* randNumToArray();
int* shortenArray(int array[],int* length);
int* arrayCombine(int array1[], int length1, int array2[], int length2, int&finalLength);
int** splitArray(int array[], int length, int *val, int &num);

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    //problem 1
    int x = 7;
    int y = 5;
    cout << "x:" << x << " y:" << y << endl;
    order1(&x, &y);
    cout << "x:" << x << " y:" << y << endl;

    //problem 2
    int v = 7;
    int w = 5;
    cout << "v:" << v << " w:" << w << endl;
    order2(v, w);
    cout << "v:" << v << " w:" << w << endl;

    //problem 3
    int array1[20];
    fillArray(array1, 20);
    //    for (int i=0; i<20; i++){
    //        cout<<i<<":"<<array1[i]<<endl;
    //    }

    //problem 4
    arrayPrint(array1, 20);

    //problem 5
    int index5 = -1;
    int value5 = -1;
    smallest(array1, 20, value5, index5);
    cout << "index: " << index5 << endl;
    cout << "value: " << value5 << endl;

    //problem 6;
    int index6 = -1;
    int value6 = -1;
    cout << smallest_recursive(array1, 20, value6, index6) << endl;
    cout << "index: " << index6 << endl;
    cout << "value: " << value6 << endl;

    //problem 7a;
    cout << "sum: " << sumArray(array1, 20) << endl;
    ;

    //problem 7b:
    cout << lowSequence(array1, 20) << endl;

    //problem 8:
    arrayOrder(array1, 20);
    arrayPrint(array1, 20);

    //problem 9:
    int array2[] = {2, 4, 6, 3, 7, 1, 7, 3, 6, 9};
    cout << arrayPalindrome(&array2[3], 5) << endl; //true
    cout << arrayPalindrome(&array2[4], 3) << endl;
    cout << arrayPalindrome(&array2[2], 7) << endl;
    cout << arrayPalindrome(&array2[2], 5) << endl; //false
    cout << arrayPalindrome(&array2[4], 5) << endl;

    //problem 10:
    cout << arrayPalindrome_Recursive(&array2[3], 5) << endl; //true
    cout << arrayPalindrome_Recursive(&array2[4], 3) << endl;
    cout << arrayPalindrome_Recursive(&array2[2], 7) << endl;
    cout << arrayPalindrome_Recursive(&array2[2], 5) << endl; //false
    cout << arrayPalindrome_Recursive(&array2[4], 5) << endl;

    //Problem 11:
    int index11_1 = -1;
    int index11_2 = -1;
    cout << arrayPalindromeTestAll(array2, 10, 5, index11_1) << endl;
    cout << index11_1 << endl;
    cout << arrayPalindromeTestAll(array1, 20, 5, index11_2) << endl;
    cout << index11_2 << endl;

    //Problem 12:
    int index12 = -1;
    int palSize12 = -1;

    arrayLargestPalindrome(array2, 10, palSize12, index12);
    arrayPrint(&array2[index12], palSize12);

    int index12_1 = -1;
    int palSize12_1 = -1;
    int array3[] = {1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1};

    arrayLargestPalindrome(array3, 13, palSize12_1, index12_1);
    arrayPrint(&array3[index12_1], palSize12_1);

    int index12_2 = -1;
    int palSize12_2 = -1;
    int array4[] = {2, 2, 2, 1, 2, 2, 1, 2, 2, 1};
    arrayLargestPalindrome(array4, 10, palSize12_2, index12_2);
    arrayPrint(&array4[index12_2], palSize12_2);
    
    //Problem 13:
    int length = -1;
    int array5[] = {0}; 
    int* address = array5;
    //cout<<&array5[0]<<endl;
    fillArray2(&address, &length);
    //cout<<length<<endl;
    //cout<<address<<endl;
    arrayPrint(address,length);
    
    //problem 14:
    int* array6 = {0};
    array6 = randNumToArray();
    arrayPrint(array6,4);
    
    //problem 15:
    int* array7 = {0};
    array7 = shortenArray(address,&length);
    arrayPrint(array7,length);
    
    //problem 16:
    int length16 = -1;
    int*array8 = NULL;
    array8 = arrayCombine(array1,20,array2,10,length16);
    //cout<<length16<<endl;
    arrayPrint(array8,length16);
    
    //problem 17
    int belowSplit = -1;
    int aboveSplit = -1;
    int** array9 = NULL;
    array9 = splitArray(array8,30,&belowSplit,aboveSplit);
    //cout<<belowSplit<<endl;
    //cout<<aboveSplit<<endl;
    arrayPrint(array9[0],belowSplit);
    arrayPrint(array9[1],aboveSplit);
    
    
    return 0;
    
    
}

/*
 *Problem 1
 *function: switch the order of the parameters if the first is larger than the second
 * input: int a - integer; pass by pointer
 *        int b - integer; pass by pointer
 * output: true - first parameter was less than second
 *         false - first parameter was greater than second, but they were switched
 *                 first parameter is now less than the second
 */
bool order1(int *a, int *b) {
    if (*a>*b) {
        int tempa = *a;
        *a = *b;
        *b = tempa;
        return false;
    } else {
        return true;
    }
}

/*
 *Problem 2
 *function: switch the order of the parameters if the first is larger than the second
 * input: int a - integer; pass by reference
 *        int b - integer; pass by reference
 * output: true - first parameter was less than second
 *         false - first parameter was greater than second, but they were switched
 *                 first parameter is now less than the second
 */
bool order2(int &a, int &b) {
    if (a > b) {
        int tempa = a;
        a = b;
        b = tempa;
        return false;
    } else {
        return true;
    }
}

/*
 *Problem 3
 *function: fills an array of specified length with values from 0 - 100; 
 * input: array of ints
 *        int arrayLength - size of the passed array
 *        
 * output: array now contains values 0-99
 *         return. void
 */
void fillArray(int array[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        array[i] = rand() % 100;
    }
}

/*
 *Problem 4
 *function: prints each value of an array separated by a comma.
 * input: array of ints
 *        int arraySize - the size of the array
 *        
 * output: array is printed within fn.
 *         return: void
 */
void arrayPrint(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (i == arraySize - 1) {
            cout << array[i] << endl;
        } else {
            cout << array[i] << ",";
        }
    }
}

/*
 *Problem 5
 *function: find the smallest value in the array and update passed value
 *          and index parameters
 * input: array of ints (pointer to first int)
 *        int size - size of the array (call by value)
 *        int &value - can be any value before fn is called
 *                     value will be updated with the smallest int in the array
 *                     (call by reference)
 *        int &index - can be any value before fn is call
 *                     index will be updated with the location of the smallest value in the array
 *                     call by reference
 *        
 * output: Parameters are updated outside of function.
 *         return: void
 */
void smallest(int array[], int size, int &value, int &index) {
    value = array[0];
    index = 0;
    for (int i = 1; i < size; i++) {
        //cout<<array[i-1]<<" "<<array[i]<<endl;
        if (value > array[i]) {
            //cout<<"if statement "<<int1<<" "<<int2<<endl;
            value = array[i];
            index = i;
            //cout<<int1<<" "<<int2<<"stop"<<endl;
        }
    }
}

/*
 *Problem 6
 *function: find the smallest value in the array and update passed value
 *          and index parameters (done recursively)
 * input: array of ints (pointer to first int)
 *        int size - size of the array (call by value)
 *        int &value - can be any value before fn is called
 *                     value will be updated with the smallest int in the array
 *                     (call by reference)
 *        int &index - can be any value before fn is called
 *                     index will be updated with the location of the smallest value in the array
 *                     call by reference
 *        
 * output: Parameters are updated outside of function.
 *         return: void
 */
int smallest_recursive(int array[], int size, int &value, int &index) {
    if (value == -1) {
        value = array[size - 1];
    }
    if (index == -1) {
        index = size - 1;
    }

    if (size == 1) {
        return value;
    }
    if (array[size - 2] > value) {
        return smallest_recursive(array, size - 1, value, index);
    } else {
        value = array[size - 2];
        index = size - 2;
        return smallest_recursive(array, size - 1, value, index);
    }

}

/*
 *Problem 7a
 *function: sum all of the values in the array and return the value
 *input: array of integers
 *       int x - size of the array (by val)
 *        
 * output: reutn sum of the values (int)
 */
int sumArray(int array[], int x) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += array[i];
    }
    return sum;

}

/*
 *Problem 7b
 *function: finds the smallest sequence sum of numbers with a random length 3-8
 *input: array of integers
 *       int size - size of the array (by val)
 *        
 * output: returns the index of the starting value of the subarray
 */
int lowSequence(int array[], int size) {
    int randval = (rand() % 5) + 3;
    //cout<<randval<<endl;
    int sum = sumArray(array, randval);
    int index = 0;
    for (int i = 1; i < size - randval; i++) {
        //cout<<"sum: "<<sum<<endl;
        if (sum > sumArray(&array[i], randval)) {
            //cout<<"if statement: "<<sumArray(&array[i],randval)<<endl;
            sum = sumArray(&array[i], randval);
            index = i;
        }
    }
    arrayPrint(&array[index], randval);
    return index;
}

/*
 *Problem 8
 *function: puts the values in the array in order (low to high)
 * input: array of integers
 *        int size - size of the array (by val)
 *        
 * output: the passed array is now in order low to high
 *         return: void 
 */
void arrayOrder(int array[], int size) {
    int tempsize = size;
    int tempindex = -1;
    int value = -1;
    //    arrayPrint(array,size);
    for (int i = 0; i < size - 1; i++) {
        smallest(&array[i], size - i, value, tempindex);
        //        cout<<endl;
        //       cout<<i<<":"<<endl;
        //        cout<<array[i]<<endl;
        //        cout<<array[tempindex+i]<<endl;
        order1(&array[i], &array[tempindex + i]);
        //arrayPrint(array,size);

    }
}

/*
 *Problem 9
 *function: determines whether or not a palindrome exists in the array
 * input: array of ints (pointer)
 *        int index - size of desired palindrome length
 *        
 * output: boolean - true - if a palindrome of the specified size exists
 *                   false - if a palindrome of the specified size isn't found
 */
bool arrayPalindrome(int array[], int index) {
    bool tf = true;
    for (int i = 0; i <= ((index) / 2); i++) {
        if (!(array[i] == array[index - 1 - i])) {
            tf = false;
        }
    }
    return tf;


}

/*
 *function: determines whether or not a palindrome exists in the array recursive
 * input: array of ints (pointer)
 *        int index - size of desired palindrome length
 *        
 * output: boolean - true - if a palindrome of the specified size exists
 *                   false - if a palindrome of the specified size isn't found
 */
bool arrayPalindrome_Recursive(int array[], int index) {
    if (index == 1) {
        return true;
    } else {
        if (array[0] == array[index - 1]) {
            return (array[1], index - 1);
        } else {
            return false;
        }
    }


}

/*
 *Problem 11
 *function: determines whether or not a palindrome of specified size exists
 * input: array of ints
 *        int size - size of the array
 *        int palSize - specify the size of palindrome
 *        int &index - index of the found palindrome (by ref)
 *                    
 *        
 * output: return: true - palindrome of specified size found
 *                 false - no palindrome of specified size
 *         index is updated with first int of palindrome 
 *               or to -1 if no palindrome was found
 *         
 */
bool arrayPalindromeTestAll(int array[], int size, int palSize, int &index) {
    bool tf = false;
    for (int i = 0; i < (size - palSize); i++) {
        if (arrayPalindrome(&array[i], palSize)) {
            tf = true;
            index = i;
        }
    }
    if (!tf) {
        index = -1;
    }

    return tf;
}

/*
 *Problem 12
*function: searches for the largest palindrome
 * input: array of ints
 *        int size - size of the array
 *        int &palSize - initialized to a value before fn
 *                       will be updated to the size of a palindrome or -1(if no palindrome is found)
 *        int &index - index of the found palindrome (by ref)
 *                    
 *        
 * output: return: true - palindrome found
 *                 false - no palindrome found
 *         index is updated with first int of palindrome 
 *               or to -1 if no palindrome was found
 *         palSize is updated with the size of the found largest palindrome
 *                 or -1 if no palidrome is found.
 *         
 */
bool arrayLargestPalindrome(int array[], int size, int &palSize, int &index) {
    palSize = size;
    while (palSize > 0) {
        if (arrayPalindromeTestAll(array, size, palSize, index)) {
            return true;
        }

        palSize--;
    }
    palSize = -1;
    index = -1;
    return false;
}

/*
 *Problem 13
 *function: generates dyn allocated array of length 8-33 and fills with ints 0-50
 * input: int**firstInt - pointer to pointer of int
 *        int* size  - pointer to size of the array
 *                     initialized outside fnct
 *        
 * output: return address of first int in array stored in heap
 */
int* fillArray2(int** firstInt, int*size) {
    *size = (rand() % 25) + 8;
    int* array = NULL;
    array = new int[*size];
    //cout<<array<<endl;
    *firstInt = &array[0];
    for (int i = 0; i < *size; i++) {
        array[i] = rand()%51;
    }
    return array;
}

/*
 *Problem 14
 *function: generates a random number 100-10000 and splits the values into an array
 * input: none
 *        
 * output: address of the array which is stored in the heap
 */
int* randNumToArray(){
    int num = (rand()%9900)+100;
    cout<<num<<endl;
    int size = 0;
    int val = 0;
    int place = 10000;
    int* array = NULL;
    
    do {
        if (num/place>=1){
            size = (int)(log10(place))+1;
            break;
        }
        place/=10; 
    }while(place>1);
    
    array = new int[size];
    val = num;
    int i = 0;
    do {
        array[i]=(val/place);
        val=val%place;
        place = place/10;    
        i++;
    }while(place>=1);
    
    return array;
}

/*
 *Problem 15
 *function: shortens an array by removing values less than 10 and values greater than 40
 * input: array
 *        length - size of the array (by pointer)
 *        
 * output: array
 *         length is updated to reflect the new length of the array
 */
int* shortenArray(int array[],int* length){
    int count = 0;
    for(int i=0; i<*length; i++){
        //cout<<array[i]<<endl;
        if (array[i]<10 || array[i]>40){
            
            count++;
        }
    }
//    cout<<count<<endl;
//    cout<<*length<<endl;
    int* array2=NULL;
    array2 = new int[*length - count];
    
    int j = 0;
    for (int i=0; i<*length;i++){
        if (array[i]>10 && array[i]<40){
            array2[j] = array[i];
            j++;
        }
    }
    *length = *length - count;
    return array2;
        
} 

/*
 *Problem 16
 *function: combine 2 arrays into 1 array
 * input: array1
 *        int length1 - length of array 1
 *        array2
 *        int length2 - length of array 2
 *        int&finalLength - initialized before fn
 *                          will be updated to reflect the length of the new array
 *        
 * output: pointer to new array which is stored in heap
 */

int * arrayCombine(int array1[], int length1, int array2[], int length2, int&finalLength){
    int i = 0;
    int j = 1;
    int k = 0;
    int* array = NULL;
    array = new int[length1+length2];
    finalLength = length1 + length2;
    while (length1>0 && length2>0){
        array[i] = array1[k];
        array[j] = array2[k];
        
        k++;
        i+=2;
        j+=2;
        length1--;
        length2--;
    }
    
    if (length1>0){
        while (length1>0){
            array[i] = array1[k];
            k++;
            i++;
            length1--;
        }
    } else if (length2>0){
        while (length1>0){
            array[j] = array2[k];
            k++;
            j++;
            length2--;
        }
    }
        
    return array;
}

/*
 *Problem 17
 *function: split an existing array into a 2D array by splitting values high and low due to a splt value
 * input: array
 *        int length - length of the array
 *        int* val - initialized before fn
 *                   updated to contain the length of the belowSplit array
 *        int&num - initialized before fn
 *                  updated to contain the length of the aboveSplit array
 *        
 * output: pointer to 2D array
 */
int** splitArray(int array[], int length, int *val, int &num){
    *val = 0;
    num =0;
    int split = rand()%20;
    
    for (int i=0; i<length; i++){
        //cout<<array[i]<<endl;
        if (array[i]<split){
            (*val)++;
        }else{
            num++;
        }
    }
    int* array1 = NULL;
    array1 = new int[*val];
    int* array2 = NULL;
    array2 = new int[num];
    int** array3 = NULL;
    array3 = new int*[2];
    array3[0] = array1;
    array3[1] = array2;
    
    *val = 0;
    num = 0;
    
    for (int i=0; i<length; i++){
        if (array[i]<split){
            array1[*val] = array[i];
            (*val)++;
        }else{
            array2[num] = array[i];
            num++;
        }
    }
    
    return array3;
    
}