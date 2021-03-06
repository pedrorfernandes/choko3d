#include "YAFAppearance.h"

YAFAppearance::YAFAppearance(string id, vector<float> emissiveValues, vector<float> ambientValues, vector<float> diffuseValues, vector<float> specularValues, float shininess) {
	initiateValues(id, emissiveValues, ambientValues, diffuseValues, specularValues, shininess);

	usesTexture = false;

	validate();
}

YAFAppearance::YAFAppearance(string id, vector<float> emissiveValues, vector<float> ambientValues, vector<float> diffuseValues, vector<float> specularValues, float shininess, string textureID, float texlength_s, float texlength_t, map<string, YAFTexture> loadedTextures) {
	initiateValues(id, emissiveValues, ambientValues, diffuseValues, specularValues, shininess);

	usesTexture = true;
	this->textureID = textureID;
	this->texlength_s = texlength_s;
	this->texlength_t = texlength_t;

	validate(textureID, loadedTextures);
}

void YAFAppearance::initiateValues(string id, vector<float> emissiveValues, vector<float> ambientValues, vector<float> diffuseValues, vector<float> specularValues, float shininess) {

	this->id = id;

	this->emissiveR = emissiveValues.at(0);
	this->emissiveG = emissiveValues.at(1);
	this->emissiveB = emissiveValues.at(2);
	this->emissiveA = emissiveValues.at(3);

	this->ambientR = ambientValues.at(0);
	this->ambientG = ambientValues.at(1);
	this->ambientB = ambientValues.at(2);
	this->ambientA = ambientValues.at(3);

	this->diffuseR = diffuseValues.at(0);
	this->diffuseG = diffuseValues.at(1);
	this->diffuseB = diffuseValues.at(2);
	this->diffuseA = diffuseValues.at(3);

	this->specularR = specularValues.at(0);
	this->specularG = specularValues.at(1);
	this->specularB = specularValues.at(2);
	this->specularA = specularValues.at(3);

	this->shininess = shininess;
}

void YAFAppearance::validate() {
    char errorMessage[ERROR_LEN];

	if( !validRGBA(emissiveR, emissiveG, emissiveB, emissiveA) ) {
        sprintf(errorMessage, "Appearance '%s': emissive (RGBA)", id.c_str());
		throw(InvalidAttributeValueException(errorMessage));
	}
	if( !validRGBA(ambientR, ambientG, ambientB, ambientA) ) {
        sprintf(errorMessage, "Appearance '%s': ambient (RGBA)", id.c_str());
		throw(InvalidAttributeValueException(errorMessage));
	}

	if( !validRGBA(diffuseR, diffuseG, diffuseB, diffuseA) ) {
        sprintf(errorMessage, "Appearance '%s': diffuse (RGBA)", id.c_str());
		throw(InvalidAttributeValueException(errorMessage));
	}

	if( !validRGBA(specularR, specularG, specularB, specularA) ) {
        sprintf(errorMessage, "Appearance '%s': specular (RGBA)", id.c_str());
		throw(InvalidAttributeValueException(errorMessage));
	}

	if( !validShininess(shininess) ) {
        sprintf(errorMessage, "Appearance '%s': shininess", id.c_str());
		throw(InvalidAttributeValueException(errorMessage));
	}
}

void YAFAppearance::validate(string textureID, map<string, YAFTexture> loadedTextures) {

	validate();

	if(loadedTextures.find(textureID) == loadedTextures.end()) {
        char errorMessage[ERROR_LEN];
        sprintf(errorMessage, "Appearance '%s': textureref (Has the texture '%s' been loaded?)", id.c_str(), textureID.c_str());
		throw(InvalidAttributeValueException(errorMessage));
    }
}


