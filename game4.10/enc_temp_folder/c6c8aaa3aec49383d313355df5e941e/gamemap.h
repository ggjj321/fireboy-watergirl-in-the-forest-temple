#include <string>

namespace game_framework {
	class CGameMap {
	public:
		CGameMap();
		void LoadBitMap();
		void OnShow();
		void OnMove();
		void ReadMapData(); // 讀取關卡資料
		/*
		bool isEmpty(int x, int y); // 判斷該格是0
		bool isFull(int x, int y); // 判斷該格是1
		void changeArray(int x, int y); // 陣列值改變
        void init();
		*/
	private:
		CMovingBitmap firstMap;	
		int x, y;
		int mapArray[29][47]; // 地圖邊界陣列
		int mapLevel; // 當前是第幾關
	};
}
