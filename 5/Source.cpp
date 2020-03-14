#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <random>
#include <ctime> 
#include <numeric>

int main()
{

	std::vector<int> sequence1 = {1,2,3,4,5,6,7,8,9,10};


	std::copy(std::istream_iterator<int>(std::cin),
	std::istream_iterator<int>(),
	std::back_inserter(sequence1));


	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(sequence1.begin(), sequence1.end(), g);


	std::copy(sequence1.cbegin(), sequence1.cend(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";


	std::sort(sequence1.begin(), sequence1.end());
	auto pos = std::unique(sequence1.begin(), sequence1.end());
	sequence1.erase(pos, sequence1.end());


	int odd_numbers = std::count_if(sequence1.begin(),
		sequence1.end(), [](int i) {return i % 2 == 1; });


	int min = *std::min_element(sequence1.begin(), sequence1.end());
	int max = *std::max_element(sequence1.begin(), sequence1.end());


	std::transform(sequence1.cbegin(), sequence1.cend(), 
		sequence1.begin(),
		[](int elem) {
		return elem * elem;
		});


	std::vector<int> sequence2;
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> uid(0, 100);
		for (int i = 0; i < sequence1.size(); i++) {
			sequence2.push_back(uid(gen));
	}

		int sum = std::accumulate(sequence2.cbegin(), sequence2.cend(), 0);



	




	//std::copy(sequence1.cbegin(), sequence1.cend(),           
	//std::ostream_iterator<int>(std::cout, "   "));
		for (int i = 0; i < sequence1.size(); i++) {
			std::cout << sequence1[i] << " ";
		}
		std::cout << "\n";
		for (int i = 0; i < sequence2.size(); i++) {
			std::cout << sequence2[i] << " ";
		}
		std::cout << "\n";
	std::cout << "\n" << odd_numbers << min << max << sum << std::endl;
	system("pause");
	return 0;
}