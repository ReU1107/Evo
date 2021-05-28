#pragma once


/*
ifdef (if define)　もしマクロが定義されていたら
ifndef (if not define) もしマクロが定義されていなかったら
この場合定義さえされていればいいため
数値を記述する必要はない
*/

/*
プロジェクト
　→プロパティ
 　　→C/C++
   　　　→プリプロセッサの定義 ＊ここでマクロを定義することができる　　マクロ名;と記述する
*/

/*
プラグインを作成する側は↓のマクロを定義しなくていい
*/

#ifdef _WIN32

#define DLLImport __declspec(dllimport)
#define DLLExport __declspec(dllexport)

// api作成側からするとcoreが輸出(export)になりpluginが輸入(import)になる
#ifdef BuildingCore
#define CoreClass class DLLExport
#define PluginClass class DLLImport

#define Core DLLExport
#define Plugin DLLImport

#else
// ↑の逆
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
* 装飾子の記法悩み中
* パスカル記法だと関数やクラス名っぽいし
* かといってマクロ全てをスネーク記法等にすると
* アサセーション等は関数内部で使用するので混同は避けたいし
* キャメルケース記法は変数に使用しているし
* 関数の前につけるようなものだしパスカルでもいいかな？
*/
