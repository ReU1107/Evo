#pragma once

namespace Alpha
{
	enum class AnimationLayerType
	{
		Base,	// �x�[�X�ƂȂ鉺�ʃ��C���[
		Add,	// �x�[�X�ɑ΂��ĉ��Z�������s����ʃ��C���[
	};
	/*
	* ���ʃ��C���[��=
	* ��ʃ��C���[��+
	* �������{�����
	* ���������ʂ̉��ʃ��C���[��2�ȏ㑶�݂������Ԍ�ɒǉ����ꂽ���̂̌��ʂɂȂ�
	*/

	class AnimationLayer
	{
	public:
		virtual ~AnimationLayer() noexcept {}

		
	private:
		// AnimationStateMachine* m_stateMachine;	// �X�e�[�g�}�V�[��

	};

	// �x�[�X���C���[
	class AnimationBaseLayer final : public AnimationLayer
	{

	};

	// ���Z���C���[
	class AnimationAddLayer final : public AnimationLayer
	{

	};
}