#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }

int main()
{
    vector<int> vect{ 4, 5, 5, 4 };
    int index = removeElement(vect, 4);
    cout << index << endl;

    return 0;
}