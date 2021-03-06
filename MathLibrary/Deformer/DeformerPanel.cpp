#include "DeformerPanel.h"
#include "Stacker/Primitive.h"
#include "Stacker/Controller.h"

DeformerPanel::DeformerPanel()
{
	activeScene = NULL;

	dw.setupUi(this);

	// Connections
	connect(dw.createBoundingButton, SIGNAL(clicked()), SLOT(onCreateBoundingClicked()));
}

void DeformerPanel::setActiveScene( Scene * newScene)
{
	activeScene = newScene;
}

void DeformerPanel::onCreateBoundingClicked()
{
	if(!activeScene || !activeScene->activeObject())
		return;

	Controller * ctrl = (Controller *)activeScene->activeObject()->ptr["controller"];
	Primitive * prim = ctrl->getSelectedPrimitive();

	if(!prim) return;

	QSurfaceMesh* mesh = prim->m_mesh;

	activeDeformer = new QFFD(mesh, BoundingBoxFFD, Vec3i(dw.xRes->value(), dw.yRes->value(), dw.zRes->value()));

	connect(activeDeformer, SIGNAL(meshDeformed()), activeScene, SLOT(updateActiveObject()));

	emit( deformerCreated(activeDeformer) );
}
