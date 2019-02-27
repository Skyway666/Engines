#ifndef _COMPONENTBUTTONUI_
#define _COMPONENTBUTTONUI_

#include "Component.h"


class ComponentRectTransform;
class ComponentImageUI;
class ResourceTexture;

enum ButtonState {
	B_IDLE = 0,
	B_MOUSEOVER,
	B_PRESSED
};

class ComponentButtonUI :public Component
{
public:
	ComponentButtonUI(GameObject* parent);
	~ComponentButtonUI();

	bool Update(float dt)override;
	void Save(JSON_Object* config) override;

	const ResourceTexture* getResourceTexture(ButtonState state);
	void setResourceTexture(ResourceTexture* tex, ButtonState state); 
	void DeassignTexture(ButtonState state);
	inline void setState(ButtonState _state) { state = _state; ChangeGOImage(); };// for debug, may be obsolete
	void ChangeGOImage();	

	ButtonState state = B_IDLE;

	inline void doFadeIn() {	alpha = 0.0f; fadingIn = true;}
	inline void doFadeOut() { alpha = 1.0f; fadingOut = true; }
	
	
private:

	ComponentRectTransform * rectTransform = nullptr;
	ComponentImageUI* image = nullptr;

	ResourceTexture* idle = nullptr;
	ResourceTexture* hover = nullptr;
	ResourceTexture* pressed = nullptr;

	void FadeIn();
	void FadeOut();
	bool fadingIn = false;
	bool fadingOut = false;
	float alpha = 1.0f;
};

#endif