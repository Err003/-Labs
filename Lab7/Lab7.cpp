#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
std::vector<std::tuple<int, int, char>> Zip(const std::string& text, int size = 256, int backSize = 15)
{
	std::vector<std::tuple<int, int, char>> zipped;
	int n = text.length();
	int i = 0;
	while (i < n)
	{
		int maxLength = 0;
		int distance = 0;
		int start = std::max(0, i - size);
		int startBack = i;
		for (int j = start; j < startBack; ++j)
		{
			int length = 0;
			while (length < backSize &&
				i + length < n &&
				text[j + length] == text[i + length])
				++length;
			if (length > maxLength)
			{
				maxLength = length;
				distance = i - j;
			}
		}
		if (maxLength > 0)
		{
			zipped.push_back(std::make_tuple(distance, maxLength, '\0'));
			i += maxLength;
		}
		else
		{
			zipped.push_back(std::make_tuple(0, 0, text[i]));
			i += 1;
		}
	}
	return zipped;
}
std::string Unzip(const std::vector<std::tuple<int, int, char>>& zipped)
{
	std::string unzipped;
	for (const auto& item : zipped)
	{
		int distance;
		int length;
		char literal;
		std::tie(distance, length, literal) = item;
		if (length > 0)
		{
			int startIdx = unzipped.size() - distance;
			for (int i = 0; i < length; ++i)
				unzipped.push_back(unzipped[startIdx + i]);
		}
		else
			unzipped.push_back(literal);
	}
	return unzipped;
}
void Print(const std::vector<std::tuple<int, int, char>>& zipped)
{
	for (const auto& item : zipped)
	{
		int distance, length;
		char literal;
		std::tie(distance, length, literal) = item;
		if (length > 0)
			std::cout << "(" << distance << ", " << length << ") ";
		else
			std::cout << "'" << literal << "' ";
	}
	std::cout << std::endl;
}
int main()
{
	std::string input;
	std::cout << "Enter text: ";
	std::cin >> input;
	std::vector<std::tuple<int, int, char>> zipped = Zip(input);
	std::cout << "Zipped data: ";
	Print(zipped);
	std::string unzipped = Unzip(zipped);
	std::cout << "Unzipped data: " << unzipped << std::endl;
	return 0;
}