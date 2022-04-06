#include <string>

namespace game_framework {
	class CGameMap {
	public:
		CGameMap();
		void LoadBitMap();
		void OnShow();
		void OnMove();
		bool isEmpty(int x, int y)noexcept; // �P�_�Ӯ�O0
		bool isFull(int x, int y)noexcept; // �P�_�Ӯ�O1
		bool isRedWater(int x, int y)noexcept; // �P�_�Ӯ�O����
		bool isBlueWater(int x, int y)noexcept; // �P�_�Ӯ�O�Ť�
		bool isGreenWater(int x, int y)noexcept; // �P�_�Ӯ�O���
		void ChangeArray(int x, int y, int num); // �}�C�ȧ���
		void ReadMapData()noexcept; // Ū�����d���
		void LastLevel();
		void NextLevel();
		int GetGx(int x);
		int GetGy(int y);
		bool isSameArray(int x1, int y1, int x2, int y2);
	private:
		CMovingBitmap firstMap;	
		int x, y;
		int mapArray[29][47]; // �a����ɰ}�C
		int mapLevel; // ��e�O�ĴX��
	};
}
