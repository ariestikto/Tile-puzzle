#include <iostream>		// using IO functions (i.e. cin, cout)
#include <string>			// using string
#include <algorithm>    // std::random_shuffle
#include <queue>        // std::queue
#include <deque>        // std::deque
#include <cmath>        // std::abs
#include <array>			// std::array
#include <vector>			// std::vector
using namespace std;

#include "tile.h"
#include "board.h"
#include "point.h"
#include "helper.h"
#include "algorithm.h"

int main() {
	srand(time(0)); // seed random function
	Tile tileAgent(":)", 3, 3, true);


	for (int i = 0; i < 1; ++i)
	{
		cout << "NUMBER " << i+1 << endl;
		Board B;
		Board B2;
		Board B3;
		Board B4;
		Board B5;
		resetBoard(&B, tileAgent);
		resetBoard(&B2, tileAgent);
		resetBoard(&B3, tileAgent);
		resetBoard(&B4, tileAgent);
		resetBoard(&B5, tileAgent);
		
		cout << "BFS" << endl;
		BFS(&B, tileAgent);
		
		cout << "DFS" << endl;
		DFS(&B2, tileAgent);

		cout << "ID_DFS" << endl;
		ID_DFS(&B3, tileAgent);
		
		cout << "GBFS" << endl;
		GBFS(&B4, tileAgent);

		cout << "ASS" << endl;
		ASS(&B5, tileAgent);

		cout << endl;
	}

	return 0;
}