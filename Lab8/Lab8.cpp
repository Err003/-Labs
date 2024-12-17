#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
struct Node
{
	char letter;
	int frequency;
	Node* left;
	Node* right;
	Node(char letter, int frequency)
	{
		this->letter = letter;
		this->frequency = frequency;
		left = nullptr;
		right = nullptr;
	}
	bool operator>(const Node& other) const
	{
		return frequency > other.frequency;
	}
};
static std::unordered_map<char, int> BuildTable(const std::string& text)
{
	std::unordered_map<char, int> frequency;
	for (char c : text)
		frequency[c]++;
	return frequency;
}
static Node* BuildTree(const std::unordered_map<char, int>& frequency)
{
	std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> minHeap;
	for (const auto& entry : frequency)
		minHeap.push(new Node(entry.first, entry.second));
	while (minHeap.size() > 1)
	{
		Node* left = minHeap.top();
		minHeap.pop();
		Node* right = minHeap.top();
		minHeap.pop();
		Node* merged = new Node('\0', left->frequency + right->frequency);
		merged->left = left;
		merged->right = right;
		minHeap.push(merged);
	}
	return minHeap.top();
}
static void GenerateCodes(Node* root, const std::string& code, std::unordered_map<char, std::string>& huffmanCodes)
{
	if (!root) return;
	if (root->letter != '\0')
		huffmanCodes[root->letter] = code;
	GenerateCodes(root->left, code + "0", huffmanCodes);
	GenerateCodes(root->right, code + "1", huffmanCodes);
}
static std::string Encode(const std::string& text, const std::unordered_map<char, std::string>& huffmanCodes)
{
	std::string encodedText;
	for (char c : text)
		encodedText += huffmanCodes.at(c);
	return encodedText;
}
std::string Decode(const std::string& encodedText, Node* root)
{
	std::string decodedText;
	Node* currentNode = root;
	for (char bit : encodedText)
	{
		if (bit == '0')
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
		if (currentNode->letter != '\0')
		{
			decodedText += currentNode->letter;
			currentNode = root;
		}
	}
	return decodedText;
}
int main()
{
	std::string text;
	std::cin >> text;
	std::unordered_map<char, int> frequency = BuildTable(text);
	Node* root = BuildTree(frequency);
	std::unordered_map<char, std::string> huffmanCodes;
	GenerateCodes(root, "", huffmanCodes);
	std::cout << "Huffman Codes:\n";
	for (const auto& pair : huffmanCodes)
		std::cout << pair.first << ": " << pair.second << std::endl;
	std::string encodedText = Encode(text, huffmanCodes);
	std::cout << "\nEncoded Text: " << encodedText << std::endl;
	std::string decodedText = Decode(encodedText, root);
	std::cout << "\nDecoded Text: " << decodedText << std::endl;
	return 0;
}