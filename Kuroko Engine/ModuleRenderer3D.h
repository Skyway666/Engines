#pragma once
#include "Module.h"
#include "Globals.h"
#include "Light.h"
#include "Vector3.h"

#define MAX_LIGHTS 8

class ModuleRenderer3D : public Module
{
public:
	ModuleRenderer3D(Application* app, bool start_enabled = true);
	~ModuleRenderer3D();

	bool Init();
	update_status PreUpdate(float dt);
	update_status PostUpdate(float dt);
	bool CleanUp();

	void OnResize(int width, int height);

	SDL_GLContext getContext()	{ return context; }

	float4x4 CreatePerspMat(float fov, float aspect_ratio, float near_plane, float far_plane);

	void DirectDrawCube(Vector3f size);

private:
	Light lights[MAX_LIGHTS];
	SDL_GLContext context;
	float3x3 NormalMatrix;
	float4x4 ModelMatrix, ViewMatrix, ProjectionMatrix;
};