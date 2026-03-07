#include <iostream>
#include <random>

void bubble_sort(int* array, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void insertion_sort(int* array, size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        int key = array[i];
        size_t j = i;

        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = key;
    }
}

void selection_sort(int* array, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        size_t minIndex = i;

        for (size_t j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
                minIndex = j;
        }

        std::swap(array[i], array[minIndex]);
    }
}

void quick_sort_internal(int* array, int left, int right)
{
    if (left >= right)
        return;

    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[right]);
    int pivotIndex = i + 1;

    quick_sort_internal(array, left, pivotIndex - 1);
    quick_sort_internal(array, pivotIndex + 1, right);
}

void quick_sort(int* array, size_t size)
{
    if (array == nullptr || size < 2)
        return;

    quick_sort_internal(array, 0, static_cast<int>(size - 1));
}

void print_array(int* arr, size_t size)
{
    std::cout << "[";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];

        if (i < size - 1)
            std::cout << ", ";
    }

    std::cout << "]" << std::endl;
}

void fill_with_random(int* arr, size_t size, int min, int max)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(min, max);

    for (int i = 0; i < size; i++)
    {
        arr[i] = dist(gen);
    }
}

int main()
{
    size_t size = 11;
    int* nums = new int[size];

    fill_with_random(nums, size, 0, 100);
    print_array(nums, size);
    //bubble_sort(nums, size);
    //insertion_sort(nums, size);    
    //selection_sort(nums, size);    
    quick_sort(nums, size);    
    print_array(nums, size);

    delete[] nums;
}
