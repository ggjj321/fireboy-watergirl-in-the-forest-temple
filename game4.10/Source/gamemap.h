namespace game_framework {
	class Map {
	public:
		bool isEmpty(int x, int y); // 判斷該格是0
		bool isFull(int x, int y); // 判斷該格是1
		void changeArray(int x, int y); // 陣列值改變
        void init();
	private:
		// 地圖邊界陣列
		int mapArray[29][47];
	};
}
