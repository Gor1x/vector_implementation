#include <iostream>

struct MyVector
{
	int* arr;
	size_t capacity;
	size_t size;

	MyVector()
	{
		capacity = 2;
		size = 0;
		arr = (int*)malloc(capacity * sizeof(int));
	}

	MyVector(const size_t init_capacity)
	{
		capacity = init_capacity;
		size = 0;
		arr = (int*)malloc(capacity * sizeof(int));
	}

	~MyVector()
	{
		free(arr);
	}

	void reserve(const int new_capacity)
	{
		int* new_array = (int*)malloc(new_capacity * sizeof(int));
		memcpy(new_array, arr, capacity * sizeof(int));

		capacity = new_capacity;
		free(arr);

		arr = new_array;
	}

	void push_back(const int value)
	{
		if (size == capacity)
		{
			reserve(capacity * 2);
		}
		arr[size++] = value;
	}

	void set(const size_t i, const int value)
	{
		arr[i] = value;
	}

	int get(const size_t i)const
	{
		return arr[i];
	}

	size_t size()const
	{
		return size;
	}

	size_t capacity()const
	{
		return capacity;
	}

	void insert(const size_t index, const int value)
	{
		if (size == capacity)
		{
			reserve(capacity * 2);
		}
		size++;
		for (int i = size; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
	}

	void erase(const size_t index)
	{
		for (int i = index; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}

	void resize(size_t new_size)
	{
		if (new_size > capacity)
		{
			if (capacity * 2 > new_size)
				new_size = capacity * 2;
			reserve(new_size);
			size = new_size;
		}
		else //new_size <= capacity
		{
			size = new_size;
		}
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
