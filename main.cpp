#include <iostream>
using namespace std;


void print_array(int* array, int e);
void quick_sort(int* array, int start_index, int end_index);
int split_array(int* array, int pivot_value, int start_index, int end_index);
void swap(int &a, int &b);


int main(void)
{
	unsigned int i,x;

    cout<<"      //  Simple QuickSort using C++ //\n\n";
    cout<<"|| 1st. Determine the number of integers to be sorted"<<endl;
    cout<<"|| 2nd. Enter integers to be sorted"<<endl;
    cout<<"|| 3rd. Press enter to quit program\n"<<endl;

    cin>>x;

    int array[x];

	for( i = 0; i < x; i++)
	{
		 cout<<"Enter an integer : ";
		 cin>>array[i];
	}

	cout<<endl<<"Initial order: "<<endl;
	print_array(array, x);
	quick_sort(array,0,x - 1);
	cout<<endl<<"After QuickSort: "<<endl;
	print_array(array, x);

	cin.get();
	cin.get();

	return 0;
}

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void print_array(int* array, int n)
{
	int i;

	for( i = 0; i < n; i++) cout<<array[i]<<'\t';
}

void quick_sort(int* array, int start_index, int end_index)
{
	int pivot = array[start_index];
	int split_point;

	if(end_index > start_index)


	{
		split_point = split_array(array, pivot, start_index, end_index);


		array[split_point] = pivot;
		quick_sort(array, start_index, split_point-1);
		quick_sort(array, split_point+1, end_index);
	}
}


int split_array(int* array, int pivot, int start_index, int end_index)
{
	int left_limit = start_index;
	int right_limit = end_index;

	while(left_limit < right_limit)
	{
		 while( pivot < array[right_limit]
				&& right_limit > left_limit)
		 {
			  right_limit--;
		 }
		 swap(array[left_limit], array[right_limit]);

		 while( pivot >= array[left_limit]
				&& left_limit < right_limit)
		 {
			  left_limit++;
		 }
		 swap(array[right_limit], array[left_limit]);

	}
	return left_limit;

}
