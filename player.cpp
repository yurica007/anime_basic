#include "DxLib.h"
#include <cassert>
#include "game.h"
#include "player.h"

namespace
{
	//キャラクターアニメーション1コマ当たりのフレーム数
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
	m_dirNo = 0;
}

Player::~Player()
{

}

//初期化
void Player::init()
{
	m_pos.x = Game::kScreenWidth / 2 - kGraphicSizeX / 2;
	m_pos.y = Game::kScreenHeight / 2 - kGraphicSizeY / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;
}

void Player::update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isKey = false;
	if (padState & PAD_INPUT_UP)
	{
		m_dirNo = 3;
		m_pos.y -= 2;
		isKey = true;	
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_dirNo = 0;
		m_pos.y += 2;
		isKey = true;
	}
	else if (padState & PAD_INPUT_LEFT)
	{
		m_dirNo = 1;
		m_pos.x -= 2;
		isKey = true;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_dirNo = 2;
		m_pos.x += 2;
		isKey = true;
	}

	if (isKey) m_animeFrame++;
	if (m_animeFrame >= kGraphicDivX * kAnimeChangeFrame)
	{
		m_animeFrame = 0;
	}
	int tempAnimeNo = m_animeFrame / kAnimeChangeFrame;
	m_animeNo =m_dirNo * kGraphicDivX + tempAnimeNo;
}

void Player::draw()
{
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
}