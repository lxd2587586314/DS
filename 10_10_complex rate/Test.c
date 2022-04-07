#include <stdio.h>
// O(2^N)
// 斐波那契额数列的递归写法完全一个实际没用的算法，因为太慢了
// 计算阶乘递归Fac的时间复杂度？
//long long Fac(size_t N)
//{
//	if (0 == N)
//		return 1;
//
//	return Fac(N - 1) * N;
//}
// 计算阶乘递归Fac的时间复杂度？
// 
//数组nums包含从0到n的所有整数，但其中缺了一个。
//请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
int missingNumber(int* nums, int numsSize)
{
    int x = 0;
    for (int i = 0; i <= numsSize; i++)
    {
        x ^= i;
    }

    for (int i = 0; i < numsSize; i++)
    {
        x ^= nums[i];
    }
    return x;
}

//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
void reverse(int* nums, int left, int right)
{

    while (left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k) {
    if (k >= numsSize)
        k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);

}

long long Fac(size_t N) {
    if (0 == N)
        return 1;

    return Fac(N - 1) * N;
}
int main()
{
    printf("%lld\n", Fac(10000));
    return 0;
}