#include<iostream>
#include<vector>

int* MakeTable(std::string text, std::string sample)
{
	int l_text = text.length();
	int l_sample = sample.length();
	int* TAB = new int[256];
	int i, j, k = 0;
	for (i = 0; i < l_text; i++) TAB[text[i]] = l_sample;
	for (j = 0; j < l_sample - 1; j++) TAB[sample[j]] = l_sample - 1 - j;
	return TAB;
}
int BoyerMoorSearch(std::string text, std::string sample,int *TAB ,int start = 0, int end = -1)
{
	if (end == -1)
		end = text.length();
	int l_sample = sample.length();
	int i, j, k = 0;
	for (i = start + l_sample - 1, j = l_sample - 1; i <= end;i = k + TAB[text[k]])
	{
		for (k = i, j = l_sample - 1; j >= 0 && text[k] == sample[j]; )
		{
			k--;
			j--;
		}
		if (j < 0)
			return k + 1;
		if (k >= end)
			return -1;
	}
	if (i >= end && j < 0)
		return k + 1;
	else return -1;
}

std::vector<int> BoyerMoorSearchInRange(std::string text, std::string sample, int *TAB ,int start, int end)
{
	std::vector<int> Entrance;
	int	entrance = BoyerMoorSearch(text, sample, TAB ,start, end);
	if (entrance < 0)
		return Entrance;
	while (entrance >= 0)
	{
		Entrance.push_back(entrance);
		start = entrance + 1;
		entrance = BoyerMoorSearch(text, sample, TAB,start, end);
	}
	return Entrance;
}

std::vector<int> BoyerMoorSearchAll(std::string text, std::string sample, int *TAB)
{
	return BoyerMoorSearchInRange(text, sample, TAB,0, text.length());
}
int main()
{
	std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator", sample = "tor";
	std::cout << "Text: " << text << "\nSample : " << sample << std::endl;
	int* TAB = MakeTable(text, sample);
	int first_entrance = BoyerMoorSearch(text, sample, TAB);
	if (first_entrance < 0)
		std::cout << "No entrance." << std::endl;
	else
		std::cout << "Index of first entrance: " << first_entrance << std::endl;

	int start, end;
	std::cout << "Please, enter beginning of the range: ";
	std::cin >> start;
	std::cout << "Please, enter ending of the range: ";
	std::cin >> end;

	std::vector<int> Entrance = BoyerMoorSearchInRange(text, sample, TAB ,start, end);
	if (Entrance.size() == 0)
		std::cout << "No entrance in range(" << start << ";" << end << ")." << std::endl;
	else
	{
		std::cout << "Indexes of all entrance in range(" << start << ";" << end << "): ";
		for (int elem : Entrance)
			std::cout << elem << " ";
		std::cout << "\n";
	}

	Entrance = BoyerMoorSearchAll(text, sample, TAB);
	if (Entrance.size() == 0)
		std::cout << "No entrance in all text." << std::endl;
	else
	{
		std::cout << "Indexes of all entrance: ";
		for (int elem : Entrance)
			std::cout << elem << " ";
		std::cout << "\n";
	}

	std::cout << "Please, enter beginning of the range: ";
	std::cin >> start;
	std::cout << "Please, enter ending of the range: ";
	std::cin >> end;

	Entrance = BoyerMoorSearchInRange(text, sample, TAB , start, end);
	if (Entrance.size() == 0)
		std::cout << "No entrance in range(" << start << ";" << end << ")." << std::endl;
	else
	{
		std::cout << "Indexes of all entrance in range(" << start << ";" << end << "): ";
		for (int elem : Entrance)
			std::cout << elem << " ";
		std::cout << "\n";
	}
	delete[] TAB;
}