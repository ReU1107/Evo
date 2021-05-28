#pragma once


/*
ifdef (if define)�@�����}�N������`����Ă�����
ifndef (if not define) �����}�N������`����Ă��Ȃ�������
���̏ꍇ��`��������Ă���΂�������
���l���L�q����K�v�͂Ȃ�
*/

/*
�v���W�F�N�g
�@���v���p�e�B
 �@�@��C/C++
   �@�@�@���v���v���Z�b�T�̒�` �������Ń}�N�����`���邱�Ƃ��ł���@�@�}�N����;�ƋL�q����
*/

/*
�v���O�C�����쐬���鑤�́��̃}�N�����`���Ȃ��Ă���
*/

#ifdef _WIN32

#define DLLImport __declspec(dllimport)
#define DLLExport __declspec(dllexport)

// api�쐬�����炷���core���A�o(export)�ɂȂ�plugin���A��(import)�ɂȂ�
#ifdef BuildingCore
#define CoreClass class DLLExport
#define PluginClass class DLLImport

#define Core DLLExport
#define Plugin DLLImport

#else
// ���̋t
#define CoreClass class DLLImport
#define PluginClass class DLLExport

#define Core DLLImport
#define Plugin DLLImport

#endif // BuildingCore
#else
#define Core
#define Plugin
#endif

#ifdef __cplusplus

#endif // __cplusplus

#define New new

#define CoreFunction extern "C" Core
#define PluginFunction extern "C" Plugin

#define BaseClass(name) \
class name

#define DerivedClass(name,base) \
class name : public base 

#define AAA(base) using Base = base;\
PImpl


#define NAlpha namespace Alpha

/*
* CoreClass
*/

/*
* �����q�̋L�@�Y�ݒ�
* �p�X�J���L�@���Ɗ֐���N���X�����ۂ���
* ���Ƃ����ă}�N���S�Ă��X�l�[�N�L�@���ɂ����
* �A�T�Z�[�V�������͊֐������Ŏg�p����̂ō����͔���������
* �L�������P�[�X�L�@�͕ϐ��Ɏg�p���Ă��邵
* �֐��̑O�ɂ���悤�Ȃ��̂����p�X�J���ł��������ȁH
*/
