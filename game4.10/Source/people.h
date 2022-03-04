namespace game_framework {
	class people {
	public:
		void init(); // 初始化狀態
		void move(); // 處理移動
		void eatDiamond(); // 累積吃到的寶石
		void setHorizontalSpeed(int speed); // 設定左右移動速度
		void setVerticalSpeed(int speed); // 設定受重力落下速度
		void touchWaterDie(); // 碰到相反水或綠水死掉
		bool isStandOnFloor(); // 判斷腳下是否為地板
		void readKey(); // 根據鍵值判斷移動或跳躍
		bool isBlock(); // 前進路線是否有障礙物或邊界
		bool isArriveDoor(); // 判斷是否到達門口
		bool isOnLeftSlope(); // 判斷是否在左下斜坡上
		bool isOnReftSlope(); // 判斷是否在右下斜坡上
		bool isBlow(); // 判斷是否被風吹
		bool isFloorMove(); // 判斷腳下地板或障礙物是否受移動
		void bitMapShow(); // bitmap 顯示
	private:
		int x, y; // 座標
		int diamondNum; // 吃到的寶石數
		int horizontalSpeed; // 左右移速度
		int verticalSpeed; // 受重力掉落速度
		bool aliveState; // 存活狀態
		bool isMove; // 是否在移動
		bool isJump; // 是否在跳躍		
	};

}
