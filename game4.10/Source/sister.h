namespace game_framework {
	class Sister
	{
	public:
		Sister();
		void init();
		void LoadBitmap();
		void OnMove(bool leftBound, bool rightBound, bool downBound);
		void OnShow();
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		int GetX();
		int GetY();
		// void SetJumpimg(bool flag);	// �]�w�O�_�����D

	private:
		int x, y; // �y��
		CMovingBitmap peoplePic;
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isJumpimg;			// �O�_���b���W����
	};
}