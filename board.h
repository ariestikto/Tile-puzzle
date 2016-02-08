class Board {
	private:
		int size; // width x height
		int width;
		int height;
		vector<Tile> board;

	public:
		// constructor
		Board(){}
		// ---------------------------------------------------

		// setter and getter
		// change board specification and empty it
		void setSpec(int S, int W, int H) {
			size = S;
			width = W;
			height = H;
			board.resize(S);
			this->emptyBoard();						
		}

		void setContent(vector<Tile> V) {
			this->board = V;
		}

		int getSize() {
			return size;
		}

		int getWidth() {
			return width;
		}

		int getHeight() {
			return height;
		}

		vector<Tile> getContent() {
			vector<Tile> V;

			V.resize(this->size);
			for (int i = 0; i < this->size; ++i)
			{
				V[i] = this->board[i];
			}
			return V;
		}

		// ---------------------------------------------------

		// other functions
		void emptyBoard(){
			Tile tileEmpty("empty", 0, 0, true);
			
			board.clear();
			for (int i = 0; i < this->size; i++)
				board[i] = tileEmpty;
		}

		void showBoard() {
			for(int i = 0; i < this->size; i++) 
			{
				cout << board[i].getName() << "\t";
				if ((i+1)%this->width==0)
				{
					cout << "\n";
				}
			}
			cout << "\n";
		}

		void putTile(Tile T, int X, int Y) {
			board[(this->height-Y)*this->width+(X-1)] = T;
		}

		void putIndex(Tile T, int I) {
			board[I] = T;
		}
		void copyBoard(Board *B) {
			Board dummyBoard;

			*B = dummyBoard;
			B->setSpec(this->size, this->width, this->height);
			B->setContent(this->getContent());
		}

		bool isEqual(Board *B) {
			bool content = true;
			
			if (this->size == B->getSize() && this->width == B->getWidth() && this->height == B->getHeight()) 
			{
				for (int i = 0; i < this->size; ++i)
				{
					content = content && this->board[i].isEqual(B->board[i]);
				}
				return content;
			}
			return false;
		}
};