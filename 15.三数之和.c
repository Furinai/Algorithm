void sort(int *nums, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    int l = 0, r = 0, s = 0, n = 4;
    int **result = (int **)malloc(sizeof(int *) * n);
    if (nums == NULL || numsSize < 3)
    {
        return result;
    }
    sort(nums, numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (nums[i] > 0)
        {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        l = i + 1;
        r = numsSize - 1;
        while (l < r)
        {
            s = nums[i] + nums[l] + nums[r];
            if (s == 0)
            {
                if (*returnSize >= n)
                {
                    n = n * 2;
                    result = (int **)realloc(result, sizeof(int *) * n);
                    *returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * n);
                }
                result[*returnSize] = (int *)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[l];
                result[*returnSize][2] = nums[r];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (l < r && nums[l] == nums[l + 1])
                {
                    l++;
                }
                while (l < r && nums[l] == nums[l + 1])
                {
                    l++;
                }
                l++;
                r--;
            }
            else if (s < 0)
            {
                l++;
            }
            else if (s > 0)
            {
                r--;
            }
        }
    }
    return result;
}
