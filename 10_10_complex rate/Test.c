#include <stdio.h>
// O(2^N)
// 쳲����������еĵݹ�д����ȫһ��ʵ��û�õ��㷨����Ϊ̫����
// ����׳˵ݹ�Fac��ʱ�临�Ӷȣ�
//long long Fac(size_t N)
//{
//	if (0 == N)
//		return 1;
//
//	return Fac(N - 1) * N;
//}
// ����׳˵ݹ�Fac��ʱ�临�Ӷȣ�
// 
//����nums������0��n������������������ȱ��һ����
//���д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
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

//����һ�����飬�������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
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