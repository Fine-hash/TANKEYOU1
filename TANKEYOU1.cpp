#include "common.h"
#include "mci-sound.h"
#include "select-panel.h"
#include "game-control.h"

HDC main_hdc, canvas_hdc;

int main()
{
	srand((unsigned)time(NULL)); // �������������

	// ��ʼ����Ч��Դ
	InitSounds();

	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, EW_SHOWCONSOLE); // ��ʾ����̨����
	BeginBatchDraw(); // ����������ͼ��ֱ��ִ�� FlushBatchDraw �� EndBatchDraw �Ž�֮ǰ�Ļ�ͼ���

	// ����IMAGE����
	IMAGE canvas_img(CANVAS_WIDTH, CANVAS_HEIGHT);

	// ��ȡgraphics��ͼ�豸�������������window GDI������
	main_hdc = GetImageHDC(); // ��ȡĬ�ϻ�ͼ���ڵ�HDC���
	canvas_hdc = GetImageHDC(&canvas_img); // ��ȡimg�����HDC���

	// ��ʾ���ģʽѡ�����
	selelct_panel_init(); // ���ѡ�������Դ��ʼ��	

	while (_kbhit() != 27) {
		EnumSelectResult select_result = show_select_panel(); // ��Ϸ����֮���������ģʽѡ��
		game_control_init(); 
		game_control_show_stage(); // ��ʾ�ؿ���Ϣ

		switch (select_result)
		{
		case OnePlayer:
			// �����ң���һ����Ҷ�����ӵ�������

			// ���ص�ͼ����ȡ��ͼ�ļ����ݣ����ڼ�ֱ�Ӵ�����ͼ�������map
			game_control_start_game();

			// �����ͼ

			while (1);
			break;
		case TwoPlayer:
			break;
		case Custom:
			break;
		case Error:
			break;
		default:
			break;
		}
	}

}