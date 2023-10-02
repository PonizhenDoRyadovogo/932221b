#include<iostream>
#include<vector>

int BoyerMoorSearch(std::string text, std::string sample)
{
	int l_text = text.length();
	int l_sample = sample.length();
	int TAB[256];
	int i, j, k = 0;
	for (i = 0; i < l_text; i++) TAB[text[i]] = l_sample;
	for (j = 0; j < l_sample - 1; j++) TAB[sample[j]] = l_sample - 1 - j;

	for (i = l_sample - 1, j = l_sample - 1; i <= l_text;i = k + TAB[text[k]])
	{
		for (k = i, j = l_sample - 1; j >= 0 && text[k] == sample[j]; )
		{
			k--;
			j--;
		}
		if (j < 0)
			return k + 1;
		if (k >= l_text)
			return -1;
	}
	if (i >= l_text && j < 0)
		return k + 1;
	else return -1;
}

std::vector<int> BoyerMoorSearchInRange(std::string text, std::string sample, int start, int end)
{
	std::vector<int> Entrance;
	int	entrance;
	int l_text = end;
	int l_sample = sample.length();
	int TAB[256];
	int i, j, k = 0;
	for (i = start; i < l_text; i++) TAB[text[i]] = l_sample;
	for (j = 0; j < l_sample - 1; j++) TAB[sample[j]] = l_sample - 1 - j;

	for (i = start + l_sample - 1, j = l_sample - 1; i <= l_text;i = k + TAB[text[k]])
	{
		for (k = i, j = l_sample - 1; j >= 0 && text[k] == sample[j]; )
		{
			k--;
			j--;
		}
		if (j < 0)
		{
			entrance = k + 1;
			break;
		}
		if (k >= l_text)
		{
			entrance = -1;
			break;
		}
	}
	if (j < 0)
		entrance = k + 1;
	else entrance = -1;

	if (entrance < 0)
		return Entrance;
	while (entrance > 0)
	{
		Entrance.push_back(entrance);
		start = entrance + 1;
		int l_text = end;
		int l_sample = sample.length();
		int TAB[256];
		int i, j, k = 0;
		for (i = start; i < l_text; i++) TAB[text[i]] = l_sample;
		for (j = 0; j < l_sample - 1; j++) TAB[sample[j]] = l_sample - 1 - j;

		for (i = start + l_sample - 1, j = l_sample - 1; i <= l_text;i = k + TAB[text[k]])
		{
			for (k = i, j = l_sample - 1; j >= 0 && text[k] == sample[j]; )
			{
				k--;
				j--;
			}
			if (j < 0)
			{
				entrance = k + 1;
				break;
			}
			if (k >= l_text)
			{
				entrance = -1;
				break;
			}
		}
		if (j < 0)
			entrance = k + 1;
		else entrance = -1;
	}
	return Entrance;
}

std::vector<int> BoyerMoorSearchAll(std::string text, std::string sample)
{
	return BoyerMoorSearchInRange(text, sample, 0, text.length());
}
int main()
{
	std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator", sample = "tor";
	std::cout << "Text: " << text << "\nSample : " << sample << std::endl;

	int first_entrance = BoyerMoorSearch(text, sample);
	if (first_entrance < 0)
		std::cout << "No entrance." << std::endl;
	else
		std::cout << "Index of first entrance: " << first_entrance << std::endl;

	int start, end;
	std::cout << "Please, enter beginning of the range: ";
	std::cin >> start;
	std::cout << "Please, enter ending of the range: ";
	std::cin >> end;

	std::vector<int> Entrance = BoyerMoorSearchInRange(text, sample, start, end);
	if (Entrance.size() == 0)
		std::cout << "No entrance in range(" << start << ";" << end << ")." << std::endl;
	else
	{
		std::cout << "Indexes of all entrance in range(" << start << ";" << end << "): ";
		for (int elem : Entrance)
			std::cout << elem << " ";
		std::cout << "\n";
	}

	Entrance = BoyerMoorSearchAll(text, sample);
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

	Entrance = BoyerMoorSearchInRange(text, sample, start, end);
	if (Entrance.size() == 0)
		std::cout << "No entrance in range(" << start << ";" << end << ")." << std::endl;
	else
	{
		std::cout << "Indexes of all entrance in range(" << start << ";" << end << "): ";
		for (int elem : Entrance)
			std::cout << elem << " ";
		std::cout << "\n";
	}
}