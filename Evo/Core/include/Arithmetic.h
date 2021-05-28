#pragma once
#include "Vector.h"
#include "Quaternion.h"
#include "Matrix.h"
#include "MathUtility.h"

namespace Alpha
{
	// �x�N�g���̒����擾(Sqrt�Ȃ�)
	template<class Type, int32 N>
	static inline Type VectorLengthSq(const TVector<Type, N>& vec);

	// �x�N�g���̒����擾(Sqrt����)
	template<class Type, int32 N>
	static inline Type VectorLength(const TVector<Type, N>& vec);

	// ���όv�Z
	template<class Type, int32 N>
	static inline Type VectorDot(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs);

	// ���K��
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorNormalize(const TVector<Type, N>& vec);

	// �x�N�g�����
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorLerp(const TVector<Type, N>& lhs, const TVector<Type, N>& rhs, const float s);

	// �O�όv�Z
	static inline Vector3 Vector3Cross(const Vector3& lhs, const Vector3& rhs);

	// ���s�x�N�g��
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorParallel(const TVector<Type, N>& normal, const TVector<Type, N>& dir);

	// ���˃x�N�g��
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorReflect(const TVector<Type, N>& normal, const TVector<Type, N>& dir);

	// �x�N�g������
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const Type min, const Type max);

	// �x�N�g������
	template<class Type, int32 N>
	static inline TVector<Type, N> VectorClamp(const TVector<Type, N>& vec, const TVector<Type, N>& min, const TVector<Type, N>& max);

	// �t�s��
	static inline Matrix4x4 Matrix4x4Inverse(const Matrix4x4& m);

	// �]�u�s��
	template<class Type, int32 R, int32 C>
	static inline TMatrix<Type, R, C> MatrixTranspose(const TMatrix<Type, R, C>& base);

	// Vector*Matrix
	template<class Type,int32 Row, int32 Column>
	static inline TVector<Type, Column> VectorMultiply(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat);

	// �x�N�g��*�s��(�ʒu�p)
	static inline Vector3 Vector3Transform(const Vector3& vec, const Matrix4x4& mat);
	
	// �x�N�g��*�s��(�����p) �s���4�s4��ڂ̊|���Z������܂���
	static inline Vector3 Vector3TransformDir(const Vector3& vec, const Matrix4x4& mat);

	// �x�N�g��*�s��
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> Mul(const TVector<Type, Row>& vec, const TMatrix<Type, Row, Column>& mat);

	// �s��p���̏����(Y��)���
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixUp(const TMatrix<Type, Row, Column>& mat);

	// �s��p���̏����(-Y��)���
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixDown(const TMatrix<Type, Row, Column>& mat);

	// �s��p���̏����(X��)���
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixRight(const TMatrix<Type, Row, Column>& mat);

	// �s��p���̏����(-X��)���
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixLeft(const TMatrix<Type, Row, Column>& mat);

	// �s��p���̏����(Z��)���
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixForward(const TMatrix<Type, Row, Column>& mat);

	// �s��p���̏����(-Z��)���
	template<class Type, int32 Row, int32 Column>
	static inline TVector<Type, Column> MatrixBackward(const TMatrix<Type, Row, Column>& mat);

	// ���[���A�s�b�`�A���[��]
	static inline Matrix4x4 Matrix4x4RotationRollPitchYaw(const float roll, const float pitch, const float yaw, const RotationOrder order = RotationOrder::ZXY);

	// X����]�s��
	static inline Matrix4x4 Matrix4x4RotationX(const float angle);

	// Y����]�s��
	static inline Matrix4x4 Matrix4x4RotationY(const float angle);

	// Z����]�s��
	static inline Matrix4x4 Matrix4x4RotationZ(const float angle);

	// �X�P�[�����O�s��
	static inline Matrix4x4 Matrix4x4Scaling(const Vector3& scale);

	// ��]�s��
	static inline Matrix4x4 Matrix4x4Rotation(const Quaternion& rotate);

	// �ړ��s��
	static inline Matrix4x4 Matrix4x4Translation(const Vector3& translation);

	// �p���̑O����(+Z��)
	static inline Vector3 Matrix4x4Forward(const Matrix4x4& matrix);

	// �p���̌����(-Z��)
	static inline Vector3 Matrix4x4Backward(const Matrix4x4& matrix);

	// �p���̑O����(+X��)
	static inline Vector3 Matrix4x4Right(const Matrix4x4& matrix);

	// �p���̌����(-X��)
	static inline Vector3 Matrix4x4Left(const Matrix4x4& matrix);

	// �p���̑O����(+Y��)
	static inline Vector3 Matrix4x4Up(const Matrix4x4& matrix);

	// �p���̌����(-Y��)
	static inline Vector3 Matrix4x4Down(const Matrix4x4& matrix);

	// ���W
	static inline Vector3 Matrix4x4Position(const Matrix4x4& matrix);

	// �l����
	static inline float QuaternionLengthSq(const Quaternion& q);

	// �l����
	static inline float QuaternionLength(const Quaternion& q);

	// 
	static inline float QuaternionDot(const Quaternion& lhs, const Quaternion& rhs);

	// �l�������K��
	static inline Quaternion QuaternionNormalize(const Quaternion& q);

	// ��]
	static inline Quaternion QuaternionRotationAxis(const Vector3& axis, const float angle);

	// ���[���s�b�`���[
	static inline Quaternion QuaternionRollPitchYaw(float roll, float pitch, float yaw);

	// �����l����
	static inline Quaternion QuaternionConjugate(const Quaternion& q);

	// �t�l����
	static inline Quaternion QuaternionInverse(const Quaternion& q);

	// ��]�l���
	static inline Quaternion QuaternionSlerp(const Quaternion& lhs, const Quaternion& rhs, const float t);

	// x,y,z���ꂼ��̉�]�l�擾
	static inline Vector3 QuaternionAngle(const Quaternion& quaternion);
	
	// ��]�s����l�����쐬
	static inline Quaternion QuaternionRotationMatrix(const Matrix4x4& matrix);

	// 
	static inline Quaternion QuaternionLookAt(const Vector3& target, const Matrix4x4& matrix, const Vector3& up = (0.0f, 1.0f, 0.0f));
	static inline Quaternion QuaternionLookAt(const float x, const float y, const float z, const Matrix4x4& matrix, const Vector3& up = (0.0f, 1.0f, 0.0f));

}


#include "ArithmeticImpl.h"