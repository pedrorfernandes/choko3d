#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"
#include "CGFscene.h"
#include <sstream>
#include <stdio.h>

class XMLScene : public CGFscene 
{
public:
	XMLScene(char *filename);
	~XMLScene();

	static TiXmlElement *findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val);
    template<class T> vector<T> getValues(TiXmlElement * element, vector<string> attributeNames);
    template<class T> T getValue(TiXmlElement * element, char * attributeName);
    template<class T> vector<T> getValues(TiXmlElement * element, char * attributeName);

	
protected:

	TiXmlDocument* doc;

	TiXmlElement* globalsElement; 
	TiXmlElement* camerasElement;
	TiXmlElement* lightingElement;
	TiXmlElement* texturesElement;
	TiXmlElement* appearancesElement;
	TiXmlElement* graphElement;

};

template<class T>
vector<T> XMLScene::getValues(TiXmlElement * element, char * attributeName) {
    vector<T> values;
    T value;
    
    char* valString = NULL;
    valString = (char *) element->Attribute(attributeName);
    
    // TODO throw exception?
    if (valString == NULL ) return values;
    
    stringstream ss (valString);
    
    while ( !ss.eof() ) {
        if ( ss >> value )
            values.push_back(value);
        else {
            // TODO error handling
            printf("something went wrong parsing %s!!\n", attributeName);
            break;
        }
    }
    
    return values;
}

template<class T>
T XMLScene::getValue(TiXmlElement * element, char * attributeName) {
    return getValues<T>(element, attributeName).at(0);
}


template<class T>
vector<T> XMLScene::getValues(TiXmlElement* element, vector<string> attributeNames) {
    
	vector<T> values;
    
	for(size_t i = 0; i < attributeNames.size(); i++) {
        
		vector<T> currentValues = getValues<T>( element, (char*)attributeNames.at(i).c_str() );
        
        for(size_t j = 0; j < currentValues.size(); j++ ){
            values.push_back( currentValues.at(j) );
        }
	}
    
	return values;
}

#endif