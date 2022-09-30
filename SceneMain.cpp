#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

namespace
{
	//�O���t�B�b�N�t�@�C����
	const char* const kPlayerGraphicFikename = "data/char.png";
}

SceneMain::SceneMain()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		handle = -1;
	}
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	LoadDivGraph("data/char.png", Player::kGraphicDivNum,
		Player::kGraphicDivX, Player::kGraphicDivY,
		Player::kGraphicSizeX, Player::kGraphicSizeY, m_hPlayerGraphic);

	for (int i = 0; i < Player::kGraphicDivNum; i++)
	{
		m_player.setHandle(i, m_hPlayerGraphic[i]);
	}
	m_player.init();
}

// �I������
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(handle);
	}

}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
}