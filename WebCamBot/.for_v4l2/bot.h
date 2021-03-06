//
// ������ ���-���-����
//
// robocraft.ru
//

#ifndef _BOT_H_
#define _BOT_H_

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

#include "vision/camera_v4l2.h"
#include "vision/hsv_detector.h"
#include "gimbal.h"

// �������� ���� ��� ������ �������� � ������
#define BOT_WINDOW_NAME "web-cam-bot"

class Bot
{
	// � ���� ����:
	CameraV4L2* camera; // ������
	Gimbal* gimbal; // ���������� �������
	HSVDetector* detector; // �������� ������� (�� �����)

	// ��� ����������:
	IplImage* image; // ����������� ��� ������
	const char* window_name; // �������� ���� ��� �����������
	CvFont font; // ��� ������ �������������� ��������� �� ��������

public:
	Bot();
	Bot(int width, int height);
	Bot(int width, int height, int port, int rate);
	Bot(int width, int height, const char* port_name, int rate);
	~Bot();

	// �������������
	void setup();
	void update();
	// ������� ��������� � ��������� ����� � ������
	void make();

private:
	
};

#endif //#ifndef _BOT_H_
