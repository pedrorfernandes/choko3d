#ifndef WATERLINE_H
#define WATERLINE_H

#include "ScenePrimitive.h"
#include "WaterShader.h"
#include "Plane.h"

class Waterline : public ScenePrimitive {

protected:
	WaterShader * shader;
    Plane * plane1;
	Plane * plane2;
	Plane * plane3;
	Plane * plane4;
    
public:
    string heightmap;
    string texturemap;
    string fragmentshader;
    string vertexshader;
    
    Waterline(string heightmap, string texturemap, string fragmentshader, string vertexshader);
	void draw();
	CGFshader* getShader();

};

#endif
