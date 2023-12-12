#include <iostream>

#define S 10

int main(int argc, char** argv)
{
    int A[S] = {0,1,11,13,16,66,78,101,120,200};
    int high = S;
    int low = 0;
    int mid;
    int key;

    std::cout << "Insert the element that you want to find: " << '\n';
    std::cin >> key;

    do{
        mid = low + ( (high-low)/2 );

        if(A[mid] == key)
        {
            std::cout << "Element found, at position: " << mid << '\n';
            return 0;
        }

        else if(A[mid] < key)
        {
            low = mid + 1;
        }

        else // A[mid] > key
        {
            high = mid - 1;
        }

            
    }while(low <= high);
    // Element not found:
    std::cout << "Element not found, exiting..." << std::endl;

    return 0;
}