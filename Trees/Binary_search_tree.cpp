#include <iostream>
using namespace std;
    int binarysearch(int array[] , int key , int length) {
        int low = 0 , high = length - 1 ;

        while (high >= low) {
            int midpoint = (high + low) / 2 ;

            if (key == array[midpoint]) return midpoint;

            if (key > array[midpoint]) {
                low = midpoint + 1;   //move low point after midpoint
            }else {
                high = midpoint - 1;   //move high point before midpoint
            }
        }
        return -1 ;  // mean that item not found
    }
int main()
{
        int array[9] = {1,2,3,4,5,6,7,8,9};

        int value = binarysearch(array,5,9);
        if (value != -1) {
            cout<<"Your item index is : "<<value;
        }else
            cout<<"Your item not found  > "<<value;
}
