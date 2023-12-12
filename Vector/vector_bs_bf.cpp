#include <iostream>
#include <vector>
#include <algorithm>

bool bruteForce(std::vector<int> v, int key);
bool binarySearch(std::vector<int> v, int key);

int main (int argc, const char *argv[])
{
    std::vector<int> v;
    for(auto i = 1; i < argc; i++){
        int num = std::stof(argv[i]);
        v.push_back(num);
    }
    std::sort(v.begin(), v.end());   

    for(const auto &num : v){
        std::cout << num << " ";
    }   std::cout << '\n';

       if (bruteForce(v, 5)){
        std::cout << "Key found!" << std::endl;
       } else {
        std::cout << "Key not found" << std::endl;
       }

       return 0;
}

bool bruteForce (std::vector<int> v, int key)
{
    for(const auto &n : v)
    {
        if(n == key)
        {
            return true;
        }
    }
    return false;
}

bool binarySearch(std::vector<int> v, int key)
{
    return false;
}