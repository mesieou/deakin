// See https://aka.ms/new-console-template for more information
class Program
{
    static void Main()
    {
        double[] myArr = new double[10];

        //assigning the first element of the array
        myArr[0] = 1.0;
        Console.WriteLine($"The element at index 0 in the array is {myArr[0]}");
        //assigning the second element of the array
        myArr[1] = 1.1;
        Console.WriteLine($"The element at index 1 in the array is {myArr[1]}");
        //assigning the third element of the array
        myArr[2] = 1.2;
        Console.WriteLine($"The element at index 2 in the array is {myArr[2]}");
        //assigning the fourth element of the array
        myArr[3] = 1.3;
        Console.WriteLine($"The element at index 3 in the array is {myArr[3]}");
        //assigning the fifth element of the array
        myArr[4] = 1.4;
        Console.WriteLine($"The element at index 4 in the array is {myArr[4]}");
        //assigning the sixth element of the array
        myArr[5] = 1.5;
        Console.WriteLine($"The element at index 5 in the array is {myArr[5]}");
        //assigning the seventh element of the array
        myArr[6] = 1.6;
        Console.WriteLine($"The element at index 6 in the array is {myArr[6]}");
        //assigning the eight element of the array
        myArr[7] = 1.7;
        Console.WriteLine($"The element at index 7 in the array is {myArr[7]}");
        //assigning the nineth element of the array
        myArr[8] = 1.8;
        Console.WriteLine($"The element at index 8 in the array is {myArr[8]}");
        //assigning the tenth element of the array
        myArr[9] = 1.9;
        Console.WriteLine($"The element at index 9 in the array is {myArr[9]}");

        int[] mySecArr = new int[10];

        //assing values to the array with a loop
        for (int i = 0; i < 10; i++)
        {
            mySecArr[i] = i;
        }

        //looking through the second array to print the values assigned above
        for (int i = 0; i < 10; i++)
        {
            Console.WriteLine($"The element at index {i} in the second array is {mySecArr[i]}");
        }

        //create and assign a new array
        int[] studentArray = { 87, 68, 94, 100, 83, 78, 85, 91, 76, 87 };
        int total = 0;

        //sum all the numbers inside the student array
        for (int i = 0; i < studentArray.Length; i++)
        {
            total += studentArray[i];
        }

        //print the sum result of the above loop
        Console.WriteLine($"Total marks of the student is: {total}");
        Console.WriteLine($"This consists of: {studentArray.Length} marks");
        Console.WriteLine($"Therefore, the average mark is {total / studentArray.Length} marks");

        //new student names array declaration
        string[] studentNames = new string[6];

        //loop through the array to assign names to the array
        for (int i = 0; i < studentNames.Length; i++)
        {
            Console.WriteLine($"Enter name for student {i + 1}: ");
            studentNames[i] = Console.ReadLine();
        }

        //loop through the array to print the values assigned
        for (int i = 0; i < studentNames.Length; i++)
        {
            Console.WriteLine($"Student name at index {i} is: {studentNames[i]}");
        }

        created a new array to find smallest and largest numbers
        double[] doubleArr = new double[10];
        int currSize = 0;
        double currSmallest = double.MaxValue; ;
        double currLargest = doubleArr[0];

        //assign value to the double array from the user and reassing smallest and largest
        for (int i = 0; i < doubleArr.Length; i++)
        {
            Console.WriteLine($"Enter a  decimal amount: ");
            doubleArr[i] = double.Parse(Console.ReadLine());
            if (doubleArr[i] > currLargest)
            {
                currLargest = doubleArr[i];
            }
            else if (doubleArr[i] < currSmallest)
            {
                currSmallest = doubleArr[i];
            }
            Console.WriteLine($"The entered number at index {i} is: {doubleArr[i]}");
            Console.WriteLine($"The current smallest number is: {currSmallest}");
            Console.WriteLine($"The current largest number is: {currLargest}");
        }

        // initialise ans assign a multidimentional array
        int[,] myMultiDimArr = { { 1, 2, 3, 4 }, { 1, 1, 1, 1 }, { 2, 2, 2, 2 } };

        //looop through the multidimentional array
        for (int i = 0; i < myMultiDimArr.GetLength(0); i++)
        {
            for (int j = 0; j < myMultiDimArr.GetLength(1); j++)
            {
                Console.WriteLine(myMultiDimArr[i, j]);
            }
            Console.WriteLine();
        }

        // declaring a list
        List<string> myList = new List<string>();

        //create a random value
        Random randomValue = new Random();
        int randomNumber = randomValue.Next(1, 12);

        //loop random number amount of times and add the numbers to the list
        Console.WriteLine($"You now need to add {randomNumber} students to your class list");
        for (int i = 0; i < randomNumber; i++)
        {
            Console.WriteLine($"Please enter the name of Student {i + 1}: ");
            myList.Add(Console.ReadLine());
        }

        //loop throught the list and see the numbers saved
        for (int i = 0; i < myList.Count; i++)
        {
            Console.WriteLine(myList[i]);
        }

        // method palindrome
        static bool Palindrome(int[] array)
        {
            //return false immediatelly if the array is less than one element.
            if (array.Length < 1)
            {
                return false;
            }

            //loop number of times of the size of the array
            for (int right = 0; right < array.Length; right++)
            {
                int indexFromTheRight = (array.Length - right) - 1;

                //if left and right indexes are different return false
                if (array[right] != array[indexFromTheRight])
                {
                    return false;
                }
            }

            //return true othersie meaning it is a palindrome
            return true;
        }

        static void palindromeCheckTest(bool result, bool expected, int testNum)
        {
            if (result == expected)
            {
                Console.WriteLine($"Test{testNum} Passed!");
            } else
            {
                Console.WriteLine($"Test{testNum} Failed!");
            }
        }

        //test arr length is less than 1
        int testNumber1 = 1;
        bool test1Result = Palindrome(new int[] {});
        bool expectedResultTest1 = false;
        palindromeCheckTest(test1Result, expectedResultTest1, testNumber1);

        //test arr palindrome true example 1
        int testNumber2 = 2;
        bool test2Result = Palindrome(new int[] { 1,2,2,1 });
        bool expectedResultTest2 = true;
        palindromeCheckTest(test2Result, expectedResultTest2, testNumber2);

        //test arr palindrome true example 2
        int testNumber3 = 3;
        bool test3Result = Palindrome(new int[] { 1,2,3,1,3,2,1 });
        bool expectedResultTest3 = true;
        palindromeCheckTest(test3Result, expectedResultTest3, testNumber3);

        //test arr palindrome false example 1
        int testNumber4 = 4;
        bool test4Result = Palindrome( new int[] { 3,2,1 });
        bool expectedResultTest4 = false;
        palindromeCheckTest(test4Result, expectedResultTest4, testNumber4);

        static bool IsSorted(List<int> list)
        {
            //check if list one is not sorted, if so return null
            for (int i = 0; i < list.Count - 1; i++)
            {
                if (list[i] > list[i + 1])
                {
                    return false;
                }
            }
            return true;
        }

        static void CheckListsTest(List<int> resultList, List<int> expectedList)
        {
            if (resultList == null && expectedList == null)
            {
                Console.WriteLine("Test Passed!");
                return;
            }
            else if (resultList.Count != expectedList.Count)
            {
                Console.WriteLine($"Test Failed. result list length {resultList.Count} and expected list length is {expectedList.Count}");
            }
            else
            {
                for (int i = 0; i < resultList.Count; i++)
                {
                    if (resultList[i] != expectedList[i])
                    {
                        Console.WriteLine($"Test Failed. result list the value of index {i} is {resultList[i]} and expected list is {expectedList[i]}");
                        break;
                    }
                }
                Console.WriteLine("Test Passed!");
            }
        }
        static List<int> Merge(List<int> list_a, List<int> list_b)
        {
            //check if any of the lists are not sorted.
            if (!IsSorted(list_a) || !IsSorted(list_b))
            {
                return null;
            }
            //create a result list
            List<int> result = new List<int>();
            int pointerB = 0;
            int pointerA = 0;

            while (pointerA < list_a.Count && pointerB < list_b.Count)
            {
                if (list_a[pointerA] < list_b[pointerB])
                {
                    result.Add(list_a[pointerA]);
                    pointerA++;
                }
                else
                {
                    result.Add(list_b[pointerB]);
                    pointerB++;
                }
            }
            while (pointerA < list_a.Count)
            {
                result.Add(list_a[pointerA]);
                pointerA++;

            }
            while (pointerB < list_b.Count)
            {
                result.Add(list_b[pointerB]);
                pointerB++;

            }

            return result;
        }

        List<int> listTest1 = new List<int> { 1, 2, 2, 5 };
        List<int> listTest2 = new List<int> { 1, 3, 4, 5, 7 };
        List<int> listTest3 = new List<int> { };
        List<int> listTest4 = new List<int> { 5, 2, 2, 1 };

        //test 1: two valid non empty lists merged
        List<int> listTest1Expected = new List<int> { 1, 1, 2, 2, 3, 4, 5, 5, 7 };
        List<int> listTest1Result = new List<int>();
        listTest1Result = Merge(listTest1, listTest2);
        CheckListsTest(listTest1Result, listTest1Expected);

        //test 2: two valid lists, one imput list
        List<int> listTest2Expected = new List<int> { 1, 2, 2, 5 };
        List<int> listTest2Result = new List<int>();
        listTest2Result = Merge(listTest1, listTest3);
        CheckListsTest(listTest2Result, listTest2Expected);

        //test 3: one list invalid
        List<int> listTest3Expected = null;
        List<int> listTest3Result = new List<int>();
        listTest3Result = Merge(listTest4, listTest2);
        CheckListsTest(listTest3Result, listTest3Expected);

        //method to convert a multidimentional array to a single dimention with odd numbers
        static int[] ArrayConvertion(int[,] arr)
        {
            List<int> result = new List<int>();
            for (int i = 0; i < arr.GetLength(1); i++)
            {
                for (int j = 0; j < arr.GetLength(0); j++)
                {
                    if (arr[j, i] % 2 != 0)
                    {
                        result.Add(arr[j, i]);
                    }
                }
            }
            return result.ToArray();
        }

        static bool testArrConvetion(int[] resultArr, int[] expectedArr)
        {
            bool res = true;
            if (resultArr.Length != expectedArr.Length)
            {
                res = false;
                return res;
            }
            for (int i = 0; i < resultArr.Length; i++)
            {
                if (resultArr[i] != expectedArr[i])
                {
                    res = false;
                }
            }
            return res;
        }

        int[,] testArr1 = { { 0, 2, 4, 0, 9, 5 }, { 7, 1, 3, 3, 2, 1 }, { 1, 3, 9, 8, 5, 6 }, { 4, 6, 7, 9, 1, 0 } };
        int[] expectedArr = { 7, 1, 1, 3, 3, 9, 7, 3, 9, 9, 5, 1, 5, 1 };
        int[] resultArr = ArrayConvertion(testArr1);
        bool result = testArrConvetion(resultArr, expectedArr);
        if (result)
        {
            Console.WriteLine("Test passed");
        }
        else
        {
            Console.WriteLine("Test Failed");
        }

    }
}