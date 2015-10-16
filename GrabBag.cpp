#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

const int TETRIMONO_MAX(7);
const string TETRIMONO[TETRIMONO_MAX] = {"S", "Z", "J", "L", "I", "O", "T"};

void Generate_Grab_Bag(vector<string> *GrabBag)
{
	srand(time(NULL));

	vector<int> TetrimonoChecker; // holds ints corresponding to tetrimonos we have already grabbed, so we don't grab a piece twice.

	while (TetrimonoChecker.size() < 7) // while the number of tetrimonos we have generated is less than 7
	{
		int RandTetrimono = rand() % 7; // attempt to generate a tetrimono

		bool generated = false; 
		if (TetrimonoChecker.size() > 0) // if there are 0 tetrimonos generated, we do not need to check if it is already in the list
		{
			for (int i = 0; i < TetrimonoChecker.size(); i++) // if there are > 0 tetrimonos generated, check to see if it is in the list of generated tetrimonos
			{
				if (RandTetrimono == TetrimonoChecker[i]) // if true, we have already generated this tetrimono, generated = true. try again next loop to generate unique tetrimono.
					generated = true;
			}
		}

		if (generated == false) // if we have not seen this tetrimono before
		{
			GrabBag->push_back(TETRIMONO[RandTetrimono]); // add the tetrimono to our grab bag and
			TetrimonoChecker.push_back(RandTetrimono); // mark that we have seen the tetrimono before so we do not add it again
		}
	}
}

int main()
{
	vector<string> GrabBag; // a vector holding a random order of tetrimonos

	// generate 50 blocks
	for (int i = 0; i < 50; i++)
	{
		if (GrabBag.size() == 0) // if the grab bag is empty, generate new series of tetrimonos
		{
			Generate_Grab_Bag(&GrabBag);
			//cout << "generating new batch" << endl;
		}

		string TetrimonoNext = GrabBag[GrabBag.size()-1];

		GrabBag.pop_back();

		cout << TetrimonoNext;
	}
	cout << endl;
	return 0;
}