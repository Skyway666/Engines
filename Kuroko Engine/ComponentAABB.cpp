#include "ComponentAABB.h"
#include "ComponentMesh.h"
#include "GameObject.h"

#include "glew-2.1.0\include\GL\glew.h"
#include "ComponentTransform.h"


ComponentAABB::~ComponentAABB()
{
	if (aabb) delete aabb;
	if (obb) delete obb;
}

void ComponentAABB::Reload()
{
	if (!obb)
		obb = new OBB();

	Vector3f half_size, centroid;
	getParent()->getInheritedHalfsizeAndCentroid(half_size, centroid);

	obb->pos = centroid.toMathVec();
	obb->r = half_size.toMathVec();

	transform = (ComponentTransform*)getParent()->getComponent(TRANSFORM);

	obb->axis[0] = transform->Right();
	obb->axis[1] = transform->Up();
	obb->axis[2] = transform->Forward();

	if (!aabb)
		aabb = new AABB();

	*aabb = obb->MinimalEnclosingAABB();
}

bool ComponentAABB::Update(float dt)
{
	if (isActive())
	{
		bool update = false;

		Vector3f inh_half_size, inh_centroid;
		getParent()->getInheritedHalfsizeAndCentroid(inh_half_size, inh_centroid);

		if (!inh_centroid.toMathVec().Equals(obb->pos))
		{
			obb->pos = inh_centroid.toMathVec();
			update = true;
		}

		if (!transform->Right().Equals(obb->axis[0]))
		{
			obb->axis[0] = transform->Right();
			obb->axis[1] = transform->Up();
			obb->axis[2] = transform->Forward();

			update = true;
		}


		if (!inh_half_size.toMathVec().Equals(obb->r))
		{
			obb->r = inh_half_size.toMathVec();
			update = true;
		}

		if (update)
			*aabb = obb->MinimalEnclosingAABB();
		
		
		if (draw_aabb)
			DrawAABB();
		if (draw_obb)
			DrawOBB();
	}
	return true;
}

void ComponentAABB::DrawAABB()
{
	Vector3f lowest_p = { aabb->minPoint.x, aabb->minPoint.y,aabb->minPoint.z };
	Vector3f highest_p = { aabb->maxPoint.x, aabb->maxPoint.y,aabb->maxPoint.z };

	glLineWidth(1.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);

	glVertex3f(lowest_p.x, lowest_p.y, lowest_p.z);		glVertex3f(highest_p.x, lowest_p.y, lowest_p.z);
	glVertex3f(lowest_p.x, lowest_p.y, lowest_p.z);		glVertex3f(lowest_p.x, highest_p.y, lowest_p.z);
	glVertex3f(highest_p.x, lowest_p.y, lowest_p.z);	glVertex3f(highest_p.x, highest_p.y, lowest_p.z);
	glVertex3f(lowest_p.x, highest_p.y, lowest_p.z);	glVertex3f(highest_p.x, highest_p.y, lowest_p.z);

	glVertex3f(highest_p.x, highest_p.y, highest_p.z);  glVertex3f(lowest_p.x, highest_p.y, highest_p.z);
	glVertex3f(highest_p.x, highest_p.y, highest_p.z);  glVertex3f(highest_p.x, lowest_p.y, highest_p.z);
	glVertex3f(lowest_p.x, highest_p.y, highest_p.z);	glVertex3f(lowest_p.x, lowest_p.y, highest_p.z);
	glVertex3f(highest_p.x, lowest_p.y, highest_p.z);	glVertex3f(lowest_p.x, lowest_p.y, highest_p.z);

	glVertex3f(lowest_p.x, lowest_p.y, lowest_p.z);		glVertex3f(lowest_p.x, lowest_p.y, highest_p.z);
	glVertex3f(highest_p.x, highest_p.y, lowest_p.z);	glVertex3f(highest_p.x, highest_p.y, highest_p.z);
	glVertex3f(highest_p.x, lowest_p.y, lowest_p.z);	glVertex3f(highest_p.x, lowest_p.y, highest_p.z);
	glVertex3f(lowest_p.x, highest_p.y, lowest_p.z);	glVertex3f(lowest_p.x, highest_p.y, highest_p.z);

	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);

	glLineWidth(1.0f);
}

void ComponentAABB::DrawOBB()
{
	glLineWidth(1.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);

	for (int i = 0; i < 12; i++)
		{ glVertex3f(obb->Edge(i).a.x, obb->Edge(i).a.y, obb->Edge(i).a.z);		glVertex3f(obb->Edge(i).b.x, obb->Edge(i).b.y, obb->Edge(i).b.z); }

	
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);

	glLineWidth(1.0f);
}
