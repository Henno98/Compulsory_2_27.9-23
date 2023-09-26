// Complsory_2_2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <list>
#include <queue>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;


//partition for quick sort
int Partition(int* array, int Bot, int Top)
{
 
    int split = array[Bot];
    int i = Bot, k = Top;

    while (i <= k)
    {
        while (i <= k and array[i] <= split)
        {
            i++;
        }

        while (i <= k and array[k] > split)
        {
            k--;
        }

        if (i <= k)
        {
           std:: swap(array[i], array[k]);
        }
    }

   std:: swap(array[Bot], array[k]);
    return k;
}
//Quicksort recursive function
void Quicksort(int* array, int start, int end)
{
    if (end <= start) 
        return;

		//choosing where to partition for the quicksort
        int split = Partition(array, start, end);

        //recursion
        Quicksort(array, start, split - 1 );

        Quicksort(array, split + 1, end);
    
}
//Bubblesort recursive function
void Bubblesort(int* array,int i)
{   //stops sorting if size is 0
    if (i == 0)
        return;
    //checks array size and swaps if one is larger
    for (int j = 0; j < i - 1; j++)
    {
        if (array[j] > array[j + 1]) {
            std::swap(array[j], array[j + 1]);

        }
    }
    //recursion
    Bubblesort(array, i - 1);
}
//Insertsort Iterative function
void Iterativeinsertsort(int* array, int stacksize)
{
   
    int key;
    int x;

    for (int j = 0; j < stacksize  ; j++)
    {
        key = array[j];
        x = j - 1;
           
        while (x >= 0 && array[x] > key)
        {
            array[x + 1] = array[x];
            x = x - 1;

        }
        array[x + 1] = key;
    }



}

int main()
{
	//resets rand seed
    srand(time(nullptr));

	//Choose the vector/array size
    int size;
    cout << "enter size of the array::";
    cin >> size;

    //choose max size for the rand range
    int Maxintsize;
    cout << "\nenter the max int size::";
    cin >> Maxintsize;

    //creation of vector and conversion into array
   vector< int> Vector;
   Vector.resize(size);
    for (int i = 0; i < size; i++) {
    	Vector[i] = rand() % Maxintsize;
    }
    int* array = Vector.data();

    //choose which sorting method
	int sort;
    cout << "\nchoose which sort to use\n"<<"1.Quicksort\n" << "2.Bubblesort\n" << "3.InsertSort\n";
    cin >> sort;
    //
    int Size = size;

    //starts time measure
	auto start = high_resolution_clock::now();

    //quicksort, ugh
    if (sort == 1) {
        Quicksort(array, 0, Size -1);
    }//bubblesort
    if (sort == 2) {
        Bubblesort(array, Size);
    }//iterative sort
    if (sort == 3) {
        Iterativeinsertsort(array, Size);
    }
    //ends time measure
    auto end = high_resolution_clock::now();

    //prints the array
    for (int i = 0; i < Size; i++) {
      std:: cout << array[i] << " \n";
    }

    duration<float> elapsed_time = end - start;
    float millisec = elapsed_time.count() * 1000;

    cout << "elapsed time is:" << millisec << " milliseconds\n";

    cout << "press esc to exit";
    
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

