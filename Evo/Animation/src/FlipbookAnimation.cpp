#include "FlipbookAnimation.h"

namespace Alpha
{
	class FlipbookAnimation::Impl
	{
	private:
		uint32 m_horizontalSize;			// 水平方向サイズ
		uint32 m_verticalSize;				// 垂直方向サイズ
		uint32 m_horizontalDivisionCount;	// 水平方向分割数
		uint32 m_verticalDivisionCount;		// 垂直方向分割数

	public:
		Impl();
		~Impl();

		// 水平(横)方向のサイズ設定
		void SetHorizontalSize(uint32 size);

		// 垂直(縦)方向のサイズ設定
		void SetVerticalSize(uint32 size);

		// 水平(横)方向の分割数設定
		void SetHorizontalDivisionCount(uint32 count);
		
		// 垂直(縦)方向の分割数設定
		void SetVerticalDivisionCount(uint32 count);

		// 水平(横)方向の分割サイズ取得
		uint32 GetHorizontalDivisionSize() const;

		// 垂直(縦)方向の分割取得
		uint32 GetVerticalDivisionSize() const;

		// 現在表示したい場所取得

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