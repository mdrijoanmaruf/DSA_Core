#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> runningSum(vector<int> &nums)
{

    int size = nums.size();
    for (int i = 0; i < size; i++)
    {

        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum = sum + nums[j];
        }
        nums[i] = sum;
    }

    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    runningSum(nums);
    printArray(nums);
    return 0;
}