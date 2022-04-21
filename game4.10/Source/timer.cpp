#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "timer.h"

namespace game_framework {
Timer::Timer()
{
}
void Timer::init(int coordinateX, int coordinateY)
{
	x = coordinateX;
	y = coordinateY;
	counter = 0;
	tenMinute = 0; 
	digitMinute = 0; 
	tenSecond = 0;
	digitSecond = 0;
}
void Timer::OnShow()
{
	CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f, * fp;
	f.CreatePointFont(230, "Times New Roman");	// 產生 font f; 160表示16 point的字
	fp = pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "%d%d : %d%d", tenMinute, digitMinute, tenSecond, digitSecond);
	pDC->TextOut(x, y, str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
}
void Timer::OnMove()
{
	counter += 1;
}
void Timer::TimeCalculate()
{
	if (counter == 30) {
		digitSecond += 1;

		if (digitSecond == 10) {
			tenSecond += 1;
			digitSecond = 0;
		}

		if (tenSecond == 6) {
			digitMinute += 1;
			tenSecond = 0;
		}

		if (digitMinute == 10) {
			tenMinute += 1;
			digitMinute = 0;
		}

		counter = 0;
	}
}
int Timer::getMinute()
{
	return (10 * tenMinute + digitMinute);
}
int Timer::getSecond()
{
	return (10 * tenSecond + digitSecond);
}
}