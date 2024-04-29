#include <ArduinoJson.h>

static void BuildStandaloneScreenRotationJSON(JsonObject &root, StandaloneScreenRotation screen, String textValue, int *bitmapArray) {
    // Build Bitmap
    JsonObject &bitmap = root.createNestedObject("bitmap");
    JsonArray &bitmap_data = bitmap.createNestedArray("data");
    //int symbol[] = {0,65535,65535,65535,0,0,0,0,0,65535,63488,65535,0,0,0,0,0,65535,63488,65535,0,0,0,0,0,65535,63488,65535,0,0,0,0,65535,63488,63488,63488,65535,0,0,0,65535,63488,63488,63488,65535,0,0,0,65535,63488,63488,63488,65535,0,0,0,0,65535,65535,65535,0,0,0,0};
    //int symbol[] = {1,2,3,4,5,6,7,8,9};
   
    for (int i = 0; bitmapArray[i] != -1; i++) {
        bitmap_data.add(bitmapArray[i]);
    }
    

    JsonObject &bitmap_position = bitmap.createNestedObject("position");
    bitmap_position["x"] = 0;
    bitmap_position["y"] = 0;

    JsonObject &bitmap_size = bitmap.createNestedObject("size");
    bitmap_size["width"] = 8;
    bitmap_size["height"] = 8;

    // Build Text
    JsonObject &text = root.createNestedObject("text");
    text["textString"] = textValue;
    text["scrollText"] = false;
    text["bigFont"] = false;
    text["centerText"] = true;
    text["scrollTextDelay"] = 40;
    text["hexColor"] = screen.color;

    JsonObject &text_position = text.createNestedObject("position");
    text_position["x"] = 7;
    text_position["y"] = 1;

    // Build Animation
    JsonObject &switchAnimation = root.createNestedObject("switchAnimation");
    if (screen.switchAnimation != "none") {
        switchAnimation["aktiv"] = true;
        switchAnimation["animation"] = screen.switchAnimation;
    }else {
        switchAnimation["aktiv"] = false;
    }

    root.prettyPrintTo(Serial);  
}