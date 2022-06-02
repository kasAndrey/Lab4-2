#include "Class.h"
#include <iostream>

using namespace std;

int main()
{
	Map<char, int> MyMap;
	char letter;
	int different_letter = 0;
	string text = "";

	cout << "Enter text to encode it by ShannonFano algorithm\nInput finish after 'Enter' press\n\n";

	while (cin.get(letter)) {
		if (letter == '\n') break;
		text += letter;
		if (MyMap.contains(letter)) {
			MyMap.find(letter)->value++;
		}
		else {
			MyMap.insert(letter, 1);
			different_letter++;
		}
	}

	ShannonFano_Coder My(MyMap, different_letter, text);

	cout << "\nText characters frequency table\n\n";
	My.print_frequency_table();

	My.ShannonFano_encoding(0, different_letter - 1);
	cout << "\nCodes table\n";
	My.print_code_table();
	cout << "\nOriginal text takes up " << My.original_text_size() << " bits\n\n";
	cout << "Encoded text takes up " << My.encoded_text_size() << " bits\n\n";
	cout << "Compression ratio is " << My.compression_ratio() << "\n\n";
	cout << "Print encoded text:\n";
	My.print_encoded_text();
	cout << "\n\nFinally, print decoded text:\n";
	My.print_decoded_text();
	cout << "\n\n";

}
