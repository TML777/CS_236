#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;


void quickSortMedian(int*, int, int, bool);
void quickSortFirst(int*, int, int, bool);
int partition(int*, int, int, bool);
int getMedian(int, int, int);
void randomizer(int*, int);

int main()
{
    char stillGoing = 'y';
    cout << showpoint << fixed << setprecision(4);
    while(stillGoing == 'y')
    {
        clock_t time;
        int listSize;
        
        cout << "Enter array size: ";
        cin >> listSize;
        int list[listSize];
    
        randomizer(list, listSize);
        time = clock();
        quickSortFirst(list, 0, listSize-1, false);
        time = clock() - time;
        cout << "Quick sort time, with pivot as the first element: "
            << ((float) time)/CLOCKS_PER_SEC << endl;
        
        randomizer(list, listSize);
        time = clock();
        quickSortMedian(list, 0, listSize-1, false);
        time = clock() - time;
        cout << "Quick sort time, with pivot median element: "
            << ((float) time)/CLOCKS_PER_SEC << endl;
        
        randomizer(list, listSize);
        time = clock();
        quickSortFirst(list, 0, listSize-1, true);
        time = clock() - time;
        cout << "Quick sort time and insertion sort time, with pivot as the first element: "
            << ((float) time)/CLOCKS_PER_SEC << endl;
        
        randomizer(list, listSize);
        time = clock();
        quickSortMedian(list, 0, listSize-1, true);
        time = clock() - time;
        cout << "Quick sort time and insertion sort time, with pivot median element: "
            << ((float) time)/CLOCKS_PER_SEC << endl;
        
        cout << endl << "Would you like like to enter another array size (y/n): ";
        cin >> stillGoing;
        cout << endl;
        
    }
    
    
    return 0;
}



//Sorts using quick sort with pivot median uses insertion sort if insertion is true
void quickSortMedian(int* list, int first, int last, bool insertion)
{
    if(last > first)
    {
        if(insertion && (last-first) <= 19)
        {
            int j, temp;
            for(int i = first+1; i<=last;i++)
            {
                j = i;
                while((j > first) && (list[j] < list[j-1]))
                {
                    temp = list[j];
                    list[j] = list[j-1];
                    list[j-1] = temp;
                }
            }
        }
        else
        {
            int newlast = partition(list, first, last, true);
            quickSortMedian(list, first, newlast, insertion);
            quickSortMedian(list, newlast+1, last, insertion);
        }
    }
}

//Sorts using quick sort with pivot as first uses insertion sort if insertion is true
void quickSortFirst(int* list, int first, int last, bool insertion)
{
    if(last > first)
    {
        if(insertion && (last-first) <= 19)
        
        {
            int j, temp;
            for(int i = first+1; i<=last;i++)
            {
                j = i;
                while((j > first) && (list[j] < list[j-1]))
                {
                    temp = list[j];
                    list[j] = list[j-1];
                    list[j-1] = temp;
                }
            }
        }
        else
        {
            int newlast = partition(list, first, last, false);
            quickSortFirst(list, first, newlast, insertion);
            quickSortFirst(list, newlast+1, last, insertion);
        }
    }
}

//partitions using pivot as median if median is true otherwise uses first
int partition(int* list, int low, int high, bool median)
{
    bool done = false;
    int temp, pivot;
    
    if(median)
        pivot = getMedian(list[low], list[(low+high)/2], list[high]);
    else
        pivot = list[low];
    
    
    while(!done)
    {
        while(list[low] < pivot)
            low++;
        
        while(list[high] > pivot)
            high--;
        
        if(high <= low)
            done = true;
        else
        {
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
            low++;
            high--;
        }
    }
    
    return high;
}

//returns the median of the three numbers
int getMedian(int first, int middle, int end)
{
    if(first <= end)
    {
        if(middle <= first)
            return first;
        else
            return middle;
    }
    else
    {
        if(middle <= end)
            return end;
        else
            return middle;
    }
}

//Sets the list elements to random elements
void randomizer(int* list, int listSize)
{
    srand(time(0));
    for(int i = 0; i < listSize; i++)
        list[i] = rand() % listSize;
}

