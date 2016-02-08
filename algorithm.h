// Breadth-first search (FIFO)
void BFS(Board *B, Tile T) {
	int expandedNode = 0;
	int depth = 0;
	int storedNode = 1;
	int parentX = 0;
	int parentY = 0;
	string path;
	Point P;
	queue<Point> nodes;
	array<int, 4> moves{{0,1,2,3}};

	path = "(" + to_string(tilePosition(B, T, 1)) + "," + to_string(tilePosition(B, T, 2)) + ") |"; 
	while (!isFinished(B) && depth < 25 ) {
		random_shuffle(begin(moves), end(moves));
		for (int i = 0; i < moves.size(); i++) {
			Board dummyBoard;

			B->copyBoard(&dummyBoard);
			if (isValidMove(&dummyBoard, T, moves[i])) {
				moveAgent(&dummyBoard, T, moves[i]);
				if (tilePosition(&dummyBoard, T, 1)!=parentX || tilePosition(&dummyBoard, T, 2)!= parentY)
				{
					P.setParent(tilePosition(B, T, 1), tilePosition(B, T, 2));
					P.setPosition(tilePosition(&dummyBoard, T, 1), tilePosition(&dummyBoard, T, 2));
					P.setState(dummyBoard.getContent());
					P.setDepth(depth+1);
					P.setPath(path+" (" + to_string(tilePosition(&dummyBoard, T, 1)) + "," + to_string(tilePosition(&dummyBoard, T, 2)) + ")");
					nodes.push(P);
					storedNode++;
				}
			}
		}
		B->setContent(nodes.front().getState());
		expandedNode++;
		depth = nodes.front().getDepth();
		path = nodes.front().getPath();
		parentX = nodes.front().getParentX();
		parentY = nodes.front().getParentY();
		nodes.pop();
	};
	cout << "Number of generated nodes (space complexity): " << storedNode << endl;
	cout << "Number of expanded nodes (time complexity): " << expandedNode << endl;	
	cout << "Solution depth: " << depth << endl;
	// cout << path << endl;
	// B->showBoard();	
}

// Depth-first search (LIFO)
void DFS(Board *B, Tile T) {
	int expandedNode = 0;
	int depth = 0;
	int storedNode = 1;
	int parentX = 0;
	int parentY = 0;
	string path;
	Point P;
	deque<Point> nodes;
	array<int, 4> moves{{0,1,2,3}};

	path = "(" + to_string(tilePosition(B, T, 1)) + "," + to_string(tilePosition(B, T, 2)) + ") |"; 
	while (!isFinished(B) && depth < 30000) {
		random_shuffle(begin(moves), end(moves));
		for (int i = 0; i < moves.size(); i++) {
			Board dummyBoard;

			B->copyBoard(&dummyBoard);
			if (isValidMove(&dummyBoard, T, moves[i])) {
				moveAgent(&dummyBoard, T, moves[i]);
				if (tilePosition(&dummyBoard, T, 1)!=parentX || tilePosition(&dummyBoard, T, 2)!= parentY)
				{
					P.setParent(tilePosition(B, T, 1), tilePosition(B, T, 2));
					P.setPosition(tilePosition(&dummyBoard, T, 1), tilePosition(&dummyBoard, T, 2));
					P.setState(dummyBoard.getContent());
					P.setDepth(depth+1);
					P.setPath(path+" (" + to_string(tilePosition(&dummyBoard, T, 1)) + "," + to_string(tilePosition(&dummyBoard, T, 2)) + ")");
					nodes.push_front(P);
					storedNode++;
				}
			}
		}
		B->setContent(nodes.front().getState());
		expandedNode++;
		depth = nodes.front().getDepth();
		path = nodes.front().getPath();
		parentX = nodes.front().getParentX();
		parentY = nodes.front().getParentY();
		nodes.pop_front();
	};
	cout << "Number of generated nodes (space complexity): " << storedNode << endl;
	cout << "Number of expanded nodes (time complexity): " << expandedNode << endl;	
	cout << "Solution depth: " << depth << endl;
}

// Iterative deepening Depth-first search (LIFO)
void ID_DFS(Board *B, Tile T) {
	int expandedNode = 0;
	int depth = 0;
	int storedNode = 1;
	int depthLimit = 0;
	int parentX = 0;
	int parentY = 0;
	string path;
	Point P;
	vector<Tile> V;
	deque<Point> nodes;
	array<int, 4> moves{{0,1,2,3}};

	V = B->getContent();
	path = "(" + to_string(tilePosition(B, T, 1)) + "," + to_string(tilePosition(B, T, 2)) + ") |"; 
	while (!isFinished(B) && storedNode < 1000000) {
		random_shuffle(begin(moves), end(moves));

		if (depth < depthLimit) {
			for (int i = 0; i < moves.size(); i++) {
				Board dummyBoard;

				B->copyBoard(&dummyBoard);
				if (isValidMove(&dummyBoard, T, moves[i])) {
					moveAgent(&dummyBoard, T, moves[i]);
					if (tilePosition(&dummyBoard, T, 1)!=parentX || tilePosition(&dummyBoard, T, 2)!= parentY)
					{
						P.setParent(tilePosition(B, T, 1), tilePosition(B, T, 2));
						P.setPosition(tilePosition(&dummyBoard, T, 1), tilePosition(&dummyBoard, T, 2));
						P.setState(dummyBoard.getContent());
						P.setDepth(depth+1);
						P.setPath(path+" (" + to_string(tilePosition(&dummyBoard, T, 1)) + "," + to_string(tilePosition(&dummyBoard, T, 2)) + ")");
						nodes.push_front(P);
						storedNode++;
					}
				}
			}
		}
		if (nodes.size() == 0) {
			depthLimit++;
			expandedNode = 0;
			depth = 0;
			storedNode = 1;
			parentX = 0;
			parentY = 0;
			B->setContent(V);
			path = "(" + to_string(tilePosition(B, T, 1)) + "," + to_string(tilePosition(B, T, 2)) + ") |"; 
		} else {
			B->setContent(nodes.front().getState());
			expandedNode++;
			depth = nodes.front().getDepth();
			path = nodes.front().getPath();
			parentX = nodes.front().getParentX();
			parentY = nodes.front().getParentY();
			nodes.pop_front();
		}
	};
	cout << "Number of generated nodes (space complexity): " << storedNode << endl;
	cout << "Number of expanded nodes (time complexity): " << expandedNode << endl;	
	cout << "Solution depth: " << depth << endl;
}

// Greedy Best-First Search
// Manhattan distance as heuristic function
void GBFS(Board *B, Tile T) {
	int expandedNode = 0;
	int depth = 0;
	int storedNode = 1;
	int parentX = 0;
	int parentY = 0;
	string path;
	Point P;
	priority_queue<Point, std::vector<Point>, CompareEvaluation> nodes;
	array<int, 4> moves{{0,1,2,3}};


	path = "(" + to_string(tilePosition(B, T, 1)) + "," + to_string(tilePosition(B, T, 2)) + ") |"; 
	while (!isFinished(B) && depth < 20000) {
		random_shuffle(begin(moves), end(moves));

		for (int i = 0; i < moves.size(); i++) {
			Board dummyBoard;

			B->copyBoard(&dummyBoard);
			if (isValidMove(&dummyBoard, T, moves[i])) {
				moveAgent(&dummyBoard, T, moves[i]);
				if (tilePosition(&dummyBoard, T, 1)!=parentX || tilePosition(&dummyBoard, T, 2)!= parentY)
				{
					P.setParent(tilePosition(B, T, 1), tilePosition(B, T, 2));
					P.setPosition(tilePosition(&dummyBoard, T, 1), tilePosition(&dummyBoard, T, 2));
					P.setState(dummyBoard.getContent());
					P.setDepth(depth+1);
					P.setPath(path+" (" + to_string(tilePosition(&dummyBoard, T, 1)) + "," + to_string(tilePosition(&dummyBoard, T, 2)) + ")");
					P.setEvaluation(manhattanDist(&dummyBoard, T));
					nodes.push(P);
					storedNode++;
				}
			}
		}
		B->setContent(nodes.top().getState());
		expandedNode++;
		path = nodes.top().getPath();
		depth = nodes.top().getDepth();
		nodes.pop();
	};
	cout << "Number of generated nodes (space complexity): " << storedNode << endl;
	cout << "Number of expanded nodes (time complexity): " << expandedNode << endl;	
	cout << "Solution depth: " << depth << endl;
}

// A* search
// Manhattan distance as heuristic function
void ASS(Board *B, Tile T) {
	int expandedNode = 0;
	int depth = 0;
	int storedNode = 1;
	int parentX = 0;
	int parentY = 0;
	int cost = 0;
	string path;
	Point P;
	priority_queue<Point, std::vector<Point>, CompareEvaluation> nodes;
	array<int, 4> moves{{0,1,2,3}};


	path = "(" + to_string(tilePosition(B, T, 1)) + "," + to_string(tilePosition(B, T, 2)) + ") |"; 
	while (!isFinished(B) && depth < 35) {
		random_shuffle(begin(moves), end(moves));

		for (int i = 0; i < moves.size(); i++) {
			Board dummyBoard;

			B->copyBoard(&dummyBoard);
			if (isValidMove(&dummyBoard, T, moves[i])) {
				moveAgent(&dummyBoard, T, moves[i]);
				if (tilePosition(&dummyBoard, T, 1)!=parentX || tilePosition(&dummyBoard, T, 2)!= parentY)
				{
					P.setParent(tilePosition(B, T, 1), tilePosition(B, T, 2));
					P.setPosition(tilePosition(&dummyBoard, T, 1), tilePosition(&dummyBoard, T, 2));
					P.setState(dummyBoard.getContent());
					P.setDepth(depth+1);
					P.setPath(path+" (" + to_string(tilePosition(&dummyBoard, T, 1)) + "," + to_string(tilePosition(&dummyBoard, T, 2)) + ")");
					P.setCost(cost+1);
					P.setEvaluation(manhattanDist(&dummyBoard, T) + cost + 1);
					nodes.push(P);
					storedNode++;
					// cout << "f(n) :" << manhattanDist(&dummyBoard, T) + cost + 1 << endl;
					// dummyBoard.showBoard();
				}
			}
		}
		cost = nodes.top().getCost();
		B->setContent(nodes.top().getState());
		expandedNode++;
		path = nodes.top().getPath();
		depth = nodes.top().getDepth();
		nodes.pop();
	};
	cout << "Number of generated nodes (space complexity): " << storedNode << endl;
	cout << "Number of expanded nodes (time complexity): " << expandedNode << endl;	
	cout << "Solution depth: " << depth << endl;
}