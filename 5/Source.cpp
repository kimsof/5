#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <random>
#include <ctime> 
#include <numeric>

bool simple(int n) 
{
	if (n == 1)	return false;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0) return false;
	}
	return true;
}

bool for_range(int n)
{
	return n > 1;
}

int main()
{
	/*1*/
	std::vector<int> sequence1 = {1,2,3,4,5,6,7,8,9,10};

	/*2*/
	std::copy(std::istream_iterator<int>(std::cin),
	std::istream_iterator<int>(),
	std::back_inserter(sequence1));
	
	/*3*/
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(sequence1.begin(), sequence1.end(), g);

	/*4*/
	std::sort(sequence1.begin(), sequence1.end());
	sequence1.erase(std::unique(sequence1.begin(), sequence1.end()), sequence1.end());

	/*5*/
	int odd_numbers = std::count_if(sequence1.begin(),
		sequence1.end(), [](int i) {return i % 2 == 1; });

	/*6*/
	int min = *std::min_element(sequence1.begin(), sequence1.end());
	int max = *std::max_element(sequence1.begin(), sequence1.end());

	/*7*/
	auto pos1 = std::find_if(sequence1.begin(), sequence1.end(), simple);
	int simp = sequence1[*pos1];

	/*8*/
	std::transform(sequence1.cbegin(), sequence1.cend(), 
		sequence1.begin(),
		[](int elem) {
		return elem * elem;
		}); 

	/*9*/
	std::vector<int> sequence2;
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> uid(0, 100);
		for (int i = 0; i < sequence1.size(); i++) {
			sequence2.push_back(uid(gen));
		}

	/*10*/
	int sum = std::accumulate(sequence2.cbegin(), sequence2.cend(), 0);

	/*11*/
	std::transform(sequence2.cbegin(), sequence2.cend() - 10,
		sequence2.begin(),
		[](int elem) {
		return 1;
	});

	/*12*/
	std::vector<int> sequence3;
	sequence3.reserve(sequence1.size());
	std::transform(sequence1.cbegin(), sequence1.cend(),
		sequence2.begin(), std::back_inserter(sequence3),
		[](auto elem1, auto elem2) {
			return elem1 - elem2;
	});
	
	/*13*/
	std::transform(sequence3.cbegin(), sequence3.cend(),
		sequence3.begin(),
		[](int elem ) {
		if (elem < 0) return 0;
		else return elem;
	});

	/*14*/
	sequence3.erase(std::remove(sequence3.begin(), sequence3.end(), 0), sequence3.end());

	/*15*/
	std::reverse(sequence3.begin(), sequence3.end());

	/*16*/
	std::nth_element(sequence3.begin(),   
		sequence3.end() - 3,    
		sequence3.end());

	/*17*/
	std::sort(sequence1.begin(), sequence1.end());
	std::sort(sequence2.begin(), sequence2.end());

	/*18*/
	std::vector<int> sequence4;
	std::merge(sequence1.begin(), sequence1.end(), sequence2.begin(), sequence2.end(), std::back_inserter(sequence4));

	/*19*/
	int a = count(sequence4.begin(), sequence4.end(), 0);
	int b = count(sequence4.begin(), sequence4.end(), 1);

	/*20*/
	std::cout << "sequence1:" << std::endl;
	std::copy(sequence1.cbegin(), sequence1.cend(),
	std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	std::cout << "sequence2:" << std::endl;
	std::copy(sequence2.cbegin(), sequence2.cend(),
	std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	std::cout << "sequence3:" << std::endl;
	std::copy(sequence3.cbegin(), sequence3.cend(),
	std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	std::cout << "sequence4:" << std::endl;
	std::copy(sequence4.cbegin(), sequence4.cend(),
	std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	std::cout << "There are " << odd_numbers << " odd numbers in sequence1." << std::endl;
	std::cout << "Minimum and maximum were " << min << " and " << max << " respectively in sequence1." << std::endl;
	std::cout << "One of prime numbers is " << simp << " in sequence1." << std::endl;
	std::cout << "The sum was " << sum << " in sequence2." << std::endl;
	std::cout << "The sum was " << sum << " in sequence2." << std::endl;
	std::cout << "Possible values for 1's indices are from " << a << " to " << a + b - 1 << " in sequence4." << std::endl;

	system("pause");
	return 0;
}