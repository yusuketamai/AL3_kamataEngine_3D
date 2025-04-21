#include "GameScene.h"

using namespace KamataEngine;

//デストラクタ
GameScene::~GameScene() { delete model_; }

void GameScene::Initialize() {
	//ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("mario.jpg");

	////スプライトのインスタンスの生成
	//sprite_ = Sprite::Create(textureHandol_, {100, 50});

	//3Dモデルの生成
	model_ = Model::Create();

	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	//カメラの初期化
	camera_.Initialize();
	//playerの生成
	player_ = new Player();
	//自キャラの初期化
	player_->Initialize(model_,textureHandle_,&camera_);

}

void GameScene::Update() {

	player_->update();

}

void GameScene::Draw() {
	//DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//スプライトの描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	model_->Draw(worldTransform_,camera_,textureHandle_);

	player_->Draw();

	//スプライトの描画処理
	Model::PostDraw();

	

}


