#include <iostream>
#include "/home/student/Project/ClientServerSQL/cJSON.h"

using namespace std;

int main(){
    string strJ;
    cJSON* jobj1 = cJSON_CreateObject();

    cJSON_AddNumberToObject(jobj1, "Key", 45);
    cJSON_AddStringToObject(jobj1, "Value", "Hello");

    strJ = cJSON_Print(jobj1);
    cout << strJ << endl;

    string strValue = cJSON_GetObjectItem(jobj1, "Value")->valuestring;
    int numValue = cJSON_GetObjectItem(jobj1, "Keys")->valueint;
    cout << numValue << " " << strValue << endl;

    cJSON* jobj2 = cJSON_Parse(strJ.c_str());
    strJ = cJSON_Print(jobj2);
    cout << strJ << endl;

    cout << "Hello World!" << endl;

    cJSON_Delete(jobj1);
    cJSON_Delete(jobj2);
    //cJSON_Delete(jarr);

    return 0;
}
