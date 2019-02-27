#ifndef _COMPONENTCANVAS_
#define _COMPONENTCANVAS_
#include "Component.h"
#include "MathGeoLib/Math/float2.h"

class ComponentRectTransform;

class ComponentCanvas :	public Component
{
public:
	ComponentCanvas(GameObject* parent);
	~ComponentCanvas();

	bool Update(float dt) override;
	void Draw() const override;
	void Save(JSON_Object* config) override;

	void setResolution(float2 resolution);	
	inline const float2 getResolution() { return _resolution; }

	bool draw_cross = false;

private:	

	float2 _resolution = float2::zero;
	ComponentRectTransform* rectTransform = nullptr;
	
};

#endif