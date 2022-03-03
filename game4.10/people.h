namespace game_framework {
	class people {
	public:
		void init(); // ��l�ƪ��A
		void move(); // �B�z����
		void eatDiamond(); // �ֿn�Y�쪺�_��
		void setHorizontalSpeed(int speed); // �]�w���k���ʳt��
		void setVerticalSpeed(int speed); // �]�w�����O���U�t��
		void touchWaterDie(); // �I��ۤϤ��κ������
		bool isStandOnFloor(); // �P�_�}�U�O�_���a�O
		void readKey(); // �ھ���ȧP�_���ʩθ��D
		bool isBlock(); // �e�i���u�O�_����ê�������
		bool isArriveDoor(); // �P�_�O�_��F���f
		bool isOnLeftSlope(); // �P�_�O�_�b���U�שY�W
		bool isOnReftSlope(); // �P�_�O�_�b�k�U�שY�W
		bool isBlow(); // �P�_�O�_�Q���j
		bool isFloorMove(); // �P�_�}�U�a�O�λ�ê���O�_������
		void bitMapShow(); // bitmap ���
	private:
		int x, y; // �y��
		int diamondNum; // �Y�쪺�_�ۼ�
		int horizontalSpeed; // ���k���t��
		int verticalSpeed; // �����O�����t��
		bool aliveState; // �s�����A
		bool isMove; // �O�_�b����
		bool isJump; // �O�_�b���D		
	};

}
