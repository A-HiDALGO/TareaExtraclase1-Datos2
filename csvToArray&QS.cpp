#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;



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
   
void displayArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<"\t"; 
      
} 
   



string datos(){

    
	string StringToInt = "";
    ifstream in("36kb.csv");

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
        cout << "\n";
  
    }
    
    
    
 /*
 	string pagedArray [size];
 	
    for (size_t i=0; i<array.size(); ++i)
    {
        for (size_t j=0; j<array[i].size(); ++j)
        {

          //  pagedArray[i+j] = array[i][j];
        }
        cout << "\n";
  
    }
    
    for (int i=0; i<size; ++i)
    {
    	cout << pagedArray[i] << ",";
    }
   // cout<< "A" << array[0][0] << endl;
	
	*/
	
	//cout <<"Datos en String:  "<<endl  <<StringToInt << endl;
	cout << "--------------------------------------------------------" <<endl;
	//cout<< "prubea string to int" <<StringToInt << endl;
    return StringToInt;
    
}


//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
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
    
   cout << "array terminado[] = " <<endl;

    for (i = 0; i <= j; i++) {
        //cout << arr[i] << "," ;
        arraySize++;
        
        //
    }
    cout<< endl << endl;
    arr[0] = arraySize;
    
    cout << arraySize << endl;
    
  return arr;
}


  
// Driver code''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
int main()
{
    string str = datos();
  
    int *prueba = convertStrtoArr(str);

    
	
    cout<<"Pruebas de quicksort" <<endl;

   	int n= prueba[0];
    //int n = sizeof(prueba)/sizeof(prueba[0]); 
    cout<<"Input array"<<endl;
    displayArray(prueba++,n);
    cout<<endl;
    quickSort(prueba++, 0, n-1); 
    cout<<"Array sorted with quick sort"<<endl; 
    displayArray(prueba++,n-1); 
    
    
    return 0;

}


