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
    size_t size = 20;
    int* nums = new int[size];

    fill_with_random(nums, size, 0, 9999);
    print_array(nums, size);
    bubble_sort(nums, size);
    print_array(nums, size);


    delete[] nums;

}
