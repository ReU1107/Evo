#pragma once
#include "Vector.h"
#include "Quaternion.h"
#include "Matrix.h"
#include "MathUtility.h"

namespace Alpha
{
	// ベクトルの長さ取得(Sqrtなし)
	template<class Type, int32 N>
	static inline Type VectorLengthSq(const TVector<Type, N>& vec);

	// ベクトルの長さ取得(Sqrtあり)
	template<class Type, int32 N>
	static inline Type VectorLength(const TVector<Type, N>& vec);

	// 内積計算
	template<class Type, int32 N>
	static inline Type VectorDot(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);

	// 正規化
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorNormalize(const TVector<Type, N>& vec);

	// ベクトル補間
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorLerp(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs, const float s);

	// 外積計算
	static inline Vector3 Vector3Cross(const Vector3& lhs, const Vector3& rhs);

	// 平行ベクトル
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorParallel(const TVector<Type, N>& normal, const TVector<Type, N>& dir);

	// 反射ベクトル
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorReflect(const TVector<Type, N>& normal, const TVector<Type, N>& dir);

	// ベクトル制限
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const Type min, const Type max);

	// ベクトル制限
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const TVector<Type, N>& min, const TVector<Type, N>& max);

	// 逆行列
	static inline Matrix4x4 Matrix4x4Inverse(const Matrix4x4& m);

	// 転置行列
	template<class Type, int32 R, int32 C>
	static inline TMatrix<Type, R, C> MatrixTranspose(const TMatrix<Type, R, C>& base);

	// Vector*Matrix
	template<class Type,int32 Row, int32 Column>
	static inline TVector<Type, Column> VectorMultiply(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat);

	// ベクトル*行列(位置用)
	static inline Vector3 Vector3Transform(const Vector3& vec, const Matrix4x4& mat);
	
	// ベクトル*行列(方向用) 行列の4行4列目の掛け算がありません
	static inline Vector3 Vector3TransformDir(const Vector3& vec, const Matrix4x4& mat);

	// ベクトル*行列
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> Mul(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat);

	// 行列姿勢の上方向(Y軸)情報
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixUp(const TMatrix<Type, Row, Column>& mat);

	// 行列姿勢の上方向(-Y軸)情報
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixDown(const TMatrix<Type, Row, Column>& mat);

	// 行列姿勢の上方向(X軸)情報
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixRight(const TMatrix<Type, Row, Column>& mat);

	// 行列姿勢の上方向(-X軸)情報
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixLeft(const TMatrix<Type, Row, Column>& mat);

	// 行列姿勢の上方向(Z軸)情報
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixForward(const TMatrix<Type, Row, Column>& mat);

	// 行列姿勢の上方向(-Z軸)情報
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixBackward(const TMatrix<Type, Row, Column>& mat);

	// ロール、ピッチ、ヨー回転
	static inline Matrix4x4 Matrix4x4RotationRollPitchYaw(const float roll, const float pitch, const float yaw, const RotationOrder order = RotationOrder::ZXY);

	// X軸回転行列
	static inline Matrix4x4 Matrix4x4RotationX(const float angle);

	// Y軸回転行列
	static inline Matrix4x4 Matrix4x4RotationY(const float angle);

	// Z軸回転行列
	static inline Matrix4x4 Matrix4x4RotationZ(const float angle);

	// スケーリング行列
	static inline Matrix4x4 Matrix4x4Scaling(const Vector3& scale);

	// 回転行列
	static inline Matrix4x4 Matrix4x4Rotation(const Quaternion& rotate);

	// 移動行列
	static inline Matrix4x4 Matrix4x4Translation(const Vector3& translation);

	// 姿勢の前方向(+Z軸)
	static inline Vector3 Matrix4x4Forward(const Matrix4x4& matrix);

	// 姿勢の後方向(-Z軸)
	static inline Vector3 Matrix4x4Backward(const Matrix4x4& matrix);

	// 姿勢の前方向(+X軸)
	static inline Vector3 Matrix4x4Right(const Matrix4x4& matrix);

	// 姿勢の後方向(-X軸)
	static inline Vector3 Matrix4x4Left(const Matrix4x4& matrix);

	// 姿勢の前方向(+Y軸)
	static inline Vector3 Matrix4x4Up(const Matrix4x4& matrix);

	// 姿勢の後方向(-Y軸)
	static inline Vector3 Matrix4x4Down(const Matrix4x4& matrix);

	// 座標
	static inline Vector3 Matrix4x4Position(const Matrix4x4& matrix);

	// 四元数
	static inline float QuaternionLengthSq(const Quaternion& q);

	// 四元数
	static inline float QuaternionLength(const Quaternion& q);

	// 
	static inline float QuaternionDot(const Quaternion& lhs, const Quaternion& rhs);

	// 四元数正規化
	static inline Quaternion QuaternionNormalize(const Quaternion& q);

	// 回転
	static inline Quaternion QuaternionRotationAxis(const Vector3& axis, const float angle);

	// ロールピッチヨー
	static inline Quaternion QuaternionRollPitchYaw(float roll, float pitch, float yaw);

	// 共役四元数
	static inline Quaternion QuaternionConjugate(const Quaternion& q);

	// 逆四元数
	static inline Quaternion QuaternionInverse(const Quaternion& q);

	// 回転値補間
	static inline Quaternion QuaternionSlerp(const Quaternion& lhs, const Quaternion& rhs, const float t);

	// x,y,zそれぞれの回転値取得
	static inline Vector3 QuaternionAngle(const Quaternion& quaternion);
	
	// 回転行列より四元数作成
	static inline Quaternion QuaternionRotationMatrix(const Matrix4x4& matrix);

	// 
	static inline Quaternion QuaternionLookAt(const Vector3& target, const Matrix4x4& matrix, const Vector3& up = (0.0f, 1.0f, 0.0f));
	static inline Quaternion QuaternionLookAt(const float x, const float y, const float z, const Matrix4x4& matrix, const Vector3& up = (0.0f, 1.0f, 0.0f));

}


#include "ArithmeticImpl.h"