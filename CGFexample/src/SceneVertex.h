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
#include "CGFshader.h"
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Animation;
class SceneGraph;

class SceneVertex {
	vector<SceneEdge> adj;
	bool childVisited;
	bool nodeVisited;
    Appearance * appearance;
	bool inheritedAppearance;
    map<unsigned int, unsigned int> displayLists;
	map<unsigned int, bool> initializedDisplayLists;
    
    static unsigned int currentDisplayList;

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
    
    bool usesDisplayList;
	void initializeDisplayList(unsigned int id);
    bool initializedDisplayList(unsigned int id);
    void activateDisplayList();
    void disableDisplayList();
    unsigned int getDisplayList(unsigned int id);
    
    Animation * animation;
    
    void setAnimation(Animation * animation);
    Animation * getAnimation();
	virtual CGFshader* getShader() {return NULL;}
};


class SceneComposite: public SceneVertex {
public:
	SceneComposite(float* matrix, string id);
};


#endif
