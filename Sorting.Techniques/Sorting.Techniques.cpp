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

void merge(int* array, int* temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = left;

    while (i < mid && j < right)
        temp[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];

    while (i < mid)   temp[k++] = array[i++];
    while (j < right) temp[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = temp[i];
}


void i_merge_sort(int* array, size_t size)
{
    if (size < 2)
        return;

    int* temp = new int[size];

    for (size_t width = 1; width < size; width *= 2)
    {
        for (size_t i = 0; i < size; i += 2 * width)
        {
            size_t left = i;
            size_t mid = i + width;
            size_t right = i + 2 * width;

            if (mid > size)
                mid = size;

            if (right > size)
                right = size;

            merge(array, temp, left, mid, right);
        }
    }

    delete[] temp;
}

void r_merge_sort(int* array, int* temp, size_t low, size_t high)
{
    if (high - low < 2) return;

    size_t mid = low + (high - low) / 2;

    r_merge_sort(array, temp, low, mid);
    r_merge_sort(array, temp, mid, high);
    merge(array, temp, low, mid, high);
}

void count_sort(int* array, size_t size) {
    if (size == 0) return;

    // Find min and max values
    int min = array[0], max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] < min) min = array[i];
        if (array[i] > max) max = array[i];
    }

    // Allocate and zero-initialize count array
    size_t range = max - min + 1;
    int* count = new int[range]();

    // Count occurrences
    for (size_t i = 0; i < size; i++)
        count[array[i] - min]++;

    // Reconstruct sorted array
    size_t idx = 0;
    for (size_t i = 0; i < range; i++)
        while (count[i]-- > 0)
            array[idx++] = i + min;

    delete[] count;
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
    //quick_sort(nums, size);
    
    //i_merge_sort(nums, size);
    //int* temp = new int[size];
    //r_merge_sort(nums, temp, 0, size);
    //delete[] temp;

    count_sort(nums, size);
    print_array(nums, size);

    delete[] nums;
}
