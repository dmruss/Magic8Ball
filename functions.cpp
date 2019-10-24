/*

#include "functions.h"

Magic8Response(string response, string meaning)
	this->response = response
	this->meaning = meaning



void ReadResponses(Magic8Response array[], int& size, int MAXSIZE)
	
	declare string variables called response and meaning
	declare ifstream variable called infile and open "responses.txt" into that var


	while (getline(infile, response) && size < MAXSIZE)
		infile >> meaning
		array[size] = Response(response, meaning)
		size++

	cout << responses have been read from file





void PlayMagic8(Magic8Response array[], const int& size)
	
	if size == 0
		cout << must load responses before playing
		return;


	declare string var called question
	cout << Welcome to the Magic Eight Ball\n
	cout << Please ask a yes or no question
	cin >> question

	
	initialize int var choice to (rand() % (size -1)) choosing number between 0 and the size of the array minus 1

	cout << array[choice]




string PrintResponsesAndCategories(Magic8Response array[], const int& size)

	an algorithm to compare ascii values of each response

	a loop that continues until the array is in alphabetical order by responses
		if (tolower(array[i].response[k]) > tolower(array[i+1].response[k])
			swap the two entries in the array using a temporary response type variable


	print out all entries in the array
	for (int i = 0; int < size; i++)
		cout << i+1 << array[i].response << "\n"
		cout << "  " << array[i].meaning << "\n"
		



void WriteResponsesToFile(Magic8Response array[], const int& size)

	declare an ofstream variable called outfile and create a file called outresponses.txt

	write out each item to the file
	for (int i = 0; int < size; i++)
		outfile << array[i].response << "\n"
		outfile << array[i].meaning << "\n"

	outfile.close()



void DeleteResponse(Magic8Response array[], int& size)
	
	if (array.sizeof() == 0)
		cout << There are no responses loaded into the game
		return;

	cout << Enter the number of the response you would like to delete
	declare int variable choice
	cin >> choice


	copy the response object from size-1 to the index at choice
	array[choice] = array[size-1]

	decrease size of array
	size--


	*/