//
// OpenRoboVision
//
// ������ ������ �����
//

#include "orv/orv.h"
#include "orv/vision/camera.h"
#include "orv/vision/video_writer.h"

int main(int argc, char* argv[])
{
	// ������������ � ������
	Camera camera(CV_CAP_ANY);

	// ������� ������ ������ �����
	Videowriter writer("capture.avi", cvSize(camera.getWidth(), camera.getHeight()), 15, CV_FOURCC('X','V','I','D'), 1);

	// �� ����� ���������� ������������ ��������
	writer.setShowCapture(false);

	IplImage* frame=0;

	printf("[i] press Esc for quit!\n\n");

	int counter=0;

	while(true){
		// �������� ����
		camera.update();

		// ���������� ���� � ����
		writer.write( camera.getFrame() );
	
		char c = cvWaitKey(33);
		if (c == 27) { // ������ ESC
			break;
		}
	}
	return 0;
}
