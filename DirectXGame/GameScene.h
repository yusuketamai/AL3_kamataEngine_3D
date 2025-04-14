#pragma once
#include "KamataEngine.h"
class GameScene {
public:

	//デストラクタ
	~GameScene();

	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

	//テクスチャハンドル
	uint32_t textureHandol_ = 0;

	//3Dモデル
	KamataEngine::Model* model_ = nullptr;

	//ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;
	//カメラ
	KamataEngine::Camera camera_;

};
