#include "people.h"
namespace game_framework {
	class Sister : public People {
	public:
		Sister();
		void init();
		void LoadBitmap();  	
		void OnMoveAniRight();
		void OnMoveAniLeft();
		void AddingBitmap();
	};

	private:
		int x, y; // �y��
		CMovingBitmap peoplePic;
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isJumpimg;			// �O�_���b���W����
	};
}