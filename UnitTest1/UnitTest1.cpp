#include "pch.h"
#include "CppUnitTest.h"
#include "../Class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(ConsrtructorStackTest)
		{
			stack<int> MyStack;
			Assert::IsTrue(MyStack.size() == 0);
		}
		TEST_METHOD(DesrtructorStackTest)
		{
			stack<int> MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.~stack();
			Assert::IsTrue(MyStack.size() == 0);
		}
		TEST_METHOD(PushStackTest)
		{
			stack<int> MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.top() == 3);
			MyStack.push(7);
			Assert::IsTrue(MyStack.top() == 7);
		}
		TEST_METHOD(PopStackTest)
		{
			stack<int> MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.push(7);
			Assert::IsTrue(MyStack.size() == 2);
			MyStack.pop();
			Assert::IsTrue(MyStack.size() == 1);
		}
		TEST_METHOD(TopStackTest)
		{
			stack<int> MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.top() == 3);

			MyStack.push(7);
			Assert::IsTrue(MyStack.top() == 7);
			MyStack.pop();
			Assert::IsTrue(MyStack.top() == 3);
		}
		TEST_METHOD(SizeStackTest)
		{
			stack<int> MyStack;
			Assert::IsTrue(MyStack.size() == 0);
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.push(7);
			Assert::IsTrue(MyStack.size() == 2);
			MyStack.pop();
			Assert::IsTrue(MyStack.size() == 1);
		}
		TEST_METHOD(EmptyStackTest)
		{
			stack<int> MyStack;
			Assert::IsTrue(MyStack.empty() == 1);
			MyStack.push(3);
			Assert::IsTrue(MyStack.empty() == 0);
			MyStack.push(7);
			Assert::IsTrue(MyStack.empty() == 0);
			MyStack.pop();
			Assert::IsTrue(MyStack.empty() == 0);
		}
		TEST_METHOD(ConsrtructorLinkedListTest)
		{
			List<int> My_List;
			Assert::IsTrue(My_List.size() == 0);
		}
		TEST_METHOD(DesrtructorLinkedListTest)
		{
			List<int> My_List;
			Assert::IsTrue(My_List.size() == 0);
			My_List.insert_node(17);
			Assert::IsTrue(My_List.size() == 1);
			My_List.~My_List();
			Assert::IsTrue(My_List.size() == 0);

		}
		TEST_METHOD(InsertNodeLinkedListTest)
		{
			List<int> My_List;
			My_List.insert_node(17);
			Assert::IsTrue(My_List.get_head() == 17);
			My_List.insert_node(7);
			My_List.set_next();
			Assert::IsTrue(My_List.get_head() == 7);
		}
		TEST_METHOD(SetNextLinkedListTest)
		{
			List<int> My_List;
			My_List.insert_node(17);
			Assert::IsTrue(My_List.get_head() == 17);
			try {
				My_List.set_next();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not next element", error.what());
			}
		}
		TEST_METHOD(SizeLinkedListTest)
		{
			List<int> MyLinked_list;
			Assert::IsTrue(MyLinked_list.size() == 0);
			MyLinked_list.insert_node(17);
			Assert::IsTrue(MyLinked_list.size() == 1);
			MyLinked_list.insert_node(7);
			Assert::IsTrue(MyLinked_list.size() == 2);
		}
		TEST_METHOD(DeleteNodeLinkedListTest) {
			List<int> My_List;
			Assert::IsTrue(My_List.size() == 0);
			My_List.insert_node(17);
			Assert::IsTrue(My_List.size() == 1);
			My_List.~List();
			Assert::IsTrue(My_List.size() == 0);
		}
		TEST_METHOD(InsertCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(1, 1);
			Assert::IsTrue(MyMap.find(1)->color == 0);
			MyMap.insert(3, 3);
			Assert::IsTrue(MyMap.find(1)->color == 0);
			Assert::IsTrue(MyMap.find(3)->color == 1);
			MyMap.insert(5, 5);
			Assert::IsTrue(MyMap.find(3)->color == 0);
			Assert::IsTrue(MyMap.find(1)->color == 1);
			Assert::IsTrue(MyMap.find(5)->color == 1);
			MyMap.insert(7, 7);
			Assert::IsTrue(MyMap.find(3)->color == 0);
			Assert::IsTrue(MyMap.find(1)->color == 0);
			Assert::IsTrue(MyMap.find(5)->color == 0);
			Assert::IsTrue(MyMap.find(7)->color == 1);
		}
		TEST_METHOD(ContainsCustomMapTest) {
			Map<int, char> MyMap;
			MyMap.insert(1, 'a');
			Assert::IsTrue(MyMap.contains(1) == 1);
			MyMap.insert(3, 'b');
			Assert::IsTrue(MyMap.contains(1) == 1);
			Assert::IsTrue(MyMap.contains(3) == 1);
			MyMap.insert(5, 'c');
			Assert::IsTrue(MyMap.contains(1) == 1);
			Assert::IsTrue(MyMap.contains(3) == 1);
			Assert::IsTrue(MyMap.contains(5) == 1);
			Assert::IsTrue(MyMap.contains(7) == 0);
			MyMap.insert(7, 'd');
			Assert::IsTrue(MyMap.contains(1) == 1);
			Assert::IsTrue(MyMap.contains(3) == 1);
			Assert::IsTrue(MyMap.contains(5) == 1);
			Assert::IsTrue(MyMap.contains(7) == 1);
			MyMap.remove(5);
			Assert::IsTrue(MyMap.contains(5) == 0);
		}
		TEST_METHOD(GetKeysCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(13, 31);
			MyMap.insert(8, 18);
			MyMap.insert(17, 71);
			List<int> hello = MyMap.get_keys();
			Assert::IsTrue(hello.get_head() == 13);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 8);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 17);
		}
		TEST_METHOD(GetValuesCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(13, 31);
			MyMap.insert(8, 18);
			MyMap.insert(17, 71);
			List<int> hello = MyMap.get_values();
			Assert::IsTrue(hello.get_head() == 31);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 18);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 71);
		}
		TEST_METHOD(MovingCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(90, 1);
			MyMap.insert(101, 2);
			MyMap.insert(15, 3);
			Assert::IsTrue(MyMap.find(90)->left->key == 15);
			Assert::IsTrue(MyMap.find(15)->right->key == 0);
			MyMap.remove(15);
			Assert::IsTrue(MyMap.find(90)->left->key == 0);
		}
		TEST_METHOD(LeftRotateCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(93, 1);
			MyMap.insert(100, 2);
			MyMap.insert(15, 3);
			MyMap.insert(17, 4);
			MyMap.insert(30, 5);
			Assert::IsTrue(MyMap.find(17)->color == 0);
			Assert::IsTrue(MyMap.find(30)->color == 1);
			MyMap.insert(42, 6);
			Assert::IsTrue(MyMap.find(17)->color == 1);
			Assert::IsTrue(MyMap.find(30)->color == 0);
			Assert::IsTrue(MyMap.find(42)->color == 1);
		}
		TEST_METHOD(RightRotateCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(93, 1);
			MyMap.insert(100, 2);
			MyMap.insert(15, 3);
			MyMap.insert(17, 4);
			MyMap.insert(30, 5);
			MyMap.insert(42, 6);
			Assert::IsTrue(MyMap.find(17)->color == 1);
			Assert::IsTrue(MyMap.find(30)->color == 0);
			Assert::IsTrue(MyMap.find(30)->right->key == 42);
			Assert::IsTrue(MyMap.find(42)->color == 1);
			MyMap.insert(40, 7);
			Assert::IsTrue(MyMap.find(30)->color == 1);
			Assert::IsTrue(MyMap.find(30)->right->key == 0);
			Assert::IsTrue(MyMap.find(40)->right->key == 42);
		}
		TEST_METHOD(FixAfterInsertCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(93, 1);
			MyMap.insert(100, 2);
			MyMap.insert(15, 3);
			Assert::IsTrue(MyMap.find(100)->color == 1);
			Assert::IsTrue(MyMap.find(15)->color == 1);
			MyMap.insert(17, 4);
			Assert::IsTrue(MyMap.find(100)->color == 0);
			Assert::IsTrue(MyMap.find(15)->color == 0);
			Assert::IsTrue(MyMap.find(17)->color == 1);
		}
		TEST_METHOD(FixAfterRemoveCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(93, 1);
			MyMap.insert(100, 2);
			MyMap.insert(15, 3);
			MyMap.insert(17, 4);
			Assert::IsTrue(MyMap.find(100)->color == 0);
			Assert::IsTrue(MyMap.find(15)->color == 0);
			Assert::IsTrue(MyMap.find(17)->color == 1);
			MyMap.remove(100);
			Assert::IsTrue(MyMap.find(17)->color == 0);
			Assert::IsTrue(MyMap.find(15)->color == 0);
			Assert::IsTrue(MyMap.find(93)->color == 0);
		}
		TEST_METHOD(ContainsAlgorithmCustomMapTest) {
			Map<int, char> MyMap;
			MyMap.insert(1, 'a');
			Assert::IsTrue(MyMap.contains(1) == 1);
			MyMap.insert(3, 'b');
			Assert::IsTrue(MyMap.contains(1) == 1);
			Assert::IsTrue(MyMap.contains(3) == 1);
			MyMap.insert(5, 'c');
			Assert::IsTrue(MyMap.contains(1) == 1);
			Assert::IsTrue(MyMap.contains(3) == 1);
			Assert::IsTrue(MyMap.contains(5) == 1);
			Assert::IsTrue(MyMap.contains(7) == 0);
			MyMap.insert(7, 'd');
			Assert::IsTrue(MyMap.contains(1) == 1);
			Assert::IsTrue(MyMap.contains(3) == 1);
			Assert::IsTrue(MyMap.contains(5) == 1);
			Assert::IsTrue(MyMap.contains(7) == 1);
			MyMap.remove(5);
			Assert::IsTrue(MyMap.contains(5) == 0);
		}
		TEST_METHOD(GetKeysAlgorithmCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(13, 31);
			MyMap.insert(8, 18);
			MyMap.insert(17, 71);
			List<int> hello = MyMap.get_keys();
			Assert::IsTrue(hello.get_head() == 13);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 8);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 17);
		}
		TEST_METHOD(GetValuesAlgorithmCustomMapTest) {
			Map<int, int> MyMap;
			MyMap.insert(13, 31);
			MyMap.insert(8, 18);
			MyMap.insert(17, 71);
			List<int> hello = MyMap.get_values();
			Assert::IsTrue(hello.get_head() == 31);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 18);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 71);
		}
		TEST_METHOD(ConsrtructorShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			int letters = 1;
			string original = "a";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 8);
		}
		TEST_METHOD(PrintFrequencyTableShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 4);
			int letters = 1;
			string original = "aaaa";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 32);
		}
		TEST_METHOD(EncodingShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
		}
		TEST_METHOD(PrintCodeTableShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
		}
		TEST_METHOD(OriginalTextSizeShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
		}
		TEST_METHOD(EncodedTextSizeShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text_size() == 2);
		}
		TEST_METHOD(CompressionRatioShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.compression_ratio() == 8);
		}
		TEST_METHOD(EncodedTextShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
		}
		TEST_METHOD(DecodedTextShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
			Assert::IsTrue(MySFCoder.decoded_text() == "ab");
		}
		TEST_METHOD(PrintEncodedTextShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
		}
		TEST_METHOD(PrintDecodedTextShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
			Assert::IsTrue(MySFCoder.decoded_text() == "ab");
		}
		TEST_METHOD(BubbleSortShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 3);
			MyMap.insert('b', 1);
			MyMap.insert('c', 1);
			int letters = 3;
			string original = "bcaaa";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			MySFCoder.ShannonFano_encoding(0, 2);
			Assert::IsTrue(MySFCoder.encoded_text() == "1011000");
		}
		TEST_METHOD(GetIndexCharShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
		}
		TEST_METHOD(GetIndexStringShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
			Assert::IsTrue(MySFCoder.decoded_text() == "ab");
		}
		TEST_METHOD(MinShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
			Assert::IsTrue(MySFCoder.decoded_text() == "ab");
		}
		TEST_METHOD(ContainsShannonFanoCoderTest) {
			Map<char, int> MyMap;
			MyMap.insert('a', 1);
			MyMap.insert('b', 1);
			int letters = 2;
			string original = "ab";
			ShannonFano_Coder MySFCoder(MyMap, letters, original);
			Assert::IsTrue(MySFCoder.original_text_size() == 16);
			MySFCoder.ShannonFano_encoding(0, 1);
			Assert::IsTrue(MySFCoder.encoded_text() == "01");
			Assert::IsTrue(MySFCoder.decoded_text() == "ab");
		}
	};
}
