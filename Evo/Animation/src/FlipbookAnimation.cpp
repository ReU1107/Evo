#include "FlipbookAnimation.h"

namespace Alpha
{
	class FlipbookAnimation::Impl
	{
	private:
		uint32 m_horizontalSize;			// ���������T�C�Y
		uint32 m_verticalSize;				// ���������T�C�Y
		uint32 m_horizontalDivisionCount;	// ��������������
		uint32 m_verticalDivisionCount;		// ��������������

	public:
		Impl();
		~Impl();

		// ����(��)�����̃T�C�Y�ݒ�
		void SetHorizontalSize(uint32 size);

		// ����(�c)�����̃T�C�Y�ݒ�
		void SetVerticalSize(uint32 size);

		// ����(��)�����̕������ݒ�
		void SetHorizontalDivisionCount(uint32 count);
		
		// ����(�c)�����̕������ݒ�
		void SetVerticalDivisionCount(uint32 count);

		// ����(��)�����̕����T�C�Y�擾
		uint32 GetHorizontalDivisionSize() const;

		// ����(�c)�����̕����擾
		uint32 GetVerticalDivisionSize() const;

		// ���ݕ\���������ꏊ�擾

		void Update(const float deltaTime);
	};

	FlipbookAnimation::Impl::Impl()
		: m_horizontalSize()
		, m_verticalSize()
		, m_horizontalDivisionCount()
		, m_verticalDivisionCount()
	{

	}

	FlipbookAnimation::Impl::~Impl()
	{

	}

	void FlipbookAnimation::Impl::SetHorizontalSize(uint32 size)
	{
		m_horizontalSize = size;
	}

	void FlipbookAnimation::Impl::SetVerticalSize(uint32 size)
	{
		m_verticalSize = size;
	}

	void FlipbookAnimation::Impl::SetHorizontalDivisionCount(uint32 count)
	{
		m_horizontalDivisionCount = count;
	}

	void FlipbookAnimation::Impl::SetVerticalDivisionCount(uint32 count)
	{
		m_verticalDivisionCount = count;
	}

	uint32 FlipbookAnimation::Impl::GetHorizontalDivisionSize() const
	{
		return m_horizontalDivisionCount;
	}

	uint32 FlipbookAnimation::Impl::GetVerticalDivisionSize() const
	{
		return m_verticalDivisionCount;
	}

	void FlipbookAnimation::Impl::Update(const float deltaTime)
	{

	}

	FlipbookAnimation::FlipbookAnimation()
	{

	}

	FlipbookAnimation::~FlipbookAnimation()
	{

	}
}