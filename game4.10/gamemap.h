namespace game_framework {
	class Map {
	public:
		bool isEmpty(int x, int y); // �P�_�Ӯ�O0
		bool isFull(int x, int y); // �P�_�Ӯ�O1
		void changeArray(int x, int y); // �}�C�ȧ���
	private:
		int mapArray[10][6]; // �a����ɰ}�C
	};
}
