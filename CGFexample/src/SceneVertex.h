#ifndef _SCENEVERTEX_H
#define _SCENEVERTEX_H

#include "SceneEdge.h"
#include "YAFGlobal.h"
#include "YAFCamera.h"
#include "CGFscene.h"
#include "CameraView.h"
#include "Appearance.h"
#include "YAFLight.h"
#include "SceneLight.h"
#include <vector>

using namespace std;

class SceneGraph;

class SceneVertex {
	vector<SceneEdge> adj;
	bool childVisited;
	bool nodeVisited;
    Appearance * appearance;
	bool inheritedAppearance;

protected:
	float* matrix;

public:
	//ScenePrimitive IDs are empty
	string id;

	SceneVertex();
	friend class SceneGraph;

	void addEdge(SceneVertex *dest);
	bool removeEdgeTo(SceneVertex  *d);

	bool operator<(const SceneVertex vertex);

	vector<SceneVertex*> getEdges();

	float* getMatrix();
    
    Appearance * getAppearance();
    void setAppearance(Appearance * appearance);
    
	virtual void draw() {}
};


class SceneComposite: public SceneVertex {
public:
	SceneComposite(float* matrix, string id);
};


#endif
