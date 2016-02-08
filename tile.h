class Tile {
	private:
		string tileName;
		int goalX;
		int goalY;
		bool moveAble;

	public:
		// constructor
		Tile(){}
		Tile(string N, int X, int Y, bool M) {
			tileName = N;
			goalX = X;
			goalY = Y;
			moveAble = M;
		}
		// ---------------------------------------------------

		// setter and getter
		void setName(string N) {
			tileName = N;
		}

		void setGoalX(int X) {
			goalX = X;
		}

		void setGoalY(int Y) {
			goalY = Y;
		}
 
		void setMovable(bool M) {
			moveAble = M;
		}

		string getName() {
			return tileName;
		} 

		int getGoalX() {
			return goalX;
		}

		int getGoalY() {
			return goalY;
		}

		bool isMoveable() { //getMoveable
			return moveAble;
		}

		string getGoal() {
			return "("+to_string(goalX)+","+to_string(goalY)+")";
		}
		// ---------------------------------------------------

		// other functions
		bool isEqual(Tile A) {
			bool tName, tGoal, tMoveAble;
			tName = this->getName() == A.getName();
			tGoal = this->getGoal() == A.getGoal();
			tMoveAble = this->isMoveable() == A.isMoveable();
			return (tName && tGoal && tMoveAble);
		}
};