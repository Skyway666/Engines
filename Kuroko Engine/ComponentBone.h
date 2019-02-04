#ifndef _COMPONENT_BONE
#define _COMPONENT_BONE

#include "Component.h"
//TMP - substitute by Bone.h
#include "Globals.h"

class ComponentBone : public Component
{
public:
	ComponentBone(GameObject* gameobject) : Component(gameobject, BONE) {};   // empty constructor
	ComponentBone(JSON_Object* deff, GameObject* parent);
	~ComponentBone();

	void Save(JSON_Object* config);

private:

	uint bone_resource_uuid = 0;
	float4x4 globalOffset = float4x4::identity;
};

#endif // !_COMPONENT_BONE