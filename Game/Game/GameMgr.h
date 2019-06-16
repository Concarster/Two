#pragma once
#include <Engine/Util/Define.h>
#include <Engine/Display/Display.h>

class GameMgr : public one::Display
{
public:
	GameMgr();
	~GameMgr();

	// Inherited via Display
	virtual void Build() override;

	virtual void Destroy() override;

	virtual void OnEntry() override;

	virtual void OnExit() override;

	virtual void Update()override;

	virtual void Draw() override;

	virtual int GetNextDisplayID() const override;

	virtual int GetPreviousDisplayID() const override;

private:
	void CheckInput();

};

