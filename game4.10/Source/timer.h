namespace game_framework {
	class Timer {
	public:
		Timer();
		void init(int coordinateX, int coordinateY);
		void OnShow();
		void OnMove();
		void TimeCalculate();
		int getMinute();
		int getSecond();
	private:
		int x, y, counter;
		int tenMinute, digitMinute, tenSecond, digitSecond;    // time
	};
}
