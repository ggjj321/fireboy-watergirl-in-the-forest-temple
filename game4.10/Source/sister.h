namespace game_framework {
	class Sister
	{
	public:
		Sister();
		void init();
		void AddingBitmap();
		void LoadBitmap();
		void OnMove(bool leftBound, bool rightBound);
		void OnMoveAniRight();
		void OnMoveAniLeft();
		void OnShow();
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		int GetX();
		int GetY();
		bool GetIsMovingLeft();
		bool GetIsMovingRight();
		// void SetJumpimg(bool flag);	// �]�w�O�_�����D

	private:
		int x, y; // �y��
		CMovingBitmap peoplePic;
		CAnimation peopleAniR, peopleAniL;
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isJumpimg;			// �O�_���b���W����
	};
}