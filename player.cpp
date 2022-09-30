#include "DxLib.h"
#include <cassert>
#include "game.h"
#include "player.h"

namespace
{
	//�L�����N�^�[�A�j���[�V����1�R�}������̃t���[����
	constexpr int kAnimeChangeFrame = 8;
}

Player::Player()
{
	for (auto& handle : m_handle)
	{
		handle = -1;
	}

	m_animeNo = 0;
	m_animeFrame = 0;
}

Player::~Player()
{

}

//������
void Player::init()
{
	m_pos.x = Game::kScreenWidth / 2 - kGraphicSizeX / 2;
	m_pos.y = Game::kScreenHeight / 2 - kGraphicSizeY / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_animeNo = 0;
	m_animeFrame = 0;
}

void Player::update()
{
	m_animeFrame++;

	if (m_animeFrame >= kGraphicDivX * kAnimeChangeFrame)
	{
		m_animeFrame = 0;
	}

	m_animeNo = m_animeFrame / kAnimeChangeFrame;

	// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{

	}
	if (padState & PAD_INPUT_DOWN)
	{

	}
	if (padState & PAD_INPUT_LEFT)
	{

	}
	if (padState & PAD_INPUT_RIGHT)
	{

	}
}

void Player::draw()
{
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
}