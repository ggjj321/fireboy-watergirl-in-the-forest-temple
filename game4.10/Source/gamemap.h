#include <string>

namespace game_framework {
	class CGameMap {
	public:
		CGameMap();
		void LoadBitMap();
		void OnShow();
		void OnMove();
		bool isEmpty(int x, int y)noexcept; // 判斷該格是0
		bool isFull(int x, int y)noexcept; // 判斷該格是1
		bool isRedWater(int x, int y)noexcept; // 判斷該格是紅水
		bool isBlueWater(int x, int y)noexcept; // 判斷該格是藍水
		bool isGreenWater(int x, int y)noexcept; // 判斷該格是綠水
		void ChangeArray(int x, int y, int num); // 陣列值改變
		void ReadMapData()noexcept; // 讀取關卡資料
		void LastLevel();
		void NextLevel();
		int GetGx(int x);
		int GetGy(int y);
		bool isSameArray(int x1, int y1, int x2, int y2);
		bool isInArea(int x1, int y1, int x2, int y2);
		static int mapLevel; // 當前是第幾關
	private:
		CMovingBitmap firstMap, secondMap, thirdMap, fourthMap;	
		int x, y;
		int mapArray[30][47]; // 地圖邊界陣列	
		double gridSizeWeight;
		double gridSizeHeight;
	};
}
