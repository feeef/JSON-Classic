#ifndef _JSON_VALUE_H_#define _JSON_VALUE_H_// Forward declare JSONObject//class JSONObject;// Declare JSONValue//class JSONValue {public:	static enum Type      	{			DATA_TYPE_STRING,        	//    "xxx"			DATA_TYPE_NUMBER,        	//    [+/-]000.000[e[+/-]000]			DATA_TYPE_BOOLEAN,       	//    true -or- false			DATA_TYPE_NULL,          	//    null			DATA_TYPE_OBJECT,        	//    { }			DATA_TYPE_ARRAY,   			//    [ ]      	};      	      							JSONValue();								virtual				~JSONValue();							Type		getType();			string 		toString();			JSONObject*	toObject();						void 		setValue(string stringVal, Type typeVal);			//void 		setValue(vector<string, allocator<JSONValue*> >);			void 		setValue(JSONObject* objectVal);		protected:        	   	Type 									type;   	string 									stringValue;   	//vector<string, allocator<JSONValue*> > 	arrayValue;   	JSONObject* 							objectValue;	};#endif