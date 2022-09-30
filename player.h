#pragma once

#include "Vec2.h"

class Player
{
public:
	//�萔��`

	//�v���C���[�O���t�B�b�N������
	static constexpr int kGraphicDivY = 4;
	static constexpr int kGraphicDivX = 3;
	static constexpr int kGraphicDivNum = kGraphicDivX * kGraphicDivY;

	//�v���C���[�O���t�B�b�N�T�C�Y
	static constexpr int kGraphicSizeX = 32;
	static constexpr int kGraphicSizeY = 32;

public:

	Player();
	virtual ~Player();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int index, int handle) { m_handle[index] = handle; }

	// �v���C���[�̏�����
	void init();

	// ����
	void update();
	// �`��
	void draw();

private:
	int m_handle[kGraphicDivNum];

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;


	//�L�����N�^�[�̃A�j���[�V����
	int m_animeNo;	//�\������ԍ�
	int m_animeFrame;
	int m_dirNo;	// �i�s����

	int m_waitFrame;
};