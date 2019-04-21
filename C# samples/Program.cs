using System;
using System.Collections;
using System.Linq;

namespace ConsoleApp5
{
    class Program
    {
        public static void Main(string[] args)
        {
            int[] a = { 1, -2, 1, 1, -2, 1 };

            GetSizeOFSubarrayWithMaximumSum(a);

            Console.ReadKey();
        }

        static void GetSizeOFSubarrayWithMaximumSum(int[] array)
        {
            if (array == null || array.Length == 0)
            {
                return;
            }

            var maximumSum = 0;
            var sizeOfSubarrayWithMaxSum = 0;

            for (var i = 0; i < array.Length; i++)
            {
                var sum = 0;
                var sizeOfSubArray = 0;
                for (var j = i; j < array.Length; j++)
                {
                    sum += array[j];
                    sizeOfSubArray = j - i + 1;

                    Console.WriteLine($"element index = {i}, sub array size = {sizeOfSubArray}, sum = {sum}");

                    if (maximumSum < sum)
                    {
                        maximumSum = sum;
                        sizeOfSubarrayWithMaxSum = sizeOfSubArray;
                    }
                }
            }

            Console.Write($"Maximum sum = {maximumSum}, Size of subarray = {sizeOfSubarrayWithMaxSum}");
        }

        static char[] Reverse(char[] originStr)
        {
            if (originStr == null || originStr.Length == 1)
            {
                return originStr;
            }

            var revString = new char[originStr.Length];
            var leftIdx = 0;
            var rightIdx = originStr.Length - 1;

            while (leftIdx < rightIdx)
            {
                revString[leftIdx] = originStr[rightIdx];
                revString[rightIdx--] = originStr[leftIdx++];
            }

            revString[leftIdx] = originStr[rightIdx];

            return revString;
        }

        static void ReverseStandard(char[] originStr)
        {
            Array.Reverse(originStr);
        }
    }
}
