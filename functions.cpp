#include "functions.h"

Magic8Response::Magic8Response() {}; //default constructor

Magic8Response::Magic8Response(std::string response, std::string meaning) {
	this->response = response;
	this->meaning = meaning;
}//end constructor


void ReadResponses(Magic8Response array[], int& size, const int MAXSIZE) {

	std::string response, meaning;
	std::ifstream infile("magic_responses.txt");

	if (size > 0) {
		std::cout << "Responses have already been read from file\n\n";
		return;
	}
	
	while (getline(infile, response) && (size < MAXSIZE)) {
		getline(infile, meaning);
		array[size] = Magic8Response(response, meaning);
		size++;
		
	}
	std::cout << "Responses have been read from file\n\n";

}//end ReadResponses



void PlayMagic8(Magic8Response array[], int& size) {

	if (size == 0) {
		std::cout << "Must load responses before playing\n\n";
		return;
	}


	std::string question;
	std::cout << "\nWelcome to the Magic Eight Ball\n";
	std::cout << "Please ask a yes or no question...\n";
	std::cout << "Question: ";
	std::cin.ignore();
	
	getline(std::cin, question);


	int choice = (rand() % (size - 1)); // choosing number between 0 and the size of the array minus 1
	
	
	
	std::cout << "Response: " << array[choice].response << std::endl << std::endl;;
}//end PlayMagic8



void PrintResponsesAndCategories(Magic8Response array[], const int& size) {

	if (size == 0) {
		std::cout << "There are no loaded responses to print.  Please load responses from file to continue.\n\n";
		return;
	}

	Magic8Response key;
	int i, j;

	//sort responses alphabetically using insertion sort
	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;

		
		while (j >= 0 && array[j].response > key.response)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}

	//read out list of alphabetical responses and meaning 
	for (int i = 0; i < size; i++) {
		std::cout << i+1 << ". " << array[i].response << "\n";
		std::cout << array[i].meaning << "\n";
	}

}//end PrintResponsesAndCategories


void WriteResponsesToFile(Magic8Response array[], const int& size) {

	if (size == 0) {
		std::cout << "There are no responses to write to a file.  Please load responses from file to continue.\n\n";
		return;
	}

	std::ofstream outfile("outresponses.txt");

		
	for (int i = 0; i < size; i++) {
		outfile << array[i].response << "\n";
		outfile << array[i].meaning << "\n";
	}

	outfile.close();

	std::cout << "Responses successfully written to file.\n";

	

}//end WriteResponsesToFile


void DeleteResponse(Magic8Response array[], int& size) {

	if (size == 0) {
		std::cout << "There are no responses loaded into the game.  Please load responses from file to continue.\n\n";
		return;
	}
	std::cout << "There are currently "<<size<<" responses\n";
	
	int choice = -1;
	while (choice > size  || choice <= 0) {
		std::cout << "Enter the number of the response you would like to delete" << std::endl;
		std::cin >> choice;
		if (choice > size || choice <= 0)
			std::cout << "That is not a valid entry.\n";
	}
	
	std::cout << "Are you sure you want to delete this response (y or n):\n";
	std::cout << array[choice - 1].response << std::endl;
	char answer = 'z';
	bool done = false;
	while (!done) {
		std::cin >> answer;
		switch (answer) {
		case 'n':
		case 'N':
			std::cout << "Response number " << choice << " was not deleted.\n";
			return;
		case 'y':
		case 'Y':
			done = true;
			std::cout << "Response number " << choice << " was deleted.\n\n";
			break;
		default:
			std::cout << "Please enter y or n.\n";
		}
	}

	//copy the response object from size - 1 to the index at choice
	array[choice - 1] = array[size - 1];

	
		
	size--;


}//end DeleteResponse
