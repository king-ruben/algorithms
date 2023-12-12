#include <iostream>
#define S 10

/**
 * Function declarations
*/
int binarySearch(int A[], int n, int k);

/**
 * Global variables
*/
int high = S;
int low = 0;
int mid;
int key;

/**
 * Main function
*/
int main(int argc, char** argv)
{
    int A[S] = {0,1,11,13,16,66,78,101,120,200};
    

    std::cout << "Insert the element that you want to find: " << '\n';
    std::cin >> key;

    int found = binarySearch(A, S, key);

    return 0;
}

/**
 * Binary search algorithm, takes an array, the size and the key to search
 * Returns -1 if element not found, position of the element in the array otherwise
*/
int binarySearch (int A[], int n, int k)
{
    do
    {
        mid = low + ( (high-low)/2 );

        if (A[mid] == key)
        {
            std::cout << "Element found, at position: " << mid << '\n';
            return mid;
        }

        else if (A[mid] < key)
        {
            low = mid + 1;
        }

        else // A[mid] > key
        {
            high = mid - 1;
        }

            
    } while (low <= high);
    // Element not found:
    std::cout << "Element not found, exiting..." << std::endl;
    return -1;
}