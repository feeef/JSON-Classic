# JSON Classic

JSON Classic is a C++ JSON library for the classic Macintosh operating system. Those old macs can still be fun to use. The goal of this lib is to help building modern lightweight client apps for the old machines.

This project was created under Code Warrior Pro 1 and has been succesfully tested on a PowerPC as well as on a 68k mac. (There is no proper test files yet. Just some calls in the main function.)

Feel free to use and update this code for any projects.


To run the CodeWarrior project, just unstuff JSON-Classic.sit. It is the project file compressed to preserve its CodeWarrior resources.


# Features

## Read JSON

```c++
stringstream strm;
strm << "{                                  \
          \"key\":\"value\",                \
          \"number\":1,                     \
          \"object\":{\"key1\":\"value1\"}, \
          \"array\":[1,2,3]                 \
          }";

JSONReader *reader = new JSONReader();

string status = reader->readStream(strm);

// 'status' will hold a verbose output of the reading process.
// (This was done for debugging purpose and should be improved)
```

## Access JSON data

```c++
JSONObject *root = reader->getRootObject();

// String attribute
//
JSONValue *stringValue = root->getValue("key");
JSONValue::Type type = stringValue->getType();  // ==> JSONValue::DATA_TYPE_STRING
string str = stringValue->toString();           // ==> "value"

// Number attribute
//
JSONValue *numberValue = root->getValue("number");
JSONValue::Type type = numberValue->getType();  // ==> JSONValue::DATA_TYPE_NUMBER
string str = numberValue->toString();           // ==> "1"

// Objects
//
// Both arrays and hash objects are handled by the class JSONObject.
// the JSON root element is always a JSONObject. 
// 
// The JSONObject::isArray() methods indicates if the object is an array.
//
JSONValue *arrayValue = root->getValue("array");
JSONValue::Type type = arrayValue->getType();       // ==> JSONValue::DATA_TYPE_ARRAY
JSONObject *arrayObject = arrayValue->toObject();   // Used to access child elements
string str = arrayValue->toString();                // ==> "[1,2,3]"

JSONValue *objectValue = root->getValue("object");
JSONValue::Type type = objectValue->getType();      // ==> JSONValue::DATA_TYPE_OBJECT
JSONObject *obj = objectValue->toObject();          // Used to access child elements
string str = objectValue->toString();               // ==> "{"key1":"value1"}"
```

## Value types

```c++
static enum Type
{
  DATA_TYPE_STRING,        	//    "xxx"
  DATA_TYPE_NUMBER,        	//    [+/-]000.000[e[+/-]000]
  DATA_TYPE_BOOLEAN,       	//    true -or- false
  DATA_TYPE_NULL,          	//    null
  DATA_TYPE_OBJECT,        	//    { }
  DATA_TYPE_ARRAY,   			//    [ ]
}
```

## Updating JSON data

```c++
root->setValue("number2", "10", JSONValue::DATA_TYPE_NUMBER);
root->erase("number2");

JSONObject *array = root->getValue("array")->toObject();
array->push(4);     // (value)
array->insert(2,7); // (position, value)
array->erase(0);    // (position)
```

## Generating JSON string

```c++
string jsonString = root->toString();

string specificObjectString = root->getValue("array")->toString();
```


