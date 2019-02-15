#include "ComponentImageUI.h"
#include "GameObject.h"
#include "glew-2.1.0\include\GL\glew.h"
#include "MathGeoLib/Math/float4x4.h"
#include "MathGeoLib/Math/Quat.h"
#include "ComponentRectTransform.h"


ComponentImageUI::ComponentImageUI(GameObject* parent) : Component(parent, UI_IMAGE)
{
	rectTransform = (ComponentRectTransform*)parent->getComponent(RECTTRANSFORM);
}


ComponentImageUI::~ComponentImageUI()
{
	rectTransform = nullptr;
}

bool ComponentImageUI::Update(float dt)
{
	return true;
}

void ComponentImageUI::Draw() const
{
	//glPushMatrix();
	//float4x4 globalMat;
	//globalMat = float4x4::FromTRS(float3(rectTransform->getGlobalPos().x, rectTransform->getGlobalPos().y, 0), Quat(0, 0, 0, 0), float3(rectTransform->getWidth(), rectTransform->getHeight(), 0));
	//glMultMatrixf(globalMat.Transposed().ptr());

	//glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//glBindBuffer(GL_ARRAY_BUFFER, 0); //resets the buffer
	//glBindTexture(GL_TEXTURE_2D, 0);
	//glEnable(GL_BLEND);
	//glColor4f(1.0, 1.0, 1.0, alpha);
	//glLineWidth(4.0f);

	//if (HasTexture()) {

	//	glBindTexture(GL_TEXTURE_2D, resourceTexture->gpuID);
	//	glTexCoordPointer(2, GL_FLOAT, 0, &(texCoords[0]));
	//}
	//glBindBuffer(GL_ARRAY_BUFFER, rectTransform->GetVertexID());
	//glVertexPointer(3, GL_FLOAT, 0, NULL);
	//glDrawArrays(GL_QUADS, 0, 4);

	//glLineWidth(1.0f);

	//glBindTexture(GL_TEXTURE_2D, 0);
	//glBindBuffer(GL_ARRAY_BUFFER, 0); //resets the buffer
	//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	//glDisableClientState(GL_VERTEX_ARRAY);

	//glDisable(GL_BLEND);
	//glPopMatrix();

}

void ComponentImageUI::Save(JSON_Object * config)
{
}
