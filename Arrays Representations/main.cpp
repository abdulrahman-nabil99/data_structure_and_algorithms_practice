#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>

using namespace std;
template<class T>
class List {
private:
    T* _items;
    long int _index = 0;
    long int _size = 1;
    void resize(int size) {
        T* newItems = new T[size];
        for (int i = 0; i < _index; i++) {
            newItems[i] = _items[i];
        }
        delete[] _items;
        _size = size;
        _items = newItems;
    }
    void resize_if_need() {
        if (_index == _size) {
            int newSize = _size * 2;
            resize(newSize);
        }
    }
public:
    List() {
        _items = new T[_size];
    }
    List(int size) {
        _size = size;
        _items = new T[size];
    }
    ~List() {
        delete[] _items;
    }
    void merge(List<T>& right) {
        int newLenght = _index + right.count();
        T* tempItems = new T[newLenght];
        int i = 0, j = 0, k = 0;
        while (i < _index && j < right.count()) {
            tempItems[k++] = (_items[i] <= right.get(j)) ? _items[i++] : right.get(j++);
        }
        while (i < _index) {
            tempItems[k++] = _items[i++];
        }

        while (j < right.count()) {
            tempItems[k++] = right.get(j++);
        }

        delete[] _items;
        _items = tempItems;
        _index = newLenght;
        _size = newLenght * 2;
    }
    List<T> intersect(List<T>& right) {
        List<T> result;
        for (int i = 0; i < _index; i++) {
            T item = _items[i];

            if (right.contains(item) && !result.contains(item)) {
                result.add(item);
            }
        }
        return result;
    }
    List<T> set_union(List<T>& right) {
        List<T> result;
        for (int i = 0; i < _index; i++) {
            if (!result.contains(_items[i])) {
                result.add(_items[i]);
            }
        }
        for (int i = 0; i < right.count(); i++) {
            T item = right.get(i);
            if (!result.contains(item)) {
                result.add(item);
            }
        }
        return result;
    }
    List<T> difference(List<T>& right) {
        List<T> result;

        for (int i = 0; i < _index; i++) {
            T item = _items[i];

            if (!right.contains(item)) {
                result.add(item);
            }
        }
        return result;
    }
    int insert_at(int index, T item) {
        if (index < 0) {
            return -1;
        }
        resize_if_need();
        if (index >= _index) {
            _items[_index] = item;
        }
        else {
            for (int i = _index; i > index; i--) {
                _items[i] = _items[i - 1];
            }
            _items[index] = item;
        }
        _index++;
        return _index - 1;
    }
    int delete_at(int index) {
        if (index < 0 || index >= _index) {
            return -1;
        }
        for (int i = index; i < _index-1; i++)
        {
            _items[i] = _items[i + 1];
        }
        _index--;
        _items[_index] = 0;
        return _index - 1;
    }
    int add(T item) {
        resize_if_need();
        _items[_index] = item;
        _index++;
        return _index - 1;
    }
    T get(int index) {
        if (index >= _index || index < 0) {
            return -1;
        }
        return _items[index];
    }
    bool contains(T item) const {
        for (int i = 0; i < _index; i++) {
            if (_items[i] == item)
                return true;
        }
        return false;
    }
    int set(int index, T item) {
        if (index >= _index || index < 0) {
            return -1;
        }
        _items[index] = item;
        return _index;
    }
    int un_shift(T item) {
        insert_at(0, item);
    }
    int count() {
        return _index;
    }
    bool is_sorted() {
        for (int i = 0; i < _size - 1; i++) {
            if (_items[i] > _items[i + 1])
                return false;
        }
        return true;
    }
    int search(T element) {
        for (int i = 0; i < _index; i++) {
            if (element == _items[i]) {
                return i;
            }
        }
        return -1;
    }
    int b_search(T element) {
        if (_index == 0) {
            return -1;
        }
        int low = 0;
        int high = _index - 1;        
        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (_items[mid] == element) {
                return mid;
            }
            high = _items[mid] > element ? mid - 1 : high;
            low = _items[mid] > element ? low : mid + 1;
        }
        return -1;
    }
    void reverse() {
        int l = 0, r = _index -1;
        while (r > l) {
            T carry = _items[r];
            _items[r] = _items[l];
            _items[l] = carry;
            l++;
            r--;
        }
    }
    void print() {
        cout << "(";
        for (int i = 0; i < _index; i++) {
            cout << _items[i];
            if (i != _index - 1) {
                cout << ",";
            }
        }
        cout << ")" << endl;
    }
};

int main() {
	int** dArray = new int* [4];
	for (int i = 0; i < 4;i++) {
		dArray[i] = new int[4];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dArray[i][j] = i + j;
			cout << dArray[i][j] << (j == 3 ? "" : ", ");
		}
		cout << endl;
	}
	int nums[5] = { 1,2,3,4,5 };
	int* array = new int[5] {6,7,8,9,10};
	cout << "Numbers # Using n : nums" << endl;
	for (int n : nums) {
		cout << n << endl;
	}
	cout << "Array # Using basic for loop" << endl;
	for (int i = 0; i < 5; i++) {
		cout << array[i] << endl;
	}
	delete[] array;
	for (int i = 0; i < 4; i++) {
		delete[] dArray[i];
	}

    //List<int> numsList(1000);
    //numsList.add(1);
    //numsList.add(2);
    //numsList.add(3);
    //numsList.add(4);
    //numsList.add(5);
    //numsList.add(6);
    //numsList.insert_at(2, 54);
    //numsList.delete_at(2);
    //cout << numsList.count() << endl;
    //cout << numsList.search(54) << endl;
    //cout << numsList.search(55) << endl;
    //numsList.print();
    //auto start = std::chrono::high_resolution_clock::now();
    //cout << "Adding 20 items" << endl;
    //for (int i = 0; i < 20; i++) {
    //    numsList.add(i);
    //}
    //numsList.print();
    //numsList.reverse();
    //numsList.print();
    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> elapsed = end - start;
    //auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    //cout << "finshed adding in "<< us.count() << "us" << endl;
    //cout << "finshed adding in "<< ms.count() << "ms" << endl;
    //cout << "search starting" << endl;
    //start = std::chrono::high_resolution_clock::now();
    //cout << "found the index of the item at index " << numsList.b_search(300) << endl;
    //end = std::chrono::high_resolution_clock::now();
    //elapsed = end - start;
    //us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    //cout << "found the index in "<< us.count() << "us" << endl;
    //cout << "found the index in "<< ms.count() << "ms" << endl;
    List<int> numsList1(5);
    numsList1.add(1);
    numsList1.add(4);
    numsList1.add(7);
    numsList1.add(9);
    numsList1.add(10);
    List<int> numsList2(5);
    numsList2.add(2);
    numsList2.add(3);
    numsList2.add(5);
    numsList2.add(6);
    numsList2.add(7);
    numsList1.merge(numsList2);
    numsList1.print();
	return 0;
}