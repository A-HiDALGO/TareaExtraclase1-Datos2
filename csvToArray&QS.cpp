#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;



//====================================================================SELECTION SORT
//Swap function
void swap2(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            swap2(&arr[min_idx], &arr[i]);
    }
}
 
//Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
//====================================================================INSERTION SORT
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
  
        // Move elements of arr[0..i-1],  
        // that are greater than key, to one 
        // position ahead of their 
        // current position
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
  
// A utility function to print an array 
// of size n 
/*
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl;
} 
*/
//====================================================================QUICK SORT
// Swap two elements - Utility function  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
// partition the array using last element as pivot
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
   
//quicksort algorithm
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        //partition the array 
        int pivot = partition(arr, low, high); 
   
        //sort the sub arrays independently 
        quickSort(arr, low, pivot - 1); 
        quickSort(arr, pivot + 1, high); 
    } 
} 
   
   
   



//---------------------------------------------------------------------------------Get the csv file ass a string
string datos(){

    
	string StringToInt = "";
    ifstream in("1kb.csv");

    string line, field;

    vector< vector<string> > array;  // the 2D array
    vector<string> v;                // array of values for one line only

    while ( getline(in,line) )    // get next line in file
    {
        v.clear();
        stringstream ss(line);

        while (getline(ss,field,','))  // break line into comma delimitted fields
        {
            v.push_back(field);  // add each field to the 1D array
        }

        array.push_back(v);  // add the 1D array to the 2D array
    }

    // print out what was read in
	int size = 0;
    for (size_t i=0; i<array.size(); ++i)
    {
        for (size_t j=0; j<array[i].size(); ++j)
        {
            //cout << array[i][j] << ","; // (separate fields by ,)
            
            
            if(j==array[i].size()-1){
            	StringToInt =   StringToInt + array[i][j] ;
            	
			}
			else{
				StringToInt =   StringToInt + array[i][j] + ", ";
			}
            
            
            size ++;
            
        }

  
    }
    

    return StringToInt;
    
}
 
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''' CONVERT THE STRING TO AN ARRAY
int *convertStrtoArr(string str)
{
    // get length of string str
    int str_length = str.length();
  
    // create an array with size as string
    // length and initialize with 0
    
    
    int arr[str_length] = {};
    int arraySize = 0;
  
    int j = 1, i;
  
    // Traverse the string
    
    for (i = 0; str[i] != '\0'; i++) {
  
        // if str[i] is ', ' then split
        if (str[i] == ',')
            continue;
         if (str[i] == ' '){
            // Increment j to point to next
            // array location
            j++;
        }
        else {
  
            // subtract str[i] by 48 to convert it to int
            // Generate number by multiplying 10 and adding
            // (int)(str[i])
            arr[j] = arr[j] * 10 + (str[i] - 48);
        }
    }
    
   //cout << "array terminado[] = " <<endl;

    for (i = 0; i <= j; i++) {
        //cout << arr[i] << "," ;
        arraySize++;
        
        //
    }
    //cout<< endl << endl;
    arr[0] = arraySize;
	
    
    
    //cout << arraySize << endl;
    
  return arr;
}
//===================================================================Function to print the array
void displayArray(int arr[], int size) 
{ 
    int i; 
    arr++;
    for (i=0; i < size - 1; i++) 
        cout<<arr[i]<<"\t"; 
      	cout<< endl;
} 



  
// Driver code''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
int main()
{
	string entrada;
    string str = datos();
    int *DatosFinales = convertStrtoArr(str);
    int n= DatosFinales[0];
    //int pruebas[]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    //int n = 20;
    
    cout << "Digite " << endl << "QS para  Quick sort" << endl << "IS para Insertion sort" << endl <<   "SS para Selection sort"  << endl;
    
    cin  >> entrada;
    
    cout<<"Input array"<<endl;
    displayArray(DatosFinales++,n);
    cout<<endl;
    
    if(entrada == "QS" || entrada == "qs"){
    	quickSort(DatosFinales, 0, n-1); 
   	    cout<<"Array sorted with quick sort"<<endl; 
   	     displayArray(DatosFinales++,n); 

	}
    
    else if(entrada == "IS" || entrada == "is" ){
       insertionSort(DatosFinales, n); 
       cout<<"Array sorted with Insertion sort"<<endl; 
        displayArray(DatosFinales++,n); 
     
	}
	
	else if(entrada == "SS" || entrada == "ss" ){
		selectionSort(DatosFinales, n);
    	cout<<"Array sorted with Selection sort"<<endl; 
    	 displayArray(DatosFinales++,n); 
	}
	
	else{
		cout << "Usted no digito una enrada valida" << endl;
	}


   
    
    return 0;

}



