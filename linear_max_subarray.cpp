/*
 * linear_max_subarray.cpp
 * RC
 */

#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::max;


int MaxSub(std::vector<int>A, int size);

int main(int argc, const char *argv[])
{
	//creates an int vector array-dynamic called a_vector
	std::vector<int> a_vector;
	
	if (argc != 2)
	{
		cout<<"Incorrect input!!";
	}
	
	//initialize the ifstream
	std::ifstream the_file(argv[1]);
	if (!the_file.is_open())
	{
		cout<<"Could not open file!!!\n";
	}
	int count = 0;
	int number;
	//sends every int in the_file to number
	while(the_file >> number)
	{
		//adds int input from the_file to a_vector
		a_vector.push_back(number);
		count++;
	}
	//cout<<the_file <<"\n";
	
	//runs MaxSub method on a w/ count as size
	cout << MaxSub(a_vector, count) << "\n";
	return 0;
}

//Method for finding max subarray
int MaxSub(std::vector<int>A, int size)
{
	int sub_count = A[0];
	int sub_max = A[0];
	int i;
	for(i=1; i < size; i++)		//6, -5, 8, 2, -1, 6		(16)
	{
		//the current sub count is always the greater of sum or current index
		sub_count = max(A[i], sub_count + A[i]);
		sub_max = max(sub_max, sub_count);
	}
	return sub_max;
}
