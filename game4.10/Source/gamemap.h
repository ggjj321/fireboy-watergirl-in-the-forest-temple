#include <string>

namespace game_framework {
	class CGameMap {
	public:
		CGameMap();
		void LoadBitMap();
		void OnShow();
		void OnMove();
		/*
		bool isEmpty(int x, int y); // �P�_�Ӯ�O0
		bool isFull(int x, int y); // �P�_�Ӯ�O1
		void changeArray(int x, int y); // �}�C�ȧ���
        void init();
		*/
	private:
		CMovingBitmap firstMap;
		//int mapArray[29][47]; // �a����ɰ}�C
		int x, y;
	};
}
