class Point {
	private:
		int posX;
		int posY;
		int depth;
		int parentX;
		int parentY;
		int cost;
		vector<Tile> state;
		string path;

	public:
		int evaluation;
		// constructor
		Point(){}
		// ---------------------------------------------------

		// setter and getter
		void setPosition(int X, int Y) {
			posX = X;
			posY = Y;
		}

		void setDepth(int D) {
			depth = D;
		}

		void setState(vector<Tile> V) {
			this->state = V;
		}

		void setPath(string P) {
			path = P;

		}
		void setParent(int X, int Y) {
			parentX = X;
			parentY = Y;
		}

		void setEvaluation(int E) {
			evaluation = E;
		}

		void setCost(int C) {
			cost = C;
		}

		int getX() {
			return posX;
		}

		int getY() {
			return posY;
		}

		int getDepth() {
			return depth;
		}

		int getDepth() const {
			return depth;
		}

		string getPath() {
			return path;
		}

		string getPath() const {
			return path;
		}
		
		vector<Tile> getState() {
			vector<Tile> V;

			V.resize(this->state.size());
			for (int i = 0; i < this->state.size(); ++i)
			{
				V[i] = this->state[i];
			}
			return V;
		}

		vector<Tile> getState() const {
			vector<Tile> V;

			V.resize(this->state.size());
			for (int i = 0; i < this->state.size(); ++i)
			{
				V[i] = this->state[i];
			}
			return V;
		}

		int getParentX() {
			return parentX;
		}

		int getParentY() {
			return parentY;
		}

		int getEvaluation() {
			return evaluation;
		}

		int getEvaluation() const {
			return evaluation;
		}

		int getCost() {
			return cost;
		}

		int getCost() const {
			return cost;
		}
		// ---------------------------------------------------
};
// comparator
struct CompareEvaluation {
    bool operator()(Point const & p1, Point const & p2) {
        return p1.evaluation > p2.evaluation;
    }
};