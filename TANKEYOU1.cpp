// TANKEYOU1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "common.h"
#include "mic-sound.h"
#include "select-panel.h"

HDC main_hdc,canvas_hdc;

int main()
{
	srand((unsigned)time(NULL));//�������������

	//��ʼ����Ч��Դ
	InitSounds();

	initgraph(WINDOW_WIDTH,WINDOW_HEIGHT,EW_SHOWCONSOLE);//��ʾ����̨����
	BeginBatchDraw();//����������ͼ��ֱ��ִ��FlushBatchDraw��EndBatchDraw�Ž�֮ǰ�Ļ�ͼ���

	//����IMAGE����
	IMAGE canvas_img(CANVAS_WIDTH,CANVAS_HEIGHT);

	//��ȡgraphics��ͼ�豸�������������window GDI������
	main_hdc = GetImageHDC();//��ȡĬ�ϻ�ͼ���ڵ�HDC���
	canvas_hdc = GetImageHDC(&canvas_img);//��ȡimg�����HDC���

	//��ʾ���ģʽѡ�����
	selelct_panel_init();//���ѡ�������Դ��ʼ��

	while(_kbhit() !=27){
		EnumSelectResult select_result=show_select_panel();//��Ϸ����֮���������ģʽѡ��

		switch(select_result)
		{
			case OnePlayer:
				//������

				//���ص�ͼ

				//�����ͼ
				break;
			case TwoPlayer:
				break;
			case Custom:
				break;
			case ERROR:
				break;
			default:
				break;
		}
	}
}




