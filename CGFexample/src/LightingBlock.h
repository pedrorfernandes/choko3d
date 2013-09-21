#ifndef LIGHTINGBLOCK_H
#define LIGHTINGBLOCK_H

#include "YAFElement.h"

class LightAttributes: public YAFElement {
private:
	static vector<string> usedLightIDs;

public:
	string id;
	bool enabled;
	bool isOmni;

	//if omni light:
	float locationX;
	float locationY;
	float locationZ;
	float ambientR;
	float ambientG;
	float ambientB;
	float ambientA;
	float diffuseR;
	float diffuseG;
	float diffuseB;
	float diffuseA;
	float specularR;
	float specularG;
	float specularB;
	float specularA;

	//if spot light:
	float angle;
	float exponent;
	float directionX;
	float directionY;
	float directionZ;

	LightAttributes(string id, bool enabled, bool isOmni, vector<int> values);
	void validate();
};

class LightingBlock: public YAFElement {
public:
	bool doublesided;
	bool local;
	bool enabled;
	float ambientR;
	float ambientG;
	float ambientB;
	float ambientA;
	vector<LightAttributes> lights;

	LightingBlock(vector<bool> ligthingProperties, vector<float> ambientRGBA, vector<LightAttributes> lights);
};

#endif